#include "stdafx.h"
#include "PyDbSymbolTableRecord.h"
#include "PyDbObjectId.h"

using namespace boost::python;
//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord  wrapper
void makeAcDbSymbolTableRecordWrapper()
{
    class_<PyDbSymbolTableRecord, bases<PyDbObject>>("SymbolTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbSymbolTableRecord::className).staticmethod("className")
        .def("getName", &PyDbSymbolTableRecord::getName)
        .def("setName", &PyDbSymbolTableRecord::setName)
        .def("isDependent", &PyDbSymbolTableRecord::isDependent)
        .def("isResolved", &PyDbSymbolTableRecord::isResolved)
        .def("isRenamable", &PyDbSymbolTableRecord::isRenamable)
        ;
}

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
PyDbSymbolTableRecord::PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbSymbolTableRecord::PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbSymbolTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbSymbolTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbSymbolTableRecord::getName()
{
    AcString arxName;
    auto imp = impObj();
    if (imp != nullptr)
        imp->getName(arxName);
    return wstr_to_utf8(arxName);
}

Acad::ErrorStatus PyDbSymbolTableRecord::setName(const std::string name)
{
    auto imp = impObj();
    if (imp != nullptr)
        return  imp->setName(utf8_to_wstr(name).c_str());
    throw PyNullObject();
}

bool PyDbSymbolTableRecord::isDependent() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isDependent();
    throw PyNullObject();
}

bool PyDbSymbolTableRecord::isResolved() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isResolved();
    throw PyNullObject();
}

bool PyDbSymbolTableRecord::isRenamable() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isRenamable();
    throw PyNullObject();
#endif
}

std::string PyDbSymbolTableRecord::className()
{
    return "AcDbSymbolTableRecord";
}

AcDbSymbolTableRecord* PyDbSymbolTableRecord::impObj() const
{
    return static_cast<AcDbSymbolTableRecord*>(m_pImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbDimStyleTableRecord 
void makeAcDbDimStyleTableRecordWrapper()
{
    class_<PyDbDimStyleTableRecord, bases<PyDbSymbolTableRecord>>("DimStyleTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbDimStyleTableRecord::className).staticmethod("className")
        ;
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord()
    : PyDbSymbolTableRecord(new AcDbDimStyleTableRecord(),true)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(AcDbDimStyleTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(nullptr, false)
{
    AcDbDimStyleTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbDimStyleTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbDimStyleTableRecord::className()
{
    return "AcDbDimStyleTableRecord";
}

AcDbDimStyleTableRecord* PyDbDimStyleTableRecord::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbDimStyleTableRecord*>(m_pImp.get());
}
