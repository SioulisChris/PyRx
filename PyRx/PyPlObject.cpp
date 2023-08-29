#include "stdafx.h"
#include "PyPlObject.h"
#include "PyDbLayout.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//AcPlPlotFactory
void makeAcPlPlotFactoryWrapper()
{
    PyDocString DS("PlotFactory");
    class_<PyPlPlotFactory>("PlotFactory", boost::python::no_init)
        .def("createPreviewEngine", &PyPlPlotFactory::createPreviewEngine1)
        .def("createPreviewEngine", &PyPlPlotFactory::createPreviewEngine2).staticmethod("createPreviewEngine")
        .def("createPublishEngine", &PyPlPlotFactory::createPublishEngine).staticmethod("createPublishEngine")
        .def("className", &PyPlPlotFactory::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<ProcessPlotState>("ProcessPlotState ")
        .value("kNotPlotting ", ProcessPlotState::kNotPlotting)
        .value("kForegroundPlotting ", ProcessPlotState::kForegroundPlotting)
        .value("kBackgroundPlotting ", ProcessPlotState::kBackgroundPlotting)
        .export_values()
        ;
}

PyPlPlotEngine PyPlPlotFactory::createPreviewEngine1()
{
    AcPlPlotEngine* ptr = nullptr;
    AcPlPlotFactory::createPreviewEngine(ptr);
    return PyPlPlotEngine(ptr);
}

PyPlPlotEngine PyPlPlotFactory::createPreviewEngine2(long flags)
{
    AcPlPlotEngine* ptr = nullptr;
    AcPlPlotFactory::createPreviewEngine(ptr, flags);
    return PyPlPlotEngine(ptr);
}

PyPlPlotEngine PyPlPlotFactory::createPublishEngine()
{
    AcPlPlotEngine* ptr = nullptr;
    AcPlPlotFactory::createPublishEngine(ptr);
    return PyPlPlotEngine(ptr);
}

ProcessPlotState PyPlPlotFactory::processPlotState()
{
    return acplProcessPlotState();
}

std::string PyPlPlotFactory::className()
{
    return "AcPlPlotFactory";
}

//-----------------------------------------------------------------------------------------
//PyPlPlotEngine
void makePyPlPlotEngineWrapper()
{
    PyDocString DS("PlotEngine");
    class_<PyPlPlotEngine>("PlotEngine", boost::python::no_init)
        .def("className", &PyPlObject::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlPlotEngine::PyPlPlotEngine(const AcPlPlotEngine* ptr)
    : m_imp(ptr)
{
}

std::string PyPlPlotEngine::className()
{
    return "AcPlPlotEngine";
}

const AcPlPlotEngine* PyPlPlotEngine::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<const AcPlPlotEngine*>(m_imp);
}

//-----------------------------------------------------------------------------------------
//PyRxObject
void makePyPlObjectWrapper()
{
    PyDocString DS("PlObject");
    class_<PyPlObject, bases<PyRxObject>>("PlObject", boost::python::no_init)
        .def("className", &PyPlObject::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlObject::PyPlObject(const AcPlObject* ptr)
    :PyRxObject(ptr)
{
}

PyPlObject::PyPlObject(AcPlObject* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

std::string PyPlObject::className()
{
    return std::string{ "AcPlObject" };
}

AcPlObject* PyPlObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcPlObject*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlDSDData
void makePyPlDSDDataWrapper()
{
    PyDocString DS("DSDData");
    class_<PyPlDSDData, bases<PyPlObject>>("PlObject")
        .def("projectPath", &PyPlDSDData::projectPath)
        .def("setProjectPath", &PyPlDSDData::setProjectPath)
        .def("destinationName", &PyPlDSDData::destinationName)
        .def("setDestinationName", &PyPlDSDData::setDestinationName)
        .def("getDSDEntries", &PyPlDSDData::getDSDEntries)
        .def("setDSDEntries", &PyPlDSDData::setDSDEntries)
        .def("getPrecisionEntries", &PyPlDSDData::getPrecisionEntries)
        .def("setPrecisionEntries", &PyPlDSDData::setPrecisionEntries)
        .def("numberOfDSDEntries", &PyPlDSDData::numberOfDSDEntries)
        .def("sheetType", &PyPlDSDData::sheetType)
        .def("setSheetType", &PyPlDSDData::setSheetType)
        .def("password", &PyPlDSDData::password)
        .def("setPassword", &PyPlDSDData::setPassword)
        .def("getUnrecognizedData", &PyPlDSDData::getUnrecognizedData)
        .def("setUnrecognizedData", &PyPlDSDData::setUnrecognizedData1)
        .def("setUnrecognizedData", &PyPlDSDData::setUnrecognizedData2)
        .def("majorVersion", &PyPlDSDData::majorVersion)
        .def("setMajorVersion", &PyPlDSDData::setMajorVersion)
        .def("minorVersion", &PyPlDSDData::minorVersion)
        .def("setMinorVersion", &PyPlDSDData::setMinorVersion)
        .def("sheetSetName", &PyPlDSDData::sheetSetName)
        .def("setSheetSetName", &PyPlDSDData::setSheetSetName)
        .def("noOfCopies", &PyPlDSDData::noOfCopies)
        .def("setNoOfCopies", &PyPlDSDData::setNoOfCopies)
        .def("setIsSheetSet", &PyPlDSDData::setIsSheetSet)
        .def("isSheetSet", &PyPlDSDData::isSheetSet)
        .def("isHomogeneous", &PyPlDSDData::isHomogeneous)
        .def("setIsHomogeneous", &PyPlDSDData::setIsHomogeneous)
        .def("plotStampOn", &PyPlDSDData::plotStampOn)
        .def("setPlotStampOn", &PyPlDSDData::setPlotStampOn)
        .def("viewFile", &PyPlDSDData::viewFile)
        .def("setViewFile", &PyPlDSDData::setViewFile)
        .def("selectionSetName", &PyPlDSDData::selectionSetName)
        .def("setSelectionSetName", &PyPlDSDData::setSelectionSetName)
        .def("categoryName", &PyPlDSDData::categoryName)
        .def("setCategoryName", &PyPlDSDData::setCategoryName)
        .def("logFilePath", &PyPlDSDData::logFilePath)
        .def("setLogFilePath", &PyPlDSDData::setLogFilePath)
        .def("get3dDwfOptions", &PyPlDSDData::get3dDwfOptions)
        .def("set3dDwfOptions", &PyPlDSDData::set3dDwfOptions)
        .def("includeLayerInfo", &PyPlDSDData::includeLayerInfo)
        .def("setIncludeLayerInfo", &PyPlDSDData::setIncludeLayerInfo)
        .def("lineMerge", &PyPlDSDData::lineMerge)
        .def("setLineMerge", &PyPlDSDData::setLineMerge)
        .def("currentPrecision", &PyPlDSDData::currentPrecision)
        .def("setCurrentPrecision", &PyPlDSDData::setCurrentPrecision)
        .def("promptForDwfName", &PyPlDSDData::promptForDwfName)
        .def("setPromptForDwfName", &PyPlDSDData::setPromptForDwfName)
        .def("pwdProtectPublishedDWF", &PyPlDSDData::pwdProtectPublishedDWF)
        .def("setPwdProtectPublishedDWF", &PyPlDSDData::setPwdProtectPublishedDWF)
        .def("promptForPassword", &PyPlDSDData::promptForPassword)
        .def("setPromptForPassword", &PyPlDSDData::setPromptForPassword)
        .def("initializeLayouts", &PyPlDSDData::initializeLayouts)
        .def("setInitializeLayouts", &PyPlDSDData::setInitializeLayouts)
        .def("desc", &PyPlDSDData::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyPlDSDData::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlDSDData::PyPlDSDData()
    : PyPlDSDData(new AcPlDSDData(), true)
{
}

PyPlDSDData::PyPlDSDData(AcPlDSDData* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

std::string PyPlDSDData::projectPath() const
{
    return wstr_to_utf8(impObj()->projectPath());
}

void PyPlDSDData::setProjectPath(const std::string& pVal)
{
    impObj()->setProjectPath(utf8_to_wstr(pVal).c_str());
}

std::string PyPlDSDData::destinationName() const
{
    return wstr_to_utf8(impObj()->destinationName());
}

void PyPlDSDData::setDestinationName(const std::string& pVal)
{
    impObj()->setDestinationName(utf8_to_wstr(pVal).c_str());
}

boost::python::list PyPlDSDData::getDSDEntries() const
{
    PyAutoLockGIL lock;
    AcPlDSDEntries arr;
    boost::python::list pyList;
    impObj()->getDSDEntries(arr);
    for (const auto& item : arr)
        pyList.append(PyPlDSDEntry(item));
    return pyList;
}

void PyPlDSDData::setDSDEntries(const boost::python::list& val)
{
    AcPlDSDEntries arr;
    const auto& vec = py_list_to_std_vector<PyPlDSDEntry>(val);
    for (auto& item : vec)
        arr.append(AcPlDSDEntry(*item.impObj()));
    impObj()->setDSDEntries(arr);
}

boost::python::list PyPlDSDData::getPrecisionEntries() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    //...
    return pyList;
}

void PyPlDSDData::setPrecisionEntries(const boost::python::list& val)
{
    //...
}

int PyPlDSDData::numberOfDSDEntries() const
{
    return impObj()->numberOfDSDEntries();
}

PyPlDSDEntry PyPlDSDData::DSDEntryAt(int idx)
{
    return PyPlDSDEntry(impObj()->DSDEntryAt(idx));
}

AcPlDSDEntry::SheetType PyPlDSDData::sheetType() const
{
    return impObj()->sheetType();
}

void PyPlDSDData::setSheetType(AcPlDSDEntry::SheetType val)
{
    return impObj()->setSheetType(val);
}

std::string PyPlDSDData::password() const
{
    return wstr_to_utf8(impObj()->password());
}

void PyPlDSDData::setPassword(const std::string& pVal)
{
    impObj()->setPassword(utf8_to_wstr(pVal).c_str());
}

void PyPlDSDData::getUnrecognizedData(boost::python::list& sectionArray, boost::python::list& dataArray) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    //TODO: SR163653
    throw PyNotimplementedByHost();
#else
    AcStringArray _sectionArray;
    AcStringArray _dataArray;
    impObj()->getUnrecognizedData(_sectionArray, _dataArray);
    for (const auto& item : _sectionArray)
        sectionArray.append(wstr_to_utf8(item));
    for (const auto& item : _dataArray)
        dataArray.append(wstr_to_utf8(item));
#endif
}

void PyPlDSDData::setUnrecognizedData1(const std::string& pSectionName, const std::string& pSectionData)
{
    impObj()->setUnrecognizedData(utf8_to_wstr(pSectionName).c_str(), utf8_to_wstr(pSectionData).c_str());
}

void PyPlDSDData::setUnrecognizedData2(const boost::python::list& sectionArray, const boost::python::list& dataArray)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    //TODO: SR163653
    throw PyNotimplementedByHost();
#else
    impObj()->setUnrecognizedData(PyListAcStringArray(sectionArray), PyListAcStringArray(dataArray));
#endif
}

unsigned int PyPlDSDData::majorVersion() const
{
    return impObj()->majorVersion();
}

void PyPlDSDData::setMajorVersion(unsigned int majorVersion)
{
    return impObj()->setMajorVersion(majorVersion);
}

unsigned int PyPlDSDData::minorVersion() const
{
    return impObj()->minorVersion();
}

void PyPlDSDData::setMinorVersion(unsigned int minorVersion)
{
    return impObj()->setMinorVersion(minorVersion);
}

std::string PyPlDSDData::sheetSetName() const
{
    return wstr_to_utf8(impObj()->sheetSetName());
}

void PyPlDSDData::setSheetSetName(const std::string& pSheetSetName)
{
    return impObj()->setSheetSetName(utf8_to_wstr(pSheetSetName).c_str());
}

unsigned int PyPlDSDData::noOfCopies() const
{
    return impObj()->noOfCopies();
}

void PyPlDSDData::setNoOfCopies(unsigned int copies)
{
    return impObj()->setNoOfCopies(copies);
}

void PyPlDSDData::setIsSheetSet(bool bSheetSet)
{
    return impObj()->setIsSheetSet(bSheetSet);
}

bool PyPlDSDData::isSheetSet() const
{
    return impObj()->isSheetSet();
}

bool PyPlDSDData::isHomogeneous() const
{
    return impObj()->isHomogeneous();
}

void PyPlDSDData::setIsHomogeneous(bool bHomogeneous)
{
    return impObj()->setIsHomogeneous(bHomogeneous);
}

bool PyPlDSDData::plotStampOn() const
{
    return impObj()->plotStampOn();
}

void PyPlDSDData::setPlotStampOn(bool bOn)
{
    return impObj()->setPlotStampOn(bOn);
}

bool PyPlDSDData::viewFile() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->viewFile();
#endif
}

void PyPlDSDData::setViewFile(bool bViewFile)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setViewFile(bViewFile);
#endif
}

std::string PyPlDSDData::selectionSetName() const
{
    return wstr_to_utf8(impObj()->selectionSetName());
}

void PyPlDSDData::setSelectionSetName(const std::string& pSelSetName)
{
    return impObj()->setSelectionSetName(utf8_to_wstr(pSelSetName).c_str());
}

std::string PyPlDSDData::categoryName() const
{
    return wstr_to_utf8(impObj()->categoryName());
}

void PyPlDSDData::setCategoryName(const std::string& pCategoryName)
{
    return impObj()->setCategoryName(utf8_to_wstr(pCategoryName).c_str());
}

std::string PyPlDSDData::logFilePath() const
{
    return wstr_to_utf8(impObj()->logFilePath());
}

void PyPlDSDData::setLogFilePath(const std::string& pLogFilePath)
{
    return impObj()->setLogFilePath(utf8_to_wstr(pLogFilePath).c_str());
}

boost::python::tuple PyPlDSDData::get3dDwfOptions() const
{
    PyAutoLockGIL lock;
    const AcPl3dDwfOptions& opt = impObj()->get3dDwfOptions();
    return boost::python::make_tuple(opt.bGroupByXrefHierarchy, opt.bPublishWithMaterials);
}

void PyPlDSDData::set3dDwfOptions(bool bGroupByXrefHierarchy, bool bPublishWithMaterials)
{
    AcPl3dDwfOptions opt = { bGroupByXrefHierarchy ,bPublishWithMaterials };
    impObj()->set3dDwfOptions(opt);
}

bool PyPlDSDData::includeLayerInfo() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->includeLayerInfo();
#endif
}

void PyPlDSDData::setIncludeLayerInfo(bool bOn)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setIncludeLayerInfo(bOn);
#endif
}

bool PyPlDSDData::lineMerge() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->lineMerge();
#endif
}

