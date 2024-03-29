// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("")

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class PyRxLoader : public AcRxArxApp
{
    bool On_kLoadDwgMsgCallOnce = false;

public:
    PyRxLoader() : AcRxArxApp()
    {
    }

    virtual AcRx::AppRetCode On_kInitAppMsg(void* pkt)
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg(pkt);

        //init stuff here, read the API help though
        //its before doc, some code needs a doc, like printf or to reg xdtata;

        return (retCode);
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt)
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);

        //unload here

        return (retCode);
    }

    virtual AcRx::AppRetCode On_kLoadDwgMsg(void* pkt) override
    {
        AcRx::AppRetCode retCode = AcRxDbxApp::On_kLoadDwgMsg(pkt);
        if (!On_kLoadDwgMsgCallOnce)
        {
            //init with doc
            On_kLoadDwgMsgCallOnce = true;
        }
        return retCode;
    }

    static std::filesystem::path thisModulePath()
    {
        std::wstring buffer(MAX_PATH, 0);
        GetModuleFileName(_hdllInstance, buffer.data(), buffer.size());
        std::filesystem::path path{ std::move(buffer) };
        path.remove_filename();
        return path;
    }

    virtual void RegisterServerComponents()
    {
    }

    static void setenvpath(const std::wstring& pathToAdd)
    {
        std::wstring buffer(32767, 0);
        GetEnvironmentVariable(_T("PATH"), buffer.data(), buffer.size());
        buffer.erase(std::find(buffer.begin(), buffer.end(), '\0'), buffer.end());
        AcString env = buffer.c_str();
        if (env.findNoCase(pathToAdd.c_str()) == -1)
        {
            buffer.append(_T(";"));
            buffer.append(pathToAdd.c_str());
            if (SetEnvironmentVariable(_T("PATH"), buffer.data()) == 0)
            {
                acutPrintf(_T("\nFailed @ SetEnvironmentVariable %ls: "), _T("pathToAdd"));
            }
        }
    }

    
    static void PyRxLoader_loader(void)
    {
        auto modulePath = thisModulePath();
        auto oldpath = std::filesystem::current_path();
        std::filesystem::current_path(modulePath);
        auto settingsPath = modulePath /= _T("PyRx.INI");

        auto res = 0;
        {
            std::wstring installpath(MAX_PATH, 0);
            res = GetPrivateProfileStringW(_T("PYRXSETTINGS"), _T("PYTHONINSTALLEDPATH"), _T(""), installpath.data(), installpath.size(), settingsPath.c_str());
            if (res != 0)
            {
                setenvpath(installpath);
            }
            else
            {
                acutPrintf(_T("\nFailed to read setting %ls: "), _T("PYTHONINSTALLEDPATH"));
            }
        }
        {
            std::wstring wxPythonPath(MAX_PATH, 0);
            res = GetPrivateProfileStringW(_T("PYRXSETTINGS"), _T("WXPYTHONPATH"), _T(""), wxPythonPath.data(), wxPythonPath.size(), settingsPath.c_str());
            if (res != 0)
            {
                setenvpath(wxPythonPath);
            }
            else
            {
                acutPrintf(_T("Failed to read setting %ls: "), _T("WXPYTHONPATH"));
            }
        }

        acrxDynamicLinker->loadModule(_T(".\\PyRx25.0.arx"),true);
        std::filesystem::current_path(oldpath);
   
    }

};

//-----------------------------------------------------------------------------
#pragma warning( disable: 4838 ) //prevents a cast compiler warning, 
IMPLEMENT_ARX_ENTRYPOINT(PyRxLoader)
ACED_ARXCOMMAND_ENTRY_AUTO(PyRxLoader, PyRxLoader, _loader, loader, ACRX_CMD_TRANSPARENT, NULL)
#pragma warning( pop )
