#include "stdafx.h"
#include "ProcBase.h"
namespace D3D9
{
namespace Server
{
ProcBase<IDirect3D9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3D9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3D9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3D9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3D9>::RegisterSoftwareDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

void ProcBase<IDirect3D9>::GetAdapterCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    UINT res = self->GetAdapterCount();
}

void ProcBase<IDirect3D9>::GetAdapterIdentifier(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        DWORD Flags;
        D3DADAPTER_IDENTIFIER9 pIdentifier;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.Flags = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->GetAdapterIdentifier(args.Adapter, args.Flags, &args.pIdentifier);
}

void ProcBase<IDirect3D9>::GetAdapterModeCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DFORMAT Format;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.Format = g.get<D3DFORMAT>();
    assert(g.left() == 0);
    UINT res = self->GetAdapterModeCount(args.Adapter, args.Format);
}

void ProcBase<IDirect3D9>::EnumAdapterModes(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DFORMAT Format;
        UINT Mode;
        D3DDISPLAYMODE pMode;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.Format = g.get<D3DFORMAT>();
    args.Mode = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->EnumAdapterModes(args.Adapter, args.Format, args.Mode, &args.pMode);
}

void ProcBase<IDirect3D9>::GetAdapterDisplayMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DDISPLAYMODE pMode;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetAdapterDisplayMode(args.Adapter, &args.pMode);
}

void ProcBase<IDirect3D9>::CheckDeviceType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DevType;
        D3DFORMAT AdapterFormat;
        D3DFORMAT BackBufferFormat;
        BOOL bWindowed;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.DevType = g.get<D3DDEVTYPE>();
    args.AdapterFormat = g.get<D3DFORMAT>();
    args.BackBufferFormat = g.get<D3DFORMAT>();
    args.bWindowed = g.get<BOOL>();
    assert(g.left() == 0);
    HRESULT res = self->CheckDeviceType(args.Adapter, args.DevType, args.AdapterFormat, args.BackBufferFormat, args.bWindowed);
}

void ProcBase<IDirect3D9>::CheckDeviceFormat(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        D3DFORMAT AdapterFormat;
        DWORD Usage;
        D3DRESOURCETYPE RType;
        D3DFORMAT CheckFormat;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.DeviceType = g.get<D3DDEVTYPE>();
    args.AdapterFormat = g.get<D3DFORMAT>();
    args.Usage = g.get<DWORD>();
    args.RType = g.get<D3DRESOURCETYPE>();
    args.CheckFormat = g.get<D3DFORMAT>();
    assert(g.left() == 0);
    HRESULT res = self->CheckDeviceFormat(args.Adapter, args.DeviceType, args.AdapterFormat, args.Usage, args.RType, args.CheckFormat);
}

void ProcBase<IDirect3D9>::CheckDeviceMultiSampleType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        D3DFORMAT SurfaceFormat;
        BOOL Windowed;
        D3DMULTISAMPLE_TYPE MultiSampleType;
        DWORD pQualityLevels;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.DeviceType = g.get<D3DDEVTYPE>();
    args.SurfaceFormat = g.get<D3DFORMAT>();
    args.Windowed = g.get<BOOL>();
    args.MultiSampleType = g.get<D3DMULTISAMPLE_TYPE>();
    assert(g.left() == 0);
    HRESULT res = self->CheckDeviceMultiSampleType(args.Adapter, args.DeviceType, args.SurfaceFormat, args.Windowed, args.MultiSampleType, &args.pQualityLevels);
}

void ProcBase<IDirect3D9>::CheckDepthStencilMatch(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        D3DFORMAT AdapterFormat;
        D3DFORMAT RenderTargetFormat;
        D3DFORMAT DepthStencilFormat;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.DeviceType = g.get<D3DDEVTYPE>();
    args.AdapterFormat = g.get<D3DFORMAT>();
    args.RenderTargetFormat = g.get<D3DFORMAT>();
    args.DepthStencilFormat = g.get<D3DFORMAT>();
    assert(g.left() == 0);
    HRESULT res = self->CheckDepthStencilMatch(args.Adapter, args.DeviceType, args.AdapterFormat, args.RenderTargetFormat, args.DepthStencilFormat);
}

void ProcBase<IDirect3D9>::CheckDeviceFormatConversion(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        D3DFORMAT SourceFormat;
        D3DFORMAT TargetFormat;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.DeviceType = g.get<D3DDEVTYPE>();
    args.SourceFormat = g.get<D3DFORMAT>();
    args.TargetFormat = g.get<D3DFORMAT>();
    assert(g.left() == 0);
    HRESULT res = self->CheckDeviceFormatConversion(args.Adapter, args.DeviceType, args.SourceFormat, args.TargetFormat);
}

void ProcBase<IDirect3D9>::GetDeviceCaps(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        D3DCAPS9 pCaps;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.DeviceType = g.get<D3DDEVTYPE>();
    assert(g.left() == 0);
    HRESULT res = self->GetDeviceCaps(args.Adapter, args.DeviceType, &args.pCaps);
}

void ProcBase<IDirect3D9>::GetAdapterMonitor(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    assert(g.left() == 0);
    HMONITOR res = self->GetAdapterMonitor(args.Adapter);
}

void ProcBase<IDirect3D9>::CreateDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        HWND hFocusWindow;
        DWORD BehaviorFlags;
        D3DPRESENT_PARAMETERS pPresentationParameters;
        IDirect3DDevice9* ppReturnedDeviceInterface;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.DeviceType = g.get<D3DDEVTYPE>();
    args.hFocusWindow = g.get<HWND>();
    args.BehaviorFlags = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->CreateDevice(args.Adapter, args.DeviceType, args.hFocusWindow, args.BehaviorFlags, &args.pPresentationParameters, &args.ppReturnedDeviceInterface);
}

ProcBase<IDirect3DDevice9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DDevice9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DDevice9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DDevice9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DDevice9>::TestCooperativeLevel(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->TestCooperativeLevel();
}

void ProcBase<IDirect3DDevice9>::GetAvailableTextureMem(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    UINT res = self->GetAvailableTextureMem();
}

void ProcBase<IDirect3DDevice9>::EvictManagedResources(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->EvictManagedResources();
}

void ProcBase<IDirect3DDevice9>::GetDirect3D(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3D9* ppD3D9;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDirect3D(&args.ppD3D9);
}

void ProcBase<IDirect3DDevice9>::GetDeviceCaps(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DCAPS9 pCaps;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDeviceCaps(&args.pCaps);
}

void ProcBase<IDirect3DDevice9>::GetDisplayMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        D3DDISPLAYMODE pMode;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetDisplayMode(args.iSwapChain, &args.pMode);
}

void ProcBase<IDirect3DDevice9>::GetCreationParameters(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DDEVICE_CREATION_PARAMETERS pParameters;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetCreationParameters(&args.pParameters);
}

void ProcBase<IDirect3DDevice9>::SetCursorProperties(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT XHotSpot;
        UINT YHotSpot;
        IDirect3DSurface9* pCursorBitmap;
    } args;
    (void)args;
    args.XHotSpot = g.get<UINT>();
    args.YHotSpot = g.get<UINT>();
    args.pCursorBitmap = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->SetCursorProperties(args.XHotSpot, args.YHotSpot, args.pCursorBitmap);
}

void ProcBase<IDirect3DDevice9>::SetCursorPosition(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        int X;
        int Y;
        DWORD Flags;
    } args;
    (void)args;
    args.X = g.get<int>();
    args.Y = g.get<int>();
    args.Flags = g.get<DWORD>();
    assert(g.left() == 0);
    self->SetCursorPosition(args.X, args.Y, args.Flags);
}

