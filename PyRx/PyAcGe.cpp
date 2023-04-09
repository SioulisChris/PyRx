#include "stdafx.h"
#include "PyAcGe.h"

using namespace boost::python;


std::string AcGeVector3dToString(const AcGeVector3d& p)
{
    return std::format("({},{},{})", p.x, p.y, p.z);
}

std::string AcGePoint3dToString(const AcGePoint3d& p)
{
    return std::format("({},{},{})", p.x, p.y, p.z);
}


//---------------------------------------------------------------------------------------------------------------
//AcGePoint2d
std::string AcGePoint2dToString(const AcGePoint2d& p)
{
    return std::format("({},{})", p.x, p.y);
}

static AcGePoint2d AcGePoint2dkOrigin()
{
    return AcGePoint2d::kOrigin;
}

static void makeAcGePoint2dWrapper()
{
    static auto wrapper = class_<AcGePoint2d>("Point2d")
        .def(init<>())
        .def(init<const AcGePoint2d&>())
        .def(init<double, double>())

        .def("setToProduct", &AcGePoint2d::setToProduct, return_self<>())
        .def("transformBy", &AcGePoint2d::transformBy, return_self<>())
        .def("rotateBy", &AcGePoint2d::rotateBy, return_self<>())
        .def("mirror", &AcGePoint2d::mirror, return_self<>())
        .def("scaleBy", &AcGePoint2d::scaleBy, return_self<>())
        .def("setToSum", &AcGePoint2d::setToSum, return_self<>())
        .def("set", &AcGePoint2d::set, return_self<>())
        .def("asVector", &AcGePoint2d::asVector)
        .def("distanceTo", &AcGePoint2d::distanceTo)
        .def("isEqualTo", &AcGePoint2d::isEqualTo)

        .def_readwrite("x", &AcGePoint2d::x)
        .def_readwrite("y", &AcGePoint2d::y)
        .add_static_property("kOrigin", &AcGePoint2dkOrigin)

        //operators
        .def("__eq__", &AcGePoint2d::operator==)
        .def("__ne__", &AcGePoint2d::operator!=)

        .def<AcGePoint2d(AcGePoint2d::*)(double)const>("__mul__", &AcGePoint2d::operator*)
        .def<AcGePoint2d& (AcGePoint2d::*)(double)>("__imul__", &AcGePoint2d::operator*=, return_self<>())

        .def<AcGePoint2d(AcGePoint2d::*)(double)const>("__truediv__", &AcGePoint2d::operator/)
        .def<AcGePoint2d& (AcGePoint2d::*)(double)>("__itruediv__", &AcGePoint2d::operator/=, return_self<>())

        .def<AcGePoint2d(AcGePoint2d::*)(const AcGeVector2d&)const>("__add__", &AcGePoint2d::operator+)
        .def<AcGePoint2d& (AcGePoint2d::*)(const AcGeVector2d&)>("__iadd__", &AcGePoint2d::operator+=, return_self<>())

        .def<AcGePoint2d(AcGePoint2d::*)(const AcGeVector2d&)const>("__sub__", &AcGePoint2d::operator-)
        .def<AcGePoint2d& (AcGePoint2d::*)(const AcGeVector2d&)>("__isub__", &AcGePoint2d::operator-=, return_self<>())

        .def("toString", &AcGePoint2dToString)
        .def("__str__", &AcGePoint2dToString)
        ;
}

//---------------------------------------------------------------------------------------------------------------
//AcGeVector2d
std::string AcGeVector2ToString(const AcGeVector2d& p)
{
    return std::format("({},{})", p.x, p.y);
}

static AcGeVector2d AcGeVector2dkIdentity()
{
    return AcGeVector2d::kIdentity;
}

static AcGeVector2d AcGeVector2dkXAxis()
{
    return AcGeVector2d::kXAxis;
}

static AcGeVector2d AcGeVector2dkYAxis()
{
    return AcGeVector2d::kYAxis;
}

static AcGeVector2d acGeVector2dMulOperatorDouble(const double scl, const AcGeVector2d& vec)
{
    return vec * scl;
}

static AcGeVector2d acGeVector2dMulOperatorAcGeMatrix2d(const AcGeVector2d& vec, const AcGeMatrix2d& mat)
{
    return mat * vec;
}