void PyPlDSDData::setLineMerge(bool bOn)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setLineMerge(bOn);
#endif
}

std::string PyPlDSDData::currentPrecision() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->currentPrecision());
#endif
}

void PyPlDSDData::setCurrentPrecision(const std::string& pCurrentPrecision)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setCurrentPrecision(utf8_to_wstr(pCurrentPrecision).c_str());
#endif
}

bool PyPlDSDData::promptForDwfName() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->promptForDwfName();
#endif
}

void PyPlDSDData::setPromptForDwfName(bool bPromptForDwfName)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setPromptForDwfName(bPromptForDwfName);
#endif
}

bool PyPlDSDData::pwdProtectPublishedDWF() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->pwdProtectPublishedDWF();
#endif
}

void PyPlDSDData::setPwdProtectPublishedDWF(bool bPwdProtectPublishedDWF)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setPwdProtectPublishedDWF(bPwdProtectPublishedDWF);
#endif
}

bool PyPlDSDData::promptForPassword() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->promptForPassword();
#endif
}

void PyPlDSDData::setPromptForPassword(bool bPromptForPassword)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->setPromptForPassword(bPromptForPassword);
#endif
}

bool PyPlDSDData::initializeLayouts() const
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->initializeLayouts();
#endif
}

void PyPlDSDData::setInitializeLayouts(bool initLayouts)
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setInitializeLayouts(initLayouts);
#endif
}

