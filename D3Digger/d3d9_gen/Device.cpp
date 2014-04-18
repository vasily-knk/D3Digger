#include "Device.h"

namespace D3Digger
{
namespace D3D9
{
namespace Device
{

ProxyBase::ProxyBase(IBasePtr pimpl)
    : pimpl_(pimpl)
{
}

HRESULT ProxyBase::QueryInterface(REFIID riid, void** ppvObj)
{
    return pimpl_->QueryInterface(riid, ppvObj);
}

ULONG ProxyBase::AddRef()
{
    return pimpl_->AddRef();
}

ULONG ProxyBase::Release()
{
    return pimpl_->Release();
}

HRESULT ProxyBase::TestCooperativeLevel()
{
    return pimpl_->TestCooperativeLevel();
}

UINT ProxyBase::GetAvailableTextureMem()
{
    return pimpl_->GetAvailableTextureMem();
}

HRESULT ProxyBase::EvictManagedResources()
{
    return pimpl_->EvictManagedResources();
}

HRESULT ProxyBase::GetDirect3D(IDirect3D9** ppD3D9)
{
    return pimpl_->GetDirect3D(ppD3D9);
}

HRESULT ProxyBase::GetDeviceCaps(D3DCAPS9* pCaps)
{
    return pimpl_->GetDeviceCaps(pCaps);
}

HRESULT ProxyBase::GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
    return pimpl_->GetDisplayMode(iSwapChain, pMode);
}

HRESULT ProxyBase::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS* pParameters)
{
    return pimpl_->GetCreationParameters(pParameters);
}

HRESULT ProxyBase::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap)
{
    return pimpl_->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

void ProxyBase::SetCursorPosition(int X, int Y, DWORD Flags)
{
    pimpl_->SetCursorPosition(X, Y, Flags);
}

BOOL ProxyBase::ShowCursor(BOOL bShow)
{
    return pimpl_->ShowCursor(bShow);
}

HRESULT ProxyBase::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain)
{
    return pimpl_->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
}

HRESULT ProxyBase::GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain)
{
    return pimpl_->GetSwapChain(iSwapChain, pSwapChain);
}

UINT ProxyBase::GetNumberOfSwapChains()
{
    return pimpl_->GetNumberOfSwapChains();
}

HRESULT ProxyBase::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    return pimpl_->Reset(pPresentationParameters);
}

HRESULT ProxyBase::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
    return pimpl_->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT ProxyBase::GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
    return pimpl_->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
}

HRESULT ProxyBase::GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
    return pimpl_->GetRasterStatus(iSwapChain, pRasterStatus);
}

HRESULT ProxyBase::SetDialogBoxMode(BOOL bEnableDialogs)
{
    return pimpl_->SetDialogBoxMode(bEnableDialogs);
}

void ProxyBase::SetGammaRamp(UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp)
{
    pimpl_->SetGammaRamp(iSwapChain, Flags, pRamp);
}

void ProxyBase::GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
    pimpl_->GetGammaRamp(iSwapChain, pRamp);
}

HRESULT ProxyBase::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
    return pimpl_->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}

HRESULT ProxyBase::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
    return pimpl_->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}

HRESULT ProxyBase::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
    return pimpl_->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}

HRESULT ProxyBase::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
    return pimpl_->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}

HRESULT ProxyBase::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
    return pimpl_->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}

HRESULT ProxyBase::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return pimpl_->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

HRESULT ProxyBase::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return pimpl_->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

HRESULT ProxyBase::UpdateSurface(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint)
{
    return pimpl_->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}

HRESULT ProxyBase::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
{
    return pimpl_->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT ProxyBase::GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
    return pimpl_->GetRenderTargetData(pRenderTarget, pDestSurface);
}

HRESULT ProxyBase::GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
    return pimpl_->GetFrontBufferData(iSwapChain, pDestSurface);
}

HRESULT ProxyBase::StretchRect(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
    return pimpl_->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

HRESULT ProxyBase::ColorFill(IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color)
{
    return pimpl_->ColorFill(pSurface, pRect, color);
}

HRESULT ProxyBase::CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return pimpl_->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

HRESULT ProxyBase::SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
    return pimpl_->SetRenderTarget(RenderTargetIndex, pRenderTarget);
}

HRESULT ProxyBase::GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
    return pimpl_->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
}

HRESULT ProxyBase::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
    return pimpl_->SetDepthStencilSurface(pNewZStencil);
}

HRESULT ProxyBase::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
    return pimpl_->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT ProxyBase::BeginScene()
{
    return pimpl_->BeginScene();
}

