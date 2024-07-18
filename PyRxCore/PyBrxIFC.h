#pragma once

#ifdef BRXAPP
#include "IfcDefs.h"

//---------------------------------------------------------------------------------------- -
//PyIFCGuid
void makePyIFCGuidWrapper();
class PyIFCGuid
{
public:
    PyIFCGuid();
    PyIFCGuid(Ice::IfcApi::Guid* pObject, bool autoDelete);
    ~PyIFCGuid() = default;

    static std::string      className();
public:
    Ice::IfcApi::Guid*      impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Guid> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCString
void makePyIFCStringWrapper();
class PyIFCString
{
public:
    PyIFCString();
    PyIFCString(Ice::IfcApi::String* pObject, bool autoDelete);
    ~PyIFCString() = default;

    static std::string  className();
public:
    Ice::IfcApi::String*  impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::String> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCBinary
void makePyIFCBinaryWrapper();
class PyIFCBinary
{
public:
    PyIFCBinary();
    PyIFCBinary(Ice::IfcApi::Binary* pObject, bool autoDelete);
    ~PyIFCBinary() = default;

    static std::string  className();
public:
    Ice::IfcApi::Binary* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Binary> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCLogical
void makePyIFCLogicalWrapper();
class PyIFCLogical
{
public:
    PyIFCLogical();
    PyIFCLogical(Ice::IfcApi::Logical* pObject, bool autoDelete);
    ~PyIFCLogical() = default;

    static std::string  className();
public:
    Ice::IfcApi::Logical* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Logical> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCVectorDesc
void makePyIFCVectorDescWrapper();
class PyIFCVectorDesc
{
public:
    PyIFCVectorDesc();
    PyIFCVectorDesc(Ice::IfcApi::VectorDesc* pObject, bool autoDelete);
    ~PyIFCVectorDesc() = default;

    static std::string  className();
public:
    Ice::IfcApi::VectorDesc* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::VectorDesc> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCVectorValue
void makePyIFCVectorValueWrapper();
class PyIFCVectorValue
{
public:
    PyIFCVectorValue(const Ice::IfcApi::VectorValue& src);
    PyIFCVectorValue(Ice::IfcApi::VectorValue* pObject, bool autoDelete);
    ~PyIFCVectorValue() = default;

    static std::string  className();
public:
    Ice::IfcApi::VectorValue* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::VectorValue> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCSelectorDesc
void makePyIFCSelectorDescWrapper();
class PyIFCSelectorDesc
{
public:
    PyIFCSelectorDesc();
    PyIFCSelectorDesc(Ice::IfcApi::SelectorDesc* pObject, bool autoDelete);
    ~PyIFCSelectorDesc() = default;

    static std::string  className();
public:
    Ice::IfcApi::SelectorDesc* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::SelectorDesc> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCSelectValue
void makePyIFCSelectValueWrapper();
class PyIFCSelectValue
{
public:
    PyIFCSelectValue(const Ice::IfcApi::SelectValue& src);
    PyIFCSelectValue(Ice::IfcApi::SelectValue* pObject, bool autoDelete);
    ~PyIFCSelectValue() = default;

    static std::string  className();
public:
    Ice::IfcApi::SelectValue* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::SelectValue> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCEnumValue
void makePyIFCEnumValueWrapper();
class PyIFCEnumValue
{
public:
    PyIFCEnumValue(const Ice::IfcApi::EnumValue& src);
    PyIFCEnumValue(Ice::IfcApi::EnumValue* pObject, bool autoDelete);
    ~PyIFCEnumValue() = default;

    static std::string  className();
public:
    Ice::IfcApi::EnumValue* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::EnumValue> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCEntityDesc
void makePyIFCEntityDescWrapper();
class PyIFCEntityDesc
{
public:
    PyIFCEntityDesc();
    PyIFCEntityDesc(Ice::IfcApi::EntityDesc* pObject, bool autoDelete);
    ~PyIFCEntityDesc() = default;

    static std::string  className();
public:
    Ice::IfcApi::EntityDesc* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::EntityDesc> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCEntity
void makePyIFCEntityWrapper();
class PyIFCEntity
{
public:
    PyIFCEntity(const Ice::IfcApi::Entity& src);
    PyIFCEntity(Ice::IfcApi::Entity* pObject, bool autoDelete);
    ~PyIFCEntity() = default;

    static std::string  className();
public:
    Ice::IfcApi::Entity* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Entity> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCHeader
void makePyIFCHeaderWrapper();
class PyIFCHeader
{
public:
    PyIFCHeader();
    PyIFCHeader(Ice::IfcApi::Header* pObject, bool autoDelete);
    ~PyIFCHeader() = default;

    static std::string  className();
public:
    Ice::IfcApi::Header* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Header> m_pyImp;
};


//---------------------------------------------------------------------------------------- -
//PyIFCModel
void makePyIFCModelWrapper();
class PyIFCModel
{
public:

    PyIFCModel(Ice::IfcApi::Model* pObject, bool autoDelete);
    ~PyIFCModel() = default;

    static std::string  className();
public:
    Ice::IfcApi::Model* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Model> m_pyImp;
};


#endif