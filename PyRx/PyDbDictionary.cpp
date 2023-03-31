#include "stdafx.h"
#include "PyDbDictionary.h"
#include "PyDbObjectId.h"


using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//PyDbDictionary wrapper
void makeAcDbDictionaryWrapper()
{
    static auto wrapper = class_<PyDbDictionary, bases<PyDbObject>>("DbDictionary", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getAt", &PyDbDictionary::getAt)
        .def("has", &PyDbDictionary::has)
        .def("keyValuePairs", &PyDbDictionary::keyValuePairs)
        ;
}
//---------------------------------------------------------------------------------------- -
//PyDbDictionary
PyDbDictionary::PyDbDictionary(AcDbDictionary* ptr, bool autoDelete)
: PyDbObject(ptr, autoDelete)
{

}

PyDbDictionary::PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, true)
{
    AcDbDictionary* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbDictionary>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObjectId PyDbDictionary::getAt(const std::string& entryName)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbObjectId id;
    imp->getAt(utf8_to_wstr(entryName).c_str(), id);
    return PyDbObjectId(id);
}

bool PyDbDictionary::has(const std::string& entryName)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->has(utf8_to_wstr(entryName).c_str());
}

boost::python::list PyDbDictionary::keyValuePairs()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list _items;
    for (std::unique_ptr<AcDbDictionaryIterator> iter(imp->newIterator()); !iter->done(); iter->next())
        _items.append(boost::python::make_tuple(wstr_to_utf8(iter->name()), PyDbObjectId(iter->objectId())));
    return _items;
}

AcDbDictionary* PyDbDictionary::impObj() const
{
    return static_cast<AcDbDictionary*>(m_pImp);
}