HRESULT ProxyBase::EndScene()
{
    return pimpl_->EndScene();
}

HRESULT ProxyBase::Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    return pimpl_->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT ProxyBase::SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
    return pimpl_->SetTransform(State, pMatrix);
}

HRESULT ProxyBase::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix)
{
    return pimpl_->GetTransform(State, pMatrix);
}

HRESULT ProxyBase::MultiplyTransform(D3DTRANSFORMSTATETYPE unnamed0, CONST D3DMATRIX* unnamed1)
{
    return pimpl_->MultiplyTransform(unnamed0, unnamed1);
}

HRESULT ProxyBase::SetViewport(CONST D3DVIEWPORT9* pViewport)
{
    return pimpl_->SetViewport(pViewport);
}

HRESULT ProxyBase::GetViewport(D3DVIEWPORT9* pViewport)
{
    return pimpl_->GetViewport(pViewport);
}

HRESULT ProxyBase::SetMaterial(CONST D3DMATERIAL9* pMaterial)
{
    return pimpl_->SetMaterial(pMaterial);
}

HRESULT ProxyBase::GetMaterial(D3DMATERIAL9* pMaterial)
{
    return pimpl_->GetMaterial(pMaterial);
}

HRESULT ProxyBase::SetLight(DWORD Index, CONST D3DLIGHT9* unnamed0)
{
    return pimpl_->SetLight(Index, unnamed0);
}

HRESULT ProxyBase::GetLight(DWORD Index, D3DLIGHT9* unnamed0)
{
    return pimpl_->GetLight(Index, unnamed0);
}

HRESULT ProxyBase::LightEnable(DWORD Index, BOOL Enable)
{
    return pimpl_->LightEnable(Index, Enable);
}

HRESULT ProxyBase::GetLightEnable(DWORD Index, BOOL* pEnable)
{
    return pimpl_->GetLightEnable(Index, pEnable);
}

HRESULT ProxyBase::SetClipPlane(DWORD Index, CONST float* pPlane)
{
    return pimpl_->SetClipPlane(Index, pPlane);
}

HRESULT ProxyBase::GetClipPlane(DWORD Index, float* pPlane)
{
    return pimpl_->GetClipPlane(Index, pPlane);
}

HRESULT ProxyBase::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
    return pimpl_->SetRenderState(State, Value);
}

HRESULT ProxyBase::GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue)
{
    return pimpl_->GetRenderState(State, pValue);
}

HRESULT ProxyBase::CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
    return pimpl_->CreateStateBlock(Type, ppSB);
}

HRESULT ProxyBase::BeginStateBlock()
{
    return pimpl_->BeginStateBlock();
}

HRESULT ProxyBase::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
    return pimpl_->EndStateBlock(ppSB);
}

HRESULT ProxyBase::SetClipStatus(CONST D3DCLIPSTATUS9* pClipStatus)
{
    return pimpl_->SetClipStatus(pClipStatus);
}

HRESULT ProxyBase::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
    return pimpl_->GetClipStatus(pClipStatus);
}

HRESULT ProxyBase::GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture)
{
    return pimpl_->GetTexture(Stage, ppTexture);
}

HRESULT ProxyBase::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
    return pimpl_->SetTexture(Stage, pTexture);
}

HRESULT ProxyBase::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
{
    return pimpl_->GetTextureStageState(Stage, Type, pValue);
}

HRESULT ProxyBase::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    return pimpl_->SetTextureStageState(Stage, Type, Value);
}

HRESULT ProxyBase::GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
    return pimpl_->GetSamplerState(Sampler, Type, pValue);
}

HRESULT ProxyBase::SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
    return pimpl_->SetSamplerState(Sampler, Type, Value);
}

HRESULT ProxyBase::ValidateDevice(DWORD* pNumPasses)
{
    return pimpl_->ValidateDevice(pNumPasses);
}

