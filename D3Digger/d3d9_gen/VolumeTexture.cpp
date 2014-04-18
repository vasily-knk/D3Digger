#include "VolumeTexture.h"

namespace D3Digger
{
namespace D3D9
{
namespace VolumeTexture
{

ProxyBase::ProxyBase(IBasePtr pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase::SetPrivateData(REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags)
{
    return pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
}

HRESULT ProxyBase::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    return pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
}

HRESULT ProxyBase::FreePrivateData(REFGUID refguid)
{
    return pimpl_->FreePrivateData(refguid);
}

DWORD ProxyBase::SetPriority(DWORD PriorityNew)
{
    return pimpl_->SetPriority(PriorityNew);
}

DWORD ProxyBase::GetPriority()
{
    return pimpl_->GetPriority();
}

void ProxyBase::PreLoad()
{
    pimpl_->PreLoad();
}

D3DRESOURCETYPE ProxyBase::GetType()
{
    return pimpl_->GetType();
}

DWORD ProxyBase::SetLOD(DWORD LODNew)
{
    return pimpl_->SetLOD(LODNew);
}

DWORD ProxyBase::GetLOD()
{
    return pimpl_->GetLOD();
}

DWORD ProxyBase::GetLevelCount()
{
    return pimpl_->GetLevelCount();
}

HRESULT ProxyBase::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
    return pimpl_->SetAutoGenFilterType(FilterType);
}

D3DTEXTUREFILTERTYPE ProxyBase::GetAutoGenFilterType()
{
    return pimpl_->GetAutoGenFilterType();
}

void ProxyBase::GenerateMipSubLevels()
{
    pimpl_->GenerateMipSubLevels();
}

HRESULT ProxyBase::GetLevelDesc(UINT Level, D3DVOLUME_DESC* pDesc)
{
    return pimpl_->GetLevelDesc(Level, pDesc);
}

HRESULT ProxyBase::GetVolumeLevel(UINT Level, IDirect3DVolume9** ppVolumeLevel)
{
    return pimpl_->GetVolumeLevel(Level, ppVolumeLevel);
}

HRESULT ProxyBase::LockBox(UINT Level, D3DLOCKED_BOX* pLockedVolume, CONST D3DBOX* pBox, DWORD Flags)
{
    return pimpl_->LockBox(Level, pLockedVolume, pBox, Flags);
}

HRESULT ProxyBase::UnlockBox(UINT Level)
{
    return pimpl_->UnlockBox(Level);
}

HRESULT ProxyBase::AddDirtyBox(CONST D3DBOX* pDirtyBox)
{
    return pimpl_->AddDirtyBox(pDirtyBox);
}

IBasePtr ProxyBase::getPImpl() const
{
    return pimpl_;
}

} // namespace D3Digger

} // namespace D3D9

} // namespace VolumeTexture


