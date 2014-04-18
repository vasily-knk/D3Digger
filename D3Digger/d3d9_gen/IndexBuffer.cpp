#include "IndexBuffer.h"

namespace D3Digger
{
namespace D3D9
{
namespace IndexBuffer
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

HRESULT ProxyBase::Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags)
{
    return pimpl_->Lock(OffsetToLock, SizeToLock, ppbData, Flags);
}

HRESULT ProxyBase::Unlock()
{
    return pimpl_->Unlock();
}

HRESULT ProxyBase::GetDesc(D3DINDEXBUFFER_DESC* pDesc)
{
    return pimpl_->GetDesc(pDesc);
}

} // namespace D3Digger

} // namespace D3D9

} // namespace IndexBuffer