void ProcBase<IDirect3DDevice9>::ShowCursor(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        BOOL bShow;
    } args;
    (void)args;
    args.bShow = g.get<BOOL>();
    assert(g.left() == 0);
    BOOL res = self->ShowCursor(args.bShow);
}

void ProcBase<IDirect3DDevice9>::CreateAdditionalSwapChain(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DPRESENT_PARAMETERS pPresentationParameters;
        IDirect3DSwapChain9* pSwapChain;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->CreateAdditionalSwapChain(&args.pPresentationParameters, &args.pSwapChain);
}

void ProcBase<IDirect3DDevice9>::GetSwapChain(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        IDirect3DSwapChain9* pSwapChain;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetSwapChain(args.iSwapChain, &args.pSwapChain);
}

void ProcBase<IDirect3DDevice9>::GetNumberOfSwapChains(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    UINT res = self->GetNumberOfSwapChains();
}

void ProcBase<IDirect3DDevice9>::Reset(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DPRESENT_PARAMETERS pPresentationParameters;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->Reset(&args.pPresentationParameters);
}

void ProcBase<IDirect3DDevice9>::Present(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        RECT pSourceRect;
        RECT pDestRect;
        HWND hDestWindowOverride;
        RGNDATA pDirtyRegion;
    } args;
    (void)args;
    args.pSourceRect = g.get<RECT>();
    args.pDestRect = g.get<RECT>();
    args.hDestWindowOverride = g.get<HWND>();
    args.pDirtyRegion = g.get<RGNDATA>();
    assert(g.left() == 0);
    HRESULT res = self->Present(&args.pSourceRect, &args.pDestRect, args.hDestWindowOverride, &args.pDirtyRegion);
}

void ProcBase<IDirect3DDevice9>::GetBackBuffer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        UINT iBackBuffer;
        D3DBACKBUFFER_TYPE Type;
        IDirect3DSurface9* ppBackBuffer;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    args.iBackBuffer = g.get<UINT>();
    args.Type = g.get<D3DBACKBUFFER_TYPE>();
    assert(g.left() == 0);
    HRESULT res = self->GetBackBuffer(args.iSwapChain, args.iBackBuffer, args.Type, &args.ppBackBuffer);
}

void ProcBase<IDirect3DDevice9>::GetRasterStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        D3DRASTER_STATUS pRasterStatus;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetRasterStatus(args.iSwapChain, &args.pRasterStatus);
}

void ProcBase<IDirect3DDevice9>::SetDialogBoxMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        BOOL bEnableDialogs;
    } args;
    (void)args;
    args.bEnableDialogs = g.get<BOOL>();
    assert(g.left() == 0);
    HRESULT res = self->SetDialogBoxMode(args.bEnableDialogs);
}

void ProcBase<IDirect3DDevice9>::SetGammaRamp(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        DWORD Flags;
        D3DGAMMARAMP pRamp;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    args.Flags = g.get<DWORD>();
    args.pRamp = g.get<D3DGAMMARAMP>();
    assert(g.left() == 0);
    self->SetGammaRamp(args.iSwapChain, args.Flags, &args.pRamp);
}

void ProcBase<IDirect3DDevice9>::GetGammaRamp(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        D3DGAMMARAMP pRamp;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    assert(g.left() == 0);
    self->GetGammaRamp(args.iSwapChain, &args.pRamp);
}

void ProcBase<IDirect3DDevice9>::CreateTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        UINT Levels;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DTexture9* ppTexture;
        HANDLE pSharedHandle;
    } args;
    (void)args;
    args.Width = g.get<UINT>();
    args.Height = g.get<UINT>();
    args.Levels = g.get<UINT>();
    args.Usage = g.get<DWORD>();
    args.Format = g.get<D3DFORMAT>();
    args.Pool = g.get<D3DPOOL>();
    assert(g.left() == 0);
    HRESULT res = self->CreateTexture(args.Width, args.Height, args.Levels, args.Usage, args.Format, args.Pool, &args.ppTexture, &args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateVolumeTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        UINT Depth;
        UINT Levels;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DVolumeTexture9* ppVolumeTexture;
        HANDLE pSharedHandle;
    } args;
    (void)args;
    args.Width = g.get<UINT>();
    args.Height = g.get<UINT>();
    args.Depth = g.get<UINT>();
    args.Levels = g.get<UINT>();
    args.Usage = g.get<DWORD>();
    args.Format = g.get<D3DFORMAT>();
    args.Pool = g.get<D3DPOOL>();
    assert(g.left() == 0);
    HRESULT res = self->CreateVolumeTexture(args.Width, args.Height, args.Depth, args.Levels, args.Usage, args.Format, args.Pool, &args.ppVolumeTexture, &args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateCubeTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT EdgeLength;
        UINT Levels;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DCubeTexture9* ppCubeTexture;
        HANDLE pSharedHandle;
    } args;
    (void)args;
    args.EdgeLength = g.get<UINT>();
    args.Levels = g.get<UINT>();
    args.Usage = g.get<DWORD>();
    args.Format = g.get<D3DFORMAT>();
    args.Pool = g.get<D3DPOOL>();
    assert(g.left() == 0);
    HRESULT res = self->CreateCubeTexture(args.EdgeLength, args.Levels, args.Usage, args.Format, args.Pool, &args.ppCubeTexture, &args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateVertexBuffer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Length;
        DWORD Usage;
        DWORD FVF;
        D3DPOOL Pool;
        IDirect3DVertexBuffer9* ppVertexBuffer;
        HANDLE pSharedHandle;
    } args;
    (void)args;
    args.Length = g.get<UINT>();
    args.Usage = g.get<DWORD>();
    args.FVF = g.get<DWORD>();
    args.Pool = g.get<D3DPOOL>();
    assert(g.left() == 0);
    HRESULT res = self->CreateVertexBuffer(args.Length, args.Usage, args.FVF, args.Pool, &args.ppVertexBuffer, &args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateIndexBuffer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Length;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DIndexBuffer9* ppIndexBuffer;
        HANDLE pSharedHandle;
    } args;
    (void)args;
    args.Length = g.get<UINT>();
    args.Usage = g.get<DWORD>();
    args.Format = g.get<D3DFORMAT>();
    args.Pool = g.get<D3DPOOL>();
    assert(g.left() == 0);
    HRESULT res = self->CreateIndexBuffer(args.Length, args.Usage, args.Format, args.Pool, &args.ppIndexBuffer, &args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateRenderTarget(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        D3DFORMAT Format;
        D3DMULTISAMPLE_TYPE MultiSample;
        DWORD MultisampleQuality;
        BOOL Lockable;
        IDirect3DSurface9* ppSurface;
        HANDLE pSharedHandle;
    } args;
    (void)args;
    args.Width = g.get<UINT>();
    args.Height = g.get<UINT>();
    args.Format = g.get<D3DFORMAT>();
    args.MultiSample = g.get<D3DMULTISAMPLE_TYPE>();
    args.MultisampleQuality = g.get<DWORD>();
    args.Lockable = g.get<BOOL>();
    assert(g.left() == 0);
    HRESULT res = self->CreateRenderTarget(args.Width, args.Height, args.Format, args.MultiSample, args.MultisampleQuality, args.Lockable, &args.ppSurface, &args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateDepthStencilSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        D3DFORMAT Format;
        D3DMULTISAMPLE_TYPE MultiSample;
        DWORD MultisampleQuality;
        BOOL Discard;
        IDirect3DSurface9* ppSurface;
        HANDLE pSharedHandle;
    } args;
    (void)args;
    args.Width = g.get<UINT>();
    args.Height = g.get<UINT>();
    args.Format = g.get<D3DFORMAT>();
    args.MultiSample = g.get<D3DMULTISAMPLE_TYPE>();
    args.MultisampleQuality = g.get<DWORD>();
    args.Discard = g.get<BOOL>();
    assert(g.left() == 0);
    HRESULT res = self->CreateDepthStencilSurface(args.Width, args.Height, args.Format, args.MultiSample, args.MultisampleQuality, args.Discard, &args.ppSurface, &args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::UpdateSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* pSourceSurface;
        RECT pSourceRect;
        IDirect3DSurface9* pDestinationSurface;
        POINT pDestPoint;
    } args;
    (void)args;
    args.pSourceSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pSourceRect = g.get<RECT>();
    args.pDestinationSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pDestPoint = g.get<POINT>();
    assert(g.left() == 0);
    HRESULT res = self->UpdateSurface(args.pSourceSurface, &args.pSourceRect, args.pDestinationSurface, &args.pDestPoint);
}

