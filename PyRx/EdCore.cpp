#include "stdafx.h"
#include "EdCore.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "ResultBuffer.h"
#include "acedCmdNF.h"

#ifdef ARXAPP
#include "AcHTMLApi.h"
#endif

using namespace boost::python;

#ifdef ARXAPP
extern "C" bool acedGetPredefinedPattens(AcStringArray & patterns);
extern "C" Acad::ErrorStatus acedSetUndoMark(bool);
extern "C" void acedGetCommandPromptString(CString&);
#endif

//-----------------------------------------------------------------------------------------
//helpers

//-----------------------------------------------------------------------------------------
//EdCore
void makePyEdCoreWrapper()
{
    class_<EdCore>("Core")
        .def("alert", &EdCore::alert).staticmethod("alert")
        .def("arxLoad", &EdCore::arxLoad).staticmethod("arxLoad")
        .def("arxLoaded", &EdCore::arxLoaded).staticmethod("arxLoaded")
        .def("arxUnload", &EdCore::arxUnload).staticmethod("arxUnload")
        .def("audit", &EdCore::audit1)//.staticmethod("audit")
        .def("audit", &EdCore::audit2).staticmethod("audit")
        .def("callBackOnCancel", &EdCore::callBackOnCancel).staticmethod("callBackOnCancel")
        .def("clearOLELock", &EdCore::clearOLELock).staticmethod("clearOLELock")
        .def("cmdS", &EdCore::cmdS).staticmethod("cmdS")
        .def("findFile", &EdCore::findFile).staticmethod("findFile")
        .def("findTrustedFile", &EdCore::findTrustedFile).staticmethod("findTrustedFile")
        .def("getPredefinedHatchPatterns", &EdCore::getPredefinedPattens).staticmethod("getPredefinedHatchPatterns")
        .def("getFileD", &EdCore::getFileD).staticmethod("getFileD")
        .def("getFileNavDialog", &EdCore::getFileNavDialog).staticmethod("getFileNavDialog")
        .def("grDraw", &EdCore::grDraw).staticmethod("grDraw")
        .def("getCommandPromptString", &EdCore::getCommandPromptString).staticmethod("getCommandPromptString")
        .def("getVar", &EdCore::getVar).staticmethod("getVar")
        .def("setVar", &EdCore::setVar).staticmethod("setVar")
        .def("mSpace", &EdCore::mSpace).staticmethod("mSpace")
        .def("pSpace", &EdCore::pSpace).staticmethod("pSpace")
        .def("setUndoMark", &EdCore::setUndoMark).staticmethod("setUndoMark")
        .def("showHTMLModalWindow", &EdCore::showHTMLModalWindow1)
        .def("showHTMLModalWindow", &EdCore::showHTMLModalWindow2).staticmethod("showHTMLModalWindow")
        .def("update", &EdCore::update).staticmethod("update")
        .def("updateDisplay", &EdCore::updateDisplay).staticmethod("updateDisplay")
        .def("updateDisplayPause", &EdCore::updateDisplayPause).staticmethod("updateDisplayPause")
        .def("usrBrk", &EdCore::usrBrk).staticmethod("usrBrk")
        .def("viewportIdFromNumber", &EdCore::viewportIdFromNumber).staticmethod("viewportIdFromNumber")
        .def("vpLayer", &EdCore::vpLayer).staticmethod("vpLayer")
        .def("vports", &EdCore::vports).staticmethod("vports")
        .def("vports2VportTableRecords", &EdCore::vports2VportTableRecords).staticmethod("vports2VportTableRecords")
        .def("vportTableRecords2Vports", &EdCore::vportTableRecords2Vports).staticmethod("vportTableRecords2Vports")
        .def("xrefAttach", &EdCore::xrefAttach1)
        .def("xrefAttach", &EdCore::xrefAttach2).staticmethod("xrefAttach")
        .def("xrefCreateBlockname", &EdCore::xrefCreateBlockname).staticmethod("xrefCreateBlockname")
        .def("xrefDetach", &EdCore::xrefDetach1)
        .def("xrefDetach", &EdCore::xrefDetach2).staticmethod("xrefDetach")
        .def("xrefNotifyCheckFileChanged", &EdCore::xrefNotifyCheckFileChanged).staticmethod("xrefNotifyCheckFileChanged")
        .def("xrefOverlay", &EdCore::xrefOverlay1)
        .def("xrefOverlay", &EdCore::xrefOverlay2).staticmethod("xrefOverlay")
        .def("xrefReload", &EdCore::xrefReload1)
        .def("xrefReload", &EdCore::xrefReload2)
        .def("xrefReload", &EdCore::xrefReload3)
        .def("xrefReload", &EdCore::xrefReload4).staticmethod("xrefReload")
        .def("xrefResolve", &EdCore::xrefResolve1)
        .def("xrefResolve", &EdCore::xrefResolve2).staticmethod("xrefResolve")
        .def("xrefUnload", &EdCore::xrefUnload1)
        .def("xrefUnload", &EdCore::xrefUnload2).staticmethod("xrefUnload")
        .def("xrefBind", &EdCore::xrefBind1)
        .def("xrefBind", &EdCore::xrefBind2).staticmethod("xrefBind")
        .def("xrefXBind", &EdCore::xrefXBind1)
        .def("xrefXBind", &EdCore::xrefXBind2).staticmethod("xrefXBind")
        ;
}

