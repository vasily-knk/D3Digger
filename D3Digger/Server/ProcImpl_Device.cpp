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

void Impl::CreateTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        UINT Levels;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DTexture9* ppTexture;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Width);
    rp(args.Height);
    rp(args.Levels);
    rp(args.Usage);
    rp(args.Format);
    rp(args.Pool);
    readSharedHandle(rp, args.pSharedHandle);

    HRESULT res = self->CreateTexture(args.Width, args.Height, args.Levels, args.Usage, args.Format, args.Pool, &args.ppTexture, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppTexture));
    if (args.pSharedHandle) writeSharedHandle(wp, *args.pSharedHandle);
}

void Impl::CreateVolumeTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        UINT Depth;
        UINT Levels;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DVolumeTexture9* ppVolumeTexture;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Width);
    rp(args.Height);
    rp(args.Depth);
    rp(args.Levels);
    rp(args.Usage);
    rp(args.Format);
    rp(args.Pool);
    readSharedHandle(rp, args.pSharedHandle);

    HRESULT res = self->CreateVolumeTexture(args.Width, args.Height, args.Depth, args.Levels, args.Usage, args.Format, args.Pool, &args.ppVolumeTexture, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppVolumeTexture));
    if (args.pSharedHandle) writeSharedHandle(wp, *args.pSharedHandle);
}

void Impl::CreateCubeTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT EdgeLength;
        UINT Levels;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DCubeTexture9* ppCubeTexture;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.EdgeLength);
    rp(args.Levels);
    rp(args.Usage);
    rp(args.Format);
    rp(args.Pool);
    readSharedHandle(rp, args.pSharedHandle);
    HRESULT res = self->CreateCubeTexture(args.EdgeLength, args.Levels, args.Usage, args.Format, args.Pool, &args.ppCubeTexture, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppCubeTexture));
    if (args.pSharedHandle) writeSharedHandle(wp, *args.pSharedHandle);
}

void Impl::CreateVertexBuffer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Length;
        DWORD Usage;
        DWORD FVF;
        D3DPOOL Pool;
        IDirect3DVertexBuffer9* ppVertexBuffer;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Length);
    rp(args.Usage);
    rp(args.FVF);
    rp(args.Pool);
    readSharedHandle(rp, args.pSharedHandle);
    HRESULT res = self->CreateVertexBuffer(args.Length, args.Usage, args.FVF, args.Pool, &args.ppVertexBuffer, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppVertexBuffer));
    if (args.pSharedHandle) writeSharedHandle(wp, *args.pSharedHandle);
}

void Impl::CreateIndexBuffer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Length;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DIndexBuffer9* ppIndexBuffer;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Length);
    rp(args.Usage);
    rp(args.Format);
    rp(args.Pool);
    readSharedHandle(rp, args.pSharedHandle);
    HRESULT res = self->CreateIndexBuffer(args.Length, args.Usage, args.Format, args.Pool, &args.ppIndexBuffer, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppIndexBuffer));
    if (args.pSharedHandle) writeSharedHandle(wp, *args.pSharedHandle);
}

void Impl::CreateRenderTarget(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        D3DFORMAT Format;
        D3DMULTISAMPLE_TYPE MultiSample;
        DWORD MultisampleQuality;
        BOOL Lockable;
        IDirect3DSurface9* ppSurface;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Width);
    rp(args.Height);
    rp(args.Format);
    rp(args.MultiSample);
    rp(args.MultisampleQuality);
    rp(args.Lockable);
    readSharedHandle(rp, args.pSharedHandle);
    HRESULT res = self->CreateRenderTarget(args.Width, args.Height, args.Format, args.MultiSample, args.MultisampleQuality, args.Lockable, &args.ppSurface, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppSurface));
    if (args.pSharedHandle) writeSharedHandle(wp, *args.pSharedHandle);
}

void Impl::CreateDepthStencilSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        D3DFORMAT Format;
        D3DMULTISAMPLE_TYPE MultiSample;
        DWORD MultisampleQuality;
        BOOL Discard;
        IDirect3DSurface9* ppSurface;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Width);
    rp(args.Height);
    rp(args.Format);
    rp(args.MultiSample);
    rp(args.MultisampleQuality);
    rp(args.Discard);
    readSharedHandle(rp, args.pSharedHandle);
    HRESULT res = self->CreateDepthStencilSurface(args.Width, args.Height, args.Format, args.MultiSample, args.MultisampleQuality, args.Discard, &args.ppSurface, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppSurface));
    if (args.pSharedHandle) writeSharedHandle(wp, *args.pSharedHandle);
}

void Impl::CreateOffscreenPlainSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DSurface9* ppSurface;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Width);
    rp(args.Height);
    rp(args.Format);
    rp(args.Pool);
    readSharedHandle(rp, args.pSharedHandle);
    HRESULT res = self->CreateOffscreenPlainSurface(args.Width, args.Height, args.Format, args.Pool, &args.ppSurface, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppSurface));
    if (args.pSharedHandle) writeSharedHandle(wp, *args.pSharedHandle);
}

} // namespace Server

} // namespace D3D9