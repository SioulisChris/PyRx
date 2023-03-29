#include "stdafx.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//---------------------------------------------------------------------------------------------------
// makeAcDbDatabaseWrapper
void makeAcDbDatabaseWrapper()
{
    static auto wrapper = class_<PyDbDatabase, bases<PyRxObject>>("DbDatabase")
        .def(init<>())
        //.def("abortDeepClone", &PyDbDatabase::dummy)
        //.def("addAcDbObject", &PyDbDatabase::dummy)
        //.def("addReactor", &PyDbDatabase::dummy)
        .def("angbase", &PyDbDatabase::angbase)
        .def("angdir", &PyDbDatabase::angdir)
        .def("annoAllVisible", &PyDbDatabase::annoAllVisible)
        .def("annotativeDwg", &PyDbDatabase::annotativeDwg)
        //.def("applyPartialOpenFilters", &PyDbDatabase::dummy)
        .def("approxNumObjects", &PyDbDatabase::approxNumObjects)
        .def("attmode", &PyDbDatabase::attmode)
        .def("aunits", &PyDbDatabase::aunits)
        .def("auprec", &PyDbDatabase::auprec)
        .def("blipmode", &PyDbDatabase::blipmode)
        .def("byBlockLinetype", &PyDbDatabase::byBlockLinetype)

        .def("className", &PyDbDatabase::className)
        .def("create", &PyDbDatabase::create)
        .def("getFilename", &PyDbDatabase::getFilename)
        .def("readDwgFile", &PyDbDatabase::readDwgFile)
        .def("blockTableId", &PyDbDatabase::blockTableId)
        .def("modelspaceId", &PyDbDatabase::modelspaceId)
        ;
}

//---------------------------------------------------------------------------------------------------
// PyDbDatabase
PyDbDatabase::PyDbDatabase()
    :PyRxObject(acdbHostApplicationServices()->workingDatabase(), false)
{
}

PyDbDatabase::PyDbDatabase(AcDbDatabase* _pDb)
    : PyRxObject(_pDb, false)
{
}

PyDbDatabase::~PyDbDatabase()
{
}

double PyDbDatabase::angbase() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->angbase();
    throw PyNullObject();
}

bool PyDbDatabase::angdir() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->angdir();
    throw PyNullObject();
}

bool PyDbDatabase::annoAllVisible() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->annoAllVisible();
    throw PyNullObject();
}

bool PyDbDatabase::annotativeDwg() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->annotativeDwg();
    throw PyNullObject();
}

int PyDbDatabase::approxNumObjects() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->approxNumObjects();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::attmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->attmode();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::aunits() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->aunits();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::auprec() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->auprec();
    throw PyNullObject();
}

bool PyDbDatabase::blipmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->blipmode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byBlockLinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byBlockLinetype());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byBlockMaterial() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byBlockMaterial());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byLayerLinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byLayerLinetype());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byLayerMaterial() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byLayerMaterial());
    throw PyNullObject();
}

bool PyDbDatabase::cameraDisplay() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->cameraDisplay();
    throw PyNullObject();
#endif
}

double PyDbDatabase::cameraHeight() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->cameraHeight();
    throw PyNullObject();
#endif
}

Adesk::Int16 PyDbDatabase::cDynDisplayMode() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->cDynDisplayMode();
    throw PyNullObject();
#endif // BRXAPP
}

double PyDbDatabase::celtscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->celtscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::celtype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->celtype());
    throw PyNullObject();
}

AcDb::LineWeight PyDbDatabase::celweight() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->celweight();
    throw PyNullObject();
}

double PyDbDatabase::chamfera() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamfera();
    throw PyNullObject();
}

double PyDbDatabase::chamferb() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamferb();
    throw PyNullObject();
}

double PyDbDatabase::chamferc() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamferc();
    throw PyNullObject();
}

double PyDbDatabase::chamferd() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamferd();
    throw PyNullObject();
}

std::string PyDbDatabase::classDxfName(const PyRxClass& pClass)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->classDxfName(pClass.impObj()));
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::clayer() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->clayer());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::closeInput(bool bCloseFile)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->closeInput(bCloseFile);
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::cmaterial() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->cmaterial());
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::cmljust() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->cmljust();
    throw PyNullObject();
}