int EdCore::alert(const std::string& msg)
{
    return acedAlert(utf8_to_wstr(msg).c_str());
}

int EdCore::arxLoad(const std::string& msg)
{
    return acedArxLoad(utf8_to_wstr(msg).c_str());
}

boost::python::list EdCore::arxLoaded()
{
    PyAutoLockGIL lock;
    AcResBufPtr pLoaded(acedArxLoaded());
    return resbufToList(pLoaded.get());
}

int EdCore::arxUnload(const std::string& app)
{
    return acedArxUnload(utf8_to_wstr(app).c_str());
}

void EdCore::audit1(PyDbDatabase& pDb, bool bFixErrors)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(acedAudit(pDb.impObj(), bFixErrors));
#endif
}

void EdCore::audit2(PyDbDatabase& pDb, bool bFixErrors, bool bCmdLnEcho)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(acedAudit(pDb.impObj(), bFixErrors, bCmdLnEcho));
#endif
}

void EdCore::callBackOnCancel()
{
    acedCallBackOnCancel();
}

bool EdCore::clearOLELock(int handle)
{
    return acedClearOLELock(handle);
}

bool EdCore::cmdS(const boost::python::list& lst)
{
    AcResBufPtr pcmd(listToResbuf(lst));
    return acedCmdS(pcmd.get()) == RTNORM;
}

std::string EdCore::findFile(const std::string& file)
{
    std::array<wchar_t, MAX_PATH> data;
    acedFindFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.data());
}

std::string EdCore::findTrustedFile(const std::string& file)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    std::array<wchar_t, MAX_PATH> data;
    acedFindTrustedFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.data());
#endif
}

boost::python::list EdCore::getPredefinedPattens()
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcStringArray patterns;
    boost::python::list py_patterns;
    if (acedGetPredefinedPattens(patterns) == true)
    {
        for (auto& pattern : patterns)
            py_patterns.append(wstr_to_utf8(pattern));
    }
    return py_patterns;
#endif
}

std::string EdCore::getFileD(const std::string& title, const std::string& defawlt, const std::string& ext, int flags)
{
    std::string path;
    AcResBufPtr result(acutNewRb(RTSTR));
    if (acedGetFileD(utf8_to_wstr(title).c_str(), utf8_to_wstr(defawlt).c_str(), utf8_to_wstr(ext).c_str(), flags, result.get()) == RTNORM)
        path = wstr_to_utf8(result->resval.rstring);
    return path;
}

boost::python::list EdCore::getFileNavDialog(const std::string& title, const std::string& defawlt, const std::string& ext, const std::string& dlgname, int flags)
{
    PyAutoLockGIL lock;
    resbuf* result = nullptr;
    boost::python::list pyList;
    if (acedGetFileNavDialog(utf8_to_wstr(title).c_str(), utf8_to_wstr(defawlt).c_str(), utf8_to_wstr(ext).c_str(), utf8_to_wstr(dlgname).c_str(), flags, &result) == RTNORM)
    {
        AcResBufPtr resultptr(result);
        for (resbuf* pbuf = result; pbuf != nullptr; pbuf = pbuf->rbnext)
        {
            if (pbuf->restype == RTSTR)
                pyList.append(wstr_to_utf8(pbuf->resval.rstring));
        }
    }
    return pyList;
}

std::string EdCore::getCommandPromptString()
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    CString str;
    acedGetCommandPromptString(str);
    return wstr_to_utf8(str);
#endif
}

