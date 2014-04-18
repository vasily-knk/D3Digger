#include "PixelShader.h"

namespace D3Digger
{
namespace D3D9
{
namespace PixelShader
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

HRESULT ProxyBase::GetFunction(void* unnamed0, UINT* pSizeOfData)
{
    return pimpl_->GetFunction(unnamed0, pSizeOfData);
}

} // namespace D3Digger

} // namespace D3D9

} // namespace PixelShader


