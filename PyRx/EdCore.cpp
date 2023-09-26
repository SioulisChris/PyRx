#include "stdafx.h"
#include "EdCore.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "ResultBuffer.h"
#include "acedCmdNF.h"
#include "PyDbMText.h"
#include "PyApDocument.h"
#include "PyDbViewport.h"
#include "PyDbSymbolTableRecord.h"
#include "rxvar.h"

#ifdef ARXAPP
#include "AcHTMLApi.h"
#endif

using namespace boost::python;


#ifdef ARXAPP

EXTERN_C void                   acedLoadJSScript(const ACHAR* pUriOfJSFile);
EXTERN_C bool                   acedGetPredefinedPattens(AcStringArray& patterns);
EXTERN_C Acad::ErrorStatus      acedSetUndoMark(bool);
EXTERN_C void                   acedGetCommandPromptString(CString&);
EXTERN_C void                   acedDropOpenFile(const ACHAR*);
extern void                     acedGetLastCommandLines(AcStringArray&, int, bool);
extern Adesk::Boolean           acedPostCommand(const ACHAR*);
#endif

//-----------------------------------------------------------------------------------------
//Util
void makePyUtilWrapper()
{
    PyDocString DS("Util");
    class_<Util>("Util")
        .def("angle", &Util::angle)
        .def("cvUnit", &Util::cvUnit)
        .def("distance", &Util::distance)
        .def("polar", &Util::polar)
        .def("wcMatch", &Util::wcMatch)
        ;
}


double Util::angle(const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
    return acutAngle(asDblArray(pt1), asDblArray(pt1));
}

double Util::cvUnit(double val, const std::string& oldunit, const std::string& newunit)
{
    double result = 0;
    PyThrowBadRt(acutCvUnit(val, utf8_to_wstr(oldunit).c_str(), utf8_to_wstr(newunit).c_str(), &result));
    return result;
}

double Util::distance(const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
    return acutDistance(asDblArray(pt1), asDblArray(pt1));
}

AcGePoint3d Util::polar(const AcGePoint3d& pt, double angle, double dist)
{
    AcGePoint3d result;
    acutPolar(asDblArray(pt), angle, dist, asDblArray(result));
    return result;
}

bool Util::wcMatch(const std::string& string, const std::string& pattern, bool ignoreCase)
{
    return acutWcMatchEx(utf8_to_wstr(string).c_str(), utf8_to_wstr(pattern).c_str(), ignoreCase);
}