static void makeAcGeVector2dWrapper()
{
    static auto wrapper = class_<AcGeVector2d>("Vector2d")
        .def(init<>())
        .def(init<const AcGeVector2d&>())
        .def(init<double, double>())
        .def_readwrite("x", &AcGeVector2d::x)
        .def_readwrite("y", &AcGeVector2d::y)

        .add_static_property("kIdentity", &AcGeVector2dkIdentity)
        .add_static_property("kXAxis", &AcGeVector2dkXAxis)
        .add_static_property("kYAxis", &AcGeVector2dkYAxis)

        .def<AcGeVector2d& (AcGeVector2d::*)(const AcGeVector2d&, double)>("setToProduct", &AcGeVector2d::setToProduct, return_self<>())
        .def<AcGeVector2d& (AcGeVector2d::*)(const AcGeMatrix2d&, const AcGeVector2d&)>("setToProduct", &AcGeVector2d::setToProduct, return_self<>())

        .def("transformBy", &AcGeVector2d::transformBy, return_self<>())
        .def("rotateBy", &AcGeVector2d::rotateBy, return_self<>())
        .def("mirror", &AcGeVector2d::mirror, return_self<>())
        .def("setToSum", &AcGeVector2d::setToSum, return_self<>())
        .def("negate", &AcGeVector2d::negate, return_self<>())

        .def("angle", &AcGeVector2d::angle)
        .def("angleTo", &AcGeVector2d::angleTo)
        .def("normal", &AcGeVector2d::normal)

        .def<AcGeVector2d& (AcGeVector2d::*)(const AcGeTol&)>("normalize", &AcGeVector2d::normalize, return_self<>())

        .def("length", &AcGeVector2d::length)
        .def("lengthSqrd", &AcGeVector2d::lengthSqrd)
        .def("isUnitLength", &AcGeVector2d::isUnitLength)
        .def("isZeroLength", &AcGeVector2d::isZeroLength)

        .def<Adesk::Boolean(AcGeVector2d::*)(const AcGeVector2d&, const AcGeTol&)const>("isParallelTo", &AcGeVector2d::isParallelTo)
        .def<Adesk::Boolean(AcGeVector2d::*)(const AcGeVector2d&, const AcGeTol&)const>("isCodirectionalTo", &AcGeVector2d::isCodirectionalTo)
        .def<Adesk::Boolean(AcGeVector2d::*)(const AcGeVector2d&, const AcGeTol&)const>("isPerpendicularTo", &AcGeVector2d::isPerpendicularTo)

        .def("dotProduct", &AcGeVector2d::dotProduct)
        .def("isEqualTo", &AcGeVector2d::isEqualTo)
        .def("set", &AcGeVector2d::set, return_self<>())

        //operators
        .def("__eq__", &AcGeVector2d::operator==)
        .def("__ne__", &AcGeVector2d::operator!=)


        .def<AcGeVector2d(AcGeVector2d::*)(double) const>("__mul__", &AcGeVector2d::operator*)
        .def<AcGeVector2d& (AcGeVector2d::*)(double)>("__imul__", &AcGeVector2d::operator*=, return_self<>())

        .def("__mul__", &acGeVector2dMulOperatorDouble)
        .def("__mul__", &acGeVector2dMulOperatorAcGeMatrix2d)
        .def("__matmul__", &acGeVector2dMulOperatorAcGeMatrix2d)

        .def<AcGeVector2d(AcGeVector2d::*)(double)const>("__truediv__", &AcGeVector2d::operator/)
        .def<AcGeVector2d& (AcGeVector2d::*)(double)>("__itruediv__", &AcGeVector2d::operator/=, return_self<>())

        .def<AcGeVector2d(AcGeVector2d::*)(const AcGeVector2d&)const>("__add__", &AcGeVector2d::operator+)
        .def<AcGeVector2d& (AcGeVector2d::*)(const AcGeVector2d&)>("__iadd__", &AcGeVector2d::operator+=, return_self<>())

        .def<AcGeVector2d(AcGeVector2d::*)()const>("__sub__", &AcGeVector2d::operator-)
        .def<AcGeVector2d(AcGeVector2d::*)(const AcGeVector2d&)const>("__sub__", &AcGeVector2d::operator-)
        .def<AcGeVector2d& (AcGeVector2d::*)(const AcGeVector2d&)>("__isub__", &AcGeVector2d::operator-=, return_self<>())

        .def("toString", &AcGeVector2ToString)
        .def("__str__", &AcGeVector2ToString)
        ;

    implicitly_convertible<AcGeVector2d, AcGeMatrix2d>();

}

