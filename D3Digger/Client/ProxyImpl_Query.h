#pragma once

#include "ProxyImpl.h"

namespace D3D9
{
namespace Client
{

template<>
struct ProxyImpl<IDirect3DQuery9>
    : ProxyBase<IDirect3DQuery9>
{
    typedef ProxyBase<IDirect3DQuery9> Base;

    ProxyImpl(ProxyId id); 

    HRESULT STDMETHODCALLTYPE GetData(void* pData, DWORD dwSize, DWORD dwGetDataFlags);
};

} // namespace Client

} // namespace D3D9