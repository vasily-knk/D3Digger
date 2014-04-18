#include "StateBlock.h"

namespace D3Digger
{
namespace D3D9
{
namespace StateBlock
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

HRESULT ProxyBase::Capture()
{
    return pimpl_->Capture();
}

HRESULT ProxyBase::Apply()
{
    return pimpl_->Apply();
}

} // namespace D3Digger

} // namespace D3D9

} // namespace StateBlock


