#pragma once

#include "ProxyImpl.h"


struct ProxyImplDevice
    : ProxyBase<IDirect3DDevice9>
{
    typedef IDirect3DDevice9 IBase;
    typedef ProxyBase<IDirect3DDevice9> MyProxyBase;

    ProxyImplDevice(IBase *pimpl);
    HRESULT STDMETHODCALLTYPE SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture) override;

    HRESULT STDMETHODCALLTYPE Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion) override;

    HRESULT STDMETHODCALLTYPE SetVertexShaderConstantF( UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount) override;
    HRESULT STDMETHODCALLTYPE SetVertexShaderConstantI( UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount) override;
    HRESULT STDMETHODCALLTYPE SetVertexShaderConstantB( UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount) override;
    HRESULT STDMETHODCALLTYPE DrawPrimitiveUP( D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) override;
    HRESULT STDMETHODCALLTYPE DrawIndexedPrimitiveUP( D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) override;
    
    HRESULT STDMETHODCALLTYPE SetStreamSource(UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride) override;

    HRESULT STDMETHODCALLTYPE DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount) override;
    HRESULT STDMETHODCALLTYPE DrawIndexedPrimitive(D3DPRIMITIVETYPE,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount) override;
    HRESULT STDMETHODCALLTYPE Reset(D3DPRESENT_PARAMETERS *pPresentationParameters) override;

    HRESULT STDMETHODCALLTYPE UpdateSurface(IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,CONST POINT* pDestPoint) override;
    HRESULT STDMETHODCALLTYPE UpdateTexture(IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture) override;

public:
    void appendVBLock(size_t size) override;
    void appendTexLock(size_t size) override;
    bool getDisableVBLocks() const override { return disableVBLocks_; } ;
    int getCurrentFrame() const override { return currentFrame_; }
    optional<int> getLastAllowedLockFrame() const override { return boost::none; }

private:
    void dumpFrameStats();
    static size_t primCount2NumVerts(D3DPRIMITIVETYPE PrimitiveType, size_t PrimitiveCount);
    void processRenderTargets();

    void init();

private:
    struct FrameStats
    {
        FrameStats()
            : drawUps(0)
            , texLocks(0)
            , vbLocks(0)
            , ibLocks(0)
            , shaderConsts(0)
        {

        }

        size_t drawUps, texLocks, vbLocks, ibLocks, shaderConsts;
    };

    vector<FrameStats> frameStats_;
    FrameStats currentFramesStats_;
    ofstream frameStatsStream_;

    bool oReleased;
    bool disableVBLocks_;
    
private:
    int currentFrame_;
    optional<int> lastAllowedLockFrame_;
    set<size_t> dirtyVBs_;
    set<size_t> renderTargets_;

    vector<IProxy<IDirect3DVertexBuffer9> *> vbs_;

    intrusive_ptr<IDirect3DTexture9> notex_;
};

template<>
struct ProxyImplHelper<IDirect3DDevice9>
{
    typedef ProxyImplDevice Type;
};
