#include "stdafx.h"
#include "ProcImpl_Surface.h"

namespace D3D9
{

namespace Server
{

namespace
{
    typedef ProcImpl<IDirect3DSurface9> Impl;
}

Impl::ProcImpl(CreateProcArgs const &args)
    : Base(args)
{
}

void Impl::LockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
}

void Impl::UnlockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);

    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    RECT rect;
    rp(rect);
    DWORD flags;
    rp(flags);
    uint32_t bytesPerPixel;
    rp(bytesPerPixel);

    Assert(rect.left < rect.right);
    Assert(rect.top < rect.bottom);

    D3DLOCKED_RECT lockedRect;
    HRESULT res = self->LockRect(&lockedRect, &rect, flags);

    size_t lineSize = (rect.right - rect.left) * bytesPerPixel;
    
    char *dst = reinterpret_cast<char*>(lockedRect.pBits);
    for (int line = rect.top; line < rect.bottom; ++line, dst += lockedRect.Pitch)
        rp.array(dst, lineSize);

    res = self->UnlockRect();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

} // namespace Server

} // namespace D3D9