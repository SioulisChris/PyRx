#include "stdafx.h"
#include "PySmSheetSetMgr.h"


#if defined(_ARXTARGET) || defined(_BRXTARGET) 
#include "PySmSheetSetMgrImpl.h"
#include "PyDbObject.h"
#include "PyDbEval.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PySmObjectCast
template<typename T>
inline T PySmObjectCast(const PySmPersist& src)
{
    T dest(nullptr);
    PySmPersist rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

//-----------------------------------------------------------------------------------------
//PySmPersist
void makePySmPersistWrapper()
{
    PyDocString DS("Persist");
    class_<PySmPersist>("Persist", boost::python::no_init)
        .def("getIsDirty", &PySmPersist::getIsDirty, DS.SARGS())
        .def("getTypeName", &PySmPersist::getTypeName, DS.SARGS())
        .def("initNew", &PySmPersist::initNew)
        .def("getOwner", &PySmPersist::getOwner)
        .def("setOwner", &PySmPersist::setOwner)
        .def("getDatabase", &PySmPersist::getDatabase)
        .def("cast", &PySmPersist::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmPersist::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmPersist::PySmPersist(PySmPersistImpl* ptr)
{
    if (ptr != nullptr)
        m_pyImp.reset(new PySmPersistImpl(ptr->impObj()));
}

PySmPersist::PySmPersist(const PySmPersistImpl& other)
    : m_pyImp(new PySmPersistImpl(other))
{
}

bool PySmPersist::getIsDirty() const
{
    return impObj()->GetIsDirty();
}

std::string PySmPersist::getTypeName() const
{
    return wstr_to_utf8(impObj()->GetTypeName());
}

void PySmPersist::initNew(const PySmPersist& owner)
{
    impObj()->InitNew(*owner.impObj());
}

PySmPersist PySmPersist::getOwner() const
{
    return PySmPersist(impObj()->GetOwner());
}

void PySmPersist::setOwner(const PySmPersist& owner)
{
    impObj()->SetOwner(*owner.impObj());
}

PySmDatabase PySmPersist::getDatabase() const
{
    return PySmDatabase(impObj()->GetDatabase());
}

PySmPersist PySmPersist::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmPersist>(src);
}

std::string PySmPersist::className()
{
    return "AcSmPersist";
}

PySmPersistImpl* PySmPersist::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PySmAcDbDatabase
void makePySmAcDbDatabaseWrapper()
{
    PyDocString DS("AcDbDatabase");
    class_<PySmAcDbDatabase>("AcDbDatabase", boost::python::no_init)
        .def("className", &PySmAcDbDatabase::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmAcDbDatabase::PySmAcDbDatabase(PySmAcDbDatabaseImpl* ptr)
{
    if (ptr != nullptr)
        m_pyImp.reset(new PySmAcDbDatabaseImpl(ptr->impObj()));
}

PySmAcDbDatabase::PySmAcDbDatabase(const PySmAcDbDatabaseImpl& other)
    : m_pyImp(new PySmAcDbDatabaseImpl(other))
{
}

std::string PySmAcDbDatabase::className()
{
    return "AcSmAcDbDatabase";
}

PySmAcDbDatabaseImpl* PySmAcDbDatabase::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PySmObjectId
void makePySmObjectIdWrapper()
{
    PyDocString DS("ObjectId");
    class_<PySmObjectId>("ObjectId", boost::python::no_init)
        .def("getHandle", &PySmObjectId::getHandle)
        .def("getDatabase", &PySmObjectId::getDatabase)
        .def("getPersistObject", &PySmObjectId::getPersistObject)
        .def("getOwner", &PySmObjectId::getOwner)
        .def("isEqual", &PySmObjectId::isEqual)
        .def("isValid", &PySmObjectId::isValid)
        .def("className", &PySmObjectId::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmObjectId::PySmObjectId(const PySmObjectIdImpl& other)
    : m_pyImp(new PySmObjectIdImpl(other))
{
}

std::string PySmObjectId::getHandle() const
{
    return wstr_to_utf8(impObj()->GetHandle());
}

PySmDatabase PySmObjectId::getDatabase() const
{
    return PySmDatabase(impObj()->GetDatabase());
}

PySmPersist PySmObjectId::getPersistObject() const
{
    return PySmPersist(impObj()->GetPersistObject());
}

PySmPersist PySmObjectId::getOwner() const
{
    return PySmPersist(impObj()->GetOwner());
}

bool PySmObjectId::isEqual(const PySmObjectId& other)
{
    return impObj()->IsEqual(*other.impObj());
}

bool PySmObjectId::isValid()
{
    return impObj()->IsValid();
}

std::string PySmObjectId::className()
{
    return "AcSmObjectId";
}

PySmObjectIdImpl* PySmObjectId::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyValue
void makePySmCustomPropertyValueWrapper()
{
    PyDocString DS("CustomPropertyValue");
    class_<PySmCustomPropertyValue, bases<PySmPersist>>("CustomPropertyValue")
        .def("getValue", &PySmCustomPropertyValue::getValue)
        .def("setValue", &PySmCustomPropertyValue::setValue)
        .def("getFlags", &PySmCustomPropertyValue::getFlags)
        .def("setFlags", &PySmCustomPropertyValue::setFlags)
        .def("cast", &PySmCustomPropertyValue::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmCustomPropertyValue::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<SmPropertyFlags>("PropertyFlags")
        .value("kEmpty", SmPropertyFlags::EMPTY)
        .value("kSheetSetProp", SmPropertyFlags::CUSTOM_SHEETSET_PROP)
        .value("kSheetProp", SmPropertyFlags::CUSTOM_SHEET_PROP)
        .value("kSubSetProp", SmPropertyFlags::CUSTOM_SUBSET_PROP)
        .value("kIsChild", SmPropertyFlags::IS_CHILD)
        .export_values()
        ;
}

PySmCustomPropertyValue::PySmCustomPropertyValue()
    : PySmCustomPropertyValue(new PySmCustomPropertyValueImpl())
{
}

PySmCustomPropertyValue::PySmCustomPropertyValue(PySmCustomPropertyValueImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmCustomPropertyValue::PySmCustomPropertyValue(const PySmCustomPropertyValueImpl& other)
    : PySmPersist(other)
{
}

PyDbAcValue PySmCustomPropertyValue::getValue() const
{
    return PyDbAcValue(impObj()->GetValue());
}

void PySmCustomPropertyValue::setValue(const PyDbAcValue& acVal)
{
    impObj()->SetValue(*acVal.impObj());
}

SmPropertyFlags PySmCustomPropertyValue::getFlags() const
{
    return static_cast<SmPropertyFlags>(impObj()->GetFlags());
}

void PySmCustomPropertyValue::setFlags(SmPropertyFlags flags)
{
    impObj()->SetFlags(static_cast<PropertyFlags>(flags));
}

PySmCustomPropertyValue PySmCustomPropertyValue::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmCustomPropertyValue>(src);
}

std::string PySmCustomPropertyValue::className()
{
    return "AcSmCustomPropertyValue";
}

PySmCustomPropertyValueImpl* PySmCustomPropertyValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmCustomPropertyValueImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyBag
void makePySmCustomPropertyBagWrapper()
{
    PyDocString DS("CustomPropertyBag");
    class_<PySmCustomPropertyBag, bases<PySmPersist>>("CustomPropertyBag", boost::python::no_init)
        .def("getValue", &PySmCustomPropertyBag::getProperty)
        .def("setValue", &PySmCustomPropertyBag::setProperty)
        .def("getProperties", &PySmCustomPropertyBag::getProperties)
        .def("getPropertyValues", &PySmCustomPropertyBag::getPropertyValues)
        .def("cast", &PySmCustomPropertyBag::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmCustomPropertyBag::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmCustomPropertyBag::PySmCustomPropertyBag(PySmCustomPropertyBagImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmCustomPropertyBag::PySmCustomPropertyBag(const PySmCustomPropertyBagImpl& other)
    : PySmPersist(other)
{
}

PySmCustomPropertyValue PySmCustomPropertyBag::getProperty(const std::string& propName) const
{
    return PySmCustomPropertyValue(impObj()->GetProperty(utf8_to_wstr(propName).c_str()));
}

void PySmCustomPropertyBag::setProperty(const std::string& propName, const PySmCustomPropertyValue& prop)
{
    impObj()->SetProperty(utf8_to_wstr(propName).c_str(), *prop.impObj());
}

boost::python::list PySmCustomPropertyBag::getProperties() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto& i : impObj()->GetProperties())
        pylist.append(boost::python::make_tuple(wstr_to_utf8(i.first), PySmCustomPropertyValue(i.second)));
    return pylist;
}

boost::python::list PySmCustomPropertyBag::getPropertyValues() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto& i : impObj()->GetPropertyValues())
        pylist.append(boost::python::make_tuple(wstr_to_utf8(i.first), PyDbAcValue(i.second)));
    return pylist;
}

PySmCustomPropertyBag PySmCustomPropertyBag::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmCustomPropertyBag>(src);
}

std::string PySmCustomPropertyBag::className()
{
    return "AcSmCustomPropertyBag";
}

PySmCustomPropertyBagImpl* PySmCustomPropertyBag::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmCustomPropertyBagImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmFileReference
void makePySmFileReferenceWrapper()
{
    PyDocString DS("FileReference");
    class_<PySmFileReference, bases<PySmPersist>>("FileReference", boost::python::no_init)
        .def("cast", &PySmFileReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmFileReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmFileReference::PySmFileReference(PySmFileReferenceImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmFileReference::PySmFileReference(const PySmFileReferenceImpl& other)
    : PySmPersist(other)
{
}

PySmFileReference PySmFileReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmFileReference>(src);
}

std::string PySmFileReference::className()
{
    return "AcSmFileReference";
}

PySmFileReferenceImpl* PySmFileReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmFileReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbObjectReference
void makePySmAcDbObjectReferenceWrapper()
{
    PyDocString DS("DbObjectReference");
    class_<PySmAcDbObjectReference, bases<PySmFileReference>>("DbObjectReference", boost::python::no_init)
        .def("cast", &PySmProjectPointLocation::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmProjectPointLocation::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmAcDbObjectReference::PySmAcDbObjectReference(PySmAcDbObjectReferenceImpl* ptr)
    : PySmFileReference(ptr)
{
}

PySmAcDbObjectReference::PySmAcDbObjectReference(const PySmAcDbObjectReferenceImpl& other)
    : PySmFileReference(other)
{
}

PySmAcDbObjectReference PySmAcDbObjectReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmAcDbObjectReference>(src);
}

std::string PySmAcDbObjectReference::className()
{
    return "AcSmAcDbObjectReference";
}

PySmAcDbObjectReferenceImpl* PySmAcDbObjectReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmAcDbObjectReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmNamedAcDbObjectReference
void makePySmNamedAcDbObjectReferenceWrapper()
{
    PyDocString DS("NamedDbObjectReference");
    class_<PySmNamedAcDbObjectReference, bases<PySmAcDbObjectReference>>("NamedDbObjectReference", boost::python::no_init)
        .def("cast", &PySmNamedAcDbObjectReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmNamedAcDbObjectReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmNamedAcDbObjectReference::PySmNamedAcDbObjectReference(PySmNamedAcDbObjectReferenceImpl* ptr)
    : PySmAcDbObjectReference(ptr)
{
}

PySmNamedAcDbObjectReference::PySmNamedAcDbObjectReference(const PySmNamedAcDbObjectReferenceImpl& other)
    : PySmAcDbObjectReference(other)
{
}

PySmNamedAcDbObjectReference PySmNamedAcDbObjectReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmNamedAcDbObjectReference>(src);
}

std::string PySmNamedAcDbObjectReference::className()
{
    return "AcSmNamedAcDbObjectReference";
}

PySmNamedAcDbObjectReferenceImpl* PySmNamedAcDbObjectReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmNamedAcDbObjectReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbLayoutReference
void makePySmAcDbLayoutReferenceWrapper()
{
    PyDocString DS("DbLayoutReference");
    class_<PySmAcDbLayoutReference, bases<PySmNamedAcDbObjectReference>>("DbLayoutReference", boost::python::no_init)
        .def("cast", &PySmAcDbLayoutReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmAcDbLayoutReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmAcDbLayoutReference::PySmAcDbLayoutReference(PySmAcDbLayoutReferenceImpl* ptr)
    : PySmNamedAcDbObjectReference(ptr)
{
}

PySmAcDbLayoutReference::PySmAcDbLayoutReference(const PySmNamedAcDbObjectReferenceImpl& other)
    : PySmNamedAcDbObjectReference(other)
{
}

PySmAcDbLayoutReference PySmAcDbLayoutReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmAcDbLayoutReference>(src);
}

std::string PySmAcDbLayoutReference::className()
{
    return "AcSmAcDbLayoutReference";
}

PySmAcDbLayoutReferenceImpl* PySmAcDbLayoutReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmAcDbLayoutReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbViewReference
void makePySmAcDbViewReferenceWrapper()
{
    PyDocString DS("DbViewReference");
    class_<PySmAcDbViewReference, bases<PySmNamedAcDbObjectReference>>("DbViewReference", boost::python::no_init)
        .def("cast", &PySmAcDbViewReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmAcDbViewReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmAcDbViewReference::PySmAcDbViewReference(PySmAcDbViewReferenceImpl* ptr)
    : PySmNamedAcDbObjectReference(ptr)
{
}

PySmAcDbViewReference::PySmAcDbViewReference(const PySmAcDbViewReferenceImpl& other)
    : PySmNamedAcDbObjectReference(other)
{
}

PySmAcDbViewReference PySmAcDbViewReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmAcDbViewReference>(src);
}

std::string PySmAcDbViewReference::className()
{
    return "AcSmAcDbLayoutReference";
}

PySmAcDbViewReferenceImpl* PySmAcDbViewReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmAcDbViewReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbBlockRecordReference
void makePySmAcDbBlockRecordReferenceWrapper()
{
    PyDocString DS("DbBlockRecordReference");
    class_<PySmAcDbBlockRecordReference, bases<PySmNamedAcDbObjectReference>>("DbBlockRecordReference", boost::python::no_init)
        .def("cast", &PySmAcDbBlockRecordReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmAcDbBlockRecordReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmAcDbBlockRecordReference::PySmAcDbBlockRecordReference(PySmAcDbBlockRecordReferenceImpl* ptr)
    : PySmNamedAcDbObjectReference(ptr)
{
}

PySmAcDbBlockRecordReference::PySmAcDbBlockRecordReference(const PySmAcDbBlockRecordReferenceImpl& other)
    : PySmNamedAcDbObjectReference(other)
{
}

PySmAcDbBlockRecordReference PySmAcDbBlockRecordReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmAcDbBlockRecordReference>(src);
}

std::string PySmAcDbBlockRecordReference::className()
{
    return "AcSmAcDbBlockRecordReference";
}

PySmAcDbBlockRecordReferenceImpl* PySmAcDbBlockRecordReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmAcDbBlockRecordReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocation
void makePySmProjectPointLocationWrapper()
{
    PyDocString DS("ProjectPointLocation");
    class_<PySmProjectPointLocation, bases<PySmPersist>>("ProjectPointLocation", boost::python::no_init)
        .def("cast", &PySmProjectPointLocation::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmProjectPointLocation::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmProjectPointLocation::PySmProjectPointLocation(PySmProjectPointLocationImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmProjectPointLocation::PySmProjectPointLocation(const PySmProjectPointLocationImpl& other)
    : PySmPersist(other)
{
}

PySmProjectPointLocation PySmProjectPointLocation::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmProjectPointLocation>(src);
}

std::string PySmProjectPointLocation::className()
{
    return "AcSmProjectPointLocation";
}

PySmProjectPointLocationImpl* PySmProjectPointLocation::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmProjectPointLocationImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmObjectReference
void makePySmObjectReferenceWrapper()
{
    PyDocString DS("ObjectReference");
    class_<PySmObjectReference, bases<PySmPersist>>("ObjectReference", boost::python::no_init)
        .def("cast", &PySmObjectReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmObjectReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmObjectReference::PySmObjectReference(PySmObjectReferenceImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmObjectReference::PySmObjectReference(const PySmObjectReferenceImpl& other)
    : PySmPersist(other)
{
}

PySmObjectReference PySmObjectReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmObjectReference>(src);
}

std::string PySmObjectReference::className()
{
    return "AcSmObjectReference";
}

PySmObjectReferenceImpl* PySmObjectReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmObjectReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmPersistProxy
void makePySmPersistProxyWrapper()
{
    PyDocString DS("PersistProxy");
    class_<PySmPersistProxy, bases<PySmPersist>>("PersistProxy", boost::python::no_init)
        .def("cast", &PySmPersistProxy::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmPersistProxy::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmPersistProxy::PySmPersistProxy(PySmPublishOptionsImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmPersistProxy::PySmPersistProxy(const PySmPublishOptionsImpl& other)
    : PySmPersist(other)
{
}

PySmPersistProxy PySmPersistProxy::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmPersistProxy>(src);
}

std::string PySmPersistProxy::className()
{
    return "AcSmPersistProxy";
}

PySmPersistProxyImpl* PySmPersistProxy::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmPersistProxyImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmPublishOption
void makePySmPublishOptioneWrapper()
{
    PyDocString DS("PublishOption");
    class_<PySmPublishOption, bases<PySmPersist>>("PublishOption", boost::python::no_init)
        .def("cast", &PySmPublishOption::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmPublishOption::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmPublishOption::PySmPublishOption(PySmPublishOptionsImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmPublishOption::PySmPublishOption(const PySmPublishOptionsImpl& other)
    : PySmPersist(other)
{
}

PySmPublishOption PySmPublishOption::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmPublishOption>(src);
}

std::string PySmPublishOption::className()
{
    return "AcSmPublishOptions";
}

PySmPublishOptionsImpl* PySmPublishOption::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmPublishOptionsImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmComponent
void makePySmComponentWrapper()
{
    PyDocString DS("Component");
    class_<PySmComponent, bases<PySmPersist>>("Component", boost::python::no_init)
        .def("getName", &PySmComponent::getName)
        .def("setName", &PySmComponent::setName)
        .def("getDesc", &PySmComponent::getDesc)
        .def("setDesc", &PySmComponent::setDesc)
        .def("getCustomPropertyBag", &PySmComponent::getCustomPropertyBag)
        .def("cast", &PySmComponent::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmComponent::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmComponent::PySmComponent(PySmComponentImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmComponent::PySmComponent(const PySmComponentImpl& other)
    : PySmPersist(other)
{
}

std::string PySmComponent::getName() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PySmComponent::setName(const std::string& csName)
{
    impObj()->SetName(utf8_to_wstr(csName).c_str());
}

std::string PySmComponent::getDesc() const
{
    return wstr_to_utf8(impObj()->GetDesc());
}

void PySmComponent::setDesc(const std::string& csDesc)
{
    impObj()->SetDesc(utf8_to_wstr(csDesc).c_str());
}

PySmCustomPropertyBag PySmComponent::getCustomPropertyBag() const
{
    return PySmCustomPropertyBag(impObj()->GetCustomPropertyBag());
}

PySmComponent PySmComponent::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmComponent>(src);
}

std::string PySmComponent::className()
{
    return "AcSmPersist";
}

PySmComponentImpl* PySmComponent::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmComponentImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PycSmSheetSelSet
void makePySmSheetSelSetWrapper()
{
    PyDocString DS("SheetSelSet");
    class_<PySmSheetSelSet, bases<PySmComponent>>("SheetSelSet", boost::python::no_init)
        .def("cast", &PySmSheetSelSet::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheetSelSet::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetSelSet::PySmSheetSelSet(PySmSheetSelSetImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSheetSelSet::PySmSheetSelSet(const PySmSheetSelSetImpl& other)
    : PySmComponent(other)
{
}

PySmSheetSelSet PySmSheetSelSet::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheetSelSet>(src);
}

std::string PySmSheetSelSet::className()
{
    return "AcSmSheetSelSet";
}

PySmSheetSelSetImpl* PySmSheetSelSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmSheetSelSetImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PycSmSheetSelSets
void makePySmSheetSelSetsWrapper()
{
    PyDocString DS("SheetSelSets");
    class_<PySmSheetSelSets, bases<PySmComponent>>("SheetSelSets", boost::python::no_init)
        .def("cast", &PySmSheetSelSets::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheetSelSets::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetSelSets::PySmSheetSelSets(PySmSheetSelSetsImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSheetSelSets::PySmSheetSelSets(const PySmSheetSelSetsImpl& other)
    : PySmComponent(other)
{
}

PySmSheetSelSets PySmSheetSelSets::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheetSelSets>(src);
}

std::string PySmSheetSelSets::className()
{
    return "AcSmSheetSelSets";
}

PySmSheetSelSetsImpl* PySmSheetSelSets::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmSheetSelSetsImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSheetView
void makePySmSheetViewWrapper()
{
    PyDocString DS("SheetView");
    class_<PySmSheetView, bases<PySmComponent>>("SheetView", boost::python::no_init)
        .def("cast", &PySmSheetView::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheetView::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetView::PySmSheetView(PySmSheetViewImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSheetView::PySmSheetView(const PySmSheetViewImpl& other)
    : PySmComponent(other)
{
}

PySmSheetView PySmSheetView::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheetView>(src);
}

std::string PySmSheetView::className()
{
    return "AcSmSheetView";
}

PySmSheetViewImpl* PySmSheetView::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmSheetViewImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSheetViews
void makePySmSheetViewsWrapper()
{
    PyDocString DS("SheetViews");
    class_<PySmSheetViews, bases<PySmComponent>>("SheetViews", boost::python::no_init)
        .def("cast", &PySmSheetViews::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheetViews::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetViews::PySmSheetViews(PySmSheetViewsImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSheetViews::PySmSheetViews(const PySmSheetViewsImpl& other)
    : PySmComponent(other)
{
}

PySmSheetViews PySmSheetViews::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheetViews>(src);
}

std::string PySmSheetViews::className()
{
    return "AcSmSheetViews";
}

PySmSheetViewsImpl* PySmSheetViews::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmSheetViewsImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocations
void makePySmProjectPointLocationsWrapper()
{
    PyDocString DS("ProjectPointLocations");
    class_<PySmProjectPointLocations, bases<PySmComponent>>("ProjectPointLocations", boost::python::no_init)
        .def("cast", &PySmProjectPointLocations::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmProjectPointLocations::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmProjectPointLocations::PySmProjectPointLocations(PySmProjectPointLocationsImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmProjectPointLocations::PySmProjectPointLocations(const PySmProjectPointLocationsImpl& other)
    : PySmComponent(other)
{
}

PySmProjectPointLocations PySmProjectPointLocations::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmProjectPointLocations>(src);
}

std::string PySmProjectPointLocations::className()
{
    return "IAcSmProjectPointLocations";
}

PySmProjectPointLocationsImpl* PySmProjectPointLocations::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmProjectPointLocationsImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSmResources
void makePySmSmResourcesWrapper()
{
    PyDocString DS("Resources");
    class_<PySmSmResources, bases<PySmComponent>>("Resources", boost::python::no_init)
        .def("cast", &PySmSmResources::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSmResources::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSmResources::PySmSmResources(PySmResourcesImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSmResources::PySmSmResources(const PySmResourcesImpl& other)
    : PySmComponent(other)
{
}

PySmSmResources PySmSmResources::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSmResources>(src);
}

std::string PySmSmResources::className()
{
    return "AcSmResources";
}

PySmResourcesImpl* PySmSmResources::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmResourcesImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmViewCategory
void makePySmViewCategoryWrapper()
{
    PyDocString DS("ViewCategory");
    class_<PySmViewCategory, bases<PySmComponent>>("ViewCategory", boost::python::no_init)
        .def("cast", &PySmViewCategory::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmViewCategory::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmViewCategory::PySmViewCategory(PySmViewCategoryImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmViewCategory::PySmViewCategory(const PySmResourcesImpl& other)
    : PySmComponent(other)
{
}

PySmViewCategory PySmViewCategory::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmViewCategory>(src);
}

std::string PySmViewCategory::className()
{
    return "AcSmViewCategory";
}

PySmViewCategoryImpl* PySmViewCategory::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmViewCategoryImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmViewCategories
void makePySmViewCategoriesWrapper()
{
    PyDocString DS("ViewCategories");
    class_<PySmViewCategories, bases<PySmComponent>>("ViewCategories", boost::python::no_init)
        .def("cast", &PySmViewCategories::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmViewCategories::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmViewCategories::PySmViewCategories(PySmViewCategoryImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmViewCategories::PySmViewCategories(const PySmViewCategoriesImpl& other)
    : PySmComponent(other)
{
}

PySmViewCategories PySmViewCategories::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmViewCategories>(src);
}

std::string PySmViewCategories::className()
{
    return "AcSmViewCategories";
}

PySmViewCategoriesImpl* PySmViewCategories::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmViewCategoriesImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmCalloutBlocks
void makePySmCalloutBlocksWrapper()
{
    PyDocString DS("CalloutBlocks");
    class_<PySmCalloutBlocks, bases<PySmComponent>>("CalloutBlocks", boost::python::no_init)
        .def("cast", &PySmCalloutBlocks::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmCalloutBlocks::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmCalloutBlocks::PySmCalloutBlocks(PySmCalloutBlocksImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmCalloutBlocks::PySmCalloutBlocks(const PySmCalloutBlocksImpl& other)
    : PySmComponent(other)
{
}

PySmCalloutBlocks PySmCalloutBlocks::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmCalloutBlocks>(src);
}

std::string PySmCalloutBlocks::className()
{
    return "AcSmCalloutBlocks";
}

PySmCalloutBlocksImpl* PySmCalloutBlocks::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmCalloutBlocksImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSubset
void makePySmSubsetWrapper()
{
    PyDocString DS("Subset");
    class_<PySmSubset, bases<PySmComponent>>("Subset", boost::python::no_init)
        .def("cast", &PySmSubset::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSubset::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSubset::PySmSubset(PySmSubsetImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSubset::PySmSubset(const PySmSubsetImpl& other)
    : PySmComponent(other)
{
}

PySmSubset PySmSubset::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSubset>(src);
}

std::string PySmSubset::className()
{
    return "AcSmSubset";
}

PySmSubsetImpl* PySmSubset::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmSubsetImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSheet
void makePySmSheetWrapper()
{
    PyDocString DS("Sheet");
    class_<PySmSheet, bases<PySmComponent>>("Sheet", boost::python::no_init)
        .def("getNumber", &PySmSheet::getNumber)
        .def("setNumber", &PySmSheet::setNumber)
        .def("getTitle", &PySmSheet::getTitle)
        .def("setTitle", &PySmSheet::setTitle)
        .def("getDoNotPlot", &PySmSheet::getDoNotPlot)
        .def("setDoNotPlot", &PySmSheet::setDoNotPlot)
        .def("getRevisionNumber", &PySmSheet::getRevisionNumber)
        .def("setRevisionNumber", &PySmSheet::setRevisionNumber)
        .def("getRevisionDate", &PySmSheet::getRevisionDate)
        .def("setRevisionDate", &PySmSheet::setRevisionDate)
        .def("getIssuePurpose", &PySmSheet::getIssuePurpose)
        .def("setIssuePurpose", &PySmSheet::setIssuePurpose)
        .def("getCategory", &PySmSheet::getCategory)
        .def("setCategory", &PySmSheet::setCategory)
        .def("setCategory", &PySmSheet::setCategory)
        .def("cast", &PySmSheet::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheet::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheet::PySmSheet(PySmSheetImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSheet::PySmSheet(const PySmSheetImpl& other)
    : PySmComponent(other)
{
}

std::string PySmSheet::getNumber() const
{
    return wstr_to_utf8(impObj()->GetNumber());
}

void PySmSheet::setNumber(const std::string& csVal)
{
    impObj()->SetNumber(utf8_to_wstr(csVal).c_str());
}

std::string PySmSheet::getTitle() const
{
    return wstr_to_utf8(impObj()->GetTitle());
}

void PySmSheet::setTitle(const std::string& csVal)
{
    impObj()->SetTitle(utf8_to_wstr(csVal).c_str());
}

bool PySmSheet::getDoNotPlot() const
{
    return impObj()->GetDoNotPlot();
}

void PySmSheet::setDoNotPlot(bool flag)
{
    impObj()->SetDoNotPlot(flag);
}

std::string PySmSheet::getRevisionNumber() const
{
    return wstr_to_utf8(impObj()->GetRevisionNumber());
}

void PySmSheet::setRevisionNumber(const std::string& csVal)
{
    impObj()->SetRevisionNumber(utf8_to_wstr(csVal).c_str());
}

std::string PySmSheet::getRevisionDate() const
{
    return wstr_to_utf8(impObj()->GetRevisionDate());
}

void PySmSheet::setRevisionDate(const std::string& csVal)
{
    impObj()->SetRevisionDate(utf8_to_wstr(csVal).c_str());
}

std::string PySmSheet::getIssuePurpose() const
{
    return wstr_to_utf8(impObj()->GetIssuePurpose());
}

void PySmSheet::setIssuePurpose(const std::string& csVal)
{
    impObj()->SetIssuePurpose(utf8_to_wstr(csVal).c_str());
}

std::string PySmSheet::getCategory() const
{
    return wstr_to_utf8(impObj()->GetCategory());
}

void PySmSheet::setCategory(const std::string& csVal)
{
    impObj()->SetCategory(utf8_to_wstr(csVal).c_str());
}

PySmSheet PySmSheet::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheet>(src);
}

std::string PySmSheet::className()
{
    return "AcSmSheet";
}

PySmSheetImpl* PySmSheet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmSheetImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSheetSet
void makePySmSheetSetWrapper()
{
    PyDocString DS("SheetSet");
    class_<PySmSheetSet, bases<PySmSubset>>("SheetSet", boost::python::no_init)
        .def("cast", &PySmSheetSet::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheetSet::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetSet::PySmSheetSet(PySmSheetSetImpl* ptr)
    : PySmSubset(ptr)
{
}

PySmSheetSet::PySmSheetSet(const PySmSheetSetImpl& other)
    : PySmSubset(other)
{
}

PySmSheetSet PySmSheetSet::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheetSet>(src);
}

std::string PySmSheetSet::className()
{
    return "AcSmSheetSet";
}

PySmSheetSetImpl* PySmSheetSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmSheetSetImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSmDatabase
void makePySmDatabaseWrapper()
{
    PyDocString DS("Database");
    class_<PySmDatabase, bases<PySmComponent>>("Database", boost::python::no_init)
        .def("loadFromFile", &PySmDatabase::loadFromFile)
        .def("getFileName", &PySmDatabase::getFileName)
        .def("setFileName", &PySmDatabase::setFileName)
        .def("getTemplateDstFileName", &PySmDatabase::getTemplateDstFileName)
        .def("getSheetSet", &PySmDatabase::getSheetSet)
        .def("getLockStatus", &PySmDatabase::getLockStatus)
        .def("getLockOwnerInfo", &PySmDatabase::getLockOwnerInfo)
        .def("lockDb", &PySmDatabase::lockDb)
        .def("unlockDb", &PySmDatabase::unlockDb)
        .def("getPersistObjects", &PySmDatabase::getPersistObjects)
        .def("cast", &PySmDatabase::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmDatabase::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<SmLockStatus>("LockStatus")
        .value("kUnLocked", SmLockStatus::AcSmLockStatus_UnLocked)
        .value("kLockedLocal", SmLockStatus::AcSmLockStatus_Locked_Local)
        .value("kLockedRemote", SmLockStatus::AcSmLockStatus_Locked_Remote)
        .value("kLockedReadOnly", SmLockStatus::AcSmLockStatus_Locked_ReadOnly)
        .value("kLockedNotConnected", SmLockStatus::AcSmLockStatus_Locked_NotConnected)
        .value("kLockedAccessDenied", SmLockStatus::AcSmLockStatus_Locked_AccessDenied)
        .export_values()
        ;
}

PySmDatabase::PySmDatabase(PySmDatabaseImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmDatabase::PySmDatabase(const PySmDatabaseImpl& other)
    : PySmComponent(other)
{
}

void PySmDatabase::loadFromFile(const std::string& filename)
{
    impObj()->LoadFromFile(utf8_to_wstr(filename).c_str());
}

std::string PySmDatabase::getFileName() const
{
    return wstr_to_utf8(impObj()->GetFileName());
}

void PySmDatabase::setFileName(const std::string& filename)
{
    impObj()->SetFileName(utf8_to_wstr(filename).c_str());
}

std::string PySmDatabase::getTemplateDstFileName() const
{
    return wstr_to_utf8(impObj()->GetTemplateDstFileName());
}

PySmSheetSet PySmDatabase::getSheetSet() const
{
    return PySmSheetSet(impObj()->GetSheetSet());
}

SmLockStatus PySmDatabase::getLockStatus() const
{
    return SmLockStatus(impObj()->GetLockStatus());
}

boost::python::tuple PySmDatabase::getLockOwnerInfo() const
{
    PyAutoLockGIL lock;
    const auto& info = impObj()->GetLockOwnerInfo();
    return boost::python::make_tuple(wstr_to_utf8(info.first), wstr_to_utf8(info.second));
}

void PySmDatabase::lockDb()
{
    impObj()->LockDb();
}

void PySmDatabase::unlockDb(bool commit)
{
    impObj()->UnlockDb(commit);
}

boost::python::list PySmDatabase::getPersistObjects()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    const auto& v = impObj()->GetEnumerator();
    for (const auto& i : v)
        pylist.append(PySmPersist(i));
    return pylist;
}

PySmDatabase PySmDatabase::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmDatabase>(src);
}

std::string PySmDatabase::className()
{
    return "AcSmDatabase";
}

PySmDatabaseImpl* PySmDatabase::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmDatabaseImpl*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------------
//PySmSheetSetMgr
void makePySmSheetSetMgrWrapper()
{
    PyDocString DS("SheetSetMgr");
    class_<PySmSheetSetMgr>("SheetSetMgr")
        .def("createDatabase", &PySmSheetSetMgr::createDatabase1)
        .def("createDatabase", &PySmSheetSetMgr::createDatabase2)
        .def("openDatabase", &PySmSheetSetMgr::openDatabase)
        .def("findOpenDatabase", &PySmSheetSetMgr::findOpenDatabase)
        .def("closeAll", &PySmSheetSetMgr::closeAll, DS.SARGS())
        .def("close", &PySmSheetSetMgr::close)
        .def("getParentSheetSet", &PySmSheetSetMgr::getParentSheetSet)
        .def("getSheetFromLayout", &PySmSheetSetMgr::getSheetFromLayout)
        .def("databases", &PySmSheetSetMgr::databases)
        .def("className", &PySmSheetSetMgr::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetSetMgr::PySmSheetSetMgr()
    : m_pyImp(new PySmSheetSetMgrImpl())
{
}

PySmDatabase PySmSheetSetMgr::createDatabase1(const std::string& filename)
{
    return PySmDatabase(impObj()->CreateDatabase(utf8_to_wstr(filename).c_str()));
}

PySmDatabase PySmSheetSetMgr::createDatabase2(const std::string& filename, const std::string& templatefilename, bool bAlwaysCreate)
{
    return PySmDatabase(impObj()->CreateDatabase(utf8_to_wstr(filename).c_str(), utf8_to_wstr(templatefilename).c_str(), bAlwaysCreate));
}

PySmDatabase PySmSheetSetMgr::openDatabase(const std::string& filename)
{
    return PySmDatabase(impObj()->OpenDatabase(utf8_to_wstr(filename).c_str()));
}

PySmDatabase PySmSheetSetMgr::findOpenDatabase(const std::string& filename)
{
    return PySmDatabase(impObj()->FindOpenDatabase(utf8_to_wstr(filename).c_str()));
}

void PySmSheetSetMgr::closeAll()
{
    impObj()->CloseAll();
}

void PySmSheetSetMgr::close(PySmDatabase& db)
{
    impObj()->Close(*db.impObj());
}

boost::python::tuple PySmSheetSetMgr::getParentSheetSet(const std::string& dwg, const std::string& layout)
{
    PyAutoLockGIL lock;
    const auto& val = impObj()->GetParentSheetSet(utf8_to_wstr(dwg).c_str(), utf8_to_wstr(layout).c_str());
    //
    return boost::python::make_tuple();
}

boost::python::tuple PySmSheetSetMgr::getSheetFromLayout(PyDbObject& pAcDbLayout)
{
    PyAutoLockGIL lock;
    const auto& val = impObj()->GetSheetFromLayout(pAcDbLayout.impObj());
    //
    return boost::python::make_tuple();
}

boost::python::list PySmSheetSetMgr::databases() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    const auto& v = impObj()->GetDatabaseEnumerator();
    for (const auto& i : v)
        pylist.append(PySmDatabase(i));
    return pylist;
}

std::string PySmSheetSetMgr::className()
{
    return "AcSmSheetSetMgr";
}

PySmSheetSetMgrImpl* PySmSheetSetMgr::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pyImp.get();
}
#endif