void ProcBase<IDirect3DDevice9>::UpdateTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DBaseTexture9* pSourceTexture;
        IDirect3DBaseTexture9* pDestinationTexture;
    } args;
    (void)args;
    args.pSourceTexture = procMap_->getPtr<IDirect3DBaseTexture9>(g.get<ProxyId>());
    args.pDestinationTexture = procMap_->getPtr<IDirect3DBaseTexture9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->UpdateTexture(args.pSourceTexture, args.pDestinationTexture);
}

void ProcBase<IDirect3DDevice9>::GetRenderTargetData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* pRenderTarget;
        IDirect3DSurface9* pDestSurface;
    } args;
    (void)args;
    args.pRenderTarget = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pDestSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->GetRenderTargetData(args.pRenderTarget, args.pDestSurface);
}

void ProcBase<IDirect3DDevice9>::GetFrontBufferData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        IDirect3DSurface9* pDestSurface;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    args.pDestSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->GetFrontBufferData(args.iSwapChain, args.pDestSurface);
}

void ProcBase<IDirect3DDevice9>::StretchRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* pSourceSurface;
        RECT pSourceRect;
        IDirect3DSurface9* pDestSurface;
        RECT pDestRect;
        D3DTEXTUREFILTERTYPE Filter;
    } args;
    (void)args;
    args.pSourceSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pSourceRect = g.get<RECT>();
    args.pDestSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pDestRect = g.get<RECT>();
    args.Filter = g.get<D3DTEXTUREFILTERTYPE>();
    assert(g.left() == 0);
    HRESULT res = self->StretchRect(args.pSourceSurface, &args.pSourceRect, args.pDestSurface, &args.pDestRect, args.Filter);
}

void ProcBase<IDirect3DDevice9>::ColorFill(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* pSurface;
        RECT pRect;
        D3DCOLOR color;
    } args;
    (void)args;
    args.pSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pRect = g.get<RECT>();
    args.color = g.get<D3DCOLOR>();
    assert(g.left() == 0);
    HRESULT res = self->ColorFill(args.pSurface, &args.pRect, args.color);
}

void ProcBase<IDirect3DDevice9>::CreateOffscreenPlainSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DSurface9* ppSurface;
        HANDLE pSharedHandle;
    } args;
    (void)args;
    args.Width = g.get<UINT>();
    args.Height = g.get<UINT>();
    args.Format = g.get<D3DFORMAT>();
    args.Pool = g.get<D3DPOOL>();
    assert(g.left() == 0);
    HRESULT res = self->CreateOffscreenPlainSurface(args.Width, args.Height, args.Format, args.Pool, &args.ppSurface, &args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::SetRenderTarget(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD RenderTargetIndex;
        IDirect3DSurface9* pRenderTarget;
    } args;
    (void)args;
    args.RenderTargetIndex = g.get<DWORD>();
    args.pRenderTarget = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->SetRenderTarget(args.RenderTargetIndex, args.pRenderTarget);
}

void ProcBase<IDirect3DDevice9>::GetRenderTarget(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD RenderTargetIndex;
        IDirect3DSurface9* ppRenderTarget;
    } args;
    (void)args;
    args.RenderTargetIndex = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->GetRenderTarget(args.RenderTargetIndex, &args.ppRenderTarget);
}

void ProcBase<IDirect3DDevice9>::SetDepthStencilSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* pNewZStencil;
    } args;
    (void)args;
    args.pNewZStencil = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->SetDepthStencilSurface(args.pNewZStencil);
}

void ProcBase<IDirect3DDevice9>::GetDepthStencilSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* ppZStencilSurface;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDepthStencilSurface(&args.ppZStencilSurface);
}

void ProcBase<IDirect3DDevice9>::BeginScene(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->BeginScene();
}

void ProcBase<IDirect3DDevice9>::EndScene(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->EndScene();
}

void ProcBase<IDirect3DDevice9>::Clear(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Count;
        D3DRECT pRects;
        DWORD Flags;
        D3DCOLOR Color;
        float Z;
        DWORD Stencil;
    } args;
    (void)args;
    args.Count = g.get<DWORD>();
    args.pRects = g.get<D3DRECT>();
    args.Flags = g.get<DWORD>();
    args.Color = g.get<D3DCOLOR>();
    args.Z = g.get<float>();
    args.Stencil = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->Clear(args.Count, &args.pRects, args.Flags, args.Color, args.Z, args.Stencil);
}

void ProcBase<IDirect3DDevice9>::SetTransform(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DTRANSFORMSTATETYPE State;
        D3DMATRIX pMatrix;
    } args;
    (void)args;
    args.State = g.get<D3DTRANSFORMSTATETYPE>();
    args.pMatrix = g.get<D3DMATRIX>();
    assert(g.left() == 0);
    HRESULT res = self->SetTransform(args.State, &args.pMatrix);
}

void ProcBase<IDirect3DDevice9>::GetTransform(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DTRANSFORMSTATETYPE State;
        D3DMATRIX pMatrix;
    } args;
    (void)args;
    args.State = g.get<D3DTRANSFORMSTATETYPE>();
    assert(g.left() == 0);
    HRESULT res = self->GetTransform(args.State, &args.pMatrix);
}

void ProcBase<IDirect3DDevice9>::MultiplyTransform(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DTRANSFORMSTATETYPE transform;
        D3DMATRIX matrix;
    } args;
    (void)args;
    args.transform = g.get<D3DTRANSFORMSTATETYPE>();
    args.matrix = g.get<D3DMATRIX>();
    assert(g.left() == 0);
    HRESULT res = self->MultiplyTransform(args.transform, &args.matrix);
}

void ProcBase<IDirect3DDevice9>::SetViewport(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DVIEWPORT9 pViewport;
    } args;
    (void)args;
    args.pViewport = g.get<D3DVIEWPORT9>();
    assert(g.left() == 0);
    HRESULT res = self->SetViewport(&args.pViewport);
}

void ProcBase<IDirect3DDevice9>::GetViewport(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DVIEWPORT9 pViewport;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetViewport(&args.pViewport);
}

void ProcBase<IDirect3DDevice9>::SetMaterial(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DMATERIAL9 pMaterial;
    } args;
    (void)args;
    args.pMaterial = g.get<D3DMATERIAL9>();
    assert(g.left() == 0);
    HRESULT res = self->SetMaterial(&args.pMaterial);
}

void ProcBase<IDirect3DDevice9>::GetMaterial(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DMATERIAL9 pMaterial;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetMaterial(&args.pMaterial);
}

void ProcBase<IDirect3DDevice9>::SetLight(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        D3DLIGHT9 pLight;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    args.pLight = g.get<D3DLIGHT9>();
    assert(g.left() == 0);
    HRESULT res = self->SetLight(args.Index, &args.pLight);
}

