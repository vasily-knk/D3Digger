#include "stdafx.h"
#include "ProxyImpl_Query.h"

namespace D3D9
{
namespace Client
{

namespace
{
    typedef ProxyImpl<IDirect3DQuery9> Impl;
}

Impl::ProxyImpl(ProxyId id)
    : Base(id)
{
    
}

HRESULT Impl::GetData(void* pData, DWORD dwSize, DWORD dwGetDataFlags)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(dwSize);
    wp(dwGetDataFlags);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DQuery9, Methods_IDirect3DQuery9::GetData), inBytes);

    bytes::read_proc rp(outBytes);
    
    HRESULT ret; 
    rp(ret);
    
    vector<uint8_t> buffer;
    rp(buffer);

    if (SUCCEEDED(ret))
    {
        Assert(buffer.size() == dwSize);
        memcpy(pData, buffer.data(), dwSize);
    }
        
    return ret;
}

} // namespace Client

} // namespace D3D9