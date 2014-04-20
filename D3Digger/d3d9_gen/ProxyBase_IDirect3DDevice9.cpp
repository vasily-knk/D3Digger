#include "ProxyBase.h"


ProxyBase_IDirect3DDevice9::ProxyBase_IDirect3DDevice9(IDirect3DDevice9 *pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase_IDirect3DDevice9::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase_IDirect3DDevice9::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase_IDirect3DDevice9::Release()
{
    size_t refcount = pimpl_->Release();
    if (refcount == 0)
         pimpl_ = nullptr;
    return refcount;
}

HRESULT ProxyBase_IDirect3DDevice9::TestCooperativeLevel()
{
    return pimpl_->TestCooperativeLevel();
}

UINT ProxyBase_IDirect3DDevice9::GetAvailableTextureMem()
{
    return pimpl_->GetAvailableTextureMem();
}

HRESULT ProxyBase_IDirect3DDevice9::EvictManagedResources()
{
    return pimpl_->EvictManagedResources();
}

HRESULT ProxyBase_IDirect3DDevice9::GetDirect3D(IDirect3D9** ppD3D9)
{
    return pimpl_->GetDirect3D(ppD3D9);
}

HRESULT ProxyBase_IDirect3DDevice9::GetDeviceCaps(D3DCAPS9* pCaps)
{
    return pimpl_->GetDeviceCaps(pCaps);
}

HRESULT ProxyBase_IDirect3DDevice9::GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
    return pimpl_->GetDisplayMode(iSwapChain, pMode);
}

HRESULT ProxyBase_IDirect3DDevice9::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS* pParameters)
{
    return pimpl_->GetCreationParameters(pParameters);
}

HRESULT ProxyBase_IDirect3DDevice9::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap)
{
    return pimpl_->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

void ProxyBase_IDirect3DDevice9::SetCursorPosition(int X, int Y, DWORD Flags)
{
    pimpl_->SetCursorPosition(X, Y, Flags);
}

BOOL ProxyBase_IDirect3DDevice9::ShowCursor(BOOL bShow)
{
    return pimpl_->ShowCursor(bShow);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain)
{
    return pimpl_->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
}

HRESULT ProxyBase_IDirect3DDevice9::GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain)
{
    return pimpl_->GetSwapChain(iSwapChain, pSwapChain);
}

UINT ProxyBase_IDirect3DDevice9::GetNumberOfSwapChains()
{
    return pimpl_->GetNumberOfSwapChains();
}

HRESULT ProxyBase_IDirect3DDevice9::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    return pimpl_->Reset(pPresentationParameters);
}

HRESULT ProxyBase_IDirect3DDevice9::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
    return pimpl_->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT ProxyBase_IDirect3DDevice9::GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
    return pimpl_->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
}

HRESULT ProxyBase_IDirect3DDevice9::GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
    return pimpl_->GetRasterStatus(iSwapChain, pRasterStatus);
}

HRESULT ProxyBase_IDirect3DDevice9::SetDialogBoxMode(BOOL bEnableDialogs)
{
    return pimpl_->SetDialogBoxMode(bEnableDialogs);
}

void ProxyBase_IDirect3DDevice9::SetGammaRamp(UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp)
{
    pimpl_->SetGammaRamp(iSwapChain, Flags, pRamp);
}

void ProxyBase_IDirect3DDevice9::GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
    pimpl_->GetGammaRamp(iSwapChain, pRamp);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
    return pimpl_->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
    return pimpl_->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
    return pimpl_->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
    return pimpl_->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
    return pimpl_->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return pimpl_->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return pimpl_->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

HRESULT ProxyBase_IDirect3DDevice9::UpdateSurface(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint)
{
    return pimpl_->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}

HRESULT ProxyBase_IDirect3DDevice9::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
{
    return pimpl_->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT ProxyBase_IDirect3DDevice9::GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
    return pimpl_->GetRenderTargetData(pRenderTarget, pDestSurface);
}

