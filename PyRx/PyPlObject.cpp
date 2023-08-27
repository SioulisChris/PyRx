#include "stdafx.h"
#include "PyPlObject.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyRxObject
void makePyPlObjectWrapper()
{
    PyDocString DS("PlObject");
    class_<PyPlObject, bases<PyRxObject>>("PlObject", boost::python::no_init)
        .def("className", &PyPlObject::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlObject::PyPlObject(AcPlObject* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
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
    boost::python::list pyList;
    //...
    return pyList;
}

void PyPlDSDData::setDSDEntries(const boost::python::list& val)
{
    //...
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
    AcStringArray _sectionArray = PyListAcStringArray(sectionArray);
    AcStringArray _dataArray = PyListAcStringArray(dataArray);
    AcArray<ACHAR*> _sectionArray_;
    AcArray<ACHAR*>  _dataArray_;
    for (const AcString& str : _sectionArray)
        _sectionArray_.append(const_cast<ACHAR*>(str.constPtr()));
    for (const AcString& str : _dataArray)
        _dataArray_.append(const_cast<ACHAR*>(str.constPtr()));
    impObj()->setUnrecognizedData(_sectionArray_, _dataArray_);
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
