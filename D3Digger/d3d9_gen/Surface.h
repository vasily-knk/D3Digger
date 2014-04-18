#pragma once

namespace D3Digger
{
namespace D3D9
{
namespace Surface
{

typedef IDirect3DSurface9 IBase;
typedef IDirect3DSurface9 *IBasePtr;
            
struct ProxyBase
    : IBase
{
    ProxyBase(IBasePtr pimpl);
            
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObj) override;
    ULONG STDMETHODCALLTYPE AddRef() override;
    ULONG STDMETHODCALLTYPE Release() override;
    HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice9** ppDevice) override;
    HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags) override;
    HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData) override;
    HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override;
    DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override;
    DWORD STDMETHODCALLTYPE GetPriority() override;
    void STDMETHODCALLTYPE PreLoad() override;
    D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override;
    HRESULT STDMETHODCALLTYPE GetContainer(REFIID riid, void** ppContainer) override;
    HRESULT STDMETHODCALLTYPE GetDesc(D3DSURFACE_DESC* pDesc) override;
    HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags) override;
    HRESULT STDMETHODCALLTYPE UnlockRect() override;
    HRESULT STDMETHODCALLTYPE GetDC(HDC* phdc) override;
    HRESULT STDMETHODCALLTYPE ReleaseDC(HDC hdc) override;

    IBasePtr getPImpl() const;

private:
    IBasePtr pimpl_;
};
            
typedef ProxyBase *ProxyBasePtr;
} // namespace D3Digger

} // namespace D3D9

} // namespace Surface


