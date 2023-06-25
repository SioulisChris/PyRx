#include "stdafx.h"
#include "PyDb3dSolid.h"
#include "PyDbObjectId.h"


using namespace boost::python;

void makePyDb3dSolidWrapper()
{
    class_<PyDb3dSolid, bases<PyDbEntity>>("Solid3d")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("createBox", &PyDb3dSolid::createBox)
        .def("createFrustum", &PyDb3dSolid::createFrustum)
        .def("createSphere", &PyDb3dSolid::createSphere)
        .def("createTorus", &PyDb3dSolid::createTorus)
        .def("createPyramid", &PyDb3dSolid::createPyramid1)
        .def("createPyramid", &PyDb3dSolid::createPyramid2)
        .def("createWedge", &PyDb3dSolid::createWedge)
        .def("className", &PyDb3dSolid::className).staticmethod("className")
        .def("desc", &PyDb3dSolid::desc).staticmethod("desc")
        .def("cloneFrom", &PyDb3dSolid::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDb3dSolid::cast).staticmethod("cast")
        ;
}

PyDb3dSolid::PyDb3dSolid(AcDb3dSolid* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDb3dSolid::PyDb3dSolid()
    : PyDbEntity(new AcDb3dSolid(), true)
{
}

PyDb3dSolid::PyDb3dSolid(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDb3dSolid* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb3dSolid>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDb3dSolid::PyDb3dSolid(const PyDbObjectId& id)
    : PyDb3dSolid(id, AcDb::OpenMode::kForRead)
{
}

Acad::ErrorStatus PyDb3dSolid::createBox(double xLen, double yLen, double zLen)
{
    return impObj()->createBox(xLen, yLen, zLen);
}

Acad::ErrorStatus PyDb3dSolid::createFrustum(double height, double xRadius, double yRadius, double topXRadius)
{
    return impObj()->createFrustum(height, xRadius, yRadius, topXRadius);
}

Acad::ErrorStatus PyDb3dSolid::createSphere(double radius)
{
    return impObj()->createSphere(radius);
}

Acad::ErrorStatus PyDb3dSolid::createTorus(double majorRadius, double minorRadius)
{
    return impObj()->createTorus(majorRadius, minorRadius);
}

Acad::ErrorStatus PyDb3dSolid::createPyramid1(double height, int sides, double radius)
{
    return impObj()->createPyramid(height, sides, radius);
}

Acad::ErrorStatus PyDb3dSolid::createPyramid2(double height, int sides, double radius, double topRadius)
{
    return impObj()->createPyramid(height, sides, radius, topRadius);
}

Acad::ErrorStatus PyDb3dSolid::createWedge(double xLen, double yLen, double zLen)
{
    return impObj()->createWedge(xLen, yLen, zLen);
}

std::string PyDb3dSolid::className()
{
    return "AcDb3dSolid";
}

PyRxClass PyDb3dSolid::desc()
{
    return PyRxClass(AcDb3dSolid::desc(), false);
}

PyDb3dSolid PyDb3dSolid::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDb3dSolid::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDb3dSolid(static_cast<AcDb3dSolid*>(src.impObj()->clone()), true);
}

PyDb3dSolid PyDb3dSolid::cast(const PyRxObject& src)
{
    PyDb3dSolid dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDb3dSolid* PyDb3dSolid::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDb3dSolid*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyDbRegion
void makePyDbRegionWrapper()
{
    class_<PyDbRegion, bases<PyDbEntity>>("Region")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRegion::className).staticmethod("className")
        .def("desc", &PyDbRegion::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRegion::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRegion::cast).staticmethod("cast")
        ;
}

PyDbRegion::PyDbRegion()
    : PyDbEntity(new AcDbRegion(), true)
{
}

PyDbRegion::PyDbRegion(AcDbRegion* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbRegion::PyDbRegion(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbRegion* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbRegion>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbRegion::PyDbRegion(const PyDbObjectId& id)
    : PyDbRegion(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbRegion::className()
{
    return "AcDbRegion";
}

PyRxClass PyDbRegion::desc()
{
    return PyRxClass(AcDbRegion::desc(), false);
}

PyDbRegion PyDbRegion::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRegion::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRegion(static_cast<AcDbRegion*>(src.impObj()->clone()), true);
}

PyDbRegion PyDbRegion::cast(const PyRxObject& src)
{
    PyDbRegion dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRegion* PyDbRegion::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbRegion*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbBody
void makeAcDbBodyWrapper()
{
    class_<PyDbBody, bases<PyDbEntity>>("Body")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBody::className).staticmethod("className")
        .def("desc", &PyDbBody::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbBody::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbBody::cast).staticmethod("cast")
        ;
}

PyDbBody::PyDbBody()
    : PyDbEntity(new AcDbBody(), true)
{
}

PyDbBody::PyDbBody(AcDbBody* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbBody::PyDbBody(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbBody* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbBody>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbBody::PyDbBody(const PyDbObjectId& id)
    : PyDbBody(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbBody::className()
{
    return "AcDbBody";
}

PyRxClass PyDbBody::desc()
{
    return PyRxClass(AcDbBody::desc(), false);
}

PyDbBody PyDbBody::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbBody::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbBody(static_cast<AcDbBody*>(src.impObj()->clone()), true);
}

PyDbBody PyDbBody::cast(const PyRxObject& src)
{
    PyDbBody dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbBody* PyDbBody::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbBody*>(m_pyImp.get());
}
