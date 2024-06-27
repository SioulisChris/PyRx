#pragma once

#if defined(_ARXTARGET) || defined(_BRXTARGET) 

#if defined(_BRXTARGET240)
#import "axbricscaddb1.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "axbricscadsm.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET240)
#import "axdb24enu.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "acsmcomponents24.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET250)
#import "axdb25enu.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "acsmcomponents25.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

class PySmDatabaseImpl;
class PySmObjectIdImpl;

//-----------------------------------------------------------------------------------------
//PySmPersist
class PySmPersistImpl
{
public:
    PySmPersistImpl(IAcSmPersist* other);
    PySmPersistImpl(const PySmPersistImpl& other) = default;
    virtual ~PySmPersistImpl() = default;

    bool                GetIsDirty() const;
    CString             GetTypeName() const;
    void                InitNew(const PySmPersistImpl& owner);
    PySmPersistImpl     GetOwner() const;
    void                SetOwner(const PySmPersistImpl& owner);
    PySmDatabaseImpl    GetDatabase() const;
    PySmObjectIdImpl    GetObjectId() const;
    void                Clear();
    void                swap(PySmPersistImpl& other);

public:
    IAcSmPersist*       impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmPersistPtr     m_pimpl;
};

//-----------------------------------------------------------------------------------------
//IAcSmObjectId
class PySmObjectIdImpl
{
public:
    PySmObjectIdImpl(IAcSmObjectId* other);
    PySmObjectIdImpl(const PySmObjectIdImpl& other) = default;
    virtual ~PySmObjectIdImpl() = default;
    CString             GetHandle() const;
    PySmDatabaseImpl    GetDatabase() const;
    PySmPersistImpl     GetPersistObject() const;
    PySmPersistImpl     GetOwner() const;
    bool                IsEqual(const PySmObjectIdImpl& other);
    bool                IsValid();
public:
    IAcSmObjectId*      impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmObjectIdPtr m_pimpl;
};

//-----------------------------------------------------------------------------------------
//PySmFileReference
class PySmFileReferenceImpl : public PySmPersistImpl
{
public:
    explicit PySmFileReferenceImpl(IAcSmFileReference* other);
    explicit PySmFileReferenceImpl(const PySmFileReferenceImpl& other) = default;
    virtual ~PySmFileReferenceImpl() override = default;
    void        SetFileName(const CString& csVal);
    CString     GetFileName() const;
    CString     ResolveFileName() const;
    IAcSmFileReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyValue
class PySmCustomPropertyValueImpl : public PySmPersistImpl
{
public:
    PySmCustomPropertyValueImpl();
    PySmCustomPropertyValueImpl(IAcSmCustomPropertyValue* other);
    PySmCustomPropertyValueImpl(const PySmCustomPropertyValueImpl& other) = default;
    virtual ~PySmCustomPropertyValueImpl() override = default;
    AcValue         GetValue() const;
    void            SetValue(const AcValue& acVal);
    PropertyFlags   GetFlags() const;
    void            SetFlags(PropertyFlags flags);
    IAcSmCustomPropertyValue* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyBag
class PySmCustomPropertyBagImpl : public PySmPersistImpl
{
public:
    explicit PySmCustomPropertyBagImpl(IAcSmCustomPropertyBag* other);
    explicit PySmCustomPropertyBagImpl(const PySmCustomPropertyBagImpl& other) = default;
    virtual ~PySmCustomPropertyBagImpl() override = default;