PyRxClass PyPlDSDData::desc()
{
    return PyRxClass(AcPlDSDData::desc(), false);
}

std::string PyPlDSDData::className()
{
    return "AcPlDSDData";
}

AcPlDSDData* PyPlDSDData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcPlDSDData*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlDSDEntry
void makePyPlDSDEntryWrapper()
{
    PyDocString DS("DSDEntry");
    class_<PyPlDSDEntry, bases<PyPlObject>>("DSDEntry")
        .def("dwgName", &PyPlDSDEntry::dwgName)
        .def("setDwgName", &PyPlDSDEntry::setDwgName)
        .def("layout", &PyPlDSDEntry::layout)
        .def("setLayout", &PyPlDSDEntry::setLayout)
        .def("title", &PyPlDSDEntry::title)
        .def("setTitle", &PyPlDSDEntry::setTitle)
        .def("NPS", &PyPlDSDEntry::NPS)
        .def("setNPS", &PyPlDSDEntry::setNPS)
        .def("NPSSourceDWG", &PyPlDSDEntry::NPSSourceDWG)
        .def("setNPSSourceDWG", &PyPlDSDEntry::setNPSSourceDWG)
        .def("has3dDwfSetup", &PyPlDSDEntry::has3dDwfSetup)
        .def("setHas3dDwfSetup", &PyPlDSDEntry::setHas3dDwfSetup)
        .def("setupType", &PyPlDSDEntry::setupType)
        .def("setSetupType", &PyPlDSDEntry::setSetupType)
        .def("orgSheetPath", &PyPlDSDEntry::orgSheetPath)
        .def("traceSession", &PyPlDSDEntry::traceSession)
        .def("setTraceSession", &PyPlDSDEntry::setTraceSession)
        .def("desc", &PyPlDSDEntry::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyPlDSDEntry::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlDSDEntry::PyPlDSDEntry()
    : PyPlDSDEntry(new AcPlDSDEntry(), true)
{
}

PyPlDSDEntry::PyPlDSDEntry(AcPlDSDEntry* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

PyPlDSDEntry::PyPlDSDEntry(const AcPlDSDEntry& entry)
    : PyPlDSDEntry(new AcPlDSDEntry(entry), true)
{
}

std::string PyPlDSDEntry::dwgName() const
{
    return wstr_to_utf8(impObj()->dwgName());
}

void PyPlDSDEntry::setDwgName(const std::string& pName)
{
    impObj()->setDwgName(utf8_to_wstr(pName).c_str());
}

std::string PyPlDSDEntry::layout() const
{
    return wstr_to_utf8(impObj()->layout());
}

void PyPlDSDEntry::setLayout(std::string& pLayoutName)
{
    impObj()->setLayout(utf8_to_wstr(pLayoutName).c_str());
}

std::string PyPlDSDEntry::title() const
{
    return wstr_to_utf8(impObj()->title());
}

void PyPlDSDEntry::setTitle(const std::string& pTitle)
{
    impObj()->setLayout(utf8_to_wstr(pTitle).c_str());
}

std::string PyPlDSDEntry::NPS() const
{
    return wstr_to_utf8(impObj()->NPS());
}

void PyPlDSDEntry::setNPS(const std::string& pNPSName)
{
    impObj()->setNPS(utf8_to_wstr(pNPSName).c_str());
}

std::string PyPlDSDEntry::NPSSourceDWG() const
{
    return wstr_to_utf8(impObj()->NPSSourceDWG());
}

void PyPlDSDEntry::setNPSSourceDWG(const std::string& pNPWDWGName)
{
    impObj()->setNPSSourceDWG(utf8_to_wstr(pNPWDWGName).c_str());
}

bool PyPlDSDEntry::has3dDwfSetup() const
{
    return impObj()->has3dDwfSetup();
}

void PyPlDSDEntry::setHas3dDwfSetup(bool b3dDwfSetup)
{
    return impObj()->setHas3dDwfSetup(b3dDwfSetup);
}

AcPlDSDEntry::SetupType PyPlDSDEntry::setupType() const
{
    return impObj()->setupType();
}

void PyPlDSDEntry::setSetupType(AcPlDSDEntry::SetupType eType)
{
    return impObj()->setSetupType(eType);
}

std::string PyPlDSDEntry::orgSheetPath() const
{
    return wstr_to_utf8(impObj()->orgSheetPath());
}

std::string PyPlDSDEntry::traceSession() const
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->traceSession());
#endif
}

void PyPlDSDEntry::setTraceSession(const std::string& pTraceSession)
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    impObj()->setNPSSourceDWG(utf8_to_wstr(pTraceSession).c_str());
#endif
}

