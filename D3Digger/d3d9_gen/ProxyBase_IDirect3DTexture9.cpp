#include "ProxyBase.h"


ProxyBase_IDirect3DTexture9::ProxyBase_IDirect3DTexture9(IDirect3DTexture9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3DTexture9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3DTexture9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3DTexture9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3DTexture9::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase_IDirect3DTexture9::SetPrivateData(REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags)
{
    return pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
}

HRESULT ProxyBase_IDirect3DTexture9::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    return pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
}

HRESULT ProxyBase_IDirect3DTexture9::FreePrivateData(REFGUID refguid)
{
    return pimpl_->FreePrivateData(refguid);
}

DWORD ProxyBase_IDirect3DTexture9::SetPriority(DWORD PriorityNew)
{
    return pimpl_->SetPriority(PriorityNew);
}

DWORD ProxyBase_IDirect3DTexture9::GetPriority()
{
    return pimpl_->GetPriority();
}

void ProxyBase_IDirect3DTexture9::PreLoad()
{
    pimpl_->PreLoad();
}

D3DRESOURCETYPE ProxyBase_IDirect3DTexture9::GetType()
{
    return pimpl_->GetType();
}

DWORD ProxyBase_IDirect3DTexture9::SetLOD(DWORD LODNew)
{
    return pimpl_->SetLOD(LODNew);
}

DWORD ProxyBase_IDirect3DTexture9::GetLOD()
{
    return pimpl_->GetLOD();
}

DWORD ProxyBase_IDirect3DTexture9::GetLevelCount()
{
    return pimpl_->GetLevelCount();
}

HRESULT ProxyBase_IDirect3DTexture9::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
    return pimpl_->SetAutoGenFilterType(FilterType);
}

D3DTEXTUREFILTERTYPE ProxyBase_IDirect3DTexture9::GetAutoGenFilterType()
{
    return pimpl_->GetAutoGenFilterType();
}

void ProxyBase_IDirect3DTexture9::GenerateMipSubLevels()
{
    pimpl_->GenerateMipSubLevels();
}

HRESULT ProxyBase_IDirect3DTexture9::GetLevelDesc(UINT Level, D3DSURFACE_DESC* pDesc)
{
    return pimpl_->GetLevelDesc(Level, pDesc);
}

HRESULT ProxyBase_IDirect3DTexture9::GetSurfaceLevel(UINT Level, IDirect3DSurface9** ppSurfaceLevel)
{
    return pimpl_->GetSurfaceLevel(Level, ppSurfaceLevel);
}

HRESULT ProxyBase_IDirect3DTexture9::LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags)
{
    return pimpl_->LockRect(Level, pLockedRect, pRect, Flags);
}

HRESULT ProxyBase_IDirect3DTexture9::UnlockRect(UINT Level)
{
    return pimpl_->UnlockRect(Level);
}

HRESULT ProxyBase_IDirect3DTexture9::AddDirtyRect(CONST RECT* pDirtyRect)
{
    return pimpl_->AddDirtyRect(pDirtyRect);
}


