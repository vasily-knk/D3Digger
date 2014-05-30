#include "stdafx.h"
#include "ProcImpl_VB.h"

namespace D3D9
{

namespace Server
{

namespace
{
    typedef ProcImpl<IDirect3DVertexBuffer9> Impl;
}

Impl::ProcImpl(CreateProcArgs const &args)
    : Base(args)
{
}

void Impl::Lock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    (void)srcBytes;
    (void)dstBytes;
    throw std::runtime_error("should not be here");
}

void Impl::Unlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    
    UINT offset, size;
    DWORD flags;

    g.get(offset);
    g.get(size);
    g.get(flags);
    uint8_t *ptr = nullptr;

    HRESULT res;
    
    res = self->Lock(offset, size, reinterpret_cast<void**>(&ptr), flags);
    if (SUCCEEDED(res))
    {
        for (size_t i = 0; i < size; ++i)
            g.get(ptr[i]);

        res = self->Unlock();
    }
    else
    {
    }

    bytes::put<HRESULT>(res, dstBytes);
}



} // namespace Server

} // namespace D3D9