HRESULT ProxyBase_IDirect3DDevice9::GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
    return pimpl_->GetFrontBufferData(iSwapChain, pDestSurface);
}

HRESULT ProxyBase_IDirect3DDevice9::StretchRect(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
    return pimpl_->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

HRESULT ProxyBase_IDirect3DDevice9::ColorFill(IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color)
{
    return pimpl_->ColorFill(pSurface, pRect, color);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return pimpl_->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

HRESULT ProxyBase_IDirect3DDevice9::SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
    return pimpl_->SetRenderTarget(RenderTargetIndex, pRenderTarget);
}

HRESULT ProxyBase_IDirect3DDevice9::GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
    return pimpl_->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
}

HRESULT ProxyBase_IDirect3DDevice9::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
    return pimpl_->SetDepthStencilSurface(pNewZStencil);
}

HRESULT ProxyBase_IDirect3DDevice9::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
    return pimpl_->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT ProxyBase_IDirect3DDevice9::BeginScene()
{
    return pimpl_->BeginScene();
}

HRESULT ProxyBase_IDirect3DDevice9::EndScene()
{
    return pimpl_->EndScene();
}

HRESULT ProxyBase_IDirect3DDevice9::Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    return pimpl_->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT ProxyBase_IDirect3DDevice9::SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
    return pimpl_->SetTransform(State, pMatrix);
}

HRESULT ProxyBase_IDirect3DDevice9::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix)
{
    return pimpl_->GetTransform(State, pMatrix);
}

HRESULT ProxyBase_IDirect3DDevice9::MultiplyTransform(D3DTRANSFORMSTATETYPE unnamed0, CONST D3DMATRIX* unnamed1)
{
    return pimpl_->MultiplyTransform(unnamed0, unnamed1);
}

HRESULT ProxyBase_IDirect3DDevice9::SetViewport(CONST D3DVIEWPORT9* pViewport)
{
    return pimpl_->SetViewport(pViewport);
}

HRESULT ProxyBase_IDirect3DDevice9::GetViewport(D3DVIEWPORT9* pViewport)
{
    return pimpl_->GetViewport(pViewport);
}

HRESULT ProxyBase_IDirect3DDevice9::SetMaterial(CONST D3DMATERIAL9* pMaterial)
{
    return pimpl_->SetMaterial(pMaterial);
}

HRESULT ProxyBase_IDirect3DDevice9::GetMaterial(D3DMATERIAL9* pMaterial)
{
    return pimpl_->GetMaterial(pMaterial);
}

HRESULT ProxyBase_IDirect3DDevice9::SetLight(DWORD Index, CONST D3DLIGHT9* unnamed0)
{
    return pimpl_->SetLight(Index, unnamed0);
}

HRESULT ProxyBase_IDirect3DDevice9::GetLight(DWORD Index, D3DLIGHT9* unnamed0)
{
    return pimpl_->GetLight(Index, unnamed0);
}

HRESULT ProxyBase_IDirect3DDevice9::LightEnable(DWORD Index, BOOL Enable)
{
    return pimpl_->LightEnable(Index, Enable);
}

HRESULT ProxyBase_IDirect3DDevice9::GetLightEnable(DWORD Index, BOOL* pEnable)
{
    return pimpl_->GetLightEnable(Index, pEnable);
}

HRESULT ProxyBase_IDirect3DDevice9::SetClipPlane(DWORD Index, CONST float* pPlane)
{
    return pimpl_->SetClipPlane(Index, pPlane);
}

HRESULT ProxyBase_IDirect3DDevice9::GetClipPlane(DWORD Index, float* pPlane)
{
    return pimpl_->GetClipPlane(Index, pPlane);
}

HRESULT ProxyBase_IDirect3DDevice9::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
    return pimpl_->SetRenderState(State, Value);
}

HRESULT ProxyBase_IDirect3DDevice9::GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue)
{
    return pimpl_->GetRenderState(State, pValue);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
    return pimpl_->CreateStateBlock(Type, ppSB);
}

