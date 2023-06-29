#pragma once
class PyRxClass;

//TODO:
//expose this as functions to python
//BeginEditorCommand();
//CancelEditorCommand();
//ComleteEditorCommand();



//-----------------------------------------------------------------------------------------
// PyEdUserInteraction
class PyEdUserInteraction
{
    HWND m_activeWindow;
    std::vector<HWND> m_wnds;
public:
    PyEdUserInteraction();
    PyEdUserInteraction(AcApDocument* pDocument, bool prompting);
    virtual ~PyEdUserInteraction(void);
protected:
    void userInteraction(AcApDocument* pDocument, bool prompting);
    void undoUserInteraction();
};


//-----------------------------------------------------------------------------------------
// PyEdUIContext
class PyEdUIContext : AcEdUIContext, public boost::python::wrapper<PyEdUIContext>
{
    bool isAlive = false;
public:
    PyEdUIContext();
    virtual ~PyEdUIContext() override;
    virtual void* getMenuContext(const AcRxClass* pClass, const AcDbObjectIdArray& ids);
    virtual void  onCommand(Adesk::UInt32 cmd);
    virtual void  OnUpdateMenu();

    int64_t getMenuContextWr(const PyRxClass& pyclass, const boost::python::list& pyids);
    void  onCommandWr(Adesk::UInt32);
    void  OnUpdateMenuWr();

    static bool addObjectContextMenu(PyRxClass& pClass, PyEdUIContext& pContext);
    static bool removeObjectContextMenu(PyRxClass& pClass, PyEdUIContext& pContext);
    static bool addDefaultContextMenu1(PyEdUIContext& pContext);
    static bool addDefaultContextMenu2(PyEdUIContext& pContext, const std::string& appName);
    static bool removeDefaultContextMenu(PyEdUIContext& pContext);
};