double PyDbDatabase::cmlscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->cmlscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::cmlstyleID() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->cmlstyleID());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::colorDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->colorDictionaryId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::continuousLinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->continuousLinetype());
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::coords() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->coords();
    throw PyNullObject();
}

Adesk::UInt32 PyDbDatabase::countEmptyObjects(const Adesk::UInt32 flags)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->countEmptyObjects(flags);
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::detailViewStyle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->detailViewStyle());
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::detailViewStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->detailViewStyleDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::dimaso() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimaso();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::dimAssoc() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimAssoc();
    throw PyNullObject();
}

int PyDbDatabase::dimfit() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimfit();
    throw PyNullObject();
}

bool PyDbDatabase::dimsho() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimsho();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimstyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimstyle());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimStyleTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimStyleTableId());
    throw PyNullObject();
}

int PyDbDatabase::dimunit() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimunit();
    throw PyNullObject();
}

void PyDbDatabase::disablePartialOpen()
{
    auto imp = impObj();
    if (imp != nullptr)
        impObj()->disablePartialOpen();
    throw PyNullObject();
}

void PyDbDatabase::disableUndoRecording(bool disable)
{
    auto imp = impObj();
    if (imp != nullptr)
        impObj()->disableUndoRecording(disable);
    throw PyNullObject();
}

bool PyDbDatabase::dispSilh() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dispSilh();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::dragmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dragmode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dragVisStyle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dragVisStyle());
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::drawOrderCtl() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->drawOrderCtl();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::dwfframe() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dwfframe();
    throw PyNullObject();
}

bool PyDbDatabase::dwgFileWasSavedByAutodeskSoftware() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dwgFileWasSavedByAutodeskSoftware();
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::dxfIn(const std::string& dxfFilename)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dxfIn(utf8_to_wstr(dxfFilename).c_str());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::dxfOut(const std::string& dxfFilename)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dxfOut(utf8_to_wstr(dxfFilename).c_str());
    throw PyNullObject();
}

double PyDbDatabase::elevation() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->elevation();
    throw PyNullObject();
}

Adesk::UInt32 PyDbDatabase::eraseEmptyObjects(const Adesk::UInt32 flags)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->eraseEmptyObjects(flags);
    throw PyNullObject();
#endif
}

AcGePoint3d PyDbDatabase::extmax() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->extmax();
    throw PyNullObject();
}

AcGePoint3d PyDbDatabase::extmin() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->extmin();
    throw PyNullObject();
}

double PyDbDatabase::facetres() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->facetres();
    throw PyNullObject();
}

double PyDbDatabase::filletrad() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->filletrad();
    throw PyNullObject();
}

bool PyDbDatabase::fillmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->fillmode();
    throw PyNullObject();
}

void PyDbDatabase::forceWblockDatabaseCopy()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        impObj()->forceWblockDatabaseCopy();
    throw PyNullObject();
#endif
}

std::string PyDbDatabase::geoCoordinateSystemId() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(impObj()->geoCoordinateSystemId());
    throw PyNullObject();
#endif
}

bool PyDbDatabase::geoMarkerVisibility() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->geoMarkerVisibility();
    throw PyNullObject();
#endif
}

double PyDbDatabase::get3dDwfPrec() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->get3dDwfPrec();
    throw PyNullObject();
#endif
}

AcDb::PlotStyleNameType PyDbDatabase::getCePlotStyleNameId(PyDbObjectId& id) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->getCePlotStyleNameId(id.m_id);
    throw PyNullObject();
}

bool PyDbDatabase::isAppRegistered(const std::string& pszAppName) const
{
#ifdef ARX2023
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->isAppRegistered(utf8_to_wstr(pszAppName).c_str());
    throw PyNullObject();
#else
    throw PyNotimplementedByHost();
#endif // 
}

std::string PyDbDatabase::dimapost() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(impObj()->dimapost());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimblk() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimblk());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimblk1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimblk1());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimblk2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimblk2());
    throw PyNullObject();
}

