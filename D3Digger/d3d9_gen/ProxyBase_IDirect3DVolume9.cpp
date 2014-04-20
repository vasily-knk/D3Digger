#include "ProxyBase.h"


ProxyBase_IDirect3DVolume9::ProxyBase_IDirect3DVolume9(IDirect3DVolume9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3DVolume9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3DVolume9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3DVolume9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3DVolume9::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase_IDirect3DVolume9::SetPrivateData(REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags)
{
    return pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
}

HRESULT ProxyBase_IDirect3DVolume9::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    return pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
}

HRESULT ProxyBase_IDirect3DVolume9::FreePrivateData(REFGUID refguid)
{
    return pimpl_->FreePrivateData(refguid);
}

HRESULT ProxyBase_IDirect3DVolume9::GetContainer(REFIID riid, void** ppContainer)
{
    return pimpl_->GetContainer(riid, ppContainer);
}

HRESULT ProxyBase_IDirect3DVolume9::GetDesc(D3DVOLUME_DESC* pDesc)
{
    return pimpl_->GetDesc(pDesc);
}

HRESULT ProxyBase_IDirect3DVolume9::LockBox(D3DLOCKED_BOX* pLockedVolume, CONST D3DBOX* pBox, DWORD Flags)
{
    return pimpl_->LockBox(pLockedVolume, pBox, Flags);
}

HRESULT ProxyBase_IDirect3DVolume9::UnlockBox()
{
    return pimpl_->UnlockBox();
}