//-----------------------------------------------------------------------------------------
//EdCore
void makePyEdCoreWrapper()
{
    PyDocString DS("Core");
    class_<EdCore>("Core")
        .def("alert", &EdCore::alert).staticmethod("alert")
        .def("arxLoad", &EdCore::arxLoad).staticmethod("arxLoad")
        .def("arxLoaded", &EdCore::arxLoaded).staticmethod("arxLoaded")
        .def("arxUnload", &EdCore::arxUnload).staticmethod("arxUnload")
        .def("audit", &EdCore::audit1)//.staticmethod("audit")
        .def("audit", &EdCore::audit2).staticmethod("audit")
        .def("callBackOnCancel", &EdCore::callBackOnCancel).staticmethod("callBackOnCancel")
        .def("clearOLELock", &EdCore::clearOLELock).staticmethod("clearOLELock")
        .def("clipFormatName", &EdCore::clipFormatName).staticmethod("clipFormatName")
        .def("cmdCWasCancelled", &EdCore::cmdCWasCancelled).staticmethod("cmdCWasCancelled")
        .def("cmdUndefine", &EdCore::cmdUndefine).staticmethod("cmdUndefine")
        .def("getCommands", &EdCore::getCommands).staticmethod("getCommands")
        .def("coordFromPixelToWorld", &EdCore::coordFromPixelToWorld1)
        .def("coordFromPixelToWorld", &EdCore::coordFromPixelToWorld2).staticmethod("coordFromPixelToWorld")
        .def("coordFromWorldToPixel", &EdCore::coordFromWorldToPixel).staticmethod("coordFromWorldToPixel")
        .def("createInternetShortcut", &EdCore::createInternetShortcut).staticmethod("createInternetShortcut")
        .def("createViewportByView", &EdCore::createViewportByView).staticmethod("createViewportByView")
        .def("cmdS", &EdCore::cmdS).staticmethod("cmdS")
        .def("defun", &EdCore::defun).staticmethod("defun")
        .def("defunEx", &EdCore::defunEx).staticmethod("defunEx")
        .def("disableDefaultARXExceptionHandler", &EdCore::disableDefaultARXExceptionHandler).staticmethod("disableDefaultARXExceptionHandler")
        .def("disableUsrbrk", &EdCore::disableUsrbrk).staticmethod("disableUsrbrk")
        .def("displayBorder", &EdCore::displayBorder).staticmethod("displayBorder")
        .def("drawingStatusBarsVisible", &EdCore::drawingStatusBarsVisible).staticmethod("drawingStatusBarsVisible")
        .def("drawOrderInherit", &EdCore::drawOrderInherit).staticmethod("drawOrderInherit")
        .def("dropOpenFile", &EdCore::dropOpenFile).staticmethod("dropOpenFile")
        .def("eatCommandThroat", &EdCore::eatCommandThroat).staticmethod("eatCommandThroat")
        .def("editMTextInteractive", &EdCore::editMTextInteractive).staticmethod("editMTextInteractive")
        .def("enableUsrbrk", &EdCore::enableUsrbrk).staticmethod("enableUsrbrk")
        .def("findFile", &EdCore::findFile).staticmethod("findFile")
        .def("findTrustedFile", &EdCore::findTrustedFile).staticmethod("findTrustedFile")
        .def("getPredefinedHatchPatterns", &EdCore::getPredefinedPattens).staticmethod("getPredefinedHatchPatterns")
        .def("getFileD", &EdCore::getFileD).staticmethod("getFileD")
        .def("getFileNavDialog", &EdCore::getFileNavDialog).staticmethod("getFileNavDialog")
        .def("getAcadDockCmdLine", &EdCore::getAcadDockCmdLine).staticmethod("getAcadDockCmdLine")
        .def("getAcadTextCmdLine", &EdCore::getAcadTextCmdLine).staticmethod("getAcadTextCmdLine")
        .def("getCommandForDocument", &EdCore::getCommandForDocument).staticmethod("getCommandForDocument")
        .def("getCurrentSelectionSet", &EdCore::getCurrentSelectionSet).staticmethod("getCurrentSelectionSet")
        .def("getCurVportPixelToDisplay", &EdCore::getCurVportPixelToDisplay).staticmethod("getCurVportPixelToDisplay")
        .def("getCurVportScreenToDisplay", &EdCore::getCurVportScreenToDisplay).staticmethod("getCurVportScreenToDisplay")
        .def("getEnv", &EdCore::getEnv).staticmethod("getEnv")
        .def("setEnv", &EdCore::setEnv).staticmethod("setEnv")
        .def("getCfg", &EdCore::getCfg).staticmethod("getCfg")
        .def("setCfg", &EdCore::setCfg).staticmethod("setCfg")
        .def("getSym", &EdCore::getSym).staticmethod("getSym")
        .def("putSym", &EdCore::putSym).staticmethod("putSym")
        .def("getWinNum", &EdCore::getWinNum).staticmethod("getWinNum")
        .def("graphScr", &EdCore::graphScr).staticmethod("graphScr")
        .def("grDraw", &EdCore::grDraw).staticmethod("grDraw")
        .def("getCommandPromptString", &EdCore::getCommandPromptString).staticmethod("getCommandPromptString")
        .def("getLastCommandLines", &EdCore::getLastCommandLines).staticmethod("getLastCommandLines")
        .def("getBlockEditMode", &EdCore::getBlockEditMode).staticmethod("getBlockEditMode")
        .def("getVar", &EdCore::getVar).staticmethod("getVar")
        .def("setVar", &EdCore::setVar).staticmethod("setVar")
        .def("getSysVars", &EdCore::getSysVars).staticmethod("getSysVars")
        .def("getMousePositionUCS", &EdCore::getMousePositionUCS).staticmethod("getMousePositionUCS")
        .def("getMousePositionWCS", &EdCore::getMousePositionWCS).staticmethod("getMousePositionWCS")
        .def("invoke", &EdCore::invoke).staticmethod("invoke")
        .def("initDialog", &EdCore::initDialog).staticmethod("initDialog")
        .def("isDragging", &EdCore::isDragging).staticmethod("isDragging")
        .def("isInBackgroundMode", &EdCore::isInBackgroundMode).staticmethod("isInBackgroundMode")
        .def("isInputPending", &EdCore::isInputPending).staticmethod("isInputPending")
        .def("isMenuGroupLoaded", &EdCore::isMenuGroupLoaded).staticmethod("isMenuGroupLoaded")
        .def("isOsnapOverride", &EdCore::isOsnapOverride).staticmethod("isOsnapOverride")
        .def("isUpdateDisplayPaused", &EdCore::isUpdateDisplayPaused).staticmethod("isUpdateDisplayPaused")
        .def("isUsrbrkDisabled", &EdCore::isUsrbrkDisabled).staticmethod("isUsrbrkDisabled")
        .def("loadJSScript", &EdCore::loadJSScript).staticmethod("loadJSScript")
        .def("loadPartialMenu", &EdCore::loadPartialMenu).staticmethod("loadPartialMenu")
        .def("markForDelayXRefRelativePathResolve", &EdCore::markForDelayXRefRelativePathResolve).staticmethod("markForDelayXRefRelativePathResolve")
        .def("mSpace", &EdCore::mSpace).staticmethod("mSpace")
        .def("pSpace", &EdCore::pSpace).staticmethod("pSpace")
        .def("postCommand", &EdCore::postCommand).staticmethod("postCommand")
        .def("postCommandPrompt", &EdCore::postCommandPrompt).staticmethod("postCommandPrompt")
        .def("prompt", &EdCore::prompt).staticmethod("prompt")
        .def("osnap", &EdCore::osnap).staticmethod("osnap")
        .def("redraw", &EdCore::redraw).staticmethod("redraw")
        .def("reloadMenus", &EdCore::reloadMenus).staticmethod("reloadMenus")
        .def("restoreCurrentView", &EdCore::restoreCurrentView).staticmethod("restoreCurrentView")
        .def("restorePreviousUCS", &EdCore::restorePreviousUCS).staticmethod("restorePreviousUCS")
        .def("restoreStatusBar", &EdCore::restoreStatusBar).staticmethod("restoreStatusBar")
        .def("sendModelessOperationEnded", &EdCore::sendModelessOperationEnded).staticmethod("sendModelessOperationEnded")
        .def("sendModelessOperationStart", &EdCore::sendModelessOperationStart).staticmethod("sendModelessOperationStart")
        .def("setColorDialog", &EdCore::setColorDialog).staticmethod("setColorDialog")
        .def("setColorDialogTrueColor", &EdCore::setColorDialogTrueColor1)
        .def("setColorDialogTrueColor", &EdCore::setColorDialogTrueColor2).staticmethod("setColorDialogTrueColor")
        .def("setCurrentView", &EdCore::setCurrentView).staticmethod("setCurrentView")
        .def("setCurrentVPort", &EdCore::setCurrentVPort).staticmethod("setCurrentVPort")
        .def("setStatusBarProgressMeter", &EdCore::setStatusBarProgressMeter).staticmethod("setStatusBarProgressMeter")
        .def("setStatusBarProgressMeterPos", &EdCore::setStatusBarProgressMeterPos).staticmethod("setStatusBarProgressMeterPos")
        .def("setXrefResolvedWithUpdateStatus", &EdCore::setXrefResolvedWithUpdateStatus).staticmethod("setXrefResolvedWithUpdateStatus")
        .def("setUndoMark", &EdCore::setUndoMark).staticmethod("setUndoMark")
        .def("showHTMLModalWindow", &EdCore::showHTMLModalWindow1)
        .def("showHTMLModalWindow", &EdCore::showHTMLModalWindow2).staticmethod("showHTMLModalWindow")
        .def("showHTMLModelessWindow", &EdCore::showHTMLModelessWindow1)
        .def("showHTMLModelessWindow", &EdCore::showHTMLModelessWindow2).staticmethod("showHTMLModelessWindow")
        .def("skipXrefNotification", &EdCore::skipXrefNotification).staticmethod("skipXrefNotification")

        .def("trans", &EdCore::trans).staticmethod("trans")


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

ULONG_PTR EdCore::getAcadDockCmdLine()
{
    return reinterpret_cast<UINT_PTR>(acedGetAcadDockCmdLine()->GetSafeHwnd());
}

ULONG_PTR EdCore::getAcadTextCmdLine()
{
    return reinterpret_cast<UINT_PTR>(acedGetAcadTextCmdLine()->GetSafeHwnd());
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
    return PyThrowBadEs(acedAudit(pDb.impObj(), bFixErrors));
}

void EdCore::audit2(PyDbDatabase& pDb, bool bFixErrors, bool bCmdLnEcho)
{
    return PyThrowBadEs(acedAudit(pDb.impObj(), bFixErrors, bCmdLnEcho));
}

void EdCore::callBackOnCancel()
{
    acedCallBackOnCancel();
}

bool EdCore::clearOLELock(int handle)
{
    return acedClearOLELock(handle);
}

std::string EdCore::clipFormatName()
{
    return wstr_to_utf8(acedClipFormatName());
}

bool EdCore::cmdCWasCancelled()
{
    return acedCmdCWasCancelled();
}

int EdCore::cmdUndefine(const std::string& name, int undefIt)
{
    return acedCmdUndefine(utf8_to_wstr(name).c_str(), undefIt);
}

boost::python::dict EdCore::getCommands()
{
    PyAutoLockGIL lock; //lock when creating python types
    boost::python::dict Pydict;
    std::map<std::string, boost::python::list> pyMap;
    std::unique_ptr<AcEdCommandIterator>iter(acedRegCmds->iterator());
    if (iter == nullptr)
        return Pydict;

    for (; !iter->done(); iter->next())
    {
        const auto cmd = iter->command();
        pyMap[wstr_to_utf8(iter->commandGroup())].append(
            boost::python::make_tuple(wstr_to_utf8(cmd->globalName()),
                wstr_to_utf8(cmd->localName()), cmd->commandFlags()));
    }
    for (auto& item : pyMap)
    {
        Pydict[item.first] = item.second;
    }
    return Pydict;
}

bool EdCore::coordFromPixelToWorld1(const boost::python::list& tin, AcGePoint3d& pnt)
{
    PyAutoLockGIL lock;
    const size_t listSize = boost::python::len(tin);
    if (listSize != 2)
        return false;
    int x = extract<int>(tin[0]);
    int y = extract<int>(tin[1]);
    CPoint cpnt(x, y);
    acedCoordFromPixelToWorld(cpnt, asDblArray(pnt));
    return true;
}

bool EdCore::coordFromPixelToWorld2(int windnum, const boost::python::list& tin, AcGePoint3d& pnt)
{
    PyAutoLockGIL lock;
    const size_t listSize = boost::python::len(tin);
    if (listSize != 2)
        return false;
    int x = extract<int>(tin[0]);
    int y = extract<int>(tin[1]);
    CPoint cpnt(x, y);
    return acedCoordFromPixelToWorld(windnum, cpnt, asDblArray(pnt));
}

bool EdCore::coordFromWorldToPixel(int windnum, const AcGePoint3d& pnt, boost::python::list& tin)
{
    CPoint cpnt;
    if (!acedCoordFromWorldToPixel(windnum, asDblArray(pnt), cpnt))
        return false;
    PyAutoLockGIL lock;
    tin.append(cpnt.x);
    tin.append(cpnt.y);
    return true;
}

bool EdCore::createInternetShortcut(const std::string& szURL, const std::string& szShortcutPath)
{
    return acedCreateInternetShortcut(utf8_to_wstr(szURL).c_str(), utf8_to_wstr(szShortcutPath).c_str());
}

PyDbObjectId EdCore::createViewportByView(PyDbDatabase& db, PyDbObjectId& view, const AcGePoint2d& location, double scale)
{
    PyDbObjectId id;
    PyThrowBadEs(acedCreateViewportByView(db.impObj(), view.m_id, location, scale, id.m_id));
    return id;
}

int EdCore::defun(const std::string& pszName, int nFuncNum)
{
    return acedDefun(utf8_to_wstr(pszName).c_str(), nFuncNum);
}

int EdCore::defunEx(const std::string& pszGlobalName, const std::string& pszLocalName, int nFuncNum)
{
    return acedDefunEx(utf8_to_wstr(pszGlobalName).c_str(), utf8_to_wstr(pszLocalName).c_str(), nFuncNum);
}

void EdCore::disableDefaultARXExceptionHandler(bool flag)
{
    acedDisableDefaultARXExceptionHandler(flag);
}

void EdCore::disableUsrbrk()
{
    acedDisableUsrbrk();
}

bool EdCore::displayBorder(bool flag)
{
    return acedDisplayBorder(flag);
}

bool EdCore::drawingStatusBarsVisible()
{
    return acedDrawingStatusBarsVisible();
}

void EdCore::drawOrderInherit(PyDbObjectId& parent, const boost::python::list& childArray, AcEdDrawOrderCmdType cmd)
{
    auto ids = PyListToObjectIdArray(childArray);
    PyThrowBadEs(acedDrawOrderInherit(parent.m_id, ids, cmd));
}

void EdCore::dropOpenFile(const std::string& value)
{
    acedDropOpenFile(utf8_to_wstr(value).c_str());
}

int EdCore::eatCommandThroat()
{
    return acedEatCommandThroat();
}

int EdCore::editMTextInteractive(PyDbMText& mtext, bool useNewUI, bool allowTabs)
{
    return acedEditMTextInteractive(mtext.impObj(), useNewUI, allowTabs);
}

void EdCore::enableUsrbrk()
{
    return acedEnableUsrbrk();
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
    std::array<wchar_t, MAX_PATH> data;
    acedFindTrustedFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.data());
}

