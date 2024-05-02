#include "stdafx.h"
#include "stdafx.h"
#include "GsCore.h"
#include "PyGsView.h"
#include "PyDbObjectId.h"
#include "AcGsManager.h"
//#include "format_codecs/PngFormatCodec.h"


//ZWCAD 'register' is no longer a supported storage class
#pragma warning( disable: 5033 )
#include "Image.h"
#include "RgbModel.h"
#include "RgbGrayModel.h"
#include "RgbPaletteModel.h"
#include "RgbPaletteModel.h"
#include "codec_properties/FormatCodecPropertyInterface.h"
#include "format_codecs/BmpFormatCodec.h"
#include "RowProviderInterface.h"
#include "FileWriteDescriptor.h"
#include "DataBuffer.h"
#pragma warning( pop )

using namespace boost::python;

//https://adndevblog.typepad.com/autocad/2013/01/capturing-a-screen-shot-using-objectarx.html

struct AcGsDeviceDeleter
{
    void operator()(AcGsDevice* ptr)
    {
        acgsGetGsManager()->destroyAutoCADDevice(ptr);
    }
};
using AcGsDevicePtr = std::unique_ptr <AcGsDevice, AcGsDeviceDeleter>;

struct AcGsViewDeleter
{
    void operator()(AcGsView* ptr)
    {
#if !defined (_BRXTARGET240)
        acgsGetGsManager()->destroyView(ptr);
#endif
    }
};
using AcGsViewPtr = std::unique_ptr <AcGsView, AcGsViewDeleter>;

struct AcGsModelDeleter
{
    void operator()(AcGsModel* ptr)
    {
        acgsGetGsManager()->destroyAutoCADModel(ptr);
    }
};
using AcGsModelPtr = std::unique_ptr <AcGsModel, AcGsModelDeleter>;

void makeGsCoreWrapper()
{
    PyDocString DS("Core");
    class_<GsCore>("Core")
        .def("getCurrentAcGsView", &GsCore::getCurrentAcGsView, DS.SARGS({ "vpNum : int" })).staticmethod("getCurrentAcGsView")
        .def("getCurrent3DAcGsView", &GsCore::getCurrent3DAcGsView, DS.SARGS({ "vpNum : int" })).staticmethod("getCurrent3DAcGsView")
        .def("getViewParameters", &GsCore::getViewParameters, DS.SARGS({ "vpNum : int", "view : PyGs.View" })).staticmethod("getViewParameters")

        .def("setViewParameters", &GsCore::setViewParameters1)
        .def("setViewParameters", &GsCore::setViewParameters2,
            DS.SARGS({ "vpNum : int", "view : PyGs.View", "bRegen: bool","bRescale: bool","bSync: bool=False" })).staticmethod("setViewParameters")

        .def("getBlockImage", &GsCore::getBlockImage,
            DS.SARGS({ "blkid: PyDb.ObjectId" , "sx: int", "sy: int","rgb: list[int]=None" }), arg("rgb") = boost::python::object()).staticmethod("getBlockImage")
        ;
}

PyGsView GsCore::getCurrentAcGsView(int vpNum)
{
    return PyGsView(acgsGetCurrentAcGsView(vpNum), false);
}

PyGsView GsCore::getCurrent3DAcGsView(int vpNum)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyGsView(acgsGetCurrent3dAcGsView(vpNum), false);
#endif
}

bool GsCore::getViewParameters(int vpNum, PyGsView& view)
{
    return acgsGetViewParameters(vpNum, view.impObj());
}

bool GsCore::setViewParameters1(int viewportNumber, const PyGsView& obj, bool bRegenRequired, bool bRescaleRequired)
{
    return acgsSetViewParameters(viewportNumber, obj.impObj(), bRegenRequired, bRescaleRequired);
}

bool GsCore::setViewParameters2(int viewportNumber, const PyGsView& obj, bool bRegenRequired, bool bRescaleRequired, bool bSyncRequired)
{
    return acgsSetViewParameters(viewportNumber, obj.impObj(), bRegenRequired, bRescaleRequired, bSyncRequired);
}

static int cvport()
{
    struct resbuf rb;
    acedGetVar(_T("CVPORT"), &rb);
    return rb.resval.rint;
}

