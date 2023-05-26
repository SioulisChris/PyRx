#pragma once
#include "PyDbObject.h"


void makeAcDbSymbolTableRecordWrapper();

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
class PyDbSymbolTableRecord : public PyDbObject
{
public:
    PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete);
    PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbSymbolTableRecord() override = default;
    std::string         getName();
    Acad::ErrorStatus   setName(const std::string name);
    bool                isDependent() const;
    bool                isResolved() const;
    bool                isRenamable() const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSymbolTableRecord cloneFrom(const PyRxObject& src);
    static PyDbSymbolTableRecord cast(const PyRxObject& src);
public:
    AcDbSymbolTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbDimStyleTableRecord 
void makeAcDbDimStyleTableRecordWrapper();
class PyDbDimStyleTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbDimStyleTableRecord();
    PyDbDimStyleTableRecord(AcDbDimStyleTableRecord* ptr, bool autoDelete);
    PyDbDimStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
public:
    static std::string className();
    static PyRxClass desc();
    static PyDbSymbolTableRecord cloneFrom(const PyRxObject& src);
    static PyDbSymbolTableRecord cast(const PyRxObject& src);
public:
    AcDbDimStyleTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};