boost::python::list EdCore::getPredefinedPattens()
{
    PyAutoLockGIL lock;
    AcStringArray patterns;
    boost::python::list py_patterns;
    if (acedGetPredefinedPattens(patterns) == true)
    {
        for (auto& pattern : patterns)
            py_patterns.append(wstr_to_utf8(pattern));
    }
    return py_patterns;
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
    CString str;
    acedGetCommandPromptString(str);
    return wstr_to_utf8(str);
}

boost::python::list EdCore::getLastCommandLines(int lineCount, bool ignoreNull)
{
    AcStringArray strs;
    acedGetLastCommandLines(strs, lineCount, ignoreNull);
    return AcStringArrayToPyList(strs);
}

unsigned int EdCore::getBlockEditMode()
{
    return acedGetBlockEditMode();
}

std::string EdCore::getCommandForDocument(const PyApDocument& doc)
{
    AcString cmd;
    PyThrowBadEs(acedGetCommandForDocument(doc.impObj(), cmd));
    return wstr_to_utf8(cmd);
}

boost::python::list EdCore::getCurrentSelectionSet()
{
    AcDbObjectIdArray sset;
    PyThrowBadEs(acedGetCurrentSelectionSet(sset));
    return ObjectIdArrayToPyList(sset);
}

boost::python::tuple EdCore::getCurVportPixelToDisplay()
{
    PyAutoLockGIL lock;
    double xFactor = 0;
    double yFactor = 0;
    acedGetCurVportPixelToDisplay(xFactor, yFactor);
    return boost::python::make_tuple(xFactor, yFactor);
}

