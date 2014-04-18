// D3D9.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "../d3d9_impl/D3D.h"
#include "../d3d9_impl/HierElem.h"


IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
    using namespace D3Digger::D3D9;

    static auto dll = LoadLibrary(L"C:\\Windows\\System32\\d3d9.dll");
    static D3Digger::HierElemKeeper keeper;

    typedef IDirect3D9* (WINAPI *Creator)(UINT);

    Creator creator = reinterpret_cast<Creator>(GetProcAddress(dll, "Direct3DCreate9"));

    D3D::IBasePtr pimpl = creator(SDKVersion);

    if (pimpl)
    {
        D3D::ProxyImplPtr child = D3D::ProxyImpl::create(pimpl);
        keeper.addChild(child);
        return child.get();
    }
    else
    {
        return nullptr;
    }
}