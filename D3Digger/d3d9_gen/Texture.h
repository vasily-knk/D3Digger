#pragma once

namespace D3Digger
{
namespace D3D9
{
namespace Texture
{

typedef IDirect3DTexture9 IBase;
typedef IDirect3DTexture9 *IBasePtr;
            
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
    DWORD STDMETHODCALLTYPE SetLOD(DWORD LODNew) override;
    DWORD STDMETHODCALLTYPE GetLOD() override;
    DWORD STDMETHODCALLTYPE GetLevelCount() override;
    HRESULT STDMETHODCALLTYPE SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType) override;
    D3DTEXTUREFILTERTYPE STDMETHODCALLTYPE GetAutoGenFilterType() override;
    void STDMETHODCALLTYPE GenerateMipSubLevels() override;
    HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DSURFACE_DESC* pDesc) override;
    HRESULT STDMETHODCALLTYPE GetSurfaceLevel(UINT Level, IDirect3DSurface9** ppSurfaceLevel) override;
    HRESULT STDMETHODCALLTYPE LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags) override;
    HRESULT STDMETHODCALLTYPE UnlockRect(UINT Level) override;
    HRESULT STDMETHODCALLTYPE AddDirtyRect(CONST RECT* pDirtyRect) override;

    IBasePtr getPImpl() const;

private:
    IBasePtr pimpl_;
};
            
typedef ProxyBase *ProxyBasePtr;
} // namespace D3Digger

} // namespace D3D9

} // namespace Texture


