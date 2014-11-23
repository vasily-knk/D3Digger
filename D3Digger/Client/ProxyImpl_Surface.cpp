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
    int aaa = 5;
    Base::GetDesc(&desc_);
}

HRESULT Impl::LockRect(D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
    RECT rect;
    if (pRect)
    {
        rect = *pRect;
    }
    else
    {
        rect = {0, 0, desc_.Width, desc_.Height};
    }
    
    int w = rect.right - rect.left;
    int h = rect.bottom - rect.top;
    assert(w > 0 && h > 0);

    size_t bytes_per_pixel = 4;

    size_t desired_size = w * h * bytes_per_pixel;
    buffer_.resize(desired_size);

    lockData_ = LockData({rect, Flags});

    pLockedRect->Pitch = w * bytes_per_pixel;
    pLockedRect->pBits = buffer_.data();
    
    return D3D_OK;
}

HRESULT Impl::UnlockRect()
{
    if (lockData_)
    {
        BytesPtr inBytes = bytes::make();
        bytes::write_proc wp(inBytes);
        wp(getId());
        wp(lockData_->rect);
        wp(lockData_->flags);
        wp(buffer_);
    
        getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::UnlockRect), inBytes);

        lockData_.reset();
        buffer_.clear();
    }
    return D3D_OK;
}

} // namespace Client

} // namespace D3D9