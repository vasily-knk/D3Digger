#include "ProxyBase.h"


ProxyBase_IDirect3DVertexBuffer9::ProxyBase_IDirect3DVertexBuffer9(IDirect3DVertexBuffer9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3DVertexBuffer9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3DVertexBuffer9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3DVertexBuffer9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3DVertexBuffer9::GetDevice(IDirect3DDevice9** ppDevice)
{
    return pimpl_->GetDevice(ppDevice);
}

HRESULT ProxyBase_IDirect3DVertexBuffer9::SetPrivateData(REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags)
{
    return pimpl_->SetPrivateData(refguid, pData, SizeOfData, Flags);
}

HRESULT ProxyBase_IDirect3DVertexBuffer9::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
    return pimpl_->GetPrivateData(refguid, pData, pSizeOfData);
}

HRESULT ProxyBase_IDirect3DVertexBuffer9::FreePrivateData(REFGUID refguid)
{
    return pimpl_->FreePrivateData(refguid);
}

DWORD ProxyBase_IDirect3DVertexBuffer9::SetPriority(DWORD PriorityNew)
{
    return pimpl_->SetPriority(PriorityNew);
}

DWORD ProxyBase_IDirect3DVertexBuffer9::GetPriority()
{
    return pimpl_->GetPriority();
}

void ProxyBase_IDirect3DVertexBuffer9::PreLoad()
{
    pimpl_->PreLoad();
}

D3DRESOURCETYPE ProxyBase_IDirect3DVertexBuffer9::GetType()
{
    return pimpl_->GetType();
}

HRESULT ProxyBase_IDirect3DVertexBuffer9::Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags)
{
    return pimpl_->Lock(OffsetToLock, SizeToLock, ppbData, Flags);
}

HRESULT ProxyBase_IDirect3DVertexBuffer9::Unlock()
{
    return pimpl_->Unlock();
}

HRESULT ProxyBase_IDirect3DVertexBuffer9::GetDesc(D3DVERTEXBUFFER_DESC* pDesc)
{
    return pimpl_->GetDesc(pDesc);
}


