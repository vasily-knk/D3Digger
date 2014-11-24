#include "stdafx.h"
#include "ProxyImpl_IB.h"

namespace D3D9
{
namespace Client
{

namespace
{
    typedef ProxyImpl<IDirect3DIndexBuffer9> Impl;
}

Impl::ProxyImpl(ProxyId id)
    : Base(id)
    , buffer_(getSize())
{
    
}

Impl::~ProxyImpl()
{
    int aaa = 5;
}

HRESULT Impl::Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags)
{
    if (!ppbData)
    {
        assert(false);
        return D3DERR_INVALIDCALL;
    }

    LockData ld;

    if (!OffsetToLock && !SizeToLock)
    {
        OffsetToLock = 0;
        SizeToLock = buffer_.size();
    }

    ld.offset = OffsetToLock;
    ld.size = SizeToLock;
    ld.flags = Flags;
    lockStack_.push(ld);

    *ppbData = reinterpret_cast<void*>(buffer_.data() + OffsetToLock);

    return D3D_OK;
}                            

HRESULT Impl::Unlock()
{
    if (lockStack_.empty())
    {
        assert(false);
        return D3DERR_INVALIDCALL;
    }

    LockData ld = lockStack_.top();
    lockStack_.pop();
    
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());

    wp(ld.offset);
    wp(ld.size  );
    wp(ld.flags );
    wp.array(buffer_.data() + ld.offset, ld.size);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DIndexBuffer9, Methods_IDirect3DIndexBuffer9::Unlock), inBytes);
    
    return D3D_OK;
}

size_t Impl::getSize()
{
    D3DINDEXBUFFER_DESC desc;
    Base::GetDesc(&desc);
    return desc.Size;
}

} // namespace Client

} // namespace D3D9