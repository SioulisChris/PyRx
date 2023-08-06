#pragma once
#include "PyGiDrawable.h"
class PyDbEntity;
class PyDbObjectId;
class PyDbDatabase;
class PyDbField;
class PyDbHandle;
class PyDbObjectReactor;
class PyDbEntityReactor;
class PyDbSnoopDwgFiler;

//----------------------------------------------------------------------------------------
//PyDbObject
void makePyDbObjectWrapper();
class PyDbObject : public PyGiDrawable
{
protected:
    inline PyDbObject() = default;
public:
    PyDbObject(AcDbObject* ptr, bool autoDelete);
    PyDbObject(const PyDbObjectId&);
    PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    inline virtual ~PyDbObject() override;
    PyDbObjectId        objectId() const;
    PyDbObjectId        ownerId() const;
    void                setOwnerId(const PyDbObjectId& objId);
    PyDbDatabase        database() const;
    void                createExtensionDictionary();
    PyDbObjectId        extensionDictionary() const;
    void                releaseExtensionDictionary();
    void                close();
    void                upgradeOpen();
    void                upgradeFromNotify(Adesk::Boolean& wasWritable);
    void                downgradeOpen();
    void                downgradeToNotify(Adesk::Boolean wasWritable);
    void                cancel();
    void                erase1();
    void                erase2(Adesk::Boolean erasing);
    void                handOverTo(PyDbObject& newObject, Adesk::Boolean keepXData, Adesk::Boolean keepExtDict);
    void                swapIdWith(PyDbObjectId& otherId, Adesk::Boolean swapXdata, Adesk::Boolean swapExtDict);
    void                setXData(const boost::python::list& xdata);
    virtual boost::python::list xData(const std::string& regappName) const;
    void                xDataTransformBy(const AcGeMatrix3d& xform);
    Adesk::Boolean      isEraseStatusToggled() const;
    Adesk::Boolean      isErased() const;
    Adesk::Boolean      isReadEnabled() const;
    Adesk::Boolean      isWriteEnabled() const;
    Adesk::Boolean      isNotifyEnabled() const;
    Adesk::Boolean      isModified() const;
    Adesk::Boolean      isModifiedXData() const;
    Adesk::Boolean      isModifiedGraphics() const;
    Adesk::Boolean      isNewObject() const;
    Adesk::Boolean      isNotifying() const;
    Adesk::Boolean      isUndoing() const;
    Adesk::Boolean      isCancelling() const;
    Adesk::Boolean      isReallyClosing() const;
    Adesk::Boolean      isTransactionResident() const;
    Adesk::Boolean      isAProxy() const;
    void                assertReadEnabled() const;
    void                assertWriteEnabled();
    void                assertNotifyEnabled() const;
    bool                isUndoRecordingDisabled() const;
    void                disableUndoRecording(Adesk::Boolean disable);
    void                addPersistentReactor(const PyDbObjectId& objId);
    void                removePersistentReactor(const PyDbObjectId& objId);
    bool                hasPersistentReactor(const PyDbObjectId& objId) const;
    bool                hasFields(void) const;
    PyDbObjectId        getField1();
    PyDbObjectId        getField2(const std::string& propName);
    PyDbObjectId        setField1(PyDbField& pField);
    PyDbObjectId        setField2(const std::string& propName, PyDbField& pField);
    PyDbHandle          getHandle() const;
    void                removeField1(const PyDbObjectId& fieldId);
    void                removeField2(const std::string& propName);
    PyDbObjectId        getFieldDictionary(void) const;
    void                addReactor(PyDbObjectReactor& pReactor) const;
    void                removeReactor(PyDbObjectReactor& pReactor) const;
    void                snoop(PyDbSnoopDwgFiler& filer);
    static PyRxClass    desc();
    static std::string  className();
    static PyDbObject   cloneFrom(const PyRxObject& src);
    static PyDbObject   cast(const PyRxObject& src);
public:
    inline AcDbObject* impObj(const std::source_location& src = std::source_location::current()) const;
};


// TODO: This could be done better 
// boost::python::wrapper<> causes issues with subclassing i couldn't solve
// just made two classes, one for AcDbObjectReactor, and AcDbEntityReactor
// the todo part is attempt to remove code duplication
//---------------------------------------------------------------------------------------- -
//PyDbObjectReactorImpl
class PyDbObjectReactorImpl : public AcDbObjectReactor
{
public:
    PyDbObjectReactorImpl() = default;
    PyDbObjectReactorImpl(PyDbObjectReactor* ptr);
    virtual ~PyDbObjectReactorImpl() override = default;
    virtual void    cancelled(const AcDbObject* pObj) override;
    virtual void    copied(const AcDbObject* src, const AcDbObject* newObj) override;
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    virtual void    erased(const AcDbObject*, Adesk::Boolean = Adesk::kTrue) override;
#else
    virtual void    erased(const AcDbObject*, bool bErasing) override;
#endif
    virtual void    goodbye(const AcDbObject* ptr) override;
    virtual void    openedForModify(const AcDbObject* ptr) override;
    virtual void    modified(const AcDbObject* ptr)override;
    virtual void    subObjModified(const AcDbObject* ptr, const AcDbObject* subObj) override;
    virtual void    modifyUndone(const AcDbObject* ptr) override;
    virtual void    modifiedXData(const AcDbObject* ptr) override;
    virtual void    unappended(const AcDbObject* ptr) override;
    virtual void    reappended(const AcDbObject* ptr) override;
    virtual void    objectClosed(const AcDbObjectId id) override;

public:
    PyDbObjectReactor* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    PyDbObjectReactor* m_backPtr = nullptr;
};

