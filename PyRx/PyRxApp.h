#pragma once
#include "stdafx.h"
#include "PyLispService.h"

//------------------------------------------------------------------------------------------------
//  PyRxMethod holds command objects
struct PyRxMethod
{
    PyObjectPtr modname;
    PyObjectPtr mod;
    PyObjectPtr rslt;

    //TODO: had problems using PyObjectPtr on these
    PyObject* mdict = nullptr;
    PyObject* OnPyInitApp = nullptr;
    PyObject* OnPyUnloadApp = nullptr;
    PyObject* OnPyLoadDwg = nullptr;
    PyObject* OnPyUnloadDwg = nullptr;
};

//------------------------------------------------------------------------------------------------
//  this is AutoCAD's main frame
class WinFrame : public wxFrame
{
public:
    WinFrame(HWND hwnd);
};

//------------------------------------------------------------------------------------------------
// the wxApp
class WxRxApp : public wxApp
{
public:
    WxRxApp() = default;
    virtual ~WxRxApp() override = default;
    virtual bool    OnInit() override;
    virtual int     OnExit() override;
    virtual void    WakeUpIdle() override;
    virtual void    ExitMainLoop() override;
    bool            Init_wxPython();
    static WxRxApp& instance();
public:
    std::unique_ptr<WinFrame> frame;
};

//------------------------------------------------------------------------------------------------
// the PyRxApp, holds the command objects
class PyRxApp
{
public:
    bool init();
    bool uninit();
    static bool setPyConfig();
    static bool appendSearchPath(const TCHAR* pModulePath);
    static std::wstring the_error();
    static std::filesystem::path modulePath();
    static PyRxApp& instance();
public:

    using FuncNameMap = std::unordered_map<AcString, PyRxMethod>;
    using LoadedPaths = std::unordered_set<std::filesystem::path>;
    using CmdNameMap = std::unordered_map<AcString, PyObject*>;
    using CmdLispMap = std::unordered_map<int, AcString>;
    using PathForCommand = std::unordered_map<AcString, std::filesystem::path>;

    FuncNameMap funcNameMap;
    LoadedPaths loadedModulePaths;
    CmdNameMap commands;
    PyLispService lispService;
    PathForCommand pathForCommand;

    void* appPkt = nullptr;
    bool isLoaded = false;
};