//---------------------------------------------------------------------------------------------------------------
//AcGeMatrix2d
static AcGeMatrix2d AcGeMatrix2dkIdentity()
{
    return AcGeMatrix2d::kIdentity;
}

std::string AcGeMatrix2dToString(const AcGeMatrix2d& x)
{
    return  std::format("(({0},{1},{2}),({3},{4},{5}),({6},{7},{8}))",
        x.entry[0][0], x.entry[0][1], x.entry[0][2],
        x.entry[1][0], x.entry[1][1], x.entry[1][2],
        x.entry[2][0], x.entry[2][1], x.entry[2][2]);
}

static AcGeMatrix2d AcGeMatrix2dtranslation(const AcGeVector2d& vec)
{
    return AcGeMatrix2d::translation(vec);
}

static AcGeMatrix2d AcGeMatrix2drotation(double angle, const AcGePoint2d& center)
{
    return AcGeMatrix2d::rotation(angle, center);
}

static AcGeMatrix2d AcGeMatrix2scaling(double scaleAll, const AcGePoint2d& center)
{
    return AcGeMatrix2d::scaling(scaleAll, center);
}

static AcGeMatrix2d AcGeMatrix2mirroring(const AcGePoint2d& pnt)
{
    return AcGeMatrix2d::mirroring(pnt);
}

static AcGeMatrix2d AcGeMatrix2mirroring2(const AcGeLine2d& line)
{
    return AcGeMatrix2d::mirroring(line);
}

static AcGeMatrix2d AcGeMatrix2alignCoordSys
   (const AcGePoint2d& fromOrigin,
    const AcGeVector2d& fromE0,
    const AcGeVector2d& fromE1,
    const AcGePoint2d& toOrigin,
    const AcGeVector2d& toE0,
    const AcGeVector2d& toE1)
{
    return AcGeMatrix2d::alignCoordSys(fromOrigin, fromE0, fromE1, toOrigin, toE0, toE1);
}

static auto makeAcGeMatrix2dWrapper()
{
    static auto wrapper = class_<AcGeMatrix2d>("Matrix2d")

        .add_static_property("kIdentity", &AcGeMatrix2dkIdentity)
        .def("setToIdentity", &AcGeMatrix2d::setToIdentity, return_self<>())
        .def("preMultBy", &AcGeMatrix2d::preMultBy, return_self<>())
        .def("postMultBy", &AcGeMatrix2d::postMultBy, return_self<>())
        .def("setToProduct", &AcGeMatrix2d::setToProduct, return_self<>())
        .def("invert", &AcGeMatrix2d::invert, return_self<>())
        .def("inverse", &AcGeMatrix2d::inverse)
        .def("isSingular", &AcGeMatrix2d::isSingular)
        .def("transposeIt", &AcGeMatrix2d::transposeIt, return_self<>())
        .def("transpose", &AcGeMatrix2d::transpose)
        .def("isEqualTo", &AcGeMatrix2d::isEqualTo)
        .def("isUniScaledOrtho", &AcGeMatrix2d::isUniScaledOrtho)
        .def("isScaledOrtho", &AcGeMatrix2d::isScaledOrtho)
        .def("scale", &AcGeMatrix2d::scale)
        .def("det", &AcGeMatrix2d::det)
        .def("setTranslation", &AcGeMatrix2d::setTranslation, return_self<>())
        .def<AcGeVector2d(AcGeMatrix2d::*)(void)const>("translation", &AcGeMatrix2d::translation)
        .def("isConformal", &AcGeMatrix2d::isConformal)
        .def("setCoordSystem", &AcGeMatrix2d::setCoordSystem, return_self<>())
        .def("getCoordSystem", &AcGeMatrix2d::getCoordSystem)
        .def("setToTranslation", &AcGeMatrix2d::setToTranslation, return_self<>())
        .def("setToRotation", &AcGeMatrix2d::setToRotation, return_self<>())
        .def("setToScaling", &AcGeMatrix2d::setToScaling, return_self<>())
        .def<AcGeMatrix2d&(AcGeMatrix2d::*)(const AcGePoint2d&)>("setToMirroring", &AcGeMatrix2d::setToMirroring, return_self<>())
        .def<AcGeMatrix2d&(AcGeMatrix2d::*)(const AcGeLine2d&)>("setToMirroring", &AcGeMatrix2d::setToMirroring, return_self<>())
        .def("setToAlignCoordSys", &AcGeMatrix2d::setToAlignCoordSys, return_self<>())

        .def("translation", &AcGeMatrix2dtranslation).staticmethod("translation")
        .def("rotation", &AcGeMatrix2drotation).staticmethod("rotation")
        .def("scaling", &AcGeMatrix2scaling).staticmethod("scaling")
        .def("mirroring", &AcGeMatrix2mirroring).staticmethod("mirroring")
        .def("mirroring", &AcGeMatrix2mirroring2).staticmethod("mirroring")
        .def("alignCoordSys", &AcGeMatrix2alignCoordSys).staticmethod("alignCoordSys")
        .def<double(AcGeMatrix2d::*)(unsigned int, unsigned int)const>("elementAt", &AcGeMatrix2d::operator())

        .def("__eq__", &AcGeMatrix2d::operator==)
        .def("__ne__", &AcGeMatrix2d::operator!=)
        .def<AcGeMatrix2d(AcGeMatrix2d::*)(const AcGeMatrix2d&) const>("__mul__", &AcGeMatrix2d::operator*)
        .def<AcGeMatrix2d& (AcGeMatrix2d::*)(const AcGeMatrix2d&)>("__imul__", &AcGeMatrix2d::operator*=, return_self<>())
        .def<AcGeMatrix2d(AcGeMatrix2d::*)(const AcGeMatrix2d&) const>("__matmul__", &AcGeMatrix2d::operator*)
        .def<AcGeMatrix2d& (AcGeMatrix2d::*)(const AcGeMatrix2d&)>("__matmul__", &AcGeMatrix2d::operator*=, return_self<>())

        .def("toString", &AcGeMatrix2dToString)
        .def("__str__", &AcGeMatrix2dToString)
        ;
    return wrapper;
}


