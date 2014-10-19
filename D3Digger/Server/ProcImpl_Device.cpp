#include "stdafx.h"
#include "ProcImpl_Device.h"

namespace D3D9
{

namespace Server
{

namespace
{
    typedef ProcImpl<IDirect3DDevice9> Impl;
}

Impl::ProcImpl(CreateProcArgs const &args)
    : Base(args)
{
}



void Impl::Clear(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Count;
        vector<D3DRECT> pRects;
        DWORD Flags;
        D3DCOLOR Color;
        float Z;
        DWORD Stencil;
    } args;

    (void)args;
    rp(args.Count);
    
    args.pRects.resize(args.Count);
    for (size_t i = 0; i < args.Count; ++i)
        rp(args.pRects.at(i));

    rp(args.Flags);
    rp(args.Color);
    rp(args.Z);
    rp(args.Stencil);
    HRESULT res = self->Clear(args.Count, args.pRects.empty() ? nullptr : &args.pRects.at(0), args.Flags, args.Color, args.Z, args.Stencil);
    bytes::write_proc wp(dstBytes);
    wp(res);
}


} // namespace Server

} // namespace D3D9