#include "Texture.h"

namespace D3Digger
{
namespace D3D9
{
namespace Texture
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
    return pimpl_->Release();
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

HRESULT ProxyBase::GetLevelDesc(UINT Level, D3DSURFACE_DESC* pDesc)
{
    return pimpl_->GetLevelDesc(Level, pDesc);
}

HRESULT ProxyBase::GetSurfaceLevel(UINT Level, IDirect3DSurface9** ppSurfaceLevel)
{
    return pimpl_->GetSurfaceLevel(Level, ppSurfaceLevel);
}

HRESULT ProxyBase::LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags)
{
    return pimpl_->LockRect(Level, pLockedRect, pRect, Flags);
}

HRESULT ProxyBase::UnlockRect(UINT Level)
{
    return pimpl_->UnlockRect(Level);
}

HRESULT ProxyBase::AddDirtyRect(CONST RECT* pDirtyRect)
{
    return pimpl_->AddDirtyRect(pDirtyRect);
}

} // namespace D3Digger

} // namespace D3D9

} // namespace Texture


