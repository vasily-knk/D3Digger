MY_BEGIN_INTERFACE(IUnknown)

        MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 
MY_END_INTERFACE

MY_BEGIN_INTERFACE_(IDirect3D9, IUnknown)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3D9 methods ***/
    MY_STDMETHOD(RegisterSoftwareDevice, ( void* pInitializeFunction) ) 
    MY_STDMETHOD_(UINT, GetAdapterCount, () ) 
    MY_STDMETHOD(GetAdapterIdentifier, ( UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER9* pIdentifier) ) 
    MY_STDMETHOD_(UINT, GetAdapterModeCount, ( UINT Adapter,D3DFORMAT Format) ) 
    MY_STDMETHOD(EnumAdapterModes, ( UINT Adapter,D3DFORMAT Format,UINT Mode,D3DDISPLAYMODE* pMode) ) 
    MY_STDMETHOD(GetAdapterDisplayMode, ( UINT Adapter,D3DDISPLAYMODE* pMode) ) 
    MY_STDMETHOD(CheckDeviceType, ( UINT Adapter,D3DDEVTYPE DevType,D3DFORMAT AdapterFormat,D3DFORMAT BackBufferFormat,BOOL bWindowed) ) 
    MY_STDMETHOD(CheckDeviceFormat, ( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat) ) 
    MY_STDMETHOD(CheckDeviceMultiSampleType, ( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType,DWORD* pQualityLevels) ) 
    MY_STDMETHOD(CheckDepthStencilMatch, ( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat) ) 
    MY_STDMETHOD(CheckDeviceFormatConversion, ( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SourceFormat,D3DFORMAT TargetFormat) ) 
    MY_STDMETHOD(GetDeviceCaps, ( UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps) ) 
    MY_STDMETHOD_(HMONITOR, GetAdapterMonitor, ( UINT Adapter) ) 
    MY_STDMETHOD(CreateDevice, ( UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface) ) 
MY_END_INTERFACE

