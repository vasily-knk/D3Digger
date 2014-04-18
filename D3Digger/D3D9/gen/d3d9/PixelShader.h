#pragma once

namespace D3Digger
{
namespace D3D9
{
namespace PixelShader
{

typedef IDirect3DPixelShader9 IBase;
typedef IDirect3DPixelShader9 *IBasePtr;
            
struct ProxyBase
    : IBase
{
    ProxyBase(IBasePtr pimpl);
            
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObj) override;
    ULONG STDMETHODCALLTYPE AddRef() override;
    ULONG STDMETHODCALLTYPE Release() override;
    HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice9** ppDevice) override;
    HRESULT STDMETHODCALLTYPE GetFunction(void*, UINT* pSizeOfData) override;

private:
    IBasePtr pimpl_;
};
            
typedef ProxyBase *ProxyBasePtr;
} // namespace D3Digger

} // namespace D3D9

} // namespace PixelShader