boost::python::tuple EdCore::getCurVportScreenToDisplay()
{
    PyAutoLockGIL lock;
    double xFactor = 0;
    double yFactor = 0;
    acedGetCurVportScreenToDisplay(xFactor, yFactor);
    return boost::python::make_tuple(xFactor, yFactor);
}

float EdCore::getDpiScalingValue()
{
    return acedGetDpiScalingValue();
}

std::string EdCore::getEnv(const std::string& env)
{
#if defined(_ARXTARGET) && (_ARXTARGET >= 242)
    AcString val;
    PyThrowBadRt(acedGetEnv(utf8_to_wstr(env).c_str(), val));
    return wstr_to_utf8(val);
#else
    std::array<wchar_t, 1024> buff = { 0 };
    PyThrowBadRt(acedGetEnv(utf8_to_wstr(env).c_str(), buff.data(), buff.size()));
    return wstr_to_utf8(buff.data());
#endif
}

void EdCore::setEnv(const std::string& sym, const std::string& val)
{
    PyThrowBadRt(acedSetEnv(utf8_to_wstr(sym).c_str(), utf8_to_wstr(val).c_str()));
}

std::string EdCore::getCfg(const std::string& str)
{
    std::array<wchar_t, 2048> buff = { 0 };
    PyThrowBadRt(acedGetCfg(utf8_to_wstr(str).c_str(), buff.data(), buff.size()));
    return wstr_to_utf8(buff.data());
}

