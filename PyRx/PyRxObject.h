#pragma once
class PyRxClass;

//-----------------------------------------------------------------------------------------
//PyRxObject
void makePyRxObjectWrapper();

class PyRxObject
{
public:
    PyRxObject(const AcRxObject* ptr);
    PyRxObject(AcRxObject* ptr, bool autoDelete, bool isDbObject);
    inline virtual ~PyRxObject() = default;
    bool operator==(const PyRxObject& rhs) const;
    bool operator!=(const PyRxObject& rhs) const;
    PyRxClass           isA() const;
    bool                isKindOf(const PyRxClass& aClass);
    void                forceKeepAlive(bool flag);
    void                dispose();
    bool                isNullObj();
    int                 implRefCount();
    void                copyFrom(PyRxObject& obj);
    PyRxObject          queryX(const PyRxClass& protocolClass) const;
    static PyRxClass    desc();
    static std::string  className();
public:
    inline AcRxObject* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<AcRxObject> m_pyImp;
};


//-----------------------------------------------------------------------------------------
//PyRxClass
void makePyRxClassWrapper();

class PyRxClass : public PyRxObject
{
public:
    PyRxClass(AcRxClass* ptr, bool autoDelete);
    virtual ~PyRxClass() override = default;
    bool                isDerivedFrom(const PyRxClass& other) const;
    std::string         name();
    std::string         appName() const;
    std::string         dxfName() const;
    PyRxObject          queryX(const PyRxClass& protocolClass) const;
    static PyRxClass    desc();
    static std::string  className();

public:
    inline AcRxClass* impObj(const std::source_location& src = std::source_location::current()) const;
};

