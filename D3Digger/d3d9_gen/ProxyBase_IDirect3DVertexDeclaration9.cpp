#include "ProxyBase.h"


ProxyBase_IDirect3DVertexDeclaration9::ProxyBase_IDirect3DVertexDeclaration9(IDirect3DVertexDeclaration9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3DVertexDeclaration9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3DVertexDeclaration9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3DVertexDeclaration9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3DVertexDeclaration9::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase_IDirect3DVertexDeclaration9::GetDeclaration(D3DVERTEXELEMENT9* pElement, UINT* pNumElements)
{
    return pimpl_->GetDeclaration(pElement, pNumElements);
}