//---------------------------------------------------------------------------------------------------------------
//AcGePoint3d
static auto makeAcGePoint3dWrapper()
{
    static auto wrapper = class_<AcGePoint3d>("Point3d")
        .def(init<>())
        .def(init<double, double, double>())
        .def("distanceTo", &AcGePoint3d::distanceTo)
        .def("transformBy", &AcGePoint3d::transformBy, return_self<>())
        .def_readwrite("x", &AcGePoint3d::x)
        .def_readwrite("y", &AcGePoint3d::y)
        .def_readwrite("z", &AcGePoint3d::z)
        .def_readonly("kOrigin", &AcGePoint3d::kOrigin)
        .def("__eq__", &AcGePoint3d::operator==)
        .def("__ne__", &AcGePoint3d::operator!=)



        .def("toString", &AcGePoint3dToString)
        .def("__str__", &AcGePoint3dToString)
        ;
    return wrapper;
}

void makeAcGeTolWrapper()
{
    static auto wrapper = class_<AcGeTol>("GeTol")
        .def(init<>())
        .def_readonly("equalPoint", &AcGeTol::equalPoint)
        .def_readonly("equalVector", &AcGeTol::equalVector)
        .def_readonly("setEqualPoint", &AcGeTol::setEqualPoint)
        .def_readonly("setEqualVector", &AcGeTol::setEqualVector)
        ;
}

static auto makeAcGeVector3dWrapper()
{
    static auto wrapper = class_<AcGeVector3d>("Vector3d")
        .def(init<>())
        .def(init<double, double, double>())
        .def_readwrite("x", &AcGeVector3d::x)
        .def_readwrite("y", &AcGeVector3d::y)
        .def_readwrite("z", &AcGeVector3d::z)
        .def_readonly("kXAxis", &AcGeVector3d::kXAxis)
        .def_readonly("kYAxis", &AcGeVector3d::kYAxis)
        .def_readonly("kZAxis", &AcGeVector3d::kZAxis)
        .def("__eq__", &AcGeVector3d::operator==)
        .def("__ne__", &AcGeVector3d::operator!=)
        .def("toString", &AcGeVector3dToString)
        ;
    return wrapper;
}

