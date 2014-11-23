#include "stdafx.h"
#include "ProxyImpl_Texture.h"

namespace D3D9
{
namespace Client
{

namespace
{
    typedef ProxyImpl<IDirect3DTexture9> Impl;
}

Impl::ProxyImpl(ProxyId id)
    : Base(id)
{
    size_t levels = Base::GetLevelCount();
    surfaces_.resize(levels, nullptr);

    for (size_t i = 0; i < levels; ++i)
        Base::GetSurfaceLevel(i, &surfaces_.at(i));

    int aaa = 5;
}

Impl::~ProxyImpl()
{
    for (IDirect3DSurface9* surface : surfaces_)
        surface->Release();

    surfaces_.clear();
}

HRESULT Impl::GetSurfaceLevel(UINT Level, IDirect3DSurface9** ppSurfaceLevel)
{
    if (!ppSurfaceLevel)
        return D3DERR_INVALIDCALL;

    *ppSurfaceLevel = surfaces_.at(Level);
    (*ppSurfaceLevel)->AddRef();

    return D3D_OK;
}

HRESULT Impl::LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
    return surfaces_.at(Level)->LockRect(pLockedRect, pRect, Flags);
}

HRESULT Impl::UnlockRect(UINT Level)
{
    return surfaces_.at(Level)->UnlockRect();
}


} // namespace Client

} // namespace D3D9