//---------------------------------------------------------------------------------------- -
//PyDbObjectReactor
void makePyDbObjectReactorWrapper();
class PyDbObjectReactor : public PyRxObject, public boost::python::wrapper<PyDbObjectReactor>
{
public:
    PyDbObjectReactor();
    virtual ~PyDbObjectReactor() = default;
    void        cancelled(const PyDbObject& pObj);
    void        copied(const PyDbObject& src, const PyDbObject& newObj);
    void        erased(const PyDbObject& src, bool bErasing);
    void        goodbye(const PyDbObject& ptr);
    void        openedForModify(const PyDbObject& ptr);
    void        modified(const PyDbObject& ptr);
    void        subObjModified(const PyDbObject& ptr, const PyDbObject& subObj);
    void        modifyUndone(const PyDbObject& ptr);
    void        modifiedXData(const PyDbObject& ptr);
    void        unappended(const PyDbObject& ptr);
    void        reappended(const PyDbObject& ptr);
    void        objectClosed(const PyDbObjectId& id);
public:
    static PyRxClass    desc();
    static std::string  className();

public:
    AcDbObjectReactor* impObj(const std::source_location& src = std::source_location::current()) const;

public://prevent reentry on error
    bool reg_cancelled = true;
    bool reg_copied = true;
    bool reg_erased = true;
    bool reg_goodbye = true;
    bool reg_openedForModify = true;
    bool reg_modified = true;
    bool reg_subObjModified = true;
    bool reg_modifyUndone = true;
    bool reg_modifiedXData = true;
    bool reg_unappended = true;
    bool reg_reappended = true;
    bool reg_objectClosed = true;
};

//---------------------------------------------------------------------------------------- -
//AcDbEntityReactorImpl
class AcDbEntityReactorImpl : public AcDbEntityReactor
{
public:
    AcDbEntityReactorImpl() = default;
    AcDbEntityReactorImpl(PyDbEntityReactor* ptr);
    virtual ~AcDbEntityReactorImpl() override = default;
    virtual void        cancelled(const AcDbObject* pObj) override;
    virtual void        copied(const AcDbObject* src, const AcDbObject* newObj) override;
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    virtual void        erased(const AcDbObject*, Adesk::Boolean = Adesk::kTrue) override;
#else
    virtual void        erased(const AcDbObject*, bool bErasing) override;
#endif
    virtual void        goodbye(const AcDbObject* ptr) override;
    virtual void        openedForModify(const AcDbObject* ptr) override;
    virtual void        modified(const AcDbObject* ptr)override;
    virtual void        subObjModified(const AcDbObject* ptr, const AcDbObject* subObj) override;
    virtual void        modifyUndone(const AcDbObject* ptr) override;
    virtual void        modifiedXData(const AcDbObject* ptr) override;
    virtual void        unappended(const AcDbObject* ptr) override;
    virtual void        reappended(const AcDbObject* ptr) override;
    virtual void        objectClosed(const AcDbObjectId id) override;
    virtual void        modifiedGraphics(const AcDbEntity*) override;
    virtual void        dragCloneToBeDeleted(const AcDbEntity* pOriginalObj, const AcDbEntity* pClone) override;
public:
    PyDbEntityReactor* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    PyDbEntityReactor* m_backPtr = nullptr;
};

//---------------------------------------------------------------------------------------- -
//PyDbEntityReactor
void makePyDbEntityReactorWrapper();
class PyDbEntityReactor : public PyRxObject, public boost::python::wrapper<PyDbEntityReactor>
{
public:
    PyDbEntityReactor();
    virtual ~PyDbEntityReactor() = default;
    void        cancelled(const PyDbObject& pObj);
    void        copied(const PyDbObject& src, const PyDbObject& newObj);
    void        erased(const PyDbObject& src, bool bErasing);
    void        goodbye(const PyDbObject& ptr);
    void        openedForModify(const PyDbObject& ptr);
    void        modified(const PyDbObject& ptr);
    void        subObjModified(const PyDbObject& ptr, const PyDbObject& subObj);
    void        modifyUndone(const PyDbObject& ptr);
    void        modifiedXData(const PyDbObject& ptr);
    void        unappended(const PyDbObject& ptr);
    void        reappended(const PyDbObject& ptr);
    void        objectClosed(const PyDbObjectId& id);
    void        modifiedGraphics(const PyDbEntity& ent);
    void        dragCloneToBeDeleted(const PyDbEntity& pOriginalObj, const  PyDbEntity& pClone);
public:
    static PyRxClass    desc();
    static std::string  className();

public:
    AcDbEntityReactor* impObj(const std::source_location& src = std::source_location::current()) const;

public://prevent reentry on error
    bool reg_cancelled = true;
    bool reg_copied = true;
    bool reg_erased = true;
    bool reg_goodbye = true;
    bool reg_openedForModify = true;
    bool reg_modified = true;
    bool reg_subObjModified = true;
    bool reg_modifyUndone = true;
    bool reg_modifiedXData = true;
    bool reg_unappended = true;
    bool reg_reappended = true;
    bool reg_objectClosed = true;
    bool reg_modifiedGraphics = true;
    bool reg_dragCloneToBeDeleted = true;
};