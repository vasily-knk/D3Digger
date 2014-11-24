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
    , bytesPerPixel_(4)
{
    Base::GetDesc(&desc_);
    buffer_.resize(desc_.Width * desc_.Height * bytesPerPixel_);
}

HRESULT Impl::LockRect(D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
    if (lockData_)
    {
        Assert(false);
        return D3DERR_INVALIDCALL;
    }
    
    RECT rect = calcRect(pRect);

    lockData_ = LockData({rect, Flags});
    pLockedRect->Pitch = calcPitch();
    pLockedRect->pBits = buffer_.data() + calcBufferOffset(rect);
   
    return D3D_OK;
}

HRESULT Impl::UnlockRect()
{
    if (!lockData_)
    {
        Assert(false);
        return D3DERR_INVALIDCALL;
    }

    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(lockData_->rect);
    wp(lockData_->flags);

    size_t bufferOffset = calcBufferOffset(lockData_->rect);
    size_t pitch = calcPitch();
    size_t rowSize = (lockData_->rect.right - lockData_->rect.left) * bytesPerPixel_;

    char* ptr = buffer_.data() + bufferOffset;
    for (int y = lockData_->rect.top; y < lockData_->rect.bottom; ++y, ptr += pitch)
        wp.array(ptr, rowSize);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DSurface9, Methods_IDirect3DSurface9::UnlockRect), inBytes);

    lockData_.reset();
    buffer_.clear();
    return D3D_OK;
}

size_t Impl::calcBufferOffset(RECT const &rect) const
{
    Assert(rect.right > rect.left);
    Assert(rect.bottom > rect.top);

    size_t pitch = calcPitch();
    return rect.top * pitch + rect.left * bytesPerPixel_;
}

size_t Impl::calcPitch() const
{
    return desc_.Width * bytesPerPixel_;
}

RECT Impl::calcRect(RECT const *pSrcRect) const
{
    RECT rect;
    if (pSrcRect)
        rect = *pSrcRect;
    else
        rect = {0, 0, desc_.Width, desc_.Height};
    
    Assert(rect.right > rect.left);
    Assert(rect.bottom > rect.top);
    return rect;
}


} // namespace Client

} // namespace D3D9