PyRxClass PyPlDSDEntry::desc()
{
    return PyRxClass(AcPlDSDEntry::desc(), false);
}

std::string PyPlDSDEntry::className()
{
    return "AcPlDSDEntry";
}

AcPlDSDEntry* PyPlDSDEntry::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcPlDSDEntry*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlPlotInfo
void makePyPlPlotInfoWrapper()
{
    PyDocString DS("PlotInfo");
    class_<PyPlPlotInfo, bases<PyPlObject>>("PlotInfo")
        .def("copyFrom", &PyPlPlotInfo::copyFrom)
        .def("setLayout", &PyPlPlotInfo::setLayout)
        .def("layout", &PyPlPlotInfo::layout)
        .def("setOverrideSettings", &PyPlPlotInfo::setOverrideSettings)
        .def("overrideSettings", &PyPlPlotInfo::overrideSettings)
        .def("setDeviceOverride", &PyPlPlotInfo::setDeviceOverride)
        .def("validatedSettings", &PyPlPlotInfo::validatedSettings)
        .def("setValidatedSettings", &PyPlPlotInfo::setValidatedSettings)
        .def("validatedConfig", &PyPlPlotInfo::validatedConfig)
        .def("setValidatedConfig", &PyPlPlotInfo::setValidatedConfig)
        .def("deviceOverride", &PyPlPlotInfo::deviceOverride)
        .def("isCompatibleDocument", &PyPlPlotInfo::isCompatibleDocument)
        .def("isValidated", &PyPlPlotInfo::isValidated)
        .def("mergeStatus", &PyPlPlotInfo::mergeStatus)
        .def("OrgFilePath", &PyPlPlotInfo::OrgFilePath)
        .def("desc", &PyPlPlotInfo::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyPlPlotInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlPlotInfo::PyPlPlotInfo()
    : PyPlPlotInfo(new AcPlPlotInfo(), true)
{
}

PyPlPlotInfo::PyPlPlotInfo(AcPlPlotInfo* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

PyPlPlotInfo::PyPlPlotInfo(const AcPlPlotInfo& entry)
    : PyPlPlotInfo(new AcPlPlotInfo(entry), true)
{
}

void PyPlPlotInfo::copyFrom(const PyRxObject& pOther)
{
    PyThrowBadEs(impObj()->copyFrom(pOther.impObj()));
}

void PyPlPlotInfo::setLayout(PyDbObjectId& layoutId)
{
    impObj()->setLayout(layoutId.m_id);
}

PyDbObjectId PyPlPlotInfo::layout() const
{
    return PyDbObjectId(impObj()->layout());
}

void PyPlPlotInfo::setOverrideSettings(const PyDbPlotSettings& pOverrides)
{
    impObj()->setOverrideSettings(pOverrides.impObj());
}

PyDbPlotSettings PyPlPlotInfo::overrideSettings() const
{
    return PyDbPlotSettings(impObj()->overrideSettings());
}

void PyPlPlotInfo::setDeviceOverride(const PyPlPlotConfig& pconf)
{
    impObj()->setDeviceOverride(pconf.impObj());
}

PyDbPlotSettings PyPlPlotInfo::validatedSettings() const
{
    return PyDbPlotSettings(impObj()->validatedSettings());
}

void PyPlPlotInfo::setValidatedSettings(const PyDbPlotSettings& pValidatedSettings)
{
    impObj()->setOverrideSettings(pValidatedSettings.impObj());
}

PyPlPlotConfig PyPlPlotInfo::validatedConfig() const
{
    return PyPlPlotConfig(impObj()->validatedConfig());
}

void PyPlPlotInfo::setValidatedConfig(const PyPlPlotConfig& pConfig)
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    impObj()->setValidatedConfig(pConfig.impObj());
#endif
}

PyPlPlotConfig PyPlPlotInfo::deviceOverride() const
{
    return PyPlPlotConfig(impObj()->deviceOverride());
}

bool PyPlPlotInfo::isCompatibleDocument(const PyPlPlotInfo& pOtherInfo) const
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isCompatibleDocument(pOtherInfo.impObj());
#endif
}

bool PyPlPlotInfo::isValidated() const
{
    return impObj()->isValidated();
}

unsigned long PyPlPlotInfo::mergeStatus() const
{
    return impObj()->mergeStatus();
}

std::string PyPlPlotInfo::OrgFilePath()
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    AcString str = impObj()->OrgFilePath();
    return wstr_to_utf8(str);
#endif
}

