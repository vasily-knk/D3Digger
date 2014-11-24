#pragma once

#include "ProxyImpl.h"

namespace D3D9
{
namespace Client
{

template<>
struct ProxyImpl<IDirect3DDevice9>
    : ProxyBase<IDirect3DDevice9>
{
    typedef ProxyBase<IDirect3DDevice9> Base;

    ProxyImpl(ProxyId id); 
    
    HRESULT STDMETHODCALLTYPE Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil) override;
    HRESULT STDMETHODCALLTYPE Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion) override;
    HRESULT STDMETHODCALLTYPE CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery) override;
    HRESULT STDMETHODCALLTYPE CreateVertexDeclaration(const D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl) override;
};

} // namespace Client

} // namespace D3D9