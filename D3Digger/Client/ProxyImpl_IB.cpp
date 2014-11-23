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
    , size_(getSize())
{
    
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
        SizeToLock = size_;
    }

    ld.flags = Flags;
    ld.offset = OffsetToLock;
    ld.buffer = make_shared<vector<uint8_t>>(SizeToLock);
    lockStack_.push(ld);

    *ppbData = reinterpret_cast<void*>(lockStack_.top().buffer->data());

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

    uint16_t *temp = reinterpret_cast<uint16_t*>(ld.buffer->data());
    
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());

    wp(UINT(ld.offset));
    wp(ld.flags);
    wp(*ld.buffer);
    
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