void ProcBase<IDirect3DDevice9>::GetLight(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        D3DLIGHT9 pLight;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->GetLight(args.Index, &args.pLight);
}

void ProcBase<IDirect3DDevice9>::LightEnable(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        BOOL Enable;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    args.Enable = g.get<BOOL>();
    assert(g.left() == 0);
    HRESULT res = self->LightEnable(args.Index, args.Enable);
}

void ProcBase<IDirect3DDevice9>::GetLightEnable(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        BOOL pEnable;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->GetLightEnable(args.Index, &args.pEnable);
}

void ProcBase<IDirect3DDevice9>::SetClipPlane(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        float pPlane;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    args.pPlane = g.get<float>();
    assert(g.left() == 0);
    HRESULT res = self->SetClipPlane(args.Index, &args.pPlane);
}

void ProcBase<IDirect3DDevice9>::GetClipPlane(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        float pPlane;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->GetClipPlane(args.Index, &args.pPlane);
}

void ProcBase<IDirect3DDevice9>::SetRenderState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DRENDERSTATETYPE State;
        DWORD Value;
    } args;
    (void)args;
    args.State = g.get<D3DRENDERSTATETYPE>();
    args.Value = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->SetRenderState(args.State, args.Value);
}

void ProcBase<IDirect3DDevice9>::GetRenderState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DRENDERSTATETYPE State;
        DWORD pValue;
    } args;
    (void)args;
    args.State = g.get<D3DRENDERSTATETYPE>();
    assert(g.left() == 0);
    HRESULT res = self->GetRenderState(args.State, &args.pValue);
}

void ProcBase<IDirect3DDevice9>::CreateStateBlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DSTATEBLOCKTYPE Type;
        IDirect3DStateBlock9* ppSB;
    } args;
    (void)args;
    args.Type = g.get<D3DSTATEBLOCKTYPE>();
    assert(g.left() == 0);
    HRESULT res = self->CreateStateBlock(args.Type, &args.ppSB);
}

void ProcBase<IDirect3DDevice9>::BeginStateBlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->BeginStateBlock();
}

void ProcBase<IDirect3DDevice9>::EndStateBlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DStateBlock9* ppSB;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->EndStateBlock(&args.ppSB);
}

void ProcBase<IDirect3DDevice9>::SetClipStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DCLIPSTATUS9 pClipStatus;
    } args;
    (void)args;
    args.pClipStatus = g.get<D3DCLIPSTATUS9>();
    assert(g.left() == 0);
    HRESULT res = self->SetClipStatus(&args.pClipStatus);
}

void ProcBase<IDirect3DDevice9>::GetClipStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DCLIPSTATUS9 pClipStatus;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetClipStatus(&args.pClipStatus);
}

void ProcBase<IDirect3DDevice9>::GetTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Stage;
        IDirect3DBaseTexture9* ppTexture;
    } args;
    (void)args;
    args.Stage = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->GetTexture(args.Stage, &args.ppTexture);
}

void ProcBase<IDirect3DDevice9>::SetTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Stage;
        IDirect3DBaseTexture9* pTexture;
    } args;
    (void)args;
    args.Stage = g.get<DWORD>();
    args.pTexture = procMap_->getPtr<IDirect3DBaseTexture9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->SetTexture(args.Stage, args.pTexture);
}

void ProcBase<IDirect3DDevice9>::GetTextureStageState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Stage;
        D3DTEXTURESTAGESTATETYPE Type;
        DWORD pValue;
    } args;
    (void)args;
    args.Stage = g.get<DWORD>();
    args.Type = g.get<D3DTEXTURESTAGESTATETYPE>();
    assert(g.left() == 0);
    HRESULT res = self->GetTextureStageState(args.Stage, args.Type, &args.pValue);
}

void ProcBase<IDirect3DDevice9>::SetTextureStageState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Stage;
        D3DTEXTURESTAGESTATETYPE Type;
        DWORD Value;
    } args;
    (void)args;
    args.Stage = g.get<DWORD>();
    args.Type = g.get<D3DTEXTURESTAGESTATETYPE>();
    args.Value = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->SetTextureStageState(args.Stage, args.Type, args.Value);
}

void ProcBase<IDirect3DDevice9>::GetSamplerState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Sampler;
        D3DSAMPLERSTATETYPE Type;
        DWORD pValue;
    } args;
    (void)args;
    args.Sampler = g.get<DWORD>();
    args.Type = g.get<D3DSAMPLERSTATETYPE>();
    assert(g.left() == 0);
    HRESULT res = self->GetSamplerState(args.Sampler, args.Type, &args.pValue);
}

void ProcBase<IDirect3DDevice9>::SetSamplerState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Sampler;
        D3DSAMPLERSTATETYPE Type;
        DWORD Value;
    } args;
    (void)args;
    args.Sampler = g.get<DWORD>();
    args.Type = g.get<D3DSAMPLERSTATETYPE>();
    args.Value = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->SetSamplerState(args.Sampler, args.Type, args.Value);
}

void ProcBase<IDirect3DDevice9>::ValidateDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD pNumPasses;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->ValidateDevice(&args.pNumPasses);
}

void ProcBase<IDirect3DDevice9>::SetPaletteEntries(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT PaletteNumber;
        PALETTEENTRY pEntries;
    } args;
    (void)args;
    args.PaletteNumber = g.get<UINT>();
    args.pEntries = g.get<PALETTEENTRY>();
    assert(g.left() == 0);
    HRESULT res = self->SetPaletteEntries(args.PaletteNumber, &args.pEntries);
}

void ProcBase<IDirect3DDevice9>::GetPaletteEntries(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT PaletteNumber;
        PALETTEENTRY pEntries;
    } args;
    (void)args;
    args.PaletteNumber = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetPaletteEntries(args.PaletteNumber, &args.pEntries);
}

void ProcBase<IDirect3DDevice9>::SetCurrentTexturePalette(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT PaletteNumber;
    } args;
    (void)args;
    args.PaletteNumber = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->SetCurrentTexturePalette(args.PaletteNumber);
}

void ProcBase<IDirect3DDevice9>::GetCurrentTexturePalette(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT PaletteNumber;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetCurrentTexturePalette(&args.PaletteNumber);
}

void ProcBase<IDirect3DDevice9>::SetScissorRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        RECT pRect;
    } args;
    (void)args;
    args.pRect = g.get<RECT>();
    assert(g.left() == 0);
    HRESULT res = self->SetScissorRect(&args.pRect);
}

void ProcBase<IDirect3DDevice9>::GetScissorRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        RECT pRect;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetScissorRect(&args.pRect);
}

void ProcBase<IDirect3DDevice9>::SetSoftwareVertexProcessing(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        BOOL bSoftware;
    } args;
    (void)args;
    args.bSoftware = g.get<BOOL>();
    assert(g.left() == 0);
    HRESULT res = self->SetSoftwareVertexProcessing(args.bSoftware);
}

void ProcBase<IDirect3DDevice9>::GetSoftwareVertexProcessing(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    BOOL res = self->GetSoftwareVertexProcessing();
}

void ProcBase<IDirect3DDevice9>::SetNPatchMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        float nSegments;
    } args;
    (void)args;
    args.nSegments = g.get<float>();
    assert(g.left() == 0);
    HRESULT res = self->SetNPatchMode(args.nSegments);
}

void ProcBase<IDirect3DDevice9>::GetNPatchMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    float res = self->GetNPatchMode();
}

void ProcBase<IDirect3DDevice9>::DrawPrimitive(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DPRIMITIVETYPE PrimitiveType;
        UINT StartVertex;
        UINT PrimitiveCount;
    } args;
    (void)args;
    args.PrimitiveType = g.get<D3DPRIMITIVETYPE>();
    args.StartVertex = g.get<UINT>();
    args.PrimitiveCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->DrawPrimitive(args.PrimitiveType, args.StartVertex, args.PrimitiveCount);
}

