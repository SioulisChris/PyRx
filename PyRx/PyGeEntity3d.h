#pragma once
class  PyGePlane;

//-----------------------------------------------------------------------------------------
//PyGeEntity3d wrapper
void makePyGeEntity3dWrapper();
class PyGeEntity3d
{
protected:
    PyGeEntity3d() = default;
public:
    PyGeEntity3d(const AcGeEntity3d* pEnt);
    PyGeEntity3d(AcGeEntity3d* pEnt, bool autoDelete = true);
    ~PyGeEntity3d() = default;
    bool operator==(PyGeEntity3d const& rhs) const;
    bool operator!=(PyGeEntity3d const& rhs) const;
    Adesk::Boolean  isKindOf(AcGe::EntityId entType) const;
    AcGe::EntityId  type() const;
    PyGeEntity3d    copy() const;
    Adesk::Boolean  isEqualTo1(const PyGeEntity3d& ent) const;
    Adesk::Boolean  isEqualTo2(const PyGeEntity3d& ent, const AcGeTol& tol) const;
    void            transformBy(const AcGeMatrix3d& xfm);
    void            translateBy(const AcGeVector3d& translateVec);
    void            rotateBy1(double angle, const AcGeVector3d& vec);
    void            rotateBy2(double angle, const AcGeVector3d& vec, const AcGePoint3d& wrtPoint);
    void            mirror(const PyGePlane& plane);
    void            scaleBy1(double scaleFactor);
    void            scaleBy2(double scaleFactor, const AcGePoint3d& wrtPoint);
    Adesk::Boolean  isOn1(const AcGePoint3d& pnt) const;
    Adesk::Boolean  isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    bool            isNull()const;
    static std::string className();
public:
    AcGeEntity3d* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcGeEntity3d> m_imp;
};

inline AcGeVoidPointerArray PyListToGeVoidPointerArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<PyGeEntity3d>(iterable);
    AcGeVoidPointerArray arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item.impObj());
    return arr;
}