void EdCore::setCfg(const std::string& sym, const std::string& val)
{
    PyThrowBadRt(acedSetCfg(utf8_to_wstr(sym).c_str(), utf8_to_wstr(val).c_str()));
}

boost::python::list EdCore::getSym(const std::string& symname)
{
    PyAutoLockGIL lock;
    resbuf* rb = nullptr;
    acedGetSym(utf8_to_wstr(symname).c_str(), &rb);
    AcResBufPtr holder(rb);
    return resbufToList(rb);
}

bool EdCore::putSym(const std::string& symname, boost::python::list& buf)
{
    AcResBufPtr ptr(listToResbuf(buf));
    return acedPutSym(utf8_to_wstr(symname).c_str(), ptr.get()) == RTNORM;
}

int EdCore::getWinNum(int ptx, int pty)
{
    return acedGetWinNum(ptx, pty);
}

void EdCore::graphScr()
{
    PyThrowBadRt(acedGraphScr());
}

Adesk::Boolean EdCore::initDialog(Adesk::Boolean useDialog)
{
    return acedInitDialog(useDialog);
}

int EdCore::isDragging()
{
    return acedIsDragging();
}

bool EdCore::isInBackgroundMode()
{
    return acedIsInBackgroundMode();
}

bool EdCore::isInputPending()
{
    return acedIsInputPending();
}

