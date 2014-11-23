#include "stdafx.h"
#include "ProcImpl_IB.h"

namespace D3D9
{

namespace Server
{

namespace
{
    typedef ProcImpl<IDirect3DIndexBuffer9> Impl;
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
    bytes::read_proc rp(srcBytes);
    ProxyId id;
    rp(id);
    
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(id);
    
    UINT offset;
    DWORD flags;
    vector<uint8_t> buffer;

    rp(offset);
    rp(flags);
    rp(buffer);
    uint8_t *ptr = nullptr;

    HRESULT res;
    
    res = self->Lock(offset, buffer.size(), reinterpret_cast<void**>(&ptr), flags);
    if (SUCCEEDED(res))
    {
        memcpy(ptr, buffer.data(), buffer.size());
        res = self->Unlock();
    }
    else
    {
        assert(false);
    }

    bytes::write_proc wp(dstBytes);
    wp(res);
}



} // namespace Server

} // namespace D3D9