#include "VertexDeclaration.h"

namespace D3Digger
{
namespace D3D9
{
namespace VertexDeclaration
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

HRESULT ProxyBase::GetDeclaration(D3DVERTEXELEMENT9* pElement, UINT* pNumElements)
{
    return pimpl_->GetDeclaration(pElement, pNumElements);
}

IBasePtr ProxyBase::getPImpl() const
{
    return pimpl_;
}

} // namespace D3Digger

} // namespace D3D9

} // namespace VertexDeclaration