void ProcBase<IDirect3DDevice9>::DrawIndexedPrimitive(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DPRIMITIVETYPE PrimitiveType;
        INT BaseVertexIndex;
        UINT MinVertexIndex;
        UINT NumVertices;
        UINT startIndex;
        UINT primCount;
    } args;
    (void)args;
    args.PrimitiveType = g.get<D3DPRIMITIVETYPE>();
    args.BaseVertexIndex = g.get<INT>();
    args.MinVertexIndex = g.get<UINT>();
    args.NumVertices = g.get<UINT>();
    args.startIndex = g.get<UINT>();
    args.primCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->DrawIndexedPrimitive(args.PrimitiveType, args.BaseVertexIndex, args.MinVertexIndex, args.NumVertices, args.startIndex, args.primCount);
}

void ProcBase<IDirect3DDevice9>::DrawPrimitiveUP(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: const void*");
}

void ProcBase<IDirect3DDevice9>::DrawIndexedPrimitiveUP(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: const void*");
}

void ProcBase<IDirect3DDevice9>::ProcessVertices(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT SrcStartIndex;
        UINT DestIndex;
        UINT VertexCount;
        IDirect3DVertexBuffer9* pDestBuffer;
        IDirect3DVertexDeclaration9* pVertexDecl;
        DWORD Flags;
    } args;
    (void)args;
    args.SrcStartIndex = g.get<UINT>();
    args.DestIndex = g.get<UINT>();
    args.VertexCount = g.get<UINT>();
    args.pDestBuffer = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    args.pVertexDecl = procMap_->getPtr<IDirect3DVertexDeclaration9>(g.get<ProxyId>());
    args.Flags = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->ProcessVertices(args.SrcStartIndex, args.DestIndex, args.VertexCount, args.pDestBuffer, args.pVertexDecl, args.Flags);
}

void ProcBase<IDirect3DDevice9>::CreateVertexDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DVERTEXELEMENT9 pVertexElements;
        IDirect3DVertexDeclaration9* ppDecl;
    } args;
    (void)args;
    args.pVertexElements = g.get<D3DVERTEXELEMENT9>();
    assert(g.left() == 0);
    HRESULT res = self->CreateVertexDeclaration(&args.pVertexElements, &args.ppDecl);
}

void ProcBase<IDirect3DDevice9>::SetVertexDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DVertexDeclaration9* pDecl;
    } args;
    (void)args;
    args.pDecl = procMap_->getPtr<IDirect3DVertexDeclaration9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->SetVertexDeclaration(args.pDecl);
}

void ProcBase<IDirect3DDevice9>::GetVertexDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DVertexDeclaration9* ppDecl;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetVertexDeclaration(&args.ppDecl);
}

void ProcBase<IDirect3DDevice9>::SetFVF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD FVF;
    } args;
    (void)args;
    args.FVF = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->SetFVF(args.FVF);
}

void ProcBase<IDirect3DDevice9>::GetFVF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD pFVF;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetFVF(&args.pFVF);
}

void ProcBase<IDirect3DDevice9>::CreateVertexShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD pFunction;
        IDirect3DVertexShader9* ppShader;
    } args;
    (void)args;
    args.pFunction = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->CreateVertexShader(&args.pFunction, &args.ppShader);
}

void ProcBase<IDirect3DDevice9>::SetVertexShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DVertexShader9* pShader;
    } args;
    (void)args;
    args.pShader = procMap_->getPtr<IDirect3DVertexShader9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->SetVertexShader(args.pShader);
}

void ProcBase<IDirect3DDevice9>::GetVertexShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DVertexShader9* ppShader;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetVertexShader(&args.ppShader);
}

void ProcBase<IDirect3DDevice9>::SetVertexShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        float pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<float>();
    args.Vector4fCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->SetVertexShaderConstantF(args.StartRegister, &args.pConstantData, args.Vector4fCount);
}

void ProcBase<IDirect3DDevice9>::GetVertexShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        float pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.Vector4fCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetVertexShaderConstantF(args.StartRegister, &args.pConstantData, args.Vector4fCount);
}

void ProcBase<IDirect3DDevice9>::SetVertexShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        int pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<int>();
    args.Vector4iCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->SetVertexShaderConstantI(args.StartRegister, &args.pConstantData, args.Vector4iCount);
}

void ProcBase<IDirect3DDevice9>::GetVertexShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        int pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.Vector4iCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetVertexShaderConstantI(args.StartRegister, &args.pConstantData, args.Vector4iCount);
}

void ProcBase<IDirect3DDevice9>::SetVertexShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        BOOL pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<BOOL>();
    args.BoolCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->SetVertexShaderConstantB(args.StartRegister, &args.pConstantData, args.BoolCount);
}

void ProcBase<IDirect3DDevice9>::GetVertexShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        BOOL pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.BoolCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetVertexShaderConstantB(args.StartRegister, &args.pConstantData, args.BoolCount);
}

void ProcBase<IDirect3DDevice9>::SetStreamSource(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StreamNumber;
        IDirect3DVertexBuffer9* pStreamData;
        UINT OffsetInBytes;
        UINT Stride;
    } args;
    (void)args;
    args.StreamNumber = g.get<UINT>();
    args.pStreamData = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    args.OffsetInBytes = g.get<UINT>();
    args.Stride = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->SetStreamSource(args.StreamNumber, args.pStreamData, args.OffsetInBytes, args.Stride);
}

void ProcBase<IDirect3DDevice9>::GetStreamSource(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StreamNumber;
        IDirect3DVertexBuffer9* ppStreamData;
        UINT pOffsetInBytes;
        UINT pStride;
    } args;
    (void)args;
    args.StreamNumber = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetStreamSource(args.StreamNumber, &args.ppStreamData, &args.pOffsetInBytes, &args.pStride);
}

void ProcBase<IDirect3DDevice9>::SetStreamSourceFreq(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StreamNumber;
        UINT Setting;
    } args;
    (void)args;
    args.StreamNumber = g.get<UINT>();
    args.Setting = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->SetStreamSourceFreq(args.StreamNumber, args.Setting);
}

void ProcBase<IDirect3DDevice9>::GetStreamSourceFreq(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StreamNumber;
        UINT pSetting;
    } args;
    (void)args;
    args.StreamNumber = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetStreamSourceFreq(args.StreamNumber, &args.pSetting);
}

void ProcBase<IDirect3DDevice9>::SetIndices(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DIndexBuffer9* pIndexData;
    } args;
    (void)args;
    args.pIndexData = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->SetIndices(args.pIndexData);
}

void ProcBase<IDirect3DDevice9>::GetIndices(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DIndexBuffer9* ppIndexData;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetIndices(&args.ppIndexData);
}

void ProcBase<IDirect3DDevice9>::CreatePixelShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD pFunction;
        IDirect3DPixelShader9* ppShader;
    } args;
    (void)args;
    args.pFunction = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->CreatePixelShader(&args.pFunction, &args.ppShader);
}

void ProcBase<IDirect3DDevice9>::SetPixelShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DPixelShader9* pShader;
    } args;
    (void)args;
    args.pShader = procMap_->getPtr<IDirect3DPixelShader9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->SetPixelShader(args.pShader);
}

void ProcBase<IDirect3DDevice9>::GetPixelShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DPixelShader9* ppShader;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetPixelShader(&args.ppShader);
}

