#include "Surface.h"

namespace D3Digger
{
namespace D3D9
{
namespace Surface
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

HRESULT ProxyBase::GetContainer(REFIID riid, void** ppContainer)
{
    return pimpl_->GetContainer(riid, ppContainer);
}

HRESULT ProxyBase::GetDesc(D3DSURFACE_DESC* pDesc)
{
    return pimpl_->GetDesc(pDesc);
}

HRESULT ProxyBase::LockRect(D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags)
{
    return pimpl_->LockRect(pLockedRect, pRect, Flags);
}

HRESULT ProxyBase::UnlockRect()
{
    return pimpl_->UnlockRect();
}

HRESULT ProxyBase::GetDC(HDC* phdc)
{
    return pimpl_->GetDC(phdc);
}

HRESULT ProxyBase::ReleaseDC(HDC hdc)
{
    return pimpl_->ReleaseDC(hdc);
}

IBasePtr ProxyBase::getPImpl() const
{
    return pimpl_;
}

} // namespace D3Digger

} // namespace D3D9

} // namespace Surface


