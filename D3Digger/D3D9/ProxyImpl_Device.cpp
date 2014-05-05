#include "stdafx.h"
#include "ProxyImpl_Device.h"
#include "ProxyImpl_Texture.h"
#include "ProxyImpl_VertexBuffer.h"

ProxyImplDevice::ProxyImplDevice(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
    , frameStatsStream_("frame_stats.txt")
    , oReleased(true)
    , disableVBLocks_(false)
    , currentFrame_(0)
{
    static vector<string> names = boost::assign::list_of("drawUps")("texLocks")("vbLocks")("ibLocks")("shaderConsts")("Total");

    std::ostream_iterator<string> out_it (frameStatsStream_, "; ");
    std::copy(names.begin(), names.end(), out_it);
    frameStatsStream_ << endl;

    init();
}


HRESULT ProxyImplDevice::Reset(D3DPRESENT_PARAMETERS *pPresentationParameters)
{
    notex_.reset();
    
    HRESULT res = MyProxyBase::Reset(pPresentationParameters);
    init();
    
    return res;
}

void ProxyImplDevice::init()
{
    IDirect3DTexture9 *notexPimpl = nullptr;
    HRESULT res = D3DXCreateTextureFromFileA(pimpl_, "D:\\notex.png", &notexPimpl);
    assert(SUCCEEDED(res));

    notex_ = intrusive_ptr<IDirect3DTexture9>(notexPimpl, false);
}

HRESULT ProxyImplDevice::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pBaseTex)
{
    renderTargets_.erase(Stage);
    
    if (pBaseTex) 
    {
        if (pBaseTex->GetType() == D3DRTYPE_TEXTURE)
        {
            TextureProxyPtr pTexture(dynamic_cast<TextureProxyRawPtr>(pBaseTex), true);
            assert(pTexture);

            D3DSURFACE_DESC desc;
            HRESULT res = pTexture->GetLevelDesc(0, &desc);            
            assert(SUCCEEDED(res));
            if ((desc.Usage & D3DUSAGE_RENDERTARGET) != 0)
                renderTargets_.insert(Stage);
            else
            {
                auto texUpdateFrame = pTexture->lastUpdateFrame();
                if (!texUpdateFrame || *texUpdateFrame > lastAllowedLockFrame_)             
                    return pimpl_->SetTexture(Stage, notex_.get());      
            }
        }
    }

    return MyProxyBase::SetTexture(Stage, pBaseTex);
}

HRESULT ProxyImplDevice::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
    bool oState = (GetAsyncKeyState(0x4F) & (1 << 15)) != 0;
    
    if (oState && oReleased)
    {
        lastAllowedLockFrame_ = currentFrame_;
    }
    
    oReleased = !oState;
    
    static const size_t NUM_FRAMES = 10;
    
    frameStats_.push_back(currentFramesStats_);
    if (frameStats_.size() >= NUM_FRAMES)
    {
        assert(frameStats_.size() == NUM_FRAMES);
        
        dumpFrameStats();

        frameStats_.clear();
    }

    currentFramesStats_ = FrameStats();
    ++currentFrame_;

    dirtyVBs_.clear();
    renderTargets_.clear();
    return ProxyBase<IDirect3DDevice9>::Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

void ProxyImplDevice::dumpFrameStats()
{
    assert(!frameStats_.empty());
    
    size_t n = frameStats_.size();

    FrameStats avg;
    avg.drawUps      = std::accumulate(frameStats_.begin(), frameStats_.end(), 0, [](size_t init, FrameStats const &s) { return init + s.drawUps      ; }) / n / 1024;
    avg.texLocks     = std::accumulate(frameStats_.begin(), frameStats_.end(), 0, [](size_t init, FrameStats const &s) { return init + s.texLocks     ; }) / n / 1024;
    avg.vbLocks      = std::accumulate(frameStats_.begin(), frameStats_.end(), 0, [](size_t init, FrameStats const &s) { return init + s.vbLocks      ; }) / n / 1024;
    avg.ibLocks      = std::accumulate(frameStats_.begin(), frameStats_.end(), 0, [](size_t init, FrameStats const &s) { return init + s.ibLocks      ; }) / n / 1024;
    avg.shaderConsts = std::accumulate(frameStats_.begin(), frameStats_.end(), 0, [](size_t init, FrameStats const &s) { return init + s.shaderConsts ; }) / n / 1024;

    size_t total = avg.drawUps + avg.texLocks + avg.vbLocks + avg.ibLocks + avg.shaderConsts;
    vector<size_t> values = boost::assign::list_of(avg.drawUps)(avg.texLocks)(avg.vbLocks)(avg.ibLocks)(avg.shaderConsts)(total);
    std::ostream_iterator<size_t> out_it (frameStatsStream_, "; ");
    std::copy(values.begin(), values.end(), out_it);
    frameStatsStream_ << endl;
    frameStatsStream_.flush();
}