PyObject* GsCore::getBlockImage(const PyDbObjectId& blkid, int width, int height, boost::python::object& rgb)
{
#if defined(_ZRXTARGET)
    PyThrowBadEs(Acad::eNotImplementedYet);
    return nullptr;
#endif
#if defined(_GRXTARGET)
    PyThrowBadEs(Acad::eNotImplementedYet);
    return nullptr;
#endif

    PyAutoLockGIL lock;
    AcGsManager* gsManager = acgsGetGsManager();

    AcGsKernelDescriptor descriptor;
    descriptor.addRequirement(AcGsKernelDescriptor::k3DDrawing);
    AcGsGraphicsKernel* pGraphicsKernel = AcGsManager::acquireGraphicsKernel(descriptor);
    if (pGraphicsKernel == nullptr)
        return nullptr;

    AcGsDevicePtr pOffDevice(gsManager->createAutoCADOffScreenDevice(*pGraphicsKernel));
    AcGsModelPtr pModel(gsManager->createAutoCADModel(*pGraphicsKernel));
    AcGsViewPtr pView(gsManager->createView(pOffDevice.get()));
    pOffDevice->onSize(width, height);
    if (!pOffDevice->add(pView.get()))
        return nullptr;

    if (bool flag = acgsGetViewParameters(cvport(), pView.get()); flag == false)
        acutPrintf(_T("\nFailed to copy view parameters: "));

    AcDbBlockTableRecordPointer pBlock(blkid.m_id);
    if (!pView->add(pBlock, pModel.get()))
        return nullptr;

#if defined(_ARXTARGET)
    auto v = pView->upVector();
    pView->setView(pView->position(), pView->target(), v.negate(), pView->fieldWidth(), pView->fieldHeight());
#else
    pView->setView(pView->position(), pView->target(), pView->upVector(), pView->fieldWidth(), pView->fieldHeight());
#endif

    AcDbExtents ex;
    ex.addBlockExt(pBlock);
    pView->zoomExtents(ex.minPoint(), ex.maxPoint());

    if (!rgb.is_none())
    {
        auto _rgb = PyListToInt32Array(rgb);
        if (_rgb.length() == 3)
        {
            AcGsColor bkclr;
            bkclr.m_blue = _rgb[0];
            bkclr.m_green = _rgb[1];
            bkclr.m_red = _rgb[2];
            pOffDevice->setBackgroundColor(bkclr);
        }
    }

    //do all view settings before here;
    pOffDevice->update();
    pView->update();

    Atil::RgbModel rgbModel(32);
    Atil::ImagePixel initialColor(rgbModel.pixelType());
    Atil::Image image(Atil::Size(width, height), &rgbModel, initialColor);
    pView->getSnapShot(&image, AcGsDCPoint(0, 0));
    if (!image.isValid())
        return nullptr;

    Atil::Offset upperLeft(0, 0);
    Atil::Size wholeImage = image.size();
    Atil::ImageContext* imgContext = image.createContext(Atil::ImageContext::kWrite, wholeImage, upperLeft);
    Atil::DataModelAttributes::PixelType pixelType = imgContext->getPixelType();
    if (pixelType != Atil::DataModelAttributes::kRgba)
        return nullptr;

    //I know, I'll work on this later
    wxImage* pWxImage = new wxImage(wxSize(wholeImage.width, wholeImage.height));
    for (int x = 0; x < wholeImage.width; ++x)
    {
        for (int y = 0; y < wholeImage.height; ++y)
        {
            Atil::RgbColor pix(imgContext->get32(x, y));
            const auto& rgba = pix.rgba;
            pWxImage->SetRGB(x, y, rgba.red, rgba.green, rgba.blue);
        }
    }
    if (!pWxImage->IsOk())
        return nullptr;

#if defined(_ARXTARGET)
    *pWxImage = pWxImage->Mirror();
#endif // _ARXTARGET

    pView->eraseAll();

    PyObject* _wxobj = wxPyConstructObject(pWxImage, wxT("wxImage"), true);
    if (_wxobj == nullptr)
        throw PyNullObject();
    return _wxobj;
}
