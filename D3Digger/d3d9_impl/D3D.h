#pragma once

#include "../d3d9_gen/D3D.h"
#include "HierElem.h"
#include "fwd.h"

namespace D3Digger
{
namespace D3D9
{
namespace D3D
{

struct ProxyImpl
    : IHierElem
    , ProxyBase
{
    static ProxyImplPtr create(IBasePtr pimpl);
    ~ProxyImpl();

    ULONG STDMETHODCALLTYPE Release() override;

public:
    HRESULT STDMETHODCALLTYPE CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface) override;

private:
    ProxyImpl(IBasePtr pimpl);

private:
    HierElemKeeper keeper_;
};

} // namespace Device

} // namespace D3D9

} // namespace D3Digger
