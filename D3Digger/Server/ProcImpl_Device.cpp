#include "stdafx.h"
#include "ProcImpl_Device.h"

namespace D3D9
{

namespace Server
{

namespace
{
    typedef ProcImpl<IDirect3DDevice9> Impl;

    void readSharedHandle(bytes::read_proc &/*proc*/, optional<HANDLE> &dst)
    {
        dst = none;
    }

    void writeSharedHandle(bytes::write_proc &/*proc*/, HANDLE /*src*/)
    {
    }
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

void Impl::CreateVertexDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());

    struct {
        IDirect3DVertexDeclaration9* ppDecl;
    } args;

    vector<D3DVERTEXELEMENT9> elements;
    rp(elements);

    HRESULT res = self->CreateVertexDeclaration(elements.data(), &args.ppDecl);
    
    bytes::write_proc wp(dstBytes);
    wp(res);
    CHECK_PROC_RESULT(res);

    wp(procMap_->getProxyID(args.ppDecl));
}

void Impl::CreateVertexShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    
    struct {
        vector<DWORD> pFunction;
        IDirect3DVertexShader9* ppShader;
    } args;

    uint32_t shader_length;
    rp(shader_length);

    args.pFunction.resize(shader_length);
    rp.array(args.pFunction.data(), shader_length);

    HRESULT res = self->CreateVertexShader(args.pFunction.data(), &args.ppShader);
    bytes::write_proc wp(dstBytes);
    wp(res);
    Assert(SUCCEEDED(res));
    CHECK_PROC_RESULT(res);
    wp(procMap_->getProxyID(args.ppShader));
}

void Impl::CreatePixelShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    
    struct {
        vector<DWORD> pFunction;
        IDirect3DPixelShader9* ppShader;
    } args;

    uint32_t shader_length;
    rp(shader_length);

    args.pFunction.resize(shader_length);
    rp.array(args.pFunction.data(), shader_length);

    HRESULT res = self->CreatePixelShader(args.pFunction.data(), &args.ppShader);
    bytes::write_proc wp(dstBytes);
    wp(res);
    Assert(SUCCEEDED(res));
    CHECK_PROC_RESULT(res);
    wp(procMap_->getProxyID(args.ppShader));
}


} // namespace Server

} // namespace D3D9