HRESULT ProxyBase::SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY* pEntries)
{
    return pimpl_->SetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT ProxyBase::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries)
{
    return pimpl_->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT ProxyBase::SetCurrentTexturePalette(UINT PaletteNumber)
{
    return pimpl_->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT ProxyBase::GetCurrentTexturePalette(UINT* PaletteNumber)
{
    return pimpl_->GetCurrentTexturePalette(PaletteNumber);
}

HRESULT ProxyBase::SetScissorRect(CONST RECT* pRect)
{
    return pimpl_->SetScissorRect(pRect);
}

HRESULT ProxyBase::GetScissorRect(RECT* pRect)
{
    return pimpl_->GetScissorRect(pRect);
}

HRESULT ProxyBase::SetSoftwareVertexProcessing(BOOL bSoftware)
{
    return pimpl_->SetSoftwareVertexProcessing(bSoftware);
}

BOOL ProxyBase::GetSoftwareVertexProcessing()
{
    return pimpl_->GetSoftwareVertexProcessing();
}

HRESULT ProxyBase::SetNPatchMode(float nSegments)
{
    return pimpl_->SetNPatchMode(nSegments);
}

float ProxyBase::GetNPatchMode()
{
    return pimpl_->GetNPatchMode();
}

HRESULT ProxyBase::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    return pimpl_->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT ProxyBase::DrawIndexedPrimitive(D3DPRIMITIVETYPE unnamed0, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
    return pimpl_->DrawIndexedPrimitive(unnamed0, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT ProxyBase::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    return pimpl_->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT ProxyBase::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    return pimpl_->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT ProxyBase::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
    return pimpl_->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}

HRESULT ProxyBase::CreateVertexDeclaration(CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
    return pimpl_->CreateVertexDeclaration(pVertexElements, ppDecl);
}

HRESULT ProxyBase::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
    return pimpl_->SetVertexDeclaration(pDecl);
}

HRESULT ProxyBase::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
    return pimpl_->GetVertexDeclaration(ppDecl);
}

HRESULT ProxyBase::SetFVF(DWORD FVF)
{
    return pimpl_->SetFVF(FVF);
}

HRESULT ProxyBase::GetFVF(DWORD* pFVF)
{
    return pimpl_->GetFVF(pFVF);
}

HRESULT ProxyBase::CreateVertexShader(CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
    return pimpl_->CreateVertexShader(pFunction, ppShader);
}

HRESULT ProxyBase::SetVertexShader(IDirect3DVertexShader9* pShader)
{
    return pimpl_->SetVertexShader(pShader);
}

HRESULT ProxyBase::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
    return pimpl_->GetVertexShader(ppShader);
}

HRESULT ProxyBase::SetVertexShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
    return pimpl_->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT ProxyBase::GetVertexShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
    return pimpl_->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT ProxyBase::SetVertexShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
    return pimpl_->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT ProxyBase::GetVertexShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
    return pimpl_->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT ProxyBase::SetVertexShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT BoolCount)
{
    return pimpl_->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT ProxyBase::GetVertexShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
    return pimpl_->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT ProxyBase::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
    return pimpl_->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT ProxyBase::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride)
{
    return pimpl_->GetStreamSource(StreamNumber, ppStreamData, pOffsetInBytes, pStride);
}

HRESULT ProxyBase::SetStreamSourceFreq(UINT StreamNumber, UINT Setting)
{
    return pimpl_->SetStreamSourceFreq(StreamNumber, Setting);
}

HRESULT ProxyBase::GetStreamSourceFreq(UINT StreamNumber, UINT* pSetting)
{
    return pimpl_->GetStreamSourceFreq(StreamNumber, pSetting);
}

HRESULT ProxyBase::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
    return pimpl_->SetIndices(pIndexData);
}

HRESULT ProxyBase::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
    return pimpl_->GetIndices(ppIndexData);
}

HRESULT ProxyBase::CreatePixelShader(CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
    return pimpl_->CreatePixelShader(pFunction, ppShader);
}

HRESULT ProxyBase::SetPixelShader(IDirect3DPixelShader9* pShader)
{
    return pimpl_->SetPixelShader(pShader);
}

HRESULT ProxyBase::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
    return pimpl_->GetPixelShader(ppShader);
}

HRESULT ProxyBase::SetPixelShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
    return pimpl_->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT ProxyBase::GetPixelShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
    return pimpl_->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT ProxyBase::SetPixelShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
    return pimpl_->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT ProxyBase::GetPixelShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
    return pimpl_->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT ProxyBase::SetPixelShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT BoolCount)
{
    return pimpl_->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT ProxyBase::GetPixelShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
    return pimpl_->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT ProxyBase::DrawRectPatch(UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo)
{
    return pimpl_->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT ProxyBase::DrawTriPatch(UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo)
{
    return pimpl_->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT ProxyBase::DeletePatch(UINT Handle)
{
    return pimpl_->DeletePatch(Handle);
}

HRESULT ProxyBase::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
    return pimpl_->CreateQuery(Type, ppQuery);
}

} // namespace D3Digger

} // namespace D3D9

} // namespace Device


