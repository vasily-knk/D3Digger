#include "stdafx.h"
#include "ProxyImpl_Device.h"


namespace D3D9
{
namespace Client
{

namespace
{
    typedef ProxyImpl<IDirect3DDevice9> Impl;
}

Impl::ProxyImpl(ProxyId id)
    : Base(id)
{
    
}

HRESULT Impl::Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);

    wp(getId());
    wp(Count);
    for (size_t i = 0; i < Count; ++i)
        wp(pRects[i]);
    wp(Flags);
    wp(Color);
    wp(Z);
    wp(Stencil);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::Clear), inBytes);
    
    return D3D_OK;
}

HRESULT Impl::Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);

    wp(getId());
    wp(ptr2opt(pSourceRect));
    wp(ptr2opt(pDestRect));
    wp(hDestWindowOverride);
    wp(ptr2opt(pDirtyRegion));
    
    getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::Present), inBytes);
    
    return D3D_OK;
}


} // namespace Client

} // namespace D3D9