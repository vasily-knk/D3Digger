// D3D9.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ProxyBase.h"

template<>
shared_ptr<IProxy<IDirect3DBaseTexture9>> createProxy<IDirect3DBaseTexture9>(IDirect3DBaseTexture9 *pimpl)
{
    assert(false);
    return shared_ptr<IProxy<IDirect3DBaseTexture9>>();
}


IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
    {
        ofstream out("d3d9.log");
        out << "Hello!" << endl;
    }
    
    static auto dll = LoadLibrary(L"C:\\Windows\\System32\\d3d9.dll");
    typedef IDirect3D9* (WINAPI *Creator)(UINT);

    Creator creator = reinterpret_cast<Creator>(GetProcAddress(dll, "Direct3DCreate9"));

    IDirect3D9 *pimpl = creator(SDKVersion);
    return wrapProxy<IDirect3D9>(pimpl).get();
}