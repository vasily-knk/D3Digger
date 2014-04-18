// D3D9.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "gen/d3d9/D3D.h"
#include "gen/d3d9/Device.h"

namespace D3Digger
{
namespace D3D9
{

namespace Device
{
struct ProxyImpl
    : ProxyBase
{
    
};

}

namespace D3D
{

struct ProxyImpl
    : ProxyBase
{
    ProxyImpl(IBasePtr pimpl)
        : ProxyBase(pimpl)
    {
        ofstream out("D:\\d3d9.log");
        out << "Hello world!" << endl;
    }

    HRESULT STDMETHODCALLTYPE CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface) override
    {
        auto res = ProxyBase::CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
        Device::ProxyImpl *deviceProxy = new Device::ProxyBase(*ppReturnedDeviceInterface);
        *ppReturnedDeviceInterface = deviceProxy;
        return res;
    }

};

} // namespace D3D9

} // namespace D3D

} // namespace D3Digger

IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
    static auto dll = LoadLibrary(L"C:\\Windows\\System32\\d3d9.dll");
    typedef IDirect3D9* (WINAPI *fn_t)(UINT);

    auto fn = reinterpret_cast<fn_t>(GetProcAddress(dll, "Direct3DCreate9"));

    using namespace D3Digger::D3D9;
    D3D::IBasePtr pimpl = fn(SDKVersion);

    return new D3D::ProxyImpl(pimpl);
}