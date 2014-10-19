#include "stdafx.h"
#include "ProxyImpl_Surface.h"


namespace D3D9
{
namespace Client
{

namespace
{
    typedef ProxyImpl<IDirect3DSurface9> Impl;
}

Impl::ProxyImpl(ProxyId id)
    : Base(id)
{
}

HRESULT Impl::LockRect(D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
    int w = 0, h = 0;
    if (!pRect)
    {
        w = desc().Width;
        h = desc().Height;
    }
    else
    {
        w = pRect->right - pRect->left;
        h = pRect->bottom - pRect->top;
    }
    assert(w > 0 && h > 0);

    int bytes_per_pixel = 4;

    size_t desired_size = w * h * bytes_per_pixel;
    buffer_.resize(desired_size);

    pLockedRect->Pitch = w * bytes_per_pixel;
    pLockedRect->pBits = buffer_.data();
    
    return D3D_OK;
}

HRESULT Impl::UnlockRect()
{
    buffer_.clear();
    return D3D_OK;
}

D3DSURFACE_DESC const &Impl::desc() 
{
    if (!desc_)
    {
        D3DSURFACE_DESC desc;
        GetDesc(&desc);
        desc_ = desc;
    }

    return *desc_;
}

} // namespace Client

} // namespace D3D9