MY_BEGIN_INTERFACE_(IDirect3DDevice9, IUnknown)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DDevice9 methods ***/
    MY_STDMETHOD(TestCooperativeLevel, () ) 
    MY_STDMETHOD_(UINT, GetAvailableTextureMem, () ) 
    MY_STDMETHOD(EvictManagedResources, () ) 
    MY_STDMETHOD(GetDirect3D, ( IDirect3D9** ppD3D9) ) 
    MY_STDMETHOD(GetDeviceCaps, ( D3DCAPS9* pCaps) ) 
    MY_STDMETHOD(GetDisplayMode, ( UINT iSwapChain,D3DDISPLAYMODE* pMode) ) 
    MY_STDMETHOD(GetCreationParameters, ( D3DDEVICE_CREATION_PARAMETERS *pParameters) ) 
    MY_STDMETHOD(SetCursorProperties, ( UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap) ) 
    MY_STDMETHOD_(void, SetCursorPosition, ( int X,int Y,DWORD Flags) ) 
    MY_STDMETHOD_(BOOL, ShowCursor, ( BOOL bShow) ) 
    MY_STDMETHOD(CreateAdditionalSwapChain, ( D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain) ) 
    MY_STDMETHOD(GetSwapChain, ( UINT iSwapChain,IDirect3DSwapChain9** pSwapChain) ) 
    MY_STDMETHOD_(UINT, GetNumberOfSwapChains, () ) 
    MY_STDMETHOD(Reset, ( D3DPRESENT_PARAMETERS* pPresentationParameters) ) 
    MY_STDMETHOD(Present, ( CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion) ) 
    MY_STDMETHOD(GetBackBuffer, ( UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer) ) 
    MY_STDMETHOD(GetRasterStatus, ( UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus) ) 
    MY_STDMETHOD(SetDialogBoxMode, ( BOOL bEnableDialogs) ) 
    MY_STDMETHOD_(void, SetGammaRamp, ( UINT iSwapChain,DWORD Flags,CONST D3DGAMMARAMP* pRamp) ) 
    MY_STDMETHOD_(void, GetGammaRamp, ( UINT iSwapChain,D3DGAMMARAMP* pRamp) ) 
    MY_STDMETHOD(CreateTexture, ( UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle) ) 
    MY_STDMETHOD(CreateVolumeTexture, ( UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle) ) 
    MY_STDMETHOD(CreateCubeTexture, ( UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle) ) 
    MY_STDMETHOD(CreateVertexBuffer, ( UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle) ) 
    MY_STDMETHOD(CreateIndexBuffer, ( UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle) ) 
    MY_STDMETHOD(CreateRenderTarget, ( UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) ) 
    MY_STDMETHOD(CreateDepthStencilSurface, ( UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) ) 
    MY_STDMETHOD(UpdateSurface, ( IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,CONST POINT* pDestPoint) ) 
    MY_STDMETHOD(UpdateTexture, ( IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture) ) 
    MY_STDMETHOD(GetRenderTargetData, ( IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface) ) 
    MY_STDMETHOD(GetFrontBufferData, ( UINT iSwapChain,IDirect3DSurface9* pDestSurface) ) 
    MY_STDMETHOD(StretchRect, ( IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestSurface,CONST RECT* pDestRect,D3DTEXTUREFILTERTYPE Filter) ) 
    MY_STDMETHOD(ColorFill, ( IDirect3DSurface9* pSurface,CONST RECT* pRect,D3DCOLOR color) ) 
    MY_STDMETHOD(CreateOffscreenPlainSurface, ( UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) ) 
    MY_STDMETHOD(SetRenderTarget, ( DWORD RenderTargetIndex,IDirect3DSurface9* pRenderTarget) ) 
    MY_STDMETHOD(GetRenderTarget, ( DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget) ) 
    MY_STDMETHOD(SetDepthStencilSurface, ( IDirect3DSurface9* pNewZStencil) ) 
    MY_STDMETHOD(GetDepthStencilSurface, ( IDirect3DSurface9** ppZStencilSurface) ) 
    MY_STDMETHOD(BeginScene, () ) 
    MY_STDMETHOD(EndScene, () ) 
    MY_STDMETHOD(Clear, ( DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil) ) 
    MY_STDMETHOD(SetTransform, ( D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix) ) 
    MY_STDMETHOD(GetTransform, ( D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix) ) 
    MY_STDMETHOD(MultiplyTransform, ( D3DTRANSFORMSTATETYPE,CONST D3DMATRIX*) ) 
    MY_STDMETHOD(SetViewport, ( CONST D3DVIEWPORT9* pViewport) ) 
    MY_STDMETHOD(GetViewport, ( D3DVIEWPORT9* pViewport) ) 
    MY_STDMETHOD(SetMaterial, ( CONST D3DMATERIAL9* pMaterial) ) 
    MY_STDMETHOD(GetMaterial, ( D3DMATERIAL9* pMaterial) ) 
    MY_STDMETHOD(SetLight, ( DWORD Index,CONST D3DLIGHT9*) ) 
    MY_STDMETHOD(GetLight, ( DWORD Index,D3DLIGHT9*) ) 
    MY_STDMETHOD(LightEnable, ( DWORD Index,BOOL Enable) ) 
    MY_STDMETHOD(GetLightEnable, ( DWORD Index,BOOL* pEnable) ) 
    MY_STDMETHOD(SetClipPlane, ( DWORD Index,CONST float* pPlane) ) 
    MY_STDMETHOD(GetClipPlane, ( DWORD Index,float* pPlane) ) 
    MY_STDMETHOD(SetRenderState, ( D3DRENDERSTATETYPE State,DWORD Value) ) 
    MY_STDMETHOD(GetRenderState, ( D3DRENDERSTATETYPE State,DWORD* pValue) ) 
    MY_STDMETHOD(CreateStateBlock, ( D3DSTATEBLOCKTYPE Type,IDirect3DStateBlock9** ppSB) ) 
    MY_STDMETHOD(BeginStateBlock, () ) 
    MY_STDMETHOD(EndStateBlock, ( IDirect3DStateBlock9** ppSB) ) 
    MY_STDMETHOD(SetClipStatus, ( CONST D3DCLIPSTATUS9* pClipStatus) ) 
    MY_STDMETHOD(GetClipStatus, ( D3DCLIPSTATUS9* pClipStatus) ) 
    MY_STDMETHOD(GetTexture, ( DWORD Stage,IDirect3DBaseTexture9** ppTexture) ) 
    MY_STDMETHOD(SetTexture, ( DWORD Stage,IDirect3DBaseTexture9* pTexture) ) 
    MY_STDMETHOD(GetTextureStageState, ( DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue) ) 
    MY_STDMETHOD(SetTextureStageState, ( DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value) ) 
    MY_STDMETHOD(GetSamplerState, ( DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD* pValue) ) 
    MY_STDMETHOD(SetSamplerState, ( DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD Value) ) 
    MY_STDMETHOD(ValidateDevice, ( DWORD* pNumPasses) ) 
    MY_STDMETHOD(SetPaletteEntries, ( UINT PaletteNumber,CONST PALETTEENTRY* pEntries) ) 
    MY_STDMETHOD(GetPaletteEntries, ( UINT PaletteNumber,PALETTEENTRY* pEntries) ) 
    MY_STDMETHOD(SetCurrentTexturePalette, ( UINT PaletteNumber) ) 
    MY_STDMETHOD(GetCurrentTexturePalette, ( UINT *PaletteNumber) ) 
    MY_STDMETHOD(SetScissorRect, ( CONST RECT* pRect) ) 
    MY_STDMETHOD(GetScissorRect, ( RECT* pRect) ) 
    MY_STDMETHOD(SetSoftwareVertexProcessing, ( BOOL bSoftware) ) 
    MY_STDMETHOD_(BOOL, GetSoftwareVertexProcessing, () ) 
    MY_STDMETHOD(SetNPatchMode, ( float nSegments) ) 
    MY_STDMETHOD_(float, GetNPatchMode, () ) 
    MY_STDMETHOD(DrawPrimitive, ( D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount) ) 
    MY_STDMETHOD(DrawIndexedPrimitive, ( D3DPRIMITIVETYPE,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount) ) 
    MY_STDMETHOD(DrawPrimitiveUP, ( D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) ) 
    MY_STDMETHOD(DrawIndexedPrimitiveUP, ( D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) ) 
    MY_STDMETHOD(ProcessVertices, ( UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags) ) 
    MY_STDMETHOD(CreateVertexDeclaration, ( CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl) ) 
    MY_STDMETHOD(SetVertexDeclaration, ( IDirect3DVertexDeclaration9* pDecl) ) 
    MY_STDMETHOD(GetVertexDeclaration, ( IDirect3DVertexDeclaration9** ppDecl) ) 
    MY_STDMETHOD(SetFVF, ( DWORD FVF) ) 
    MY_STDMETHOD(GetFVF, ( DWORD* pFVF) ) 
    MY_STDMETHOD(CreateVertexShader, ( CONST DWORD* pFunction,IDirect3DVertexShader9** ppShader) ) 
    MY_STDMETHOD(SetVertexShader, ( IDirect3DVertexShader9* pShader) ) 
    MY_STDMETHOD(GetVertexShader, ( IDirect3DVertexShader9** ppShader) ) 
    MY_STDMETHOD(SetVertexShaderConstantF, ( UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount) ) 
    MY_STDMETHOD(GetVertexShaderConstantF, ( UINT StartRegister,float* pConstantData,UINT Vector4fCount) ) 
    MY_STDMETHOD(SetVertexShaderConstantI, ( UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount) ) 
    MY_STDMETHOD(GetVertexShaderConstantI, ( UINT StartRegister,int* pConstantData,UINT Vector4iCount) ) 
    MY_STDMETHOD(SetVertexShaderConstantB, ( UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount) ) 
    MY_STDMETHOD(GetVertexShaderConstantB, ( UINT StartRegister,BOOL* pConstantData,UINT BoolCount) ) 
    MY_STDMETHOD(SetStreamSource, ( UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride) ) 
    MY_STDMETHOD(GetStreamSource, ( UINT StreamNumber,IDirect3DVertexBuffer9** ppStreamData,UINT* pOffsetInBytes,UINT* pStride) ) 
    MY_STDMETHOD(SetStreamSourceFreq, ( UINT StreamNumber,UINT Setting) ) 
    MY_STDMETHOD(GetStreamSourceFreq, ( UINT StreamNumber,UINT* pSetting) ) 
    MY_STDMETHOD(SetIndices, ( IDirect3DIndexBuffer9* pIndexData) ) 
    MY_STDMETHOD(GetIndices, ( IDirect3DIndexBuffer9** ppIndexData) ) 
    MY_STDMETHOD(CreatePixelShader, ( CONST DWORD* pFunction,IDirect3DPixelShader9** ppShader) ) 
    MY_STDMETHOD(SetPixelShader, ( IDirect3DPixelShader9* pShader) ) 
    MY_STDMETHOD(GetPixelShader, ( IDirect3DPixelShader9** ppShader) ) 
    MY_STDMETHOD(SetPixelShaderConstantF, ( UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount) ) 
    MY_STDMETHOD(GetPixelShaderConstantF, ( UINT StartRegister,float* pConstantData,UINT Vector4fCount) ) 
    MY_STDMETHOD(SetPixelShaderConstantI, ( UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount) ) 
    MY_STDMETHOD(GetPixelShaderConstantI, ( UINT StartRegister,int* pConstantData,UINT Vector4iCount) ) 
    MY_STDMETHOD(SetPixelShaderConstantB, ( UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount) ) 
    MY_STDMETHOD(GetPixelShaderConstantB, ( UINT StartRegister,BOOL* pConstantData,UINT BoolCount) ) 
    MY_STDMETHOD(DrawRectPatch, ( UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo) ) 
    MY_STDMETHOD(DrawTriPatch, ( UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo) ) 
    MY_STDMETHOD(DeletePatch, ( UINT Handle) ) 
    MY_STDMETHOD(CreateQuery, ( D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery) ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DStateBlock9, IUnknown)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DStateBlock9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(Capture, () ) 
    MY_STDMETHOD(Apply, () ) 
