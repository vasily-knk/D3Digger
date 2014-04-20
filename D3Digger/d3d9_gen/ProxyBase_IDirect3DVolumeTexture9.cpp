#include "ProxyBase.h"


ProxyBase_IDirect3DVolumeTexture9::ProxyBase_IDirect3DVolumeTexture9(IDirect3DVolumeTexture9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3DVolumeTexture9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3DVolumeTexture9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::SetPrivateData(REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags)
{
    return pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    return pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::FreePrivateData(REFGUID refguid)
{
    return pimpl_->FreePrivateData(refguid);
}

DWORD ProxyBase_IDirect3DVolumeTexture9::SetPriority(DWORD PriorityNew)
{
    return pimpl_->SetPriority(PriorityNew);
}

DWORD ProxyBase_IDirect3DVolumeTexture9::GetPriority()
{
    return pimpl_->GetPriority();
}

void ProxyBase_IDirect3DVolumeTexture9::PreLoad()
{
    pimpl_->PreLoad();
}

D3DRESOURCETYPE ProxyBase_IDirect3DVolumeTexture9::GetType()
{
    return pimpl_->GetType();
}

DWORD ProxyBase_IDirect3DVolumeTexture9::SetLOD(DWORD LODNew)
{
    return pimpl_->SetLOD(LODNew);
}

DWORD ProxyBase_IDirect3DVolumeTexture9::GetLOD()
{
    return pimpl_->GetLOD();
}

DWORD ProxyBase_IDirect3DVolumeTexture9::GetLevelCount()
{
    return pimpl_->GetLevelCount();
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
    return pimpl_->SetAutoGenFilterType(FilterType);
}

D3DTEXTUREFILTERTYPE ProxyBase_IDirect3DVolumeTexture9::GetAutoGenFilterType()
{
    return pimpl_->GetAutoGenFilterType();
}

void ProxyBase_IDirect3DVolumeTexture9::GenerateMipSubLevels()
{
    pimpl_->GenerateMipSubLevels();
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::GetLevelDesc(UINT Level, D3DVOLUME_DESC* pDesc)
{
    return pimpl_->GetLevelDesc(Level, pDesc);
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::GetVolumeLevel(UINT Level, IDirect3DVolume9** ppVolumeLevel)
{
    return pimpl_->GetVolumeLevel(Level, ppVolumeLevel);
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::LockBox(UINT Level, D3DLOCKED_BOX* pLockedVolume, CONST D3DBOX* pBox, DWORD Flags)
{
    return pimpl_->LockBox(Level, pLockedVolume, pBox, Flags);
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::UnlockBox(UINT Level)
{
    return pimpl_->UnlockBox(Level);
}

HRESULT ProxyBase_IDirect3DVolumeTexture9::AddDirtyBox(CONST D3DBOX* pDirtyBox)
{
    return pimpl_->AddDirtyBox(pDirtyBox);
}