void ProcBase<IDirect3DDevice9>::SetPixelShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        float pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<float>();
    args.Vector4fCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->SetPixelShaderConstantF(args.StartRegister, &args.pConstantData, args.Vector4fCount);
}

void ProcBase<IDirect3DDevice9>::GetPixelShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        float pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.Vector4fCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetPixelShaderConstantF(args.StartRegister, &args.pConstantData, args.Vector4fCount);
}

void ProcBase<IDirect3DDevice9>::SetPixelShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        int pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<int>();
    args.Vector4iCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->SetPixelShaderConstantI(args.StartRegister, &args.pConstantData, args.Vector4iCount);
}

void ProcBase<IDirect3DDevice9>::GetPixelShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        int pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.Vector4iCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetPixelShaderConstantI(args.StartRegister, &args.pConstantData, args.Vector4iCount);
}

void ProcBase<IDirect3DDevice9>::SetPixelShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        BOOL pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<BOOL>();
    args.BoolCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->SetPixelShaderConstantB(args.StartRegister, &args.pConstantData, args.BoolCount);
}

void ProcBase<IDirect3DDevice9>::GetPixelShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        BOOL pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.BoolCount = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetPixelShaderConstantB(args.StartRegister, &args.pConstantData, args.BoolCount);
}

void ProcBase<IDirect3DDevice9>::DrawRectPatch(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Handle;
        float pNumSegs;
        D3DRECTPATCH_INFO pRectPatchInfo;
    } args;
    (void)args;
    args.Handle = g.get<UINT>();
    args.pNumSegs = g.get<float>();
    args.pRectPatchInfo = g.get<D3DRECTPATCH_INFO>();
    assert(g.left() == 0);
    HRESULT res = self->DrawRectPatch(args.Handle, &args.pNumSegs, &args.pRectPatchInfo);
}

void ProcBase<IDirect3DDevice9>::DrawTriPatch(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Handle;
        float pNumSegs;
        D3DTRIPATCH_INFO pTriPatchInfo;
    } args;
    (void)args;
    args.Handle = g.get<UINT>();
    args.pNumSegs = g.get<float>();
    args.pTriPatchInfo = g.get<D3DTRIPATCH_INFO>();
    assert(g.left() == 0);
    HRESULT res = self->DrawTriPatch(args.Handle, &args.pNumSegs, &args.pTriPatchInfo);
}

void ProcBase<IDirect3DDevice9>::DeletePatch(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Handle;
    } args;
    (void)args;
    args.Handle = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->DeletePatch(args.Handle);
}

void ProcBase<IDirect3DDevice9>::CreateQuery(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DQUERYTYPE Type;
        IDirect3DQuery9* ppQuery;
    } args;
    (void)args;
    args.Type = g.get<D3DQUERYTYPE>();
    assert(g.left() == 0);
    HRESULT res = self->CreateQuery(args.Type, &args.ppQuery);
}

ProcBase<IDirect3DStateBlock9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DStateBlock9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DStateBlock9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DStateBlock9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DStateBlock9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DStateBlock9>::Capture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->Capture();
}

void ProcBase<IDirect3DStateBlock9>::Apply(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->Apply();
}

ProcBase<IDirect3DSwapChain9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DSwapChain9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DSwapChain9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DSwapChain9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DSwapChain9>::Present(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        RECT pSourceRect;
        RECT pDestRect;
        HWND hDestWindowOverride;
        RGNDATA pDirtyRegion;
        DWORD dwFlags;
    } args;
    (void)args;
    args.pSourceRect = g.get<RECT>();
    args.pDestRect = g.get<RECT>();
    args.hDestWindowOverride = g.get<HWND>();
    args.pDirtyRegion = g.get<RGNDATA>();
    args.dwFlags = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->Present(&args.pSourceRect, &args.pDestRect, args.hDestWindowOverride, &args.pDirtyRegion, args.dwFlags);
}

void ProcBase<IDirect3DSwapChain9>::GetFrontBufferData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* pDestSurface;
    } args;
    (void)args;
    args.pDestSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    assert(g.left() == 0);
    HRESULT res = self->GetFrontBufferData(args.pDestSurface);
}

void ProcBase<IDirect3DSwapChain9>::GetBackBuffer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        UINT iBackBuffer;
        D3DBACKBUFFER_TYPE Type;
        IDirect3DSurface9* ppBackBuffer;
    } args;
    (void)args;
    args.iBackBuffer = g.get<UINT>();
    args.Type = g.get<D3DBACKBUFFER_TYPE>();
    assert(g.left() == 0);
    HRESULT res = self->GetBackBuffer(args.iBackBuffer, args.Type, &args.ppBackBuffer);
}

void ProcBase<IDirect3DSwapChain9>::GetRasterStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        D3DRASTER_STATUS pRasterStatus;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetRasterStatus(&args.pRasterStatus);
}

void ProcBase<IDirect3DSwapChain9>::GetDisplayMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        D3DDISPLAYMODE pMode;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDisplayMode(&args.pMode);
}

void ProcBase<IDirect3DSwapChain9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DSwapChain9>::GetPresentParameters(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        D3DPRESENT_PARAMETERS pPresentationParameters;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetPresentParameters(&args.pPresentationParameters);
}

ProcBase<IDirect3DVertexDeclaration9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DVertexDeclaration9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DVertexDeclaration9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DVertexDeclaration9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DVertexDeclaration9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DVertexDeclaration9>::GetDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(g.get<ProxyId>());
    struct {
        D3DVERTEXELEMENT9 pElement;
        UINT pNumElements;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDeclaration(&args.pElement, &args.pNumElements);
}

ProcBase<IDirect3DVertexShader9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DVertexShader9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DVertexShader9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexShader9 *self = procMap_->getPtr<IDirect3DVertexShader9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DVertexShader9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexShader9 *self = procMap_->getPtr<IDirect3DVertexShader9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DVertexShader9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexShader9 *self = procMap_->getPtr<IDirect3DVertexShader9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DVertexShader9>::GetFunction(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

ProcBase<IDirect3DPixelShader9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DPixelShader9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DPixelShader9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DPixelShader9 *self = procMap_->getPtr<IDirect3DPixelShader9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DPixelShader9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DPixelShader9 *self = procMap_->getPtr<IDirect3DPixelShader9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DPixelShader9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DPixelShader9 *self = procMap_->getPtr<IDirect3DPixelShader9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DPixelShader9>::GetFunction(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

ProcBase<IDirect3DTexture9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DTexture9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DTexture9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DTexture9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DTexture9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DTexture9>::SetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: const void*");
}

void ProcBase<IDirect3DTexture9>::GetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

void ProcBase<IDirect3DTexture9>::FreePrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    args.refguid = g.get<GUID>();
    assert(g.left() == 0);
    HRESULT res = self->FreePrivateData(args.refguid);
}

void ProcBase<IDirect3DTexture9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    args.PriorityNew = g.get<DWORD>();
    assert(g.left() == 0);
    DWORD res = self->SetPriority(args.PriorityNew);
}

void ProcBase<IDirect3DTexture9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetPriority();
}

void ProcBase<IDirect3DTexture9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    self->PreLoad();
}

void ProcBase<IDirect3DTexture9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    D3DRESOURCETYPE res = self->GetType();
}

void ProcBase<IDirect3DTexture9>::SetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        DWORD LODNew;
    } args;
    (void)args;
    args.LODNew = g.get<DWORD>();
    assert(g.left() == 0);
    DWORD res = self->SetLOD(args.LODNew);
}

void ProcBase<IDirect3DTexture9>::GetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetLOD();
}

void ProcBase<IDirect3DTexture9>::GetLevelCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetLevelCount();
}

