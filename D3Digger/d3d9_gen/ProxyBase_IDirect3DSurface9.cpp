#include "ProxyBase.h"


ProxyBase_IDirect3DSurface9::ProxyBase_IDirect3DSurface9(IDirect3DSurface9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3DSurface9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3DSurface9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3DSurface9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3DSurface9::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase_IDirect3DSurface9::SetPrivateData(REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags)
{
    return pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
}

HRESULT ProxyBase_IDirect3DSurface9::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    return pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
}

HRESULT ProxyBase_IDirect3DSurface9::FreePrivateData(REFGUID refguid)
{
    return pimpl_->FreePrivateData(refguid);
}

DWORD ProxyBase_IDirect3DSurface9::SetPriority(DWORD PriorityNew)
{
    return pimpl_->SetPriority(PriorityNew);
}

DWORD ProxyBase_IDirect3DSurface9::GetPriority()
{
    return pimpl_->GetPriority();
}

void ProxyBase_IDirect3DSurface9::PreLoad()
{
    pimpl_->PreLoad();
}

D3DRESOURCETYPE ProxyBase_IDirect3DSurface9::GetType()
{
    return pimpl_->GetType();
}

HRESULT ProxyBase_IDirect3DSurface9::GetContainer(REFIID riid, void** ppContainer)
{
    return pimpl_->GetContainer(riid, ppContainer);
}

HRESULT ProxyBase_IDirect3DSurface9::GetDesc(D3DSURFACE_DESC* pDesc)
{
    return pimpl_->GetDesc(pDesc);
}

HRESULT ProxyBase_IDirect3DSurface9::LockRect(D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags)
{
    return pimpl_->LockRect(pLockedRect, pRect, Flags);
}

HRESULT ProxyBase_IDirect3DSurface9::UnlockRect()
{
    return pimpl_->UnlockRect();
}

HRESULT ProxyBase_IDirect3DSurface9::GetDC(HDC* phdc)
{
    return pimpl_->GetDC(phdc);
}

HRESULT ProxyBase_IDirect3DSurface9::ReleaseDC(HDC hdc)
{
    return pimpl_->ReleaseDC(hdc);
}