boost::python::object EdCore::getVar(const std::string& sym)
{
    PyAutoLockGIL lock;
    try
    {
        resbuf buf;
        if (acedGetVar(utf8_to_wstr(sym).c_str(), &buf) != RTNORM)
        {
            return boost::python::make_tuple(false, boost::python::object());
        }
        switch (buf.restype)
        {
            case RTSHORT:
            {
                return boost::python::object(buf.resval.rint);
            }
            case RTLONG:
            {
                return boost::python::object(buf.resval.rlong);
            }
            case RTREAL:
            {
                return boost::python::object(buf.resval.rreal);
            }
            case RTSTR:
            {
                std::string val = wstr_to_utf8(buf.resval.rstring);
                acutDelString(buf.resval.rstring);
                return boost::python::object(val);
            }
            case RTPOINT:
            {
                AcGePoint2d pnt = asPnt2d(buf.resval.rpoint);
                return boost::python::object(pnt);
            }
            case RT3DPOINT:
            {
                AcGePoint3d pnt = asPnt3d(buf.resval.rpoint);
                return boost::python::object(pnt);
            }
            default:
            {
                return boost::python::object();
            }
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nExeption @ %ls"), __FUNCTIONW__);
    }
    return boost::python::object();
}

bool EdCore::setVar(const std::string& sym, const boost::python::object& src)
{
    PyAutoLockGIL lock;
    try
    {
        if (extract<double>(src).check())
        {
            const double val = extract<double>(src);
            AcResBufPtr buf(acutBuildList(RTREAL, val, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
        else if (extract<int>(src).check())
        {
            const int val = extract<int>(src);
            AcResBufPtr buf(acutBuildList(RTLONG, val, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
        else if (extract<AcGePoint2d>(src).check())
        {
            const auto val = asDblArray(extract<AcGePoint2d>(src));
            AcResBufPtr buf(acutBuildList(RTPOINT, val, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
        else if (extract<AcGePoint3d>(src).check())
        {
            const auto val = asDblArray(extract<AcGePoint3d>(src));
            AcResBufPtr buf(acutBuildList(RT3DPOINT, val, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
        else if (extract<char*>(src).check())
        {
            const AcString str = utf8_to_wstr(extract<char*>(src)).c_str();
            AcResBufPtr buf(acutBuildList(RTSTR, (const TCHAR*)str, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nExeption @ %ls"), __FUNCTIONW__);
    }
    return false;
}

void EdCore::mSpace()
{
    return PyThrowBadEs(acedMspace());
}

void EdCore::pSpace()
{
    return PyThrowBadEs(acedPspace());
}

int EdCore::grDraw(const AcGePoint3d& from, const AcGePoint3d& to, int colorIndex, int highlight)
{
    return acedGrDraw(asDblArray(from), asDblArray(to), colorIndex, highlight);
}

void EdCore::setUndoMark(bool flag)
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(acedSetUndoMark(flag));
#endif
}

bool EdCore::showHTMLModalWindow1(UINT_PTR hwnd, const std::string& uriOfHtmlPage)
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    return showHTMLModalWindow2(hwnd, uriOfHtmlPage, true);
#endif
}

bool EdCore::showHTMLModalWindow2(UINT_PTR hwnd, const std::string& uriOfHtmlPage, bool persistSizeAndPosition)
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    return acedShowHTMLModalWindow((HWND)hwnd, utf8_to_wstr(uriOfHtmlPage).c_str(), persistSizeAndPosition);
#endif
}

int EdCore::update(int vport, const AcGePoint2d& p1, const AcGePoint2d& p2)
{
    return acedUpdate(vport, asDblArray(p1), asDblArray(p2));
}

void EdCore::updateDisplay()
{
    acedUpdateDisplay();
}

void EdCore::updateDisplayPause(bool bEnable)
{
    acedUpdateDisplayPause(bEnable);
}

bool EdCore::usrBrk()
{
    return acedUsrBrk() == 1;
}

PyDbObjectId EdCore::viewportIdFromNumber(int val)
{
    return PyDbObjectId(acedViewportIdFromNumber(val));
}

void EdCore::vpLayer(const PyDbObjectId& vpId, const boost::python::list& layerIds, AcDb::VpFreezeOps operation)
{
    return PyThrowBadEs(acedVPLayer(vpId.m_id, PyListToObjectIdArray(layerIds), operation));
}

boost::python::list EdCore::vports()
{
    resbuf* buf = nullptr;
    if (auto es = acedVports(&buf); es != RTNORM)
        throw PyAcadErrorStatus(eOutOfMemory);
    AcResBufPtr autodel(buf);
    return resbufToList(buf);
}

void EdCore::vports2VportTableRecords()
{
    return PyThrowBadEs(acedVports2VportTableRecords());
}

void EdCore::vportTableRecords2Vports()
{
    return PyThrowBadEs(acedVportTableRecords2Vports());
}

void EdCore::xrefAttach1(const std::string& path, const std::string& name)
{
    return PyThrowBadEs(acedXrefAttach(utf8_to_wstr(path).c_str(), utf8_to_wstr(name).c_str()));
}

void EdCore::xrefAttach2(const std::string& path, const std::string& name, PyDbObjectId& btrid, PyDbObjectId& refid,
    AcGePoint3d& pt, AcGeScale3d& sc, double rot, bool bQuiet, PyDbDatabase& pHostDb, const std::string& passwd)
{
    return PyThrowBadEs(acedXrefAttach(
        utf8_to_wstr(path).c_str(),
        utf8_to_wstr(name).c_str(),
        &btrid.m_id,
        &refid.m_id,
        &pt,
        &sc,
        &rot,
        bQuiet,
        pHostDb.impObj(),
        utf8_to_wstr(passwd).c_str()));
}

std::string EdCore::xrefCreateBlockname(const std::string& XrefPathname)
{
    std::string result;
    ACHAR* XrefBlockname = nullptr;
    if (auto es = acedXrefCreateBlockname(utf8_to_wstr(XrefPathname).c_str(), XrefBlockname); es != eOk)
        throw PyAcadErrorStatus(es);
    result = wstr_to_utf8(XrefBlockname);
    acutDelString(XrefBlockname);
    return result;
}

void EdCore::xrefDetach1(const std::string& XrefBlockname)
{
    return PyThrowBadEs(acedXrefDetach(utf8_to_wstr(XrefBlockname).c_str()));
}

void EdCore::xrefDetach2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& pHostDb)
{
    return PyThrowBadEs(acedXrefDetach(utf8_to_wstr(XrefBlockname).c_str(), bQuiet, pHostDb.impObj()));
}

bool EdCore::xrefNotifyCheckFileChanged(const PyDbObjectId& id)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    bool flag = false;
    if (auto es = acedXrefNotifyCheckFileChanged(id.m_id, flag); es != eOk)
        throw PyAcadErrorStatus(es);
    return flag;
#endif
}

void EdCore::xrefOverlay1(const std::string& path, const std::string& name)
{
   return PyThrowBadEs(acedXrefOverlay(utf8_to_wstr(path).c_str(), utf8_to_wstr(name).c_str()));
}

void EdCore::xrefOverlay2(const std::string& path, const std::string& name, PyDbObjectId& btrid, PyDbObjectId& refid, 
    AcGePoint3d& pt, AcGeScale3d& sc, double rot, bool bQuiet, PyDbDatabase& pHostDb, const std::string& passwd)
{
    return PyThrowBadEs(acedXrefOverlay(
        utf8_to_wstr(path).c_str(),
        utf8_to_wstr(name).c_str(),
        &btrid.m_id,
        &refid.m_id,
        &pt,
        &sc,
        &rot,
        bQuiet,
        pHostDb.impObj(),
        utf8_to_wstr(passwd).c_str()));
}

void EdCore::xrefReload1(const boost::python::list& symbolIds)
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return PyThrowBadEs(acedXrefReload(ids));
}

void EdCore::xrefReload2(const boost::python::list& symbolIds, bool bQuiet, PyDbDatabase& pHostDb)
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return PyThrowBadEs(acedXrefReload(ids, bQuiet, pHostDb.impObj()));
}

void EdCore::xrefReload3(const std::string& name)
{
    return PyThrowBadEs(acedXrefReload(utf8_to_wstr(name).c_str()));
}

void EdCore::xrefReload4(const std::string& name, bool bQuiet, PyDbDatabase& pHostDb)
{
    return PyThrowBadEs(acedXrefReload(utf8_to_wstr(name).c_str(), bQuiet, pHostDb.impObj()));
}

void EdCore::xrefResolve1(PyDbDatabase& pHostDb)
{
    return PyThrowBadEs(acedXrefResolve(pHostDb.impObj()));
}

void EdCore::xrefResolve2(PyDbDatabase& pHostDb, bool bQuiet)
{
    return PyThrowBadEs(acedXrefResolve(pHostDb.impObj(), bQuiet));
}

void EdCore::xrefUnload1(const std::string& XrefBlockname)
{
    return PyThrowBadEs(acedXrefUnload(utf8_to_wstr(XrefBlockname).c_str()));
}

void EdCore::xrefUnload2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& pHostDb)
{
    return PyThrowBadEs(acedXrefUnload(utf8_to_wstr(XrefBlockname).c_str(), bQuiet, pHostDb.impObj()));
}

void EdCore::xrefBind1(const std::string& XrefBlockname)
{
    return PyThrowBadEs(acedXrefBind(utf8_to_wstr(XrefBlockname).c_str()));
}

void EdCore::xrefBind2(const std::string& XrefBlockname, bool bInsertBind, bool bQuiet, PyDbDatabase& pHostDb)
{
    return PyThrowBadEs(acedXrefBind(utf8_to_wstr(XrefBlockname).c_str(), bInsertBind, bQuiet, pHostDb.impObj()));
}

void EdCore::xrefXBind1(const boost::python::list& symbolIds)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return PyThrowBadEs(acedXrefXBind(ids));
#endif
}

void EdCore::xrefXBind2(const boost::python::list& symbolIds, bool bQuiet, PyDbDatabase& pHostDb)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return PyThrowBadEs(acedXrefXBind(ids, bQuiet, pHostDb.impObj()));
#endif
}
