// D3D9.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "../d3d9_impl/D3D.h"

IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
    static auto dll = LoadLibrary(L"C:\\Windows\\System32\\d3d9.dll");
    typedef IDirect3D9* (WINAPI *fn_t)(UINT);

    auto fn = reinterpret_cast<fn_t>(GetProcAddress(dll, "Direct3DCreate9"));

    using namespace D3Digger::D3D9;
    D3D::IBasePtr pimpl = fn(SDKVersion);

    return D3D::ProxyImpl::create(pimpl).get();
}