#include "Volume.h"

namespace D3Digger
{
namespace D3D9
{
namespace Volume
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

HRESULT ProxyBase::GetContainer(REFIID riid, void** ppContainer)
{
    return pimpl_->GetContainer(riid, ppContainer);
}

HRESULT ProxyBase::GetDesc(D3DVOLUME_DESC* pDesc)
{
    return pimpl_->GetDesc(pDesc);
}

HRESULT ProxyBase::LockBox(D3DLOCKED_BOX* pLockedVolume, CONST D3DBOX* pBox, DWORD Flags)
{
    return pimpl_->LockBox(pLockedVolume, pBox, Flags);
}

HRESULT ProxyBase::UnlockBox()
{
    return pimpl_->UnlockBox();
}

} // namespace D3Digger

} // namespace D3D9

} // namespace Volume


