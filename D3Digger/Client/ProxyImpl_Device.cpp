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
    bytes::put(getId(), inBytes);
    bytes::put(Count, inBytes);
    for (size_t i = 0; i < Count; ++i)
        bytes::put(pRects[i], inBytes);
    bytes::put(Flags, inBytes);
    bytes::put(Color, inBytes);
    bytes::put(Z, inBytes);
    bytes::put(Stencil, inBytes);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::Clear), inBytes);
    
    return D3D_OK;
}



} // namespace Client

} // namespace D3D9