MY_END_INTERFACE

MY_BEGIN_INTERFACE_(IDirect3DSwapChain9, IUnknown)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DSwapChain9 methods ***/
    MY_STDMETHOD(Present, ( CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion,DWORD dwFlags) ) 
    MY_STDMETHOD(GetFrontBufferData, ( IDirect3DSurface9* pDestSurface) ) 
    MY_STDMETHOD(GetBackBuffer, ( UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer) ) 
    MY_STDMETHOD(GetRasterStatus, ( D3DRASTER_STATUS* pRasterStatus) ) 
    MY_STDMETHOD(GetDisplayMode, ( D3DDISPLAYMODE* pMode) ) 
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(GetPresentParameters, ( D3DPRESENT_PARAMETERS* pPresentationParameters) ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DResource9, IUnknown)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DResource9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(SetPrivateData, ( REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) ) 
    MY_STDMETHOD(GetPrivateData, ( REFGUID refguid,void* pData,DWORD* pSizeOfData) ) 
    MY_STDMETHOD(FreePrivateData, ( REFGUID refguid) ) 
    MY_STDMETHOD_(DWORD, SetPriority, ( DWORD PriorityNew) ) 
    MY_STDMETHOD_(DWORD, GetPriority, () ) 
    MY_STDMETHOD_(void, PreLoad, () ) 
    MY_STDMETHOD_(D3DRESOURCETYPE, GetType, () ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DVertexDeclaration9, IUnknown)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DVertexDeclaration9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(GetDeclaration, ( D3DVERTEXELEMENT9* pElement,UINT* pNumElements) ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DVertexShader9, IUnknown)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DVertexShader9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(GetFunction, ( void*,UINT* pSizeOfData) ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DPixelShader9, IUnknown)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DPixelShader9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(GetFunction, ( void*,UINT* pSizeOfData) ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DBaseTexture9, IDirect3DResource9)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DResource9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(SetPrivateData, ( REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) ) 
    MY_STDMETHOD(GetPrivateData, ( REFGUID refguid,void* pData,DWORD* pSizeOfData) ) 
    MY_STDMETHOD(FreePrivateData, ( REFGUID refguid) ) 
    MY_STDMETHOD_(DWORD, SetPriority, ( DWORD PriorityNew) ) 
    MY_STDMETHOD_(DWORD, GetPriority, () ) 
    MY_STDMETHOD_(void, PreLoad, () ) 
    MY_STDMETHOD_(D3DRESOURCETYPE, GetType, () ) 
    MY_STDMETHOD_(DWORD, SetLOD, ( DWORD LODNew) ) 
    MY_STDMETHOD_(DWORD, GetLOD, () ) 
    MY_STDMETHOD_(DWORD, GetLevelCount, () ) 
    MY_STDMETHOD(SetAutoGenFilterType, ( D3DTEXTUREFILTERTYPE FilterType) ) 
    MY_STDMETHOD_(D3DTEXTUREFILTERTYPE, GetAutoGenFilterType, () ) 
    MY_STDMETHOD_(void, GenerateMipSubLevels, () ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DTexture9, IDirect3DBaseTexture9)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DBaseTexture9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(SetPrivateData, ( REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) ) 
    MY_STDMETHOD(GetPrivateData, ( REFGUID refguid,void* pData,DWORD* pSizeOfData) ) 
    MY_STDMETHOD(FreePrivateData, ( REFGUID refguid) ) 
    MY_STDMETHOD_(DWORD, SetPriority, ( DWORD PriorityNew) ) 
    MY_STDMETHOD_(DWORD, GetPriority, () ) 
    MY_STDMETHOD_(void, PreLoad, () ) 
    MY_STDMETHOD_(D3DRESOURCETYPE, GetType, () ) 
    MY_STDMETHOD_(DWORD, SetLOD, ( DWORD LODNew) ) 
    MY_STDMETHOD_(DWORD, GetLOD, () ) 
    MY_STDMETHOD_(DWORD, GetLevelCount, () ) 
    MY_STDMETHOD(SetAutoGenFilterType, ( D3DTEXTUREFILTERTYPE FilterType) ) 
    MY_STDMETHOD_(D3DTEXTUREFILTERTYPE, GetAutoGenFilterType, () ) 
    MY_STDMETHOD_(void, GenerateMipSubLevels, () ) 
    MY_STDMETHOD(GetLevelDesc, ( UINT Level,D3DSURFACE_DESC *pDesc) ) 
    MY_STDMETHOD(GetSurfaceLevel, ( UINT Level,IDirect3DSurface9** ppSurfaceLevel) ) 
    MY_STDMETHOD(LockRect, ( UINT Level,D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) ) 
    MY_STDMETHOD(UnlockRect, ( UINT Level) ) 
    MY_STDMETHOD(AddDirtyRect, ( CONST RECT* pDirtyRect) ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DVolumeTexture9, IDirect3DBaseTexture9)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DBaseTexture9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(SetPrivateData, ( REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) ) 
    MY_STDMETHOD(GetPrivateData, ( REFGUID refguid,void* pData,DWORD* pSizeOfData) ) 
    MY_STDMETHOD(FreePrivateData, ( REFGUID refguid) ) 
    MY_STDMETHOD_(DWORD, SetPriority, ( DWORD PriorityNew) ) 
    MY_STDMETHOD_(DWORD, GetPriority, () ) 
    MY_STDMETHOD_(void, PreLoad, () ) 
    MY_STDMETHOD_(D3DRESOURCETYPE, GetType, () ) 
    MY_STDMETHOD_(DWORD, SetLOD, ( DWORD LODNew) ) 
    MY_STDMETHOD_(DWORD, GetLOD, () ) 
    MY_STDMETHOD_(DWORD, GetLevelCount, () ) 
    MY_STDMETHOD(SetAutoGenFilterType, ( D3DTEXTUREFILTERTYPE FilterType) ) 
    MY_STDMETHOD_(D3DTEXTUREFILTERTYPE, GetAutoGenFilterType, () ) 
    MY_STDMETHOD_(void, GenerateMipSubLevels, () ) 
    MY_STDMETHOD(GetLevelDesc, ( UINT Level,D3DVOLUME_DESC *pDesc) ) 
    MY_STDMETHOD(GetVolumeLevel, ( UINT Level,IDirect3DVolume9** ppVolumeLevel) ) 
    MY_STDMETHOD(LockBox, ( UINT Level,D3DLOCKED_BOX* pLockedVolume,CONST D3DBOX* pBox,DWORD Flags) ) 
    MY_STDMETHOD(UnlockBox, ( UINT Level) ) 
    MY_STDMETHOD(AddDirtyBox, ( CONST D3DBOX* pDirtyBox) ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DCubeTexture9, IDirect3DBaseTexture9)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DBaseTexture9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(SetPrivateData, ( REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) ) 
    MY_STDMETHOD(GetPrivateData, ( REFGUID refguid,void* pData,DWORD* pSizeOfData) ) 
    MY_STDMETHOD(FreePrivateData, ( REFGUID refguid) ) 
    MY_STDMETHOD_(DWORD, SetPriority, ( DWORD PriorityNew) ) 
    MY_STDMETHOD_(DWORD, GetPriority, () ) 
    MY_STDMETHOD_(void, PreLoad, () ) 
    MY_STDMETHOD_(D3DRESOURCETYPE, GetType, () ) 
    MY_STDMETHOD_(DWORD, SetLOD, ( DWORD LODNew) ) 
    MY_STDMETHOD_(DWORD, GetLOD, () ) 
    MY_STDMETHOD_(DWORD, GetLevelCount, () ) 
    MY_STDMETHOD(SetAutoGenFilterType, ( D3DTEXTUREFILTERTYPE FilterType) ) 
    MY_STDMETHOD_(D3DTEXTUREFILTERTYPE, GetAutoGenFilterType, () ) 
    MY_STDMETHOD_(void, GenerateMipSubLevels, () ) 
    MY_STDMETHOD(GetLevelDesc, ( UINT Level,D3DSURFACE_DESC *pDesc) ) 
    MY_STDMETHOD(GetCubeMapSurface, ( D3DCUBEMAP_FACES FaceType,UINT Level,IDirect3DSurface9** ppCubeMapSurface) ) 
    MY_STDMETHOD(LockRect, ( D3DCUBEMAP_FACES FaceType,UINT Level,D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) ) 
    MY_STDMETHOD(UnlockRect, ( D3DCUBEMAP_FACES FaceType,UINT Level) ) 
    MY_STDMETHOD(AddDirtyRect, ( D3DCUBEMAP_FACES FaceType,CONST RECT* pDirtyRect) ) 
