#pragma once

namespace D3Digger
{
namespace D3D9
{
namespace StateBlock
{

typedef IDirect3DStateBlock9 IBase;
typedef IDirect3DStateBlock9 *IBasePtr;
            
struct ProxyBase
    : IBase
{
    ProxyBase(IBasePtr pimpl);
            
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObj) override;
    ULONG STDMETHODCALLTYPE AddRef() override;
    ULONG STDMETHODCALLTYPE Release() override;
    HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice9** ppDevice) override;
    HRESULT STDMETHODCALLTYPE Capture() override;
    HRESULT STDMETHODCALLTYPE Apply() override;

    IBasePtr getPImpl() const;

private:
    IBasePtr pimpl_;
};
            
typedef ProxyBase *ProxyBasePtr;
} // namespace D3Digger

} // namespace D3D9

} // namespace StateBlock