std::string PyDbDatabase::dimpost() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(impObj()->dimpost());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::getDimstyleParentId(PyDbObjectId& childStyle) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->getDimstyleParentId(childStyle.m_id));
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::groupDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->groupDictionaryId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::insert(PyDbObjectId& blockId, const std::string& pBlockName, PyDbDatabase& db, bool preserveSourceDatabase /*= true*/)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insert(blockId.m_id, utf8_to_wstr(pBlockName).c_str(), db.impObj(), preserveSourceDatabase);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::insert(PyDbObjectId& blockId, const std::string& pSourceBlockName, const std::string& pDestinationBlockName, PyDbDatabase& db, bool preserveSourceDatabase /*= true*/)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insert(blockId.m_id, utf8_to_wstr(pSourceBlockName).c_str(), utf8_to_wstr(pDestinationBlockName).c_str(), db.impObj(), preserveSourceDatabase);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::insert(const AcGeMatrix3d& xform, PyDbDatabase& db, bool preserveSourceDatabase /*= true*/)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insert(xform, db.impObj(), preserveSourceDatabase);
    throw PyNullObject();
}

AcDb::UnitsValue PyDbDatabase::insunits() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insunits();
    throw PyNullObject();
}

bool PyDbDatabase::isBeingDestroyed() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isBeingDestroyed();
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::layerTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->layerTableId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::layerZero() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->layerZero());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::layoutDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->layoutDictionaryId());
    throw PyNullObject();
}

double PyDbDatabase::lensLength() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lensLength();
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::linetypeTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->linetypeTableId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::registerApp(const std::string& pszAppName)
{
#ifdef ARX2023
    auto imp = impObj();
    if (imp != nullptr)
        return imp->registerApp(utf8_to_wstr(pszAppName).c_str());
#else
    throw PyNotimplementedByHost();
#endif
}

PyDbObjectId PyDbDatabase::materialDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->materialDictionaryId());
    throw PyNullObject();
}

AcDb::MeasurementValue PyDbDatabase::measurement() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->measurement();
    throw PyNullObject();
}

bool PyDbDatabase::mirrtext() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->mirrtext();
    throw PyNullObject();
}

double PyDbDatabase::mleaderscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->mleaderscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::mleaderstyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->mleaderstyle());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::mleaderStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->mleaderStyleDictionaryId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::mLStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->mLStyleDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::msltscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->msltscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::namedObjectsDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->namedObjectsDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::needsRecovery() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->needsRecovery();
    throw PyNullObject();
#endif
}

double PyDbDatabase::northDirection() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->northDirection();
    throw PyNullObject();
}

Adesk::Int32 PyDbDatabase::numberOfSaves() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->numberOfSaves();
    throw PyNullObject();
}

bool PyDbDatabase::orthomode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->orthomode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::paperSpaceVportId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->paperSpaceVportId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::plotSettingsDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->plotSettingsDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::plotStyleMode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->plotStyleMode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::plotStyleNameDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->plotStyleNameDictionaryId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::regAppTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->regAppTableId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::restoreOriginalXrefSymbols()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->restoreOriginalXrefSymbols();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::saveAs(const std::string& fileName)
{
    auto imp = impObj();
    if (imp != nullptr)
       return imp->saveAs(utf8_to_wstr(fileName).c_str());
    throw PyNullObject();
}

void PyDbDatabase::setFullSaveRequired()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        imp->setFullSaveRequired();
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::create(bool buildDefaultDrawing, bool noDocument)
{
    deleteNativeObject();
    m_bAutoDelete = true;
    m_pImp = new AcDbDatabase(buildDefaultDrawing, noDocument);
    return eOk;
}

Acad::ErrorStatus PyDbDatabase::readDwgFile(const char* fileName)
{
    std::wstring wsfileName{ utf8_to_wstr(fileName) };
    auto imp = impObj();
    if (imp != nullptr)
        return imp->readDwgFile(wsfileName.c_str());
    return eNullPtr;
}

std::string PyDbDatabase::getFilename()
{
    auto imp = impObj();
    if (imp != nullptr)
    {
        const TCHAR* path = nullptr;
        if (imp->getFilename(path) == eOk && path != nullptr)
            return std::string{ wstr_to_utf8(path) };
    }
    return std::string{ };
}

PyDbObjectId PyDbDatabase::currentSpaceId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->currentSpaceId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::blockTableId() const
{
    return PyDbObjectId(impObj()->blockTableId());
}

PyDbObjectId PyDbDatabase::modelspaceId() const
{
    return PyDbObjectId(acdbSymUtil()->blockModelSpaceId(impObj()));
}

std::string PyDbDatabase::className()
{
    return "AcDbDatabase";
}

AcDbDatabase* PyDbDatabase::impObj() const
{
    return static_cast<AcDbDatabase*>(m_pImp);
}