MY_END_INTERFACE
   
MY_BEGIN_INTERFACE_(IDirect3DVertexBuffer9, IDirect3DResource9)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DResource9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(SetPrivateData, ( REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) ) 
    MY_STDMETHOD(GetPrivateData, ( REFGUID refguid,void* pData,DWORD* pSizeOfData) ) 
    MY_STDMETHOD(FreePrivateData, ( REFGUID refguid) ) 
    MY_STDMETHOD_(DWORD, SetPriority, ( DWORD PriorityNew) ) 
    MY_STDMETHOD_(DWORD, GetPriority, () ) 
    MY_STDMETHOD_(void, PreLoad, () ) 
    MY_STDMETHOD_(D3DRESOURCETYPE, GetType, () ) 
    MY_STDMETHOD(Lock, ( UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) ) 
    MY_STDMETHOD(Unlock, () ) 
    MY_STDMETHOD(GetDesc, ( D3DVERTEXBUFFER_DESC *pDesc) ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DIndexBuffer9, IDirect3DResource9)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DResource9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(SetPrivateData, ( REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) ) 
    MY_STDMETHOD(GetPrivateData, ( REFGUID refguid,void* pData,DWORD* pSizeOfData) ) 
    MY_STDMETHOD(FreePrivateData, ( REFGUID refguid) ) 
    MY_STDMETHOD_(DWORD, SetPriority, ( DWORD PriorityNew) ) 
    MY_STDMETHOD_(DWORD, GetPriority, () ) 
    MY_STDMETHOD_(void, PreLoad, () ) 
    MY_STDMETHOD_(D3DRESOURCETYPE, GetType, () ) 
    MY_STDMETHOD(Lock, ( UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) ) 
    MY_STDMETHOD(Unlock, () ) 
    MY_STDMETHOD(GetDesc, ( D3DINDEXBUFFER_DESC *pDesc) ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DSurface9, IDirect3DResource9)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DResource9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(SetPrivateData, ( REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) ) 
    MY_STDMETHOD(GetPrivateData, ( REFGUID refguid,void* pData,DWORD* pSizeOfData) ) 
    MY_STDMETHOD(FreePrivateData, ( REFGUID refguid) ) 
    MY_STDMETHOD_(DWORD, SetPriority, ( DWORD PriorityNew) ) 
    MY_STDMETHOD_(DWORD, GetPriority, () ) 
    MY_STDMETHOD_(void, PreLoad, () ) 
    MY_STDMETHOD_(D3DRESOURCETYPE, GetType, () ) 
    MY_STDMETHOD(GetContainer, ( REFIID riid,void** ppContainer) ) 
    MY_STDMETHOD(GetDesc, ( D3DSURFACE_DESC *pDesc) ) 
    MY_STDMETHOD(LockRect, ( D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) ) 
    MY_STDMETHOD(UnlockRect, () ) 
    MY_STDMETHOD(GetDC, ( HDC *phdc) ) 
    MY_STDMETHOD(ReleaseDC, ( HDC hdc) ) 
