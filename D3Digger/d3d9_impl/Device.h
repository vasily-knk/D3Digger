#pragma once

#include "../d3d9_gen/Device.h"
#include "HierElem.h"
#include "fwd.h"

namespace D3Digger
{
namespace D3D9
{
namespace Device
{

struct ProxyImpl
    : IHierElem
    , ProxyBase
{
    static ProxyImplPtr create(IBasePtr pimpl);
    ~ProxyImpl();

    ULONG STDMETHODCALLTYPE Release() override;

    HRESULT STDMETHODCALLTYPE CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle) override;
    HRESULT STDMETHODCALLTYPE GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture) override;
    HRESULT STDMETHODCALLTYPE SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture) override;

private:
    IResPtr extractShared(IDirect3DBaseTexture9* pTexture) const;

private:
    ProxyImpl(IBasePtr pimpl);

private:
    HierElemKeeper keeper_;
    vector<IResPtr> textures_;
};

} // namespace Device

} // namespace D3D9

} // namespace D3Digger
