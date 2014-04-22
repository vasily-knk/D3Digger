// D3D9.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ProxyBase.h"
#include "ProxyImpl.h"

void logMethod(const char *interfaceName, const char *methodName)
{
    (void)interfaceName;
    (void)methodName;
}


HMODULE getSystemDLL()
{
    static HMODULE dll = LoadLibrary(L"C:\\Windows\\System32\\d3d9.dll");
    return dll;
}


IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
    typedef IDirect3D9* (WINAPI *Creator)(UINT);
    
    HMODULE dll = getSystemDLL();
    Creator creator = reinterpret_cast<Creator>(GetProcAddress(dll, "Direct3DCreate9"));

    IDirect3D9 *pimpl = creator(SDKVersion);
    return wrapProxy<IDirect3D9>(pimpl).get();
}

HRESULT WINAPI Direct3DCreate9Ex(UINT SDKVersion, IDirect3D9Ex** pp)
{
    typedef HRESULT (WINAPI *CreatorEx)(UINT, IDirect3D9Ex**);
    
    HMODULE dll = getSystemDLL();
    CreatorEx creatorEx = reinterpret_cast<CreatorEx>(GetProcAddress(dll, "Direct3DCreate9Ex"));
    
    HRESULT res = creatorEx(SDKVersion, pp);
    return res;
}
