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
    {
        assert(false);
        return D3DERR_INVALIDCALL;
    }

    if (!ppbData)
    {
        assert(false);
        return D3DERR_INVALIDCALL;
    }

    if (OffsetToLock + SizeToLock > buffer_.size())
    {
        assert(false);
        return D3DERR_INVALIDCALL;
    }

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
    {
        assert(false);
        return D3DERR_INVALIDCALL;
    }
    
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());

    wp(UINT(lockData_->offset));
    wp(UINT(lockData_->size));
    wp(lockData_->flags);

    for (size_t i = 0; i < lockData_->size; ++i)
        wp(buffer_.at(lockData_->offset + i));
    
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