HRESULT ProxyImplDevice::SetVertexShaderConstantF(UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount)
{
    currentFramesStats_.shaderConsts += Vector4fCount * 16;
    return ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT ProxyImplDevice::SetVertexShaderConstantI(UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
{
    currentFramesStats_.shaderConsts += Vector4iCount * 16;
    return ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT ProxyImplDevice::SetVertexShaderConstantB(UINT StartRegister,CONST BOOL* pConstantData,UINT BoolCount)
{
    currentFramesStats_.shaderConsts += BoolCount * 4;
    return ProxyBase<IDirect3DDevice9>::SetVertexShaderConstantI(StartRegister, pConstantData, BoolCount);
}

HRESULT ProxyImplDevice::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
    size_t numVerts = primCount2NumVerts(PrimitiveType, PrimitiveCount);
    currentFramesStats_.drawUps += numVerts * VertexStreamZeroStride;       
    
    if (getLastAllowedLockFrame() && *getLastAllowedLockFrame() < currentFrame_ && renderTargets_.empty())
        return D3D_OK;        

    return ProxyBase<IDirect3DDevice9>::DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride); 
}

HRESULT ProxyImplDevice::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
    size_t indexSize = (IndexDataFormat == D3DFMT_INDEX16) ? 2 : 4;
    size_t numIndices = primCount2NumVerts(PrimitiveType, PrimitiveCount);
    currentFramesStats_.drawUps += NumVertices * VertexStreamZeroStride + numIndices * indexSize;

    if (getLastAllowedLockFrame() && *getLastAllowedLockFrame() < currentFrame_ && renderTargets_.empty())
        return D3D_OK;        

    return ProxyBase<IDirect3DDevice9>::DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}                                           

size_t ProxyImplDevice::primCount2NumVerts(D3DPRIMITIVETYPE PrimitiveType, size_t PrimitiveCount)
{
    switch(PrimitiveType)
    {
    case D3DPT_POINTLIST     : return PrimitiveCount; break;
    case D3DPT_LINELIST      : return PrimitiveCount * 2; break;
    case D3DPT_LINESTRIP     : return PrimitiveCount + 1; break;
    case D3DPT_TRIANGLELIST  : return PrimitiveCount * 3; break;
    case D3DPT_TRIANGLESTRIP : return PrimitiveCount + 2; break;
    case D3DPT_TRIANGLEFAN   : return PrimitiveCount + 2; break;
    default:
        assert(false);
    }
    return PrimitiveCount;
}

void ProxyImplDevice::appendVBLock(size_t size)
{
    currentFramesStats_.vbLocks += size;
}

void ProxyImplDevice::appendTexLock(size_t size)
{
    currentFramesStats_.texLocks += size;
}

HRESULT STDMETHODCALLTYPE ProxyImplDevice::SetStreamSource(UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride)
{
    if (StreamNumber >= vbs_.size())
        vbs_.resize(StreamNumber + 1, nullptr);
    
    dirtyVBs_.erase(StreamNumber);
    if (pStreamData)
    {
        ProxyImplVertexBuffer *vb = dynamic_cast<ProxyImplVertexBuffer*>(pStreamData);
        assert(vb);
        assert(!vb->isLocked());

        if (getLastAllowedLockFrame() && vb->lastLockFrame() && *vb->lastLockFrame() > *getLastAllowedLockFrame())
            dirtyVBs_.insert(StreamNumber);

        vbs_.at(StreamNumber) = vb;
    }
    else
    {
        vbs_.at(StreamNumber) = nullptr;
    }

    return MyProxyBase::SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT STDMETHODCALLTYPE ProxyImplDevice::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount)
{
    if (!renderTargets_.empty())
        processRenderTargets();

    if (!dirtyVBs_.empty() && renderTargets_.empty())
        return D3D_OK;

    return MyProxyBase::DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT STDMETHODCALLTYPE ProxyImplDevice::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{
    if (!renderTargets_.empty())
        processRenderTargets();

    if (!dirtyVBs_.empty() && renderTargets_.empty())
        return D3D_OK;

    return MyProxyBase::DrawIndexedPrimitive(PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT ProxyImplDevice::UpdateSurface(IDirect3DSurface9* pSourceSurface, const RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, const POINT* pDestPoint)
{
    if (pDestinationSurface)
    {
        SurfaceProxyPtr dst(dynamic_cast<SurfaceProxyRawPtr>(pDestinationSurface), true);
        dst->invalidate();
    }
    return MyProxyBase::UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}

HRESULT ProxyImplDevice::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
{
    if (pDestinationTexture)
    {
        TextureProxyPtr dst(dynamic_cast<TextureProxyRawPtr>(pDestinationTexture), true);
        dst->invalidate();
    }

    return MyProxyBase::UpdateTexture(pSourceTexture, pDestinationTexture);
}

void ProxyImplDevice::processRenderTargets()
{
    int aaa = 5;
}