void ProcBase<IDirect3DTexture9>::SetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        D3DTEXTUREFILTERTYPE FilterType;
    } args;
    (void)args;
    args.FilterType = g.get<D3DTEXTUREFILTERTYPE>();
    assert(g.left() == 0);
    HRESULT res = self->SetAutoGenFilterType(args.FilterType);
}

void ProcBase<IDirect3DTexture9>::GetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    D3DTEXTUREFILTERTYPE res = self->GetAutoGenFilterType();
}

void ProcBase<IDirect3DTexture9>::GenerateMipSubLevels(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    self->GenerateMipSubLevels();
}

void ProcBase<IDirect3DTexture9>::GetLevelDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        D3DSURFACE_DESC pDesc;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetLevelDesc(args.Level, &args.pDesc);
}

void ProcBase<IDirect3DTexture9>::GetSurfaceLevel(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        IDirect3DSurface9* ppSurfaceLevel;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetSurfaceLevel(args.Level, &args.ppSurfaceLevel);
}

void ProcBase<IDirect3DTexture9>::LockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        D3DLOCKED_RECT pLockedRect;
        RECT pRect;
        DWORD Flags;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    args.pRect = g.get<RECT>();
    args.Flags = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->LockRect(args.Level, &args.pLockedRect, &args.pRect, args.Flags);
}

void ProcBase<IDirect3DTexture9>::UnlockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->UnlockRect(args.Level);
}

void ProcBase<IDirect3DTexture9>::AddDirtyRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        RECT pDirtyRect;
    } args;
    (void)args;
    args.pDirtyRect = g.get<RECT>();
    assert(g.left() == 0);
    HRESULT res = self->AddDirtyRect(&args.pDirtyRect);
}

ProcBase<IDirect3DVolumeTexture9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DVolumeTexture9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DVolumeTexture9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DVolumeTexture9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DVolumeTexture9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DVolumeTexture9>::SetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: const void*");
}

void ProcBase<IDirect3DVolumeTexture9>::GetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

void ProcBase<IDirect3DVolumeTexture9>::FreePrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    args.refguid = g.get<GUID>();
    assert(g.left() == 0);
    HRESULT res = self->FreePrivateData(args.refguid);
}

void ProcBase<IDirect3DVolumeTexture9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    args.PriorityNew = g.get<DWORD>();
    assert(g.left() == 0);
    DWORD res = self->SetPriority(args.PriorityNew);
}

void ProcBase<IDirect3DVolumeTexture9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetPriority();
}

void ProcBase<IDirect3DVolumeTexture9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    self->PreLoad();
}

void ProcBase<IDirect3DVolumeTexture9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    D3DRESOURCETYPE res = self->GetType();
}

void ProcBase<IDirect3DVolumeTexture9>::SetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        DWORD LODNew;
    } args;
    (void)args;
    args.LODNew = g.get<DWORD>();
    assert(g.left() == 0);
    DWORD res = self->SetLOD(args.LODNew);
}

void ProcBase<IDirect3DVolumeTexture9>::GetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetLOD();
}

void ProcBase<IDirect3DVolumeTexture9>::GetLevelCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetLevelCount();
}

void ProcBase<IDirect3DVolumeTexture9>::SetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        D3DTEXTUREFILTERTYPE FilterType;
    } args;
    (void)args;
    args.FilterType = g.get<D3DTEXTUREFILTERTYPE>();
    assert(g.left() == 0);
    HRESULT res = self->SetAutoGenFilterType(args.FilterType);
}

void ProcBase<IDirect3DVolumeTexture9>::GetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    D3DTEXTUREFILTERTYPE res = self->GetAutoGenFilterType();
}

void ProcBase<IDirect3DVolumeTexture9>::GenerateMipSubLevels(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    self->GenerateMipSubLevels();
}

void ProcBase<IDirect3DVolumeTexture9>::GetLevelDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        D3DVOLUME_DESC pDesc;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetLevelDesc(args.Level, &args.pDesc);
}

void ProcBase<IDirect3DVolumeTexture9>::GetVolumeLevel(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        IDirect3DVolume9* ppVolumeLevel;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetVolumeLevel(args.Level, &args.ppVolumeLevel);
}

void ProcBase<IDirect3DVolumeTexture9>::LockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        D3DLOCKED_BOX pLockedVolume;
        D3DBOX pBox;
        DWORD Flags;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    args.pBox = g.get<D3DBOX>();
    args.Flags = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->LockBox(args.Level, &args.pLockedVolume, &args.pBox, args.Flags);
}

void ProcBase<IDirect3DVolumeTexture9>::UnlockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->UnlockBox(args.Level);
}

void ProcBase<IDirect3DVolumeTexture9>::AddDirtyBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        D3DBOX pDirtyBox;
    } args;
    (void)args;
    args.pDirtyBox = g.get<D3DBOX>();
    assert(g.left() == 0);
    HRESULT res = self->AddDirtyBox(&args.pDirtyBox);
}

ProcBase<IDirect3DCubeTexture9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DCubeTexture9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DCubeTexture9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DCubeTexture9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DCubeTexture9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DCubeTexture9>::SetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: const void*");
}

void ProcBase<IDirect3DCubeTexture9>::GetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

void ProcBase<IDirect3DCubeTexture9>::FreePrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    args.refguid = g.get<GUID>();
    assert(g.left() == 0);
    HRESULT res = self->FreePrivateData(args.refguid);
}

void ProcBase<IDirect3DCubeTexture9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    args.PriorityNew = g.get<DWORD>();
    assert(g.left() == 0);
    DWORD res = self->SetPriority(args.PriorityNew);
}

void ProcBase<IDirect3DCubeTexture9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetPriority();
}

void ProcBase<IDirect3DCubeTexture9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    self->PreLoad();
}

void ProcBase<IDirect3DCubeTexture9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    D3DRESOURCETYPE res = self->GetType();
}

void ProcBase<IDirect3DCubeTexture9>::SetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        DWORD LODNew;
    } args;
    (void)args;
    args.LODNew = g.get<DWORD>();
    assert(g.left() == 0);
    DWORD res = self->SetLOD(args.LODNew);
}

void ProcBase<IDirect3DCubeTexture9>::GetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetLOD();
}

void ProcBase<IDirect3DCubeTexture9>::GetLevelCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetLevelCount();
}

void ProcBase<IDirect3DCubeTexture9>::SetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        D3DTEXTUREFILTERTYPE FilterType;
    } args;
    (void)args;
    args.FilterType = g.get<D3DTEXTUREFILTERTYPE>();
    assert(g.left() == 0);
    HRESULT res = self->SetAutoGenFilterType(args.FilterType);
}

void ProcBase<IDirect3DCubeTexture9>::GetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    D3DTEXTUREFILTERTYPE res = self->GetAutoGenFilterType();
}

void ProcBase<IDirect3DCubeTexture9>::GenerateMipSubLevels(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    self->GenerateMipSubLevels();
}

void ProcBase<IDirect3DCubeTexture9>::GetLevelDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        D3DSURFACE_DESC pDesc;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetLevelDesc(args.Level, &args.pDesc);
}

void ProcBase<IDirect3DCubeTexture9>::GetCubeMapSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        D3DCUBEMAP_FACES FaceType;
        UINT Level;
        IDirect3DSurface9* ppCubeMapSurface;
    } args;
    (void)args;
    args.FaceType = g.get<D3DCUBEMAP_FACES>();
    args.Level = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->GetCubeMapSurface(args.FaceType, args.Level, &args.ppCubeMapSurface);
}