Adesk::Boolean EdCore::isMenuGroupLoaded(const std::string& mnu)
{
    return acedIsMenuGroupLoaded(utf8_to_wstr(mnu).c_str());
}

bool EdCore::isOsnapOverride()
{
    return acedIsOsnapOverride();
}

bool EdCore::isUpdateDisplayPaused()
{
    return acedIsUpdateDisplayPaused();
}

bool EdCore::isUsrbrkDisabled()
{
    return acedIsUsrbrkDisabled();
}

void EdCore::loadJSScript(const std::string& pUriOfJSFile)
{
    acedLoadJSScript(utf8_to_wstr(pUriOfJSFile).c_str());
}

bool EdCore::loadPartialMenu(const std::string& mnu)
{
    return acedLoadPartialMenu(utf8_to_wstr(mnu).c_str());
}

void EdCore::markForDelayXRefRelativePathResolve(const PyDbObjectId& id)
{
    acedMarkForDelayXRefRelativePathResolve(id.m_id);
}

int EdCore::menuCmd(const std::string& mnu)
{
    return acedMenuCmd(utf8_to_wstr(mnu).c_str());
}

boost::python::list EdCore::invoke(const boost::python::list& args)
{
    PyAutoLockGIL lock;
    AcResBufPtr pArgs(listToResbuf(args));
    resbuf* pResult = nullptr;
    acedInvoke(pArgs.get(), &pResult);
    AcResBufPtr pResultPtr(pResult);
    return resbufToList(pResult);
}

