#pragma once

#include "ProxyImpl.h"

namespace D3D9
{
namespace Client
{

template<>
struct ProxyImpl<IDirect3DSurface9>
    : ProxyBase<IDirect3DSurface9>
{
    typedef ProxyBase<IDirect3DSurface9> Base;

    ProxyImpl(ProxyId id); 

    HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags);
    HRESULT STDMETHODCALLTYPE UnlockRect();

private:
    D3DSURFACE_DESC const &desc();

private:
    optional<D3DSURFACE_DESC> desc_;
    vector<char> buffer_;
};

} // namespace Client

} // namespace D3D9