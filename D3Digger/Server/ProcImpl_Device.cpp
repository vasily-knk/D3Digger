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
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Count;
        vector<D3DRECT> pRects;
        DWORD Flags;
        D3DCOLOR Color;
        float Z;
        DWORD Stencil;
    } args;

    (void)args;
    g.get(args.Count);
    
    args.pRects.resize(args.Count);
    for (size_t i = 0; i < args.Count; ++i)
        g.get(args.pRects.at(i));

    g.get(args.Flags);
    g.get(args.Color);
    g.get(args.Z);
    g.get(args.Stencil);
    HRESULT res = self->Clear(args.Count, args.pRects.empty() ? nullptr : &args.pRects.at(0), args.Flags, args.Color, args.Z, args.Stencil);
    bytes::put<HRESULT>(res, dstBytes);
}


} // namespace Server

} // namespace D3D9