boost::python::dict EdCore::getSysVars()
{
    PyAutoLockGIL lock;
    boost::python::dict pydict;

    std::unique_ptr<AcEdSysVarIterator> vars(new AcEdSysVarIterator());
    for (vars->reset(); !vars->done(); vars->step())
    {
        resbuf buf;
        buf.restype = 0;
        buf.resval.rint = 0;
        const AcRxVariable* var = vars->getSysVar();
        const std::string utf8Name = wstr_to_utf8(var->name());

        if (auto es = acedGetVar(var->name(), &buf); es != RTNORM)
        {
            pydict[utf8Name] = boost::python::object();
            continue;
        }
        switch (buf.restype)
        {
        case RTSTR:
        {
            pydict[utf8Name] = wstr_to_utf8(buf.resval.rstring);
            acutDelString(buf.resval.rstring);
            break;
        }
        case RTSHORT:
        {
            pydict[utf8Name] = buf.resval.rint;
            break;
        }
        case RTLONG:
        {
            pydict[utf8Name] = buf.resval.rlong;
            break;
        }
        case RTREAL:
        {
            pydict[utf8Name] = buf.resval.rreal;
            break;
        }
        case RTPOINT:
        case RT3DPOINT:
        {
            pydict[utf8Name] = asPnt3d(buf.resval.rpoint);
            break;
        }
        }
    }
    return pydict;
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
        if (PyLong_Check(src.ptr()))
        {
            const int val = extract<int32_t>(src);
            AcResBufPtr buf(acutBuildList(RTLONG, val, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
        else if (PyFloat_Check(src.ptr()))
        {
            const double val = extract<double>(src);
            AcResBufPtr buf(acutBuildList(RTREAL, val, 0));
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

void EdCore::postCommand(const std::string& str)
{
    acedPostCommand(utf8_to_wstr(str).c_str());
}

void EdCore::postCommandPrompt()
{
    acedPostCommandPrompt();
}

int EdCore::prompt(const std::string& str)
{
    return acedPrompt(utf8_to_wstr(str).c_str());
}

int EdCore::redraw(const PyDbObjectId& ent, int mode)
{
    ads_name adsn = { 0L };
    acdbGetAdsName(adsn, ent.m_id);
    return acedRedraw(adsn, mode);
}

void EdCore::reloadMenus(bool bIncrementalReloading)
{
    acedReloadMenus(bIncrementalReloading);
}

void EdCore::restoreCurrentView(const PyDbObjectId& namedViewId)
{
    PyThrowBadEs(acedRestoreCurrentView(namedViewId.m_id));
}

void EdCore::restorePreviousUCS()
{
    PyThrowBadEs(acedRestorePreviousUCS());
}

void EdCore::restoreStatusBar()
{
    acedRestoreStatusBar();
}

void EdCore::sendModelessOperationEnded(const std::string& strContext)
{
    acedSendModelessOperationEnded(utf8_to_wstr(strContext).c_str());
}

void EdCore::sendModelessOperationStart(const std::string& strContext)
{
    acedSendModelessOperationStart(utf8_to_wstr(strContext).c_str());
}

boost::python::tuple EdCore::setColorDialog(int color, Adesk::Boolean bAllowMetaColor, int nCurLayerColor)
{
    PyAutoLockGIL lock;
    int _color = color;
    auto flag = acedSetColorDialog(_color, bAllowMetaColor, nCurLayerColor);
    return boost::python::make_tuple(flag, _color);
}

boost::python::tuple EdCore::setColorDialogTrueColor1(const AcCmColor& color, Adesk::Boolean bAllowMetaColor, const AcCmColor& nCurLayerColor)
{
    PyAutoLockGIL lock;
    AcCmColor _color = color;
    auto flag = acedSetColorDialogTrueColor(_color, bAllowMetaColor, nCurLayerColor);
    return boost::python::make_tuple(flag, _color);
}

boost::python::tuple EdCore::setColorDialogTrueColor2(const AcCmColor& color, Adesk::Boolean bAllowMetaColor, const AcCmColor& nCurLayerColor, AcCm::DialogTabs tab)
{
    PyAutoLockGIL lock;
    AcCmColor _color = color;
    auto flag = acedSetColorDialogTrueColor(_color, bAllowMetaColor, nCurLayerColor, tab);
    return boost::python::make_tuple(flag, _color);
}

int EdCore::grDraw(const AcGePoint3d& from, const AcGePoint3d& to, int colorIndex, int highlight)
{
    return acedGrDraw(asDblArray(from), asDblArray(to), colorIndex, highlight);
}

AcGePoint3d EdCore::getMousePositionUCS()
{
    CPoint cursorPos;
    ::GetCursorPos(&cursorPos);
    ::ScreenToClient(adsw_acadDocWnd(), &cursorPos);

    acedDwgPoint cpt;
    acedCoordFromPixelToWorld(cursorPos, cpt);

    resbuf fromrb;
    fromrb.restype = RTSHORT;
    fromrb.resval.rint = 2; // DCS

    resbuf torb;
    torb.restype = RTSHORT;
    torb.resval.rint = 1; // WCS 

    AcGePoint3d hitPoint;
    acedTrans(cpt, &fromrb, &torb, FALSE, asDblArray(hitPoint));
    return hitPoint;
}

AcGePoint3d EdCore::getMousePositionWCS()
{
    CPoint cursorPos;
    ::GetCursorPos(&cursorPos);
    ::ScreenToClient(adsw_acadDocWnd(), &cursorPos);

    acedDwgPoint cpt;
    acedCoordFromPixelToWorld(cursorPos, cpt);

    resbuf fromrb;
    fromrb.restype = RTSHORT;
    fromrb.resval.rint = 2; // DCS

    resbuf torb;
    torb.restype = RTSHORT;
    torb.resval.rint = 0; // WCS 

    AcGePoint3d hitPoint;
    acedTrans(cpt, &fromrb, &torb, FALSE, asDblArray(hitPoint));
    return hitPoint;
}

AcGePoint3d EdCore::osnap(const AcGePoint3d& pt, const std::string& mode)
{
    AcGePoint3d result;
    PyThrowBadRt(acedOsnap(asDblArray(pt), utf8_to_wstr(mode).c_str(), asDblArray(result)));
    return result;
}

void EdCore::setUndoMark(bool flag)
{
    return PyThrowBadEs(acedSetUndoMark(flag));
}

void EdCore::setCurrentView(const PyDbViewTableRecord& vrec, const PyDbViewport& vp)
{
    return PyThrowBadEs(acedSetCurrentView(vrec.impObj(), vp.impObj()));
}

void EdCore::setCurrentVPort(const PyDbViewport& vp)
{
    return PyThrowBadEs(acedSetCurrentVPort(vp.impObj()));
}

int EdCore::setStatusBarProgressMeter(const std::string& pszLabel, int nMinPos, int nMaxPos)
{
    return acedSetStatusBarProgressMeter(utf8_to_wstr(pszLabel).c_str(), nMinPos, nMaxPos);
}

int EdCore::setStatusBarProgressMeterPos(int pos)
{
    return acedSetStatusBarProgressMeterPos(pos);
}

void EdCore::setXrefResolvedWithUpdateStatus(const PyDbBlockTableRecord& rec)
{
    return PyThrowBadEs(acedSetXrefResolvedWithUpdateStatus(rec.impObj()));
}

bool EdCore::showHTMLModalWindow1(UINT_PTR hwnd, const std::string& uriOfHtmlPage)
{
    return showHTMLModalWindow2(hwnd, uriOfHtmlPage, true);
}

bool EdCore::showHTMLModalWindow2(UINT_PTR hwnd, const std::string& uriOfHtmlPage, bool persistSizeAndPosition)
{
    return acedShowHTMLModalWindow((HWND)hwnd, utf8_to_wstr(uriOfHtmlPage).c_str(), persistSizeAndPosition);
}

UINT_PTR EdCore::showHTMLModelessWindow1(UINT_PTR owner, const std::string& uriOfHtmlPage)
{
    return showHTMLModelessWindow2(owner, uriOfHtmlPage, true);
}

UINT_PTR EdCore::showHTMLModelessWindow2(UINT_PTR owner, const std::string& uriOfHtmlPage, bool persistSizeAndPosition)
{
    return (UINT_PTR)acedShowHTMLModelessWindow((HWND)owner, utf8_to_wstr(uriOfHtmlPage).c_str(), persistSizeAndPosition);
}

void EdCore::skipXrefNotification(PyDbDatabase& db, const std::string& xrefName)
{
    PyThrowBadEs(acedSkipXrefNotification(db.impObj(), utf8_to_wstr(xrefName).c_str()));
}

AcGePoint3d EdCore::trans(AcGePoint3d& pt, const boost::python::list& from, const boost::python::list& to, int disp)
{
    AcGePoint3d result;
    AcResBufPtr pFrom(listToResbuf(from));
    AcResBufPtr pTo(listToResbuf(to));
    PyThrowBadRt(acedTrans(asDblArray(pt), pFrom.get(), pTo.get(), disp, asDblArray(result)));
    return result;
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
    bool flag = false;
    if (auto es = acedXrefNotifyCheckFileChanged(id.m_id, flag); es != eOk)
        throw PyAcadErrorStatus(es);
    return flag;
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
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return PyThrowBadEs(acedXrefXBind(ids));
}

void EdCore::xrefXBind2(const boost::python::list& symbolIds, bool bQuiet, PyDbDatabase& pHostDb)
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return PyThrowBadEs(acedXrefXBind(ids, bQuiet, pHostDb.impObj()));
}
