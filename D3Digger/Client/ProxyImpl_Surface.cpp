#include "stdafx.h"
#include "ProxyImpl_Surface.h"


namespace D3D9
{
namespace Client
{

namespace
{
    typedef ProxyImpl<IDirect3DSurface9> Impl;

size_t bytesPerPixel(D3DFORMAT Format)
{
    switch (Format)
    {
    case D3DFMT_DXT1:
    case D3DFMT_DXT2:
    case D3DFMT_DXT3:
    case D3DFMT_DXT4:
    case D3DFMT_DXT5:
        VerifyMsg(false, "DXT not supported");
        return 0;
 
    case D3DFMT_A32B32G32R32F:
        return 16;
 
    case D3DFMT_A16B16G16R16:
    case D3DFMT_Q16W16V16U16:
    case D3DFMT_A16B16G16R16F:
    case D3DFMT_G32R32F:
    case D3DFMT_MULTI2_ARGB8:
        return 8;
 
    case D3DFMT_A8R8G8B8:
    case D3DFMT_X8R8G8B8:
    case D3DFMT_D32:
    case D3DFMT_D24S8:
    //case D3DFMT_S8D24:
    case D3DFMT_X8L8V8U8:
    //case D3DFMT_X4S4D24:
    case D3DFMT_D24X4S4:
    case D3DFMT_Q8W8V8U8:
    case D3DFMT_V16U16:
    case D3DFMT_A2W10V10U10:
    case D3DFMT_A2B10G10R10:
    case D3DFMT_A8B8G8R8:
    case D3DFMT_X8B8G8R8:
    case D3DFMT_G16R16:
    case D3DFMT_D24X8:
    //case D3DFMT_X8D24:
    //case D3DFMT_W11V11U10:
    case D3DFMT_A2R10G10B10:
    case D3DFMT_G16R16F:
    case D3DFMT_R32F:
    case D3DFMT_D32F_LOCKABLE:
    case D3DFMT_D24FS8:
    case D3DFMT_D32_LOCKABLE:
        return 4;
 
    case D3DFMT_R8G8B8:
        return 3;
 
    case D3DFMT_R5G6B5:
    case D3DFMT_X1R5G5B5:
    case D3DFMT_A1R5G5B5:
    case D3DFMT_A4R4G4B4:
    case D3DFMT_A8L8:
    case D3DFMT_V8U8:
    case D3DFMT_L6V5U5:
    case D3DFMT_D16:
    case D3DFMT_D16_LOCKABLE:
    case D3DFMT_D15S1:
    //case D3DFMT_S1D15:
    case D3DFMT_A8P8:
    case D3DFMT_A8R3G3B2:
    case D3DFMT_UYVY:
    case D3DFMT_YUY2:
    case D3DFMT_X4R4G4B4:
    case D3DFMT_CxV8U8:
    case D3DFMT_L16:
    case D3DFMT_R16F:
    case D3DFMT_R8G8_B8G8:
    case D3DFMT_G8R8_G8B8:
        return 2;
 
    case D3DFMT_P8:
    case D3DFMT_L8:
    case D3DFMT_R3G3B2:
    case D3DFMT_A4L4:
    case D3DFMT_A8:
    case D3DFMT_A1:
    case D3DFMT_S8_LOCKABLE:
        return 1;
 
    default:
        VerifyMsg(false, "Unknown texture format: " << Format);
        return 0;
    };
}; 


}

Impl::ProxyImpl(ProxyId id)
    : Base(id)
    , desc_(getDesc())
    , bytesPerPixel_(bytesPerPixel(desc_.Format))
    , buffer_(desc_.Width * desc_.Height * bytesPerPixel_)
{
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
    wp(bytesPerPixel_);

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

HRESULT Impl::GetDesc(D3DSURFACE_DESC* pDesc) 
{
    if (!pDesc)
        return D3DERR_INVALIDCALL;

    *pDesc = desc_;

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

D3DSURFACE_DESC Impl::getDesc() 
{
    D3DSURFACE_DESC desc;
    Base::GetDesc(&desc);
    return desc;
}


} // namespace Client

} // namespace D3D9