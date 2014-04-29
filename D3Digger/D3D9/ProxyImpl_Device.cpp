#include "stdafx.h"
#include "ProxyImpl_Device.h"
#include "ProxyImpl_Texture.h"

template<>
shared_ptr<IProxy<IDirect3DDevice9>> createProxy<IDirect3DDevice9>(IDirect3DDevice9 *pimpl)
{
    return make_shared<ProxyImplDevice>(pimpl);
}

ProxyImplDevice::ProxyImplDevice(IBase *pimpl)
    : ProxyBase<IBase>(pimpl)
    , frameStatsStream_("frame_stats.txt")
{
    static vector<string> names = boost::assign::list_of("drawUps")("texLocks")("vbLocks")("ibLocks")("shaderConsts");

    std::ostream_iterator<string> out_it (frameStatsStream_, "; ");
    std::copy(names.begin(), names.end(), out_it);
    frameStatsStream_ << endl;
}

HRESULT ProxyImplDevice::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
    logMethod("ProxyImplDevice", "SetTexture");
    if (pTexture) 
    {
        if (pTexture->GetType() == D3DRTYPE_TEXTURE)
        {
            auto impl = dynamic_cast<ProxyImplTexture*>(pTexture);
            assert(impl);
            impl->save();
        }
        pTexture = unwrapProxy<IDirect3DBaseTexture9>(pTexture);
    }

    auto res = pimpl_->SetTexture(Stage, pTexture);
    return res;
}

HRESULT ProxyImplDevice::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
    static const size_t NUM_FRAMES = 10;
    
    frameStats_.push_back(currentFramesStats_);
    if (frameStats_.size() >= NUM_FRAMES)
    {
        assert(frameStats_.size() == NUM_FRAMES);
        
        dumpFrameStats();

        frameStats_.clear();
    }

    currentFramesStats_ = FrameStats();
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

    vector<size_t> values = boost::assign::list_of(avg.drawUps)(avg.texLocks)(avg.vbLocks)(avg.ibLocks)(avg.shaderConsts);
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
    static bool beenHere = false;
    if (!beenHere)
    {
        LOG("DrawPrimitiveUP");
        beenHere = true;
    }

    size_t numVerts = primCount2NumVerts(PrimitiveType, PrimitiveCount);
    currentFramesStats_.drawUps += numVerts * VertexStreamZeroStride;       
    return ProxyBase<IDirect3DDevice9>::DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride); 
}

HRESULT ProxyImplDevice::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
    static bool beenHere = false;
    if (!beenHere)
    {
        LOG("DrawPrimitiveUP");
        beenHere = true;
    }

    size_t indexSize = (IndexDataFormat == D3DFMT_INDEX16) ? 2 : 4;
    size_t numIndices = primCount2NumVerts(PrimitiveType, PrimitiveCount);
    currentFramesStats_.drawUps += NumVertices * VertexStreamZeroStride + numIndices * indexSize;
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