void ProcBase<IDirect3DCubeTexture9>::LockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        D3DCUBEMAP_FACES FaceType;
        UINT Level;
        D3DLOCKED_RECT pLockedRect;
        RECT pRect;
        DWORD Flags;
    } args;
    (void)args;
    args.FaceType = g.get<D3DCUBEMAP_FACES>();
    args.Level = g.get<UINT>();
    args.pRect = g.get<RECT>();
    args.Flags = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->LockRect(args.FaceType, args.Level, &args.pLockedRect, &args.pRect, args.Flags);
}

void ProcBase<IDirect3DCubeTexture9>::UnlockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        D3DCUBEMAP_FACES FaceType;
        UINT Level;
    } args;
    (void)args;
    args.FaceType = g.get<D3DCUBEMAP_FACES>();
    args.Level = g.get<UINT>();
    assert(g.left() == 0);
    HRESULT res = self->UnlockRect(args.FaceType, args.Level);
}

void ProcBase<IDirect3DCubeTexture9>::AddDirtyRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        D3DCUBEMAP_FACES FaceType;
        RECT pDirtyRect;
    } args;
    (void)args;
    args.FaceType = g.get<D3DCUBEMAP_FACES>();
    args.pDirtyRect = g.get<RECT>();
    assert(g.left() == 0);
    HRESULT res = self->AddDirtyRect(args.FaceType, &args.pDirtyRect);
}

ProcBase<IDirect3DVertexBuffer9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DVertexBuffer9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DVertexBuffer9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DVertexBuffer9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DVertexBuffer9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DVertexBuffer9>::SetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: const void*");
}

void ProcBase<IDirect3DVertexBuffer9>::GetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

void ProcBase<IDirect3DVertexBuffer9>::FreePrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    args.refguid = g.get<GUID>();
    assert(g.left() == 0);
    HRESULT res = self->FreePrivateData(args.refguid);
}

void ProcBase<IDirect3DVertexBuffer9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    args.PriorityNew = g.get<DWORD>();
    assert(g.left() == 0);
    DWORD res = self->SetPriority(args.PriorityNew);
}

void ProcBase<IDirect3DVertexBuffer9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetPriority();
}

void ProcBase<IDirect3DVertexBuffer9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    self->PreLoad();
}

void ProcBase<IDirect3DVertexBuffer9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    D3DRESOURCETYPE res = self->GetType();
}

void ProcBase<IDirect3DVertexBuffer9>::Lock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DVertexBuffer9>::Unlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->Unlock();
}

void ProcBase<IDirect3DVertexBuffer9>::GetDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        D3DVERTEXBUFFER_DESC pDesc;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDesc(&args.pDesc);
}

ProcBase<IDirect3DIndexBuffer9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DIndexBuffer9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DIndexBuffer9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DIndexBuffer9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DIndexBuffer9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DIndexBuffer9>::SetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: const void*");
}

void ProcBase<IDirect3DIndexBuffer9>::GetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

void ProcBase<IDirect3DIndexBuffer9>::FreePrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    args.refguid = g.get<GUID>();
    assert(g.left() == 0);
    HRESULT res = self->FreePrivateData(args.refguid);
}

void ProcBase<IDirect3DIndexBuffer9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    args.PriorityNew = g.get<DWORD>();
    assert(g.left() == 0);
    DWORD res = self->SetPriority(args.PriorityNew);
}

void ProcBase<IDirect3DIndexBuffer9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetPriority();
}

void ProcBase<IDirect3DIndexBuffer9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    self->PreLoad();
}

void ProcBase<IDirect3DIndexBuffer9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    D3DRESOURCETYPE res = self->GetType();
}

void ProcBase<IDirect3DIndexBuffer9>::Lock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DIndexBuffer9>::Unlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->Unlock();
}

void ProcBase<IDirect3DIndexBuffer9>::GetDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        D3DINDEXBUFFER_DESC pDesc;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDesc(&args.pDesc);
}

ProcBase<IDirect3DSurface9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DSurface9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DSurface9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DSurface9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DSurface9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DSurface9>::SetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: const void*");
}

void ProcBase<IDirect3DSurface9>::GetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

void ProcBase<IDirect3DSurface9>::FreePrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    args.refguid = g.get<GUID>();
    assert(g.left() == 0);
    HRESULT res = self->FreePrivateData(args.refguid);
}

void ProcBase<IDirect3DSurface9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    args.PriorityNew = g.get<DWORD>();
    assert(g.left() == 0);
    DWORD res = self->SetPriority(args.PriorityNew);
}

void ProcBase<IDirect3DSurface9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetPriority();
}

void ProcBase<IDirect3DSurface9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    self->PreLoad();
}

void ProcBase<IDirect3DSurface9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    D3DRESOURCETYPE res = self->GetType();
}

void ProcBase<IDirect3DSurface9>::GetContainer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DSurface9>::GetDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        D3DSURFACE_DESC pDesc;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDesc(&args.pDesc);
}

void ProcBase<IDirect3DSurface9>::LockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        D3DLOCKED_RECT pLockedRect;
        RECT pRect;
        DWORD Flags;
    } args;
    (void)args;
    args.pRect = g.get<RECT>();
    args.Flags = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->LockRect(&args.pLockedRect, &args.pRect, args.Flags);
}

void ProcBase<IDirect3DSurface9>::UnlockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->UnlockRect();
}

void ProcBase<IDirect3DSurface9>::GetDC(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        HDC phdc;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDC(&args.phdc);
}

void ProcBase<IDirect3DSurface9>::ReleaseDC(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        HDC hdc;
    } args;
    (void)args;
    args.hdc = g.get<HDC>();
    assert(g.left() == 0);
    HRESULT res = self->ReleaseDC(args.hdc);
}

ProcBase<IDirect3DVolume9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DVolume9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DVolume9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DVolume9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DVolume9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DVolume9>::SetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: const void*");
}

void ProcBase<IDirect3DVolume9>::GetPrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

void ProcBase<IDirect3DVolume9>::FreePrivateData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    args.refguid = g.get<GUID>();
    assert(g.left() == 0);
    HRESULT res = self->FreePrivateData(args.refguid);
}

void ProcBase<IDirect3DVolume9>::GetContainer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DVolume9>::GetDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        D3DVOLUME_DESC pDesc;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDesc(&args.pDesc);
}

void ProcBase<IDirect3DVolume9>::LockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        D3DLOCKED_BOX pLockedVolume;
        D3DBOX pBox;
        DWORD Flags;
    } args;
    (void)args;
    args.pBox = g.get<D3DBOX>();
    args.Flags = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->LockBox(&args.pLockedVolume, &args.pBox, args.Flags);
}

void ProcBase<IDirect3DVolume9>::UnlockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->UnlockBox();
}

ProcBase<IDirect3DQuery9>::ProcBase(CreateProcArgs const &args)
    : procMap_(args.procMap)
{
}

void ProcBase<IDirect3DQuery9>::QueryInterface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DQuery9>::AddRef(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->AddRef();
}

void ProcBase<IDirect3DQuery9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    ULONG res = self->Release();
}

void ProcBase<IDirect3DQuery9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    assert(g.left() == 0);
    HRESULT res = self->GetDevice(&args.ppDevice);
}

void ProcBase<IDirect3DQuery9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    D3DQUERYTYPE res = self->GetType();
}

void ProcBase<IDirect3DQuery9>::GetDataSize(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    assert(g.left() == 0);
    DWORD res = self->GetDataSize();
}

void ProcBase<IDirect3DQuery9>::Issue(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(g.get<ProxyId>());
    struct {
        DWORD dwIssueFlags;
    } args;
    (void)args;
    args.dwIssueFlags = g.get<DWORD>();
    assert(g.left() == 0);
    HRESULT res = self->Issue(args.dwIssueFlags);
}

void ProcBase<IDirect3DQuery9>::GetData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

} // namespace D3D9

} // namespace Server