    PySmCustomPropertyValueImpl GetProperty(const CString& propName) const;
    void                        SetProperty(const CString& propName, const PySmCustomPropertyValueImpl& prop);
    std::vector<std::pair<CString, PySmCustomPropertyValueImpl>> GetProperties() const;
    std::vector<std::pair<CString, AcValue>> GetPropertyValues() const;
    IAcSmCustomPropertyBag* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PySmObjectReference
class PySmObjectReferenceImpl : public PySmPersistImpl
{
public:
    explicit PySmObjectReferenceImpl(IAcSmObjectReference* other);
    explicit PySmObjectReferenceImpl(const PySmObjectReferenceImpl& other) = default;
    virtual ~PySmObjectReferenceImpl() override = default;
    IAcSmObjectReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocation
class PySmProjectPointLocationImpl : public PySmPersistImpl
{
public:
    explicit PySmProjectPointLocationImpl(IAcSmProjectPointLocation* other);
    explicit PySmProjectPointLocationImpl(const PySmProjectPointLocationImpl& other) = default;
    virtual ~PySmProjectPointLocationImpl() override = default;
    IAcSmProjectPointLocation* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmPersistProxy
class PySmPersistProxyImpl : public PySmPersistImpl
{
public:
    explicit PySmPersistProxyImpl(IAcSmPersistProxy* other);
    explicit PySmPersistProxyImpl(const PySmPersistProxyImpl& other) = default;
    virtual ~PySmPersistProxyImpl() override = default;
    IAcSmPersistProxy* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmPublishOption
class PySmPublishOptionImpl : public PySmPersistImpl
{
public:
    explicit PySmPublishOptionImpl(IAcSmPublishOptions* other);
    explicit PySmPublishOptionImpl(const PySmPublishOptionImpl& other) = default;
    virtual ~PySmPublishOptionImpl() override = default;
    IAcSmPublishOptions* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmComponent
class PySmComponentImpl : public PySmPersistImpl
{
public:
    explicit PySmComponentImpl(IAcSmComponent* other);
    explicit PySmComponentImpl(const PySmComponentImpl& other) = default;
    virtual ~PySmComponentImpl() override = default;
    CString         GetName() const;
    void            SetName(const CString& csName);
    CString         GetDesc() const;
    void            SetDesc(const CString& csDesc);
    PySmCustomPropertyBagImpl GetCustomPropertyBag() const;
    IAcSmComponent* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetSelSet
class PySmSheetSelSetImpl : public PySmComponentImpl
{
public:
    explicit PySmSheetSelSetImpl(IAcSmSheetSelSet* other);
    explicit PySmSheetSelSetImpl(const PySmSheetSelSetImpl& other) = default;
    virtual ~PySmSheetSelSetImpl() override = default;
    IAcSmSheetSelSet* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetSelSets
class PySmSheetSelSetsImpl : public PySmComponentImpl
{
public:
    explicit PySmSheetSelSetsImpl(IAcSmSheetSelSets* other);
    explicit PySmSheetSelSetsImpl(const PySmSheetSelSetsImpl& other) = default;
    virtual ~PySmSheetSelSetsImpl() override = default;
    IAcSmSheetSelSets* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSmResources
class PySmSmResourcesImpl : public PySmComponentImpl
{
public:
    explicit PySmSmResourcesImpl(IAcSmResources* other);
    explicit PySmSmResourcesImpl(const PySmSmResourcesImpl& other) = default;
    virtual ~PySmSmResourcesImpl() override = default;
    IAcSmResources* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetViews
class PySmSheetViewsImpl : public PySmComponentImpl
{
public:
    explicit PySmSheetViewsImpl(IAcSmSheetViews* other);
    explicit PySmSheetViewsImpl(const PySmSheetViewsImpl& other) = default;
    virtual ~PySmSheetViewsImpl() override = default;
    IAcSmSheetViews* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocations
class PySmProjectPointLocationsImpl : public PySmComponentImpl
{
public:
    explicit PySmProjectPointLocationsImpl(IAcSmProjectPointLocations* other);
    explicit PySmProjectPointLocationsImpl(const PySmProjectPointLocationsImpl& other) = default;
    virtual ~PySmProjectPointLocationsImpl() override = default;
    IAcSmProjectPointLocations* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmCalloutBlocks
class PySmCalloutBlocksImpl : public PySmComponentImpl
{
public:
    explicit PySmCalloutBlocksImpl(IAcSmCalloutBlocks* other);
    explicit PySmCalloutBlocksImpl(const PySmCalloutBlocksImpl& other) = default;
    virtual ~PySmCalloutBlocksImpl() override = default;
    IAcSmCalloutBlocks* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSubsetImpl
class PySmSubsetImpl : public PySmComponentImpl
{
public:
    explicit PySmSubsetImpl(IAcSmSubset* other);
    explicit PySmSubsetImpl(const PySmSubsetImpl& other) = default;
    virtual ~PySmSubsetImpl() override = default;
    IAcSmSubset* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetSet
class PySmSheetSetImpl : public PySmSubsetImpl
{
public:
    explicit PySmSheetSetImpl(IAcSmSheetSet* other);
    explicit PySmSheetSetImpl(const PySmSheetSetImpl& other) = default;
    virtual ~PySmSheetSetImpl() override = default;
    IAcSmSheetSet* impObj(const std::source_location& src = std::source_location::current()) const;
#if defined(_ARXTARGET)
    IAcSmSheetSet2* impObj2(const std::source_location& src = std::source_location::current()) const;
#endif

};

//-----------------------------------------------------------------------------------------
//PySmSheetImpl
class PySmSheetImpl : public PySmComponentImpl
{
public:
    explicit PySmSheetImpl(IAcSmSheet* other);
    explicit PySmSheetImpl(const PySmSheetImpl& other) = default;
    virtual ~PySmSheetImpl() override = default;

