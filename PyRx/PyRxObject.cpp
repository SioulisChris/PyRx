#include "stdafx.h"
#include "PyRxObject.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyRxObject wrapper
void makeAcRxObjectWrapper()
{
    PyDocString DS("RxObject");
    class_<PyRxObject>("RxObject", boost::python::no_init)
        .def("isA", &PyRxObject::isA, DS.ARGS())
        .def("isKindOf", &PyRxObject::isKindOf, DS.ARGS({ "rhs:PyRx.RxClass" }))
        .def("isNullObj", &PyRxObject::isNullObj, DS.ARGS())
        .def("implRefCount", &PyRxObject::implRefCount, DS.ARGS())
        .def("keepAlive", &PyRxObject::forceKeepAlive, DS.ARGS({"flag:bool"}))
        .def("dispose", &PyRxObject::dispose, DS.ARGS())
        .def("queryX", &PyRxObject::queryX, DS.ARGS({ "rhs:PyRx.RxClass" }))
        .def("copyFrom", &PyRxObject::copyFrom, DS.ARGS({ "other:PyRx.RxObject" }))
        .def("__eq__", &PyRxObject::operator==, DS.ARGS({ "rhs:PyRx.RxObject" }))
        .def("__ne__", &PyRxObject::operator!=, DS.ARGS({ "rhs:PyRx.RxObject" }))
        .def("className", &PyRxObject::className, DS.SARGS()).staticmethod("className")
        ;
}

// if the object is dbo, close it and return out
// objects that derived from PyDbObject have m_isDbObject set to true
// id the object is some sort of global pointer or should not be deleted m_autoDelete should be false
// examples would be document or current database
// note: PyDbObject::cast resets the pointer, which call this, but it's not a double delete
struct PyRxObjectDeleter
{
    inline PyRxObjectDeleter(bool autoDelete, bool isDbObject)
        : m_autoDelete(autoDelete), m_isDbObject(isDbObject)
    {
    }

    inline bool isDbroThenClose(AcRxObject* p) const
    {
        if (!m_isDbObject)
        {
            return false;
        }
        else if (m_forceKeepAlive)
        {
            return true;
        }
        else
        {
            AcDbObject* pDbo = static_cast<AcDbObject*>(p);
            if (!pDbo->objectId().isNull())
            {
                if (auto es = pDbo->close(); es != eOk) [[unlikely]] {
                    acutPrintf(_T("\nStatus = %ls in %ls: "), acadErrorStatusText(es), __FUNCTIONW__);
                }
                return true;
            }
        }
        return false;
    }

    inline void operator()(AcRxObject* p) const
    {
        if (p == nullptr) [[unlikely]]
            return;
        else if (isDbroThenClose(p))
            return;
        else if (!m_autoDelete)
            return;
        else
            delete p;
    }

    bool m_autoDelete = true;
    bool m_isDbObject = false;
    bool m_forceKeepAlive = false;
};

PyRxObject::PyRxObject(const AcRxObject* ptr)
    : m_pyImp(const_cast<AcRxObject*>(ptr), PyRxObjectDeleter(false, false))
{
}

PyRxObject::PyRxObject(AcRxObject* ptr, bool autoDelete, bool isDbOject)
    : m_pyImp(ptr, PyRxObjectDeleter(autoDelete, isDbOject))
{
}

bool PyRxObject::operator==(const PyRxObject& rhs) const
{
    return impObj()->isEqualTo(rhs.impObj());
}

bool PyRxObject::operator!=(const PyRxObject& rhs) const
{
    return !impObj()->isEqualTo(rhs.impObj());
}

PyRxClass PyRxObject::isA() const
{
    return PyRxClass(m_pyImp->isA(), false);
}

bool PyRxObject::isKindOf(const PyRxClass& aClass)
{
    return impObj()->isKindOf(aClass.impObj());
}

void PyRxObject::forceKeepAlive(bool flag)
{
    auto del_p = std::get_deleter<PyRxObjectDeleter>(m_pyImp);
    if (del_p != nullptr)
        del_p->m_forceKeepAlive = flag;
}

void PyRxObject::dispose()
{
    m_pyImp.reset();
}

bool PyRxObject::isNullObj()
{
    return m_pyImp == nullptr;
}

int PyRxObject::implRefCount()
{
    return m_pyImp.use_count();
}

void PyRxObject::copyFrom(PyRxObject& obj)
{
    PyThrowBadEs(impObj()->copyFrom(obj.impObj()));
}

PyRxObject PyRxObject::queryX(const PyRxClass& protocolClass) const
{
    AcRxObject* ptr = impObj()->queryX(protocolClass.impObj());
    if (ptr == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyRxObject(ptr, false, false);
}

PyRxClass PyRxObject::desc()
{
    return PyRxClass(AcRxObject::desc(), false);
}

std::string PyRxObject::className()
{
    return "AcRxObject";
}

AcRxObject* PyRxObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PyRxClass Wrapper
void makeAcRxClassWrapper()
{
    PyDocString DS("RxClass");
    class_<PyRxClass, bases<PyRxObject>>("RxClass", boost::python::no_init)
        .def("isDerivedFrom", &PyRxClass::isDerivedFrom, DS.ARGS({ "other : PyRx.RxClass" }))
        .def("appName", &PyRxClass::appName, DS.ARGS())
        .def("dxfName", &PyRxClass::dxfName, DS.ARGS())
        .def("name", &PyRxClass::name, DS.ARGS())
        .def("queryX", &PyRxObject::queryX, DS.ARGS({ "rhs :  PyRx.RxClass" }))
        .def("desc", &PyRxClass::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyRxClass::className, DS.SARGS()).staticmethod("className")
        ;
}

//-----------------------------------------------------------------------------------------
//PrRxClass
PyRxClass::PyRxClass(AcRxClass* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

bool PyRxClass::isDerivedFrom(const PyRxClass& other) const
{
    return impObj()->isDerivedFrom(other.impObj());
}

std::string PyRxClass::name()
{
    return wstr_to_utf8(impObj()->name());
}

std::string PyRxClass::appName() const
{
    return wstr_to_utf8(impObj()->appName());
}

std::string PyRxClass::dxfName() const
{
    return wstr_to_utf8(impObj()->dxfName());
}

PyRxObject PyRxClass::queryX(const PyRxClass& protocolClass) const
{
    AcRxObject* ptr = impObj()->queryX(protocolClass.impObj());
    if (ptr == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyRxObject(ptr, false, false);
}

PyRxClass PyRxClass::desc()
{
    return PyRxClass(AcRxClass::desc(), false);
}

std::string PyRxClass::className()
{
    return std::string{ "AcRxClass" };
}

AcRxClass* PyRxClass::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcRxClass*>(m_pyImp.get());
}