PyRxClass PyPlPlotInfo::desc()
{
    return PyRxClass(AcPlPlotInfo::desc(), false);
}

std::string PyPlPlotInfo::className()
{
    return "AcPlPlotInfo";
}

AcPlPlotInfo* PyPlPlotInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcPlPlotInfo*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlPlotConfig
void makePyPlPlotConfigWrapper()
{
    PyDocString DS("PlotConfig");
    class_<PyPlPlotConfig, bases<PyPlObject>>("PlotConfig", boost::python::no_init)
        .def("desc", &PyPlPlotConfig::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyPlPlotConfig::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlPlotConfig::PyPlPlotConfig(const AcPlPlotConfig* ptr)
    : PyPlObject(ptr)
{
}

PyPlPlotConfig::PyPlPlotConfig(AcPlPlotConfig* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

PyRxClass PyPlPlotConfig::desc()
{
    return PyRxClass(AcPlPlotConfig::desc(), false);
}

std::string PyPlPlotConfig::className()
{
    return "AcPlPlotConfig";
}

AcPlPlotConfig* PyPlPlotConfig::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcPlPlotConfig*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlPlotPageInfo
void makePyPlPlotPageInfoWrapper()
{
    PyDocString DS("PlotPageInfo");
    class_<PyPlPlotPageInfo, bases<PyPlObject>>("PlotPageInfo")
        .def("entityCount", &PyPlPlotPageInfo::entityCount, DS.SARGS())
        .def("rasterCount", &PyPlPlotPageInfo::rasterCount, DS.SARGS())
        .def("oleObjectCount", &PyPlPlotPageInfo::oleObjectCount, DS.SARGS())
        .def("gradientCount", &PyPlPlotPageInfo::gradientCount, DS.SARGS())
        .def("shadedViewportType", &PyPlPlotPageInfo::shadedViewportType, DS.SARGS())
        .def("desc", &PyPlPlotPageInfo::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyPlPlotPageInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlPlotPageInfo::PyPlPlotPageInfo()
    : PyPlObject(new AcPlPlotPageInfo(), true)
{
}

PyPlPlotPageInfo::PyPlPlotPageInfo(const AcPlPlotPageInfo* ptr)
    : PyPlObject(ptr)
{
}

PyPlPlotPageInfo::PyPlPlotPageInfo(AcPlPlotPageInfo* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

Adesk::Int32 PyPlPlotPageInfo::entityCount() const
{
    return impObj()->entityCount();
}

Adesk::Int32 PyPlPlotPageInfo::rasterCount() const
{
    return impObj()->rasterCount();
}

Adesk::Int32 PyPlPlotPageInfo::oleObjectCount() const
{
    return impObj()->oleObjectCount();
}

Adesk::Int32 PyPlPlotPageInfo::gradientCount() const
{
    return impObj()->gradientCount();
}

Adesk::Int32 PyPlPlotPageInfo::shadedViewportType() const
{
    return impObj()->shadedViewportType();
}

PyRxClass PyPlPlotPageInfo::desc()
{
    return PyRxClass(AcPlPlotPageInfo::desc(), false);
}

std::string PyPlPlotPageInfo::className()
{
    return "AcPlPlotPageInfo";
}

AcPlPlotPageInfo* PyPlPlotPageInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcPlPlotPageInfo*>(m_pyImp.get());
}