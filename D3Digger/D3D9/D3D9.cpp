// D3D9.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ProxyBase.h"
#include "ProxyImpl.h"


template<>
IProxyPtr<IDirect3D9>::Type createProxy<IDirect3D9>(IDirect3D9 *pimpl)
{
    IProxyPtr<IDirect3D9>::Type ptr(new ProxyBase<IDirect3D9>(pimpl), true);
    return ptr;
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
    auto proxy = wrapProxy<IDirect3D9>(pimpl);
    return proxy.get();
}

