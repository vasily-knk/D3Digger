#include "stdafx.h"
#include "ProxyImpl_Device.h"


namespace D3D9
{
namespace Client
{

namespace
{
    typedef ProxyImpl<IDirect3DDevice9> Impl;

    void readSharedHandle(bytes::read_proc &/*proc*/, HANDLE & /*dst*/)
    {
    }

    void writeSharedHandle(bytes::write_proc &/*proc*/, optional<HANDLE> const &/*src*/)
    {
    }

}

Impl::ProxyImpl(ProxyId id)
    : Base(id)
{
    
}

HRESULT Impl::Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);

    wp(getId());
    wp(Count);
    for (size_t i = 0; i < Count; ++i)
        wp(pRects[i]);
    wp(Flags);
    wp(Color);
    wp(Z);
    wp(Stencil);
    
    getGlobal().executor().runAsync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::Clear), inBytes);
    
    return D3D_OK;
}

HRESULT Impl::Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);

    wp(getId());
    wp(ptr2opt(pSourceRect));
    wp(ptr2opt(pDestRect));
    wp(hDestWindowOverride);
    wp(ptr2opt(pDirtyRegion));
    
    getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::Present), inBytes);
    
    return D3D_OK;
}

HRESULT Impl::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Width);
    wp(Height);
    wp(Levels);
    wp(Usage);
    wp(Format);
    wp(Pool);
    writeSharedHandle(wp, ptr2opt(pSharedHandle));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateTexture), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppTexture = getGlobal().proxyMap().getById<IDirect3DTexture9>(rp.operator()<ProxyId>());
    if (pSharedHandle) readSharedHandle(rp, *pSharedHandle);
    return ret;
}

HRESULT Impl::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Width);
    wp(Height);
    wp(Depth);
    wp(Levels);
    wp(Usage);
    wp(Format);
    wp(Pool);
    writeSharedHandle(wp, ptr2opt(pSharedHandle));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateVolumeTexture), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppVolumeTexture = getGlobal().proxyMap().getById<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    if (pSharedHandle) readSharedHandle(rp, *pSharedHandle);
    return ret;
}

HRESULT Impl::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(EdgeLength);
    wp(Levels);
    wp(Usage);
    wp(Format);
    wp(Pool);
    writeSharedHandle(wp, ptr2opt(pSharedHandle));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateCubeTexture), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppCubeTexture = getGlobal().proxyMap().getById<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    if (pSharedHandle) readSharedHandle(rp, *pSharedHandle);
    return ret;
}

HRESULT Impl::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Length);
    wp(Usage);
    wp(FVF);
    wp(Pool);
    writeSharedHandle(wp, ptr2opt(pSharedHandle));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateVertexBuffer), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppVertexBuffer = getGlobal().proxyMap().getById<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    if (pSharedHandle) readSharedHandle(rp, *pSharedHandle);
    return ret;
}

HRESULT Impl::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Length);
    wp(Usage);
    wp(Format);
    wp(Pool);
    writeSharedHandle(wp, ptr2opt(pSharedHandle));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateIndexBuffer), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppIndexBuffer = getGlobal().proxyMap().getById<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    if (pSharedHandle) readSharedHandle(rp, *pSharedHandle);
    return ret;
}

HRESULT Impl::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Width);
    wp(Height);
    wp(Format);
    wp(MultiSample);
    wp(MultisampleQuality);
    wp(Lockable);
    writeSharedHandle(wp, ptr2opt(pSharedHandle));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateRenderTarget), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppSurface = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());
    if (pSharedHandle) readSharedHandle(rp, *pSharedHandle);
    return ret;
}

HRESULT Impl::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Width);
    wp(Height);
    wp(Format);
    wp(MultiSample);
    wp(MultisampleQuality);
    wp(Discard);
    writeSharedHandle(wp, ptr2opt(pSharedHandle));
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateDepthStencilSurface), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppSurface = getGlobal().proxyMap().getById<IDirect3DSurface9>(rp.operator()<ProxyId>());
    if (pSharedHandle) readSharedHandle(rp, *pSharedHandle);
    return ret;
}


} // namespace Client

} // namespace D3D9