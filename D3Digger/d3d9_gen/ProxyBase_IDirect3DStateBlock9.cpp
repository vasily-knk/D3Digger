#include "ProxyBase.h"


ProxyBase_IDirect3DStateBlock9::ProxyBase_IDirect3DStateBlock9(IDirect3DStateBlock9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3DStateBlock9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3DStateBlock9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3DStateBlock9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3DStateBlock9::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase_IDirect3DStateBlock9::Capture()
{
    return pimpl_->Capture();
}

HRESULT ProxyBase_IDirect3DStateBlock9::Apply()
{
    return pimpl_->Apply();
}