    CString     GetNumber() const;
    void        SetNumber(const CString& csVal);
    CString     GetTitle() const;
    void        SetTitle(const CString& csVal);

    bool        GetDoNotPlot() const;
    void        SetDoNotPlot(bool flag);
    //GetLayout
    //SetLayout
    //GetSheetViews

    CString     GetRevisionNumber() const;
    void        SetRevisionNumber(const CString& csVal);
    CString     GetRevisionDate() const;
    void        SetRevisionDate(const CString& csVal);
    CString     GetIssuePurpose() const;
    void        SetIssuePurpose(const CString& csVal);
    CString     GetCategory() const;
    void        SetCategory(const CString& csVal);

    IAcSmSheet* impObj(const std::source_location& src = std::source_location::current()) const;
#if defined(_ARXTARGET)
    IAcSmSheet2* impObj2(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//PySmComponent
class PySmDatabaseImpl : public PySmComponentImpl
{
public:
    explicit PySmDatabaseImpl(IAcSmDatabase* other);
    explicit PySmDatabaseImpl(const PySmDatabaseImpl& other) = default;
    virtual ~PySmDatabaseImpl() override = default;
    void                LoadFromFile(const CString& filename);
    CString             GetFileName() const;
    void                SetFileName(const CString& filename);
    CString             GetTemplateDstFileName() const;
    PySmSheetSetImpl    GetSheetSet() const;
    AcSmLockStatus      GetLockStatus() const;
    std::pair<CString, CString>     GetLockOwnerInfo() const;
    std::vector<PySmPersistImpl>    GetEnumerator() const;

    void                LockDb();
    void                UnlockDb(bool commit);
    IAcSmDatabase* impObj(const std::source_location& src = std::source_location::current()) const;
};

class PySmSheetSetMgrImpl
{
public:
    PySmSheetSetMgrImpl();
    PySmDatabaseImpl  CreateDatabase(const CString& filename);
    PySmDatabaseImpl  CreateDatabase(const CString& filename, const CString& templatefilename, bool bAlwaysCreate);
    PySmDatabaseImpl  OpenDatabase(const CString& filename);
    PySmDatabaseImpl  FindOpenDatabase(const CString& filename);
    void              CloseAll();
    void              Close(PySmDatabaseImpl& db);

    //int Register(IAcSmEvents eventHandler);
    //void Unregister(int cookie);

    std::pair<PySmDatabaseImpl, PySmSheetSetImpl> GetParentSheetSet(const CString& dwg, const CString& layout);
    std::pair<PySmDatabaseImpl, PySmSheetImpl>    GetSheetFromLayout(AcDbObject* pAcDbLayout);
    std::vector<PySmDatabaseImpl>                 GetDatabaseEnumerator();

public:
    IAcSmSheetSetMgr* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmSheetSetMgrPtr m_pimpl;
};

#endif

