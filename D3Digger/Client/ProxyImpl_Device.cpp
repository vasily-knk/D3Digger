#include "stdafx.h"
#include "ProxyImpl_Device.h"
#include "Shaders.h"


namespace D3D9
{
namespace Client
{

namespace
{
    typedef ProxyImpl<IDirect3DDevice9> Impl;

    vector<D3DVERTEXELEMENT9> extractVertexElements(D3DVERTEXELEMENT9 const *p)
    {
        vector<D3DVERTEXELEMENT9> res;

        for (; p->Stream != 0xFF; ++p)
            res.push_back(*p);
        
        res.push_back(*p);

        return res;
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

HRESULT Impl::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(Type);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateQuery), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    
    ProxyId result_id;
    rp(result_id);
    if (ppQuery) *ppQuery = getGlobal().proxyMap().getById<IDirect3DQuery9>(result_id);

    return ret;
}

HRESULT Impl::CreateVertexDeclaration(const D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
    vector<D3DVERTEXELEMENT9> elements = extractVertexElements(pVertexElements);

    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(elements);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateVertexDeclaration), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppDecl = getGlobal().proxyMap().getById<IDirect3DVertexDeclaration9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT Impl::CreateVertexShader(const DWORD* /*pFunction*/, IDirect3DVertexShader9** ppShader)
{
    if (!ppShader)
        return D3DERR_INVALIDCALL;

    *ppShader = nullptr;
    return D3D_OK;
}

HRESULT Impl::CreatePixelShader(const DWORD* /*pFunction*/, IDirect3DPixelShader9** ppShader)
{
    if (!ppShader)
        return D3DERR_INVALIDCALL;

    *ppShader = nullptr;
    return D3D_OK;
}

/*
HRESULT Impl::CreateVertexShader(const DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
    uint32_t shader_length = getShaderSize(pFunction);
    
    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(shader_length);
    wp.array(pFunction, shader_length);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreateVertexShader), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppShader = getGlobal().proxyMap().getById<IDirect3DVertexShader9>(rp.operator()<ProxyId>());
    return ret;
}

HRESULT Impl::CreatePixelShader(const DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
    uint32_t shader_length = getShaderSize(pFunction);

    BytesPtr inBytes = bytes::make();
    bytes::write_proc wp(inBytes);
    wp(getId());
    wp(shader_length);
    wp.array(pFunction, shader_length);
    
    BytesPtr outBytes = getGlobal().executor().runSync(makeMethodId(Interfaces::IDirect3DDevice9, Methods_IDirect3DDevice9::CreatePixelShader), inBytes);
    
    bytes::read_proc rp(outBytes);
    HRESULT ret; rp(ret);
    *ppShader = getGlobal().proxyMap().getById<IDirect3DPixelShader9>(rp.operator()<ProxyId>());
    return ret;
}*/


} // namespace Client

} // namespace D3D9