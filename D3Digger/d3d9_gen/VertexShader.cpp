#include "VertexShader.h"

namespace D3Digger
{
namespace D3D9
{
namespace VertexShader
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

HRESULT ProxyBase::GetFunction(void* unnamed0, UINT* pSizeOfData)
{
    return pimpl_->GetFunction(unnamed0, pSizeOfData);
}

IBasePtr ProxyBase::getPImpl() const
{
    return pimpl_;
}

} // namespace D3Digger

} // namespace D3D9

} // namespace VertexShader