HRESULT ProxyBase_IDirect3DDevice9::BeginStateBlock()
{
    return pimpl_->BeginStateBlock();
}

HRESULT ProxyBase_IDirect3DDevice9::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
    return pimpl_->EndStateBlock(ppSB);
}

HRESULT ProxyBase_IDirect3DDevice9::SetClipStatus(CONST D3DCLIPSTATUS9* pClipStatus)
{
    return pimpl_->SetClipStatus(pClipStatus);
}

HRESULT ProxyBase_IDirect3DDevice9::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
    return pimpl_->GetClipStatus(pClipStatus);
}

HRESULT ProxyBase_IDirect3DDevice9::GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture)
{
    return pimpl_->GetTexture(Stage, ppTexture);
}

HRESULT ProxyBase_IDirect3DDevice9::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
    return pimpl_->SetTexture(Stage, pTexture);
}

HRESULT ProxyBase_IDirect3DDevice9::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
{
    return pimpl_->GetTextureStageState(Stage, Type, pValue);
}

HRESULT ProxyBase_IDirect3DDevice9::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    return pimpl_->SetTextureStageState(Stage, Type, Value);
}

HRESULT ProxyBase_IDirect3DDevice9::GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
    return pimpl_->GetSamplerState(Sampler, Type, pValue);
}

HRESULT ProxyBase_IDirect3DDevice9::SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
    return pimpl_->SetSamplerState(Sampler, Type, Value);
}

HRESULT ProxyBase_IDirect3DDevice9::ValidateDevice(DWORD* pNumPasses)
{
    return pimpl_->ValidateDevice(pNumPasses);
}

HRESULT ProxyBase_IDirect3DDevice9::SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY* pEntries)
{
    return pimpl_->SetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT ProxyBase_IDirect3DDevice9::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries)
{
    return pimpl_->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT ProxyBase_IDirect3DDevice9::SetCurrentTexturePalette(UINT PaletteNumber)
{
    return pimpl_->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT ProxyBase_IDirect3DDevice9::GetCurrentTexturePalette(UINT* PaletteNumber)
{
    return pimpl_->GetCurrentTexturePalette(PaletteNumber);
}

HRESULT ProxyBase_IDirect3DDevice9::SetScissorRect(CONST RECT* pRect)
{
    return pimpl_->SetScissorRect(pRect);
}

HRESULT ProxyBase_IDirect3DDevice9::GetScissorRect(RECT* pRect)
{
    return pimpl_->GetScissorRect(pRect);
}

HRESULT ProxyBase_IDirect3DDevice9::SetSoftwareVertexProcessing(BOOL bSoftware)
{
    return pimpl_->SetSoftwareVertexProcessing(bSoftware);
}

BOOL ProxyBase_IDirect3DDevice9::GetSoftwareVertexProcessing()
{
    return pimpl_->GetSoftwareVertexProcessing();
}

HRESULT ProxyBase_IDirect3DDevice9::SetNPatchMode(float nSegments)
{
    return pimpl_->SetNPatchMode(nSegments);
}

float ProxyBase_IDirect3DDevice9::GetNPatchMode()
{
    return pimpl_->GetNPatchMode();
}

HRESULT ProxyBase_IDirect3DDevice9::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    return pimpl_->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT ProxyBase_IDirect3DDevice9::DrawIndexedPrimitive(D3DPRIMITIVETYPE unnamed0, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
    return pimpl_->DrawIndexedPrimitive(unnamed0, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT ProxyBase_IDirect3DDevice9::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    return pimpl_->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT ProxyBase_IDirect3DDevice9::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    return pimpl_->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT ProxyBase_IDirect3DDevice9::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
    return pimpl_->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateVertexDeclaration(CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
    return pimpl_->CreateVertexDeclaration(pVertexElements, ppDecl);
}

HRESULT ProxyBase_IDirect3DDevice9::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
    return pimpl_->SetVertexDeclaration(pDecl);
}

HRESULT ProxyBase_IDirect3DDevice9::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
    return pimpl_->GetVertexDeclaration(ppDecl);
}

HRESULT ProxyBase_IDirect3DDevice9::SetFVF(DWORD FVF)
{
    return pimpl_->SetFVF(FVF);
}

HRESULT ProxyBase_IDirect3DDevice9::GetFVF(DWORD* pFVF)
{
    return pimpl_->GetFVF(pFVF);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateVertexShader(CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
    return pimpl_->CreateVertexShader(pFunction, ppShader);
}

HRESULT ProxyBase_IDirect3DDevice9::SetVertexShader(IDirect3DVertexShader9* pShader)
{
    return pimpl_->SetVertexShader(pShader);
}

HRESULT ProxyBase_IDirect3DDevice9::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
    return pimpl_->GetVertexShader(ppShader);
}

HRESULT ProxyBase_IDirect3DDevice9::SetVertexShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
    return pimpl_->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT ProxyBase_IDirect3DDevice9::GetVertexShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
    return pimpl_->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT ProxyBase_IDirect3DDevice9::SetVertexShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
    return pimpl_->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT ProxyBase_IDirect3DDevice9::GetVertexShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
    return pimpl_->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT ProxyBase_IDirect3DDevice9::SetVertexShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT BoolCount)
{
    return pimpl_->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT ProxyBase_IDirect3DDevice9::GetVertexShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
    return pimpl_->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT ProxyBase_IDirect3DDevice9::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
    return pimpl_->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT ProxyBase_IDirect3DDevice9::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride)
{
    return pimpl_->GetStreamSource(StreamNumber, ppStreamData, pOffsetInBytes, pStride);
}

HRESULT ProxyBase_IDirect3DDevice9::SetStreamSourceFreq(UINT StreamNumber, UINT Setting)
{
    return pimpl_->SetStreamSourceFreq(StreamNumber, Setting);
}

HRESULT ProxyBase_IDirect3DDevice9::GetStreamSourceFreq(UINT StreamNumber, UINT* pSetting)
{
    return pimpl_->GetStreamSourceFreq(StreamNumber, pSetting);
}

HRESULT ProxyBase_IDirect3DDevice9::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
    return pimpl_->SetIndices(pIndexData);
}

