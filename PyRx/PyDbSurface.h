#pragma once

#include "PyDbEntity.h"

class PyDbObjectId;
class AcDbLoftedSurface;
class AcDbPlaneSurface;

//----------------------------------------------------------------------
//PyDbSurface
void makePyDbSurfaceWrapper();

class PyDbSurface : public PyDbEntity
{
public:
    PyDbSurface();
    PyDbSurface(AcDbSurface* ptr, bool autoDelete);
    PyDbSurface(const PyDbObjectId& id);
    PyDbSurface(const PyDbObjectId& id, AcDb::OpenMode mode);

    boost::python::list     projectOnToSurface(const PyDbEntity& ent, const AcGeVector3d& projectionDirection);
    static std::string      className();
    static PyRxClass        desc();
    static PyDbSurface		cloneFrom(const PyRxObject& src);
    static PyDbSurface      cast(const PyRxObject& src);
public:
    AcDbSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------
//AcDbExtrudedSurface
void makePyDbExtrudedSurfaceWrapper();

class PyDbExtrudedSurface : public PyDbSurface
{
public:
    PyDbExtrudedSurface();
    PyDbExtrudedSurface(AcDbExtrudedSurface* ptr, bool autoDelete);
    PyDbExtrudedSurface(const PyDbObjectId& id);
    PyDbExtrudedSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbExtrudedSurface cloneFrom(const PyRxObject& src);
    static PyDbExtrudedSurface cast(const PyRxObject& src);
public:
    AcDbExtrudedSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------
//AcDbLoftedSurface 
void makePyDbLoftedSurfaceWrapper();
class PyDbLoftedSurface : public PyDbSurface
{
public:
    PyDbLoftedSurface();
    PyDbLoftedSurface(AcDbLoftedSurface* ptr, bool autoDelete);
    PyDbLoftedSurface(const PyDbObjectId& id);
    PyDbLoftedSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbLoftedSurface cloneFrom(const PyRxObject& src);
    static PyDbLoftedSurface cast(const PyRxObject& src);
public:
    AcDbLoftedSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------
//PyDbNurbSurface 
void makePyDbNurbSurfaceWrapper();

class PyDbNurbSurface : public PyDbSurface
{
public:
    PyDbNurbSurface();
    PyDbNurbSurface(AcDbNurbSurface* ptr, bool autoDelete);
    PyDbNurbSurface(const PyDbObjectId& id);
    PyDbNurbSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbNurbSurface cloneFrom(const PyRxObject& src);
    static PyDbNurbSurface cast(const PyRxObject& src);
public:
    AcDbNurbSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};


//----------------------------------------------------------------------
//AcDbPlaneSurface  
void makePyDbPlaneSurfaceWrapper();

class PyDbPlaneSurface : public PyDbSurface
{
public:
    PyDbPlaneSurface();
    PyDbPlaneSurface(AcDbPlaneSurface* ptr, bool autoDelete);
    PyDbPlaneSurface(const PyDbObjectId& id);
    PyDbPlaneSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPlaneSurface cloneFrom(const PyRxObject& src);
    static PyDbPlaneSurface cast(const PyRxObject& src);
public:
    AcDbPlaneSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------
//PyDbRevolvedSurface  
void makePyDbRevolvedSurfaceWrapper();

class PyDbRevolvedSurface : public PyDbSurface
{
public:
    PyDbRevolvedSurface();
    PyDbRevolvedSurface(AcDbRevolvedSurface* ptr, bool autoDelete);
    PyDbRevolvedSurface(const PyDbObjectId& id);
    PyDbRevolvedSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRevolvedSurface cloneFrom(const PyRxObject& src);
    static PyDbRevolvedSurface cast(const PyRxObject& src);
public:
    AcDbRevolvedSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------
//AcDbSweptSurface  
void makePyDbSweptSurfaceWrapper();

class PyDbSweptSurface : public PyDbSurface
{
public:
    PyDbSweptSurface();
    PyDbSweptSurface(AcDbSweptSurface* ptr, bool autoDelete);
    PyDbSweptSurface(const PyDbObjectId& id);
    PyDbSweptSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSweptSurface cloneFrom(const PyRxObject& src);
    static PyDbSweptSurface cast(const PyRxObject& src);
public:
    AcDbSweptSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

