#include "ProxyBase.h"


ProxyBase_IDirect3DPixelShader9::ProxyBase_IDirect3DPixelShader9(IDirect3DPixelShader9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3DPixelShader9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3DPixelShader9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3DPixelShader9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3DPixelShader9::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase_IDirect3DPixelShader9::GetFunction(void* unnamed0, UINT* pSizeOfData)
{
    return pimpl_->GetFunction(unnamed0, pSizeOfData);
}