HRESULT ProxyBase_IDirect3DDevice9::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
    return pimpl_->GetIndices(ppIndexData);
}

HRESULT ProxyBase_IDirect3DDevice9::CreatePixelShader(CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
    return pimpl_->CreatePixelShader(pFunction, ppShader);
}

HRESULT ProxyBase_IDirect3DDevice9::SetPixelShader(IDirect3DPixelShader9* pShader)
{
    return pimpl_->SetPixelShader(pShader);
}

HRESULT ProxyBase_IDirect3DDevice9::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
    return pimpl_->GetPixelShader(ppShader);
}

HRESULT ProxyBase_IDirect3DDevice9::SetPixelShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
    return pimpl_->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT ProxyBase_IDirect3DDevice9::GetPixelShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
    return pimpl_->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT ProxyBase_IDirect3DDevice9::SetPixelShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
    return pimpl_->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT ProxyBase_IDirect3DDevice9::GetPixelShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
    return pimpl_->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT ProxyBase_IDirect3DDevice9::SetPixelShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT BoolCount)
{
    return pimpl_->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT ProxyBase_IDirect3DDevice9::GetPixelShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
    return pimpl_->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT ProxyBase_IDirect3DDevice9::DrawRectPatch(UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo)
{
    return pimpl_->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT ProxyBase_IDirect3DDevice9::DrawTriPatch(UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo)
{
    return pimpl_->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT ProxyBase_IDirect3DDevice9::DeletePatch(UINT Handle)
{
    return pimpl_->DeletePatch(Handle);
}

HRESULT ProxyBase_IDirect3DDevice9::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
    return pimpl_->CreateQuery(Type, ppQuery);
}