static auto makeAcGeMatrix3dWrapper()
{
    static auto wrapper = class_<AcGeMatrix3d>("Matrix3d")
        .def("scale", &AcGeMatrix3d::scale)
        .def("setToScaling", &AcGeMatrix3d::setToScaling, return_self<>())
        .def("setToRotation", &AcGeMatrix3d::setToRotation, return_self<>())
        .def("__eq__", &AcGeMatrix3d::operator==)
        .def("__ne__", &AcGeMatrix3d::operator!=)
        ;
    return wrapper;
}

static auto makeAcGeScale3dWrapper()
{
    static auto wrapper = class_<AcGeScale3d>("Scale3d")
        .def_readwrite("sx", &AcGeScale3d::sx)
        .def_readwrite("sy", &AcGeScale3d::sy)
        .def_readwrite("sz", &AcGeScale3d::sz)
        .def("__eq__", &AcGeScale3d::operator==)
        .def("__ne__", &AcGeScale3d::operator!=)
        ;
    return wrapper;
}

static auto makeAcGeScale2dWrapper()
{
    static auto wrapper = class_<AcGeScale2d>("Scale2d")
        .def_readwrite("sx", &AcGeScale2d::sx)
        .def_readwrite("sy", &AcGeScale2d::sy)
        .def("__eq__", &AcGeScale2d::operator==)
        .def("__ne__", &AcGeScale2d::operator!=)
        ;
    return wrapper;
}