MY_END_INTERFACE
    
MY_BEGIN_INTERFACE_(IDirect3DVolume9, IUnknown)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DVolume9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD(SetPrivateData, ( REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) ) 
    MY_STDMETHOD(GetPrivateData, ( REFGUID refguid,void* pData,DWORD* pSizeOfData) ) 
    MY_STDMETHOD(FreePrivateData, ( REFGUID refguid) ) 
    MY_STDMETHOD(GetContainer, ( REFIID riid,void** ppContainer) ) 
    MY_STDMETHOD(GetDesc, ( D3DVOLUME_DESC *pDesc) ) 
    MY_STDMETHOD(LockBox, ( D3DLOCKED_BOX * pLockedVolume,CONST D3DBOX* pBox,DWORD Flags) ) 
    MY_STDMETHOD(UnlockBox, () ) 
MY_END_INTERFACE

MY_BEGIN_INTERFACE_(IDirect3DQuery9, IUnknown)

    /*** IUnknown methods ***/
    MY_STDMETHOD(QueryInterface, ( REFIID riid, void** ppvObj) ) 
    MY_STDMETHOD_(ULONG,AddRef, () ) 
    MY_STDMETHOD_(ULONG,Release, () ) 

    /*** IDirect3DQuery9 methods ***/
    MY_STDMETHOD(GetDevice, ( IDirect3DDevice9** ppDevice) ) 
    MY_STDMETHOD_(D3DQUERYTYPE, GetType, () ) 
    MY_STDMETHOD_(DWORD, GetDataSize, () ) 
    MY_STDMETHOD(Issue, ( DWORD dwIssueFlags) ) 
    MY_STDMETHOD(GetData, ( void* pData,DWORD dwSize,DWORD dwGetDataFlags) ) 
MY_END_INTERFACE
