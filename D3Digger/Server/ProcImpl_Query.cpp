#include "stdafx.h"
#include "ProcImpl_Query.h"

namespace D3D9
{

namespace Server
{

namespace
{
    typedef ProcImpl<IDirect3DQuery9> Impl;
}

Impl::ProcImpl(CreateProcArgs const &args)
    : Base(args)
{
}

void Impl::GetData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    // void* pData, DWORD dwSize, DWORD dwGetDataFlags
    
    bytes::read_proc rp(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(rp.operator()<ProxyId>());
    struct {
        DWORD dwSize;
        DWORD dwGetDataFlags;
    } args;

    (void)args;
    rp(args.dwSize);
    rp(args.dwGetDataFlags);

    vector<uint8_t> buffer(args.dwSize);

    HRESULT res = self->GetData(buffer.data(), args.dwSize, args.dwGetDataFlags);

    if (!SUCCEEDED(res))
        buffer.clear();
    
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(buffer);
}


} // namespace Server

} // namespace D3D9