BOOST_PYTHON_MODULE(PyGe)
{
#ifndef  PyRxDebug
    docstring_options local_docstring_options(false, true, false);
#endif // ! PyRxDebug

    makeAcGeTolWrapper();
    makeAcGePoint2dWrapper();
    makeAcGeVector2dWrapper();
    makeAcGeMatrix2dWrapper();

    makeAcGePoint3dWrapper();
    makeAcGeVector3dWrapper();
    makeAcGeMatrix3dWrapper();

    makeAcGeScale3dWrapper();
    makeAcGeScale2dWrapper();

    enum_<AcGe::EntityId>("EntityId")
        .value("kEntity2d", AcGe::EntityId::kEntity2d)
        .value("kEntity3d", AcGe::EntityId::kEntity3d)
        .value("kPointEnt2d", AcGe::EntityId::kPointEnt2d)
        .value("kPointEnt3d", AcGe::EntityId::kPointEnt3d)
        .value("kPosition2d", AcGe::EntityId::kPosition2d)
        .value("kPosition3d", AcGe::EntityId::kPosition3d)
        .value("kPointOnCurve2d", AcGe::EntityId::kPointOnCurve2d)
        .value("kPointOnCurve3d", AcGe::EntityId::kPointOnCurve3d)
        .value("kPointOnSurface", AcGe::EntityId::kPointOnSurface)
        .value("kBoundedPlane", AcGe::EntityId::kBoundedPlane)
        .value("kCircArc2d", AcGe::EntityId::kCircArc2d)
        .value("kCircArc3d", AcGe::EntityId::kCircArc3d)
        .value("kConic2d", AcGe::EntityId::kConic2d)
        .value("kConic3d", AcGe::EntityId::kConic3d)
        .value("kCurve2d", AcGe::EntityId::kCurve2d)
        .value("kCurve3d", AcGe::EntityId::kCurve3d)
        .value("kEllipArc2d", AcGe::EntityId::kEllipArc2d)
        .value("kEllipArc3d", AcGe::EntityId::kEllipArc3d)
        .value("kLine2d", AcGe::EntityId::kLine2d)
        .value("kLine3d", AcGe::EntityId::kLine3d)
        .value("kLinearEnt2d", AcGe::EntityId::kLinearEnt2d)
        .value("kLinearEnt3d", AcGe::EntityId::kLinearEnt3d)
        .value("kLineSeg2d", AcGe::EntityId::kLineSeg2d)
        .value("kLineSeg3d", AcGe::EntityId::kLineSeg3d)
        .value("kPlanarEnt", AcGe::EntityId::kPlanarEnt)
        .value("kPlane", AcGe::EntityId::kPlane)
        .value("kRay2d", AcGe::EntityId::kRay2d)
        .value("kRay3d", AcGe::EntityId::kRay3d)
        .value("kSurface", AcGe::EntityId::kSurface)
        .value("kSphere", AcGe::EntityId::kSphere)
        .value("kCylinder", AcGe::EntityId::kCylinder)
        .value("kTorus", AcGe::EntityId::kTorus)
        .value("kCone", AcGe::EntityId::kCone)
        .value("kSplineEnt2d", AcGe::EntityId::kSplineEnt2d)
        .value("kPolyline2d", AcGe::EntityId::kPolyline2d)
        .value("kAugPolyline2d", AcGe::EntityId::kAugPolyline2d)
        .value("kNurbCurve2d", AcGe::EntityId::kNurbCurve2d)
        .value("kDSpline2d", AcGe::EntityId::kDSpline2d)
        .value("kCubicSplineCurve2d", AcGe::EntityId::kCubicSplineCurve2d)
        .value("kSplineEnt3d", AcGe::EntityId::kSplineEnt3d)
        .value("kPolyline3d", AcGe::EntityId::kPolyline3d)
        .value("kAugPolyline3d", AcGe::EntityId::kAugPolyline3d)
        .value("kNurbCurve3d", AcGe::EntityId::kNurbCurve3d)
        .value("kDSpline3d", AcGe::EntityId::kDSpline3d)
        .value("kCubicSplineCurve3d", AcGe::EntityId::kCubicSplineCurve3d)
        .value("kTrimmedCrv2d", AcGe::EntityId::kTrimmedCrv2d)
        .value("kCompositeCrv2d", AcGe::EntityId::kCompositeCrv2d)
        .value("kCompositeCrv3d", AcGe::EntityId::kCompositeCrv3d)
        .value("kExternalSurface", AcGe::EntityId::kExternalSurface)
        .value("kNurbSurface", AcGe::EntityId::kNurbSurface)
        .value("kTrimmedSurface", AcGe::EntityId::kTrimmedSurface)
        .value("kOffsetSurface", AcGe::EntityId::kOffsetSurface)
        .value("kEnvelope2d", AcGe::EntityId::kEnvelope2d)
        .value("kCurveBoundedSurface", AcGe::EntityId::kCurveBoundedSurface)
        .value("kExternalCurve3d", AcGe::EntityId::kExternalCurve3d)
        .value("kExternalCurve2d", AcGe::EntityId::kExternalCurve2d)
        .value("kSurfaceCurve2dTo3d", AcGe::EntityId::kSurfaceCurve2dTo3d)
        .value("kSurfaceCurve3dTo2d", AcGe::EntityId::kSurfaceCurve3dTo2d)
        .value("kExternalBoundedSurface", AcGe::EntityId::kExternalBoundedSurface)
        .value("kCurveCurveInt2d", AcGe::EntityId::kCurveCurveInt2d)
        .value("kCurveCurveInt3d", AcGe::EntityId::kCurveCurveInt3d)
        .value("kBoundBlock2d", AcGe::EntityId::kBoundBlock2d)
        .value("kBoundBlock3d", AcGe::EntityId::kBoundBlock3d)
        .value("kOffsetCurve2d", AcGe::EntityId::kOffsetCurve2d)
        .value("kOffsetCurve3d", AcGe::EntityId::kOffsetCurve3d)
        .value("kPolynomCurve3d", AcGe::EntityId::kPolynomCurve3d)
        .value("kBezierCurve3d", AcGe::EntityId::kBezierCurve3d)
        .value("kObject", AcGe::EntityId::kObject)
        .value("kFitData3d", AcGe::EntityId::kFitData3d)
        .value("kHatch", AcGe::EntityId::kHatch)
        .value("kTrimmedCurve2d", AcGe::EntityId::kTrimmedCurve2d)
        .value("kTrimmedCurve3d", AcGe::EntityId::kTrimmedCurve3d)
        .value("kCurveSampleData", AcGe::EntityId::kCurveSampleData)
        .value("kEllipCone", AcGe::EntityId::kEllipCone)
        .value("kEllipCylinder", AcGe::EntityId::kEllipCylinder)
        .value("kIntervalBoundBlock", AcGe::EntityId::kIntervalBoundBlock)
        .value("kClipBoundary2d", AcGe::EntityId::kClipBoundary2d)
        .value("kExternalObject", AcGe::EntityId::kExternalObject)
        .value("kCurveSurfaceInt", AcGe::EntityId::kCurveSurfaceInt)
        .value("kSurfaceSurfaceInt", AcGe::EntityId::kSurfaceSurfaceInt)
#ifndef BRXAPP
        .value("Helix", AcGe::EntityId::kHelix)
#endif // !BRXAPP 
        ;
};

void initPyGeModule()
{
    PyImport_AppendInittab(PyGeNamespace, &PyInit_PyGe);
}
