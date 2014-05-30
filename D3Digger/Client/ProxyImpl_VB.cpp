#include "stdafx.h"
#include "ProxyImpl_VB.h"

namespace D3D9
{
namespace Client
{

namespace
{
    typedef ProxyImpl<IDirect3DVertexBuffer9> Impl;
}

Impl::ProxyImpl(ProxyId id)
    : Base(id)
    , buffer_(getSize())
{
    
}

HRESULT Impl::Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags)
{
    if (lockData_)
        return D3DERR_INVALIDCALL;

    if (!ppbData)
        return D3DERR_INVALIDCALL;

    if (OffsetToLock + SizeToLock > buffer_.size())
        return D3DERR_INVALIDCALL;

    LockData ld;

    if (!OffsetToLock && !SizeToLock)
    {
        ld.offset = 0;
        ld.size = buffer_.size();
    }
    else
    {
        ld.offset = OffsetToLock;
        ld.size = SizeToLock;
    }

    ld.flags = Flags;
    *ppbData = reinterpret_cast<void*>(&buffer_.at(ld.offset));
    lockData_ = ld;

    return D3D_OK;
}

HRESULT Impl::Unlock()
{
    if (!lockData_)
        return D3DERR_INVALIDCALL;
    
    BytesPtr inBytes = bytes::make();
    bytes::put(getId(), inBytes);

    bytes::put(UINT(lockData_->offset), inBytes);
    bytes::put(UINT(lockData_->size), inBytes);
    bytes::put(lockData_->flags, inBytes);

    for (size_t i = 0; i < lockData_->size; ++i)
        bytes::put<uint8_t>(buffer_.at(lockData_->offset + i), inBytes);

    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DVertexBuffer9, Methods_IDirect3DVertexBuffer9::Unlock), inBytes);
    
    lockData_.reset();
    return D3D_OK;
}

size_t Impl::getSize()
{
    D3DVERTEXBUFFER_DESC desc;
    Base::GetDesc(&desc);
    return desc.Size;
}

} // namespace Client

} // namespace D3D9