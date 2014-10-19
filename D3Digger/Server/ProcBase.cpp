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
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3D9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3D9>::RegisterSoftwareDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

void ProcBase<IDirect3D9>::GetAdapterCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    UINT res = self->GetAdapterCount();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3D9>::GetAdapterIdentifier(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        DWORD Flags;
        optional<D3DADAPTER_IDENTIFIER9> pIdentifier;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.Flags);
    rp(args.pIdentifier);
    HRESULT res = self->GetAdapterIdentifier(args.Adapter, args.Flags, opt2ptr(args.pIdentifier));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pIdentifier) wp(*args.pIdentifier);
}

void ProcBase<IDirect3D9>::GetAdapterModeCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        D3DFORMAT Format;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.Format);
    UINT res = self->GetAdapterModeCount(args.Adapter, args.Format);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3D9>::EnumAdapterModes(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        D3DFORMAT Format;
        UINT Mode;
        optional<D3DDISPLAYMODE> pMode;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.Format);
    rp(args.Mode);
    rp(args.pMode);
    HRESULT res = self->EnumAdapterModes(args.Adapter, args.Format, args.Mode, opt2ptr(args.pMode));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pMode) wp(*args.pMode);
}

void ProcBase<IDirect3D9>::GetAdapterDisplayMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        optional<D3DDISPLAYMODE> pMode;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.pMode);
    HRESULT res = self->GetAdapterDisplayMode(args.Adapter, opt2ptr(args.pMode));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pMode) wp(*args.pMode);
}

void ProcBase<IDirect3D9>::CheckDeviceType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DevType;
        D3DFORMAT AdapterFormat;
        D3DFORMAT BackBufferFormat;
        BOOL bWindowed;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.DevType);
    rp(args.AdapterFormat);
    rp(args.BackBufferFormat);
    rp(args.bWindowed);
    HRESULT res = self->CheckDeviceType(args.Adapter, args.DevType, args.AdapterFormat, args.BackBufferFormat, args.bWindowed);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3D9>::CheckDeviceFormat(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        D3DFORMAT AdapterFormat;
        DWORD Usage;
        D3DRESOURCETYPE RType;
        D3DFORMAT CheckFormat;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.DeviceType);
    rp(args.AdapterFormat);
    rp(args.Usage);
    rp(args.RType);
    rp(args.CheckFormat);
    HRESULT res = self->CheckDeviceFormat(args.Adapter, args.DeviceType, args.AdapterFormat, args.Usage, args.RType, args.CheckFormat);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3D9>::CheckDeviceMultiSampleType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        D3DFORMAT SurfaceFormat;
        BOOL Windowed;
        D3DMULTISAMPLE_TYPE MultiSampleType;
        optional<DWORD> pQualityLevels;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.DeviceType);
    rp(args.SurfaceFormat);
    rp(args.Windowed);
    rp(args.MultiSampleType);
    rp(args.pQualityLevels);
    HRESULT res = self->CheckDeviceMultiSampleType(args.Adapter, args.DeviceType, args.SurfaceFormat, args.Windowed, args.MultiSampleType, opt2ptr(args.pQualityLevels));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pQualityLevels) wp(*args.pQualityLevels);
}

void ProcBase<IDirect3D9>::CheckDepthStencilMatch(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        D3DFORMAT AdapterFormat;
        D3DFORMAT RenderTargetFormat;
        D3DFORMAT DepthStencilFormat;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.DeviceType);
    rp(args.AdapterFormat);
    rp(args.RenderTargetFormat);
    rp(args.DepthStencilFormat);
    HRESULT res = self->CheckDepthStencilMatch(args.Adapter, args.DeviceType, args.AdapterFormat, args.RenderTargetFormat, args.DepthStencilFormat);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3D9>::CheckDeviceFormatConversion(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        D3DFORMAT SourceFormat;
        D3DFORMAT TargetFormat;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.DeviceType);
    rp(args.SourceFormat);
    rp(args.TargetFormat);
    HRESULT res = self->CheckDeviceFormatConversion(args.Adapter, args.DeviceType, args.SourceFormat, args.TargetFormat);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3D9>::GetDeviceCaps(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        optional<D3DCAPS9> pCaps;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.DeviceType);
    rp(args.pCaps);
    HRESULT res = self->GetDeviceCaps(args.Adapter, args.DeviceType, opt2ptr(args.pCaps));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pCaps) wp(*args.pCaps);
}

void ProcBase<IDirect3D9>::GetAdapterMonitor(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
    } args;
    (void)args;
    rp(args.Adapter);
    HMONITOR res = self->GetAdapterMonitor(args.Adapter);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3D9>::CreateDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(rp.operator()<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        HWND hFocusWindow;
        DWORD BehaviorFlags;
        optional<D3DPRESENT_PARAMETERS> pPresentationParameters;
        IDirect3DDevice9* ppReturnedDeviceInterface;
    } args;
    (void)args;
    rp(args.Adapter);
    rp(args.DeviceType);
    rp(args.hFocusWindow);
    rp(args.BehaviorFlags);
    rp(args.pPresentationParameters);
    HRESULT res = self->CreateDevice(args.Adapter, args.DeviceType, args.hFocusWindow, args.BehaviorFlags, opt2ptr(args.pPresentationParameters), &args.ppReturnedDeviceInterface);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pPresentationParameters) wp(*args.pPresentationParameters);
    wp(procMap_->getProxyID(args.ppReturnedDeviceInterface));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::TestCooperativeLevel(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->TestCooperativeLevel();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetAvailableTextureMem(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    UINT res = self->GetAvailableTextureMem();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::EvictManagedResources(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->EvictManagedResources();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetDirect3D(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3D9* ppD3D9;
    } args;
    (void)args;
    HRESULT res = self->GetDirect3D(&args.ppD3D9);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppD3D9));
}

void ProcBase<IDirect3DDevice9>::GetDeviceCaps(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DCAPS9> pCaps;
    } args;
    (void)args;
    rp(args.pCaps);
    HRESULT res = self->GetDeviceCaps(opt2ptr(args.pCaps));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pCaps) wp(*args.pCaps);
}

void ProcBase<IDirect3DDevice9>::GetDisplayMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT iSwapChain;
        optional<D3DDISPLAYMODE> pMode;
    } args;
    (void)args;
    rp(args.iSwapChain);
    rp(args.pMode);
    HRESULT res = self->GetDisplayMode(args.iSwapChain, opt2ptr(args.pMode));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pMode) wp(*args.pMode);
}

void ProcBase<IDirect3DDevice9>::GetCreationParameters(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DDEVICE_CREATION_PARAMETERS> pParameters;
    } args;
    (void)args;
    rp(args.pParameters);
    HRESULT res = self->GetCreationParameters(opt2ptr(args.pParameters));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pParameters) wp(*args.pParameters);
}

void ProcBase<IDirect3DDevice9>::SetCursorProperties(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT XHotSpot;
        UINT YHotSpot;
        IDirect3DSurface9* pCursorBitmap;
    } args;
    (void)args;
    rp(args.XHotSpot);
    rp(args.YHotSpot);
    args.pCursorBitmap = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    HRESULT res = self->SetCursorProperties(args.XHotSpot, args.YHotSpot, args.pCursorBitmap);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::SetCursorPosition(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        int X;
        int Y;
        DWORD Flags;
    } args;
    (void)args;
    rp(args.X);
    rp(args.Y);
    rp(args.Flags);
    self->SetCursorPosition(args.X, args.Y, args.Flags);
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DDevice9>::ShowCursor(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        BOOL bShow;
    } args;
    (void)args;
    rp(args.bShow);
    BOOL res = self->ShowCursor(args.bShow);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::CreateAdditionalSwapChain(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DPRESENT_PARAMETERS> pPresentationParameters;
        IDirect3DSwapChain9* pSwapChain;
    } args;
    (void)args;
    rp(args.pPresentationParameters);
    HRESULT res = self->CreateAdditionalSwapChain(opt2ptr(args.pPresentationParameters), &args.pSwapChain);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pPresentationParameters) wp(*args.pPresentationParameters);
    wp(procMap_->getProxyID(args.pSwapChain));
}

void ProcBase<IDirect3DDevice9>::GetSwapChain(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT iSwapChain;
        IDirect3DSwapChain9* pSwapChain;
    } args;
    (void)args;
    rp(args.iSwapChain);
    HRESULT res = self->GetSwapChain(args.iSwapChain, &args.pSwapChain);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.pSwapChain));
}

void ProcBase<IDirect3DDevice9>::GetNumberOfSwapChains(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    UINT res = self->GetNumberOfSwapChains();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::Reset(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DPRESENT_PARAMETERS> pPresentationParameters;
    } args;
    (void)args;
    rp(args.pPresentationParameters);
    HRESULT res = self->Reset(opt2ptr(args.pPresentationParameters));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pPresentationParameters) wp(*args.pPresentationParameters);
}

void ProcBase<IDirect3DDevice9>::Present(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<RECT> pSourceRect;
        optional<RECT> pDestRect;
        HWND hDestWindowOverride;
        optional<RGNDATA> pDirtyRegion;
    } args;
    (void)args;
    rp(args.pSourceRect);
    rp(args.pDestRect);
    rp(args.hDestWindowOverride);
    rp(args.pDirtyRegion);
    HRESULT res = self->Present(opt2ptr(args.pSourceRect), opt2ptr(args.pDestRect), args.hDestWindowOverride, opt2ptr(args.pDirtyRegion));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetBackBuffer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT iSwapChain;
        UINT iBackBuffer;
        D3DBACKBUFFER_TYPE Type;
        IDirect3DSurface9* ppBackBuffer;
    } args;
    (void)args;
    rp(args.iSwapChain);
    rp(args.iBackBuffer);
    rp(args.Type);
    HRESULT res = self->GetBackBuffer(args.iSwapChain, args.iBackBuffer, args.Type, &args.ppBackBuffer);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppBackBuffer));
}

void ProcBase<IDirect3DDevice9>::GetRasterStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT iSwapChain;
        optional<D3DRASTER_STATUS> pRasterStatus;
    } args;
    (void)args;
    rp(args.iSwapChain);
    rp(args.pRasterStatus);
    HRESULT res = self->GetRasterStatus(args.iSwapChain, opt2ptr(args.pRasterStatus));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pRasterStatus) wp(*args.pRasterStatus);
}

void ProcBase<IDirect3DDevice9>::SetDialogBoxMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        BOOL bEnableDialogs;
    } args;
    (void)args;
    rp(args.bEnableDialogs);
    HRESULT res = self->SetDialogBoxMode(args.bEnableDialogs);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::SetGammaRamp(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT iSwapChain;
        DWORD Flags;
        optional<D3DGAMMARAMP> pRamp;
    } args;
    (void)args;
    rp(args.iSwapChain);
    rp(args.Flags);
    rp(args.pRamp);
    self->SetGammaRamp(args.iSwapChain, args.Flags, opt2ptr(args.pRamp));
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetGammaRamp(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT iSwapChain;
        optional<D3DGAMMARAMP> pRamp;
    } args;
    (void)args;
    rp(args.iSwapChain);
    rp(args.pRamp);
    self->GetGammaRamp(args.iSwapChain, opt2ptr(args.pRamp));
    bytes::write_proc wp(dstBytes);
    if (args.pRamp) wp(*args.pRamp);
}

void ProcBase<IDirect3DDevice9>::CreateTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        UINT Levels;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DTexture9* ppTexture;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Width);
    rp(args.Height);
    rp(args.Levels);
    rp(args.Usage);
    rp(args.Format);
    rp(args.Pool);
    rp(args.pSharedHandle);
    HRESULT res = self->CreateTexture(args.Width, args.Height, args.Levels, args.Usage, args.Format, args.Pool, &args.ppTexture, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppTexture));
    if (args.pSharedHandle) wp(*args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateVolumeTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        UINT Depth;
        UINT Levels;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DVolumeTexture9* ppVolumeTexture;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Width);
    rp(args.Height);
    rp(args.Depth);
    rp(args.Levels);
    rp(args.Usage);
    rp(args.Format);
    rp(args.Pool);
    rp(args.pSharedHandle);
    HRESULT res = self->CreateVolumeTexture(args.Width, args.Height, args.Depth, args.Levels, args.Usage, args.Format, args.Pool, &args.ppVolumeTexture, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppVolumeTexture));
    if (args.pSharedHandle) wp(*args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateCubeTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT EdgeLength;
        UINT Levels;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DCubeTexture9* ppCubeTexture;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.EdgeLength);
    rp(args.Levels);
    rp(args.Usage);
    rp(args.Format);
    rp(args.Pool);
    rp(args.pSharedHandle);
    HRESULT res = self->CreateCubeTexture(args.EdgeLength, args.Levels, args.Usage, args.Format, args.Pool, &args.ppCubeTexture, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppCubeTexture));
    if (args.pSharedHandle) wp(*args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateVertexBuffer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Length;
        DWORD Usage;
        DWORD FVF;
        D3DPOOL Pool;
        IDirect3DVertexBuffer9* ppVertexBuffer;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Length);
    rp(args.Usage);
    rp(args.FVF);
    rp(args.Pool);
    rp(args.pSharedHandle);
    HRESULT res = self->CreateVertexBuffer(args.Length, args.Usage, args.FVF, args.Pool, &args.ppVertexBuffer, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppVertexBuffer));
    if (args.pSharedHandle) wp(*args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateIndexBuffer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Length;
        DWORD Usage;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DIndexBuffer9* ppIndexBuffer;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Length);
    rp(args.Usage);
    rp(args.Format);
    rp(args.Pool);
    rp(args.pSharedHandle);
    HRESULT res = self->CreateIndexBuffer(args.Length, args.Usage, args.Format, args.Pool, &args.ppIndexBuffer, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppIndexBuffer));
    if (args.pSharedHandle) wp(*args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateRenderTarget(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        D3DFORMAT Format;
        D3DMULTISAMPLE_TYPE MultiSample;
        DWORD MultisampleQuality;
        BOOL Lockable;
        IDirect3DSurface9* ppSurface;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Width);
    rp(args.Height);
    rp(args.Format);
    rp(args.MultiSample);
    rp(args.MultisampleQuality);
    rp(args.Lockable);
    rp(args.pSharedHandle);
    HRESULT res = self->CreateRenderTarget(args.Width, args.Height, args.Format, args.MultiSample, args.MultisampleQuality, args.Lockable, &args.ppSurface, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppSurface));
    if (args.pSharedHandle) wp(*args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::CreateDepthStencilSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        D3DFORMAT Format;
        D3DMULTISAMPLE_TYPE MultiSample;
        DWORD MultisampleQuality;
        BOOL Discard;
        IDirect3DSurface9* ppSurface;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Width);
    rp(args.Height);
    rp(args.Format);
    rp(args.MultiSample);
    rp(args.MultisampleQuality);
    rp(args.Discard);
    rp(args.pSharedHandle);
    HRESULT res = self->CreateDepthStencilSurface(args.Width, args.Height, args.Format, args.MultiSample, args.MultisampleQuality, args.Discard, &args.ppSurface, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppSurface));
    if (args.pSharedHandle) wp(*args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::UpdateSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DSurface9* pSourceSurface;
        optional<RECT> pSourceRect;
        IDirect3DSurface9* pDestinationSurface;
        optional<POINT> pDestPoint;
    } args;
    (void)args;
    args.pSourceSurface = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    rp(args.pSourceRect);
    args.pDestinationSurface = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    rp(args.pDestPoint);
    HRESULT res = self->UpdateSurface(args.pSourceSurface, opt2ptr(args.pSourceRect), args.pDestinationSurface, opt2ptr(args.pDestPoint));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::UpdateTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DBaseTexture9* pSourceTexture;
        IDirect3DBaseTexture9* pDestinationTexture;
    } args;
    (void)args;
    args.pSourceTexture = procMap_->getPtr<IDirect3DBaseTexture9>(rp.operator()<ProxyId>());
    args.pDestinationTexture = procMap_->getPtr<IDirect3DBaseTexture9>(rp.operator()<ProxyId>());
    HRESULT res = self->UpdateTexture(args.pSourceTexture, args.pDestinationTexture);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetRenderTargetData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DSurface9* pRenderTarget;
        IDirect3DSurface9* pDestSurface;
    } args;
    (void)args;
    args.pRenderTarget = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    args.pDestSurface = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    HRESULT res = self->GetRenderTargetData(args.pRenderTarget, args.pDestSurface);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetFrontBufferData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT iSwapChain;
        IDirect3DSurface9* pDestSurface;
    } args;
    (void)args;
    rp(args.iSwapChain);
    args.pDestSurface = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    HRESULT res = self->GetFrontBufferData(args.iSwapChain, args.pDestSurface);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::StretchRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DSurface9* pSourceSurface;
        optional<RECT> pSourceRect;
        IDirect3DSurface9* pDestSurface;
        optional<RECT> pDestRect;
        D3DTEXTUREFILTERTYPE Filter;
    } args;
    (void)args;
    args.pSourceSurface = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    rp(args.pSourceRect);
    args.pDestSurface = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    rp(args.pDestRect);
    rp(args.Filter);
    HRESULT res = self->StretchRect(args.pSourceSurface, opt2ptr(args.pSourceRect), args.pDestSurface, opt2ptr(args.pDestRect), args.Filter);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::ColorFill(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DSurface9* pSurface;
        optional<RECT> pRect;
        D3DCOLOR color;
    } args;
    (void)args;
    args.pSurface = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    rp(args.pRect);
    rp(args.color);
    HRESULT res = self->ColorFill(args.pSurface, opt2ptr(args.pRect), args.color);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::CreateOffscreenPlainSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Width;
        UINT Height;
        D3DFORMAT Format;
        D3DPOOL Pool;
        IDirect3DSurface9* ppSurface;
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    rp(args.Width);
    rp(args.Height);
    rp(args.Format);
    rp(args.Pool);
    rp(args.pSharedHandle);
    HRESULT res = self->CreateOffscreenPlainSurface(args.Width, args.Height, args.Format, args.Pool, &args.ppSurface, opt2ptr(args.pSharedHandle));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppSurface));
    if (args.pSharedHandle) wp(*args.pSharedHandle);
}

void ProcBase<IDirect3DDevice9>::SetRenderTarget(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD RenderTargetIndex;
        IDirect3DSurface9* pRenderTarget;
    } args;
    (void)args;
    rp(args.RenderTargetIndex);
    args.pRenderTarget = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    HRESULT res = self->SetRenderTarget(args.RenderTargetIndex, args.pRenderTarget);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetRenderTarget(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD RenderTargetIndex;
        IDirect3DSurface9* ppRenderTarget;
    } args;
    (void)args;
    rp(args.RenderTargetIndex);
    HRESULT res = self->GetRenderTarget(args.RenderTargetIndex, &args.ppRenderTarget);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppRenderTarget));
}

void ProcBase<IDirect3DDevice9>::SetDepthStencilSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DSurface9* pNewZStencil;
    } args;
    (void)args;
    args.pNewZStencil = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    HRESULT res = self->SetDepthStencilSurface(args.pNewZStencil);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetDepthStencilSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DSurface9* ppZStencilSurface;
    } args;
    (void)args;
    HRESULT res = self->GetDepthStencilSurface(&args.ppZStencilSurface);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppZStencilSurface));
}

void ProcBase<IDirect3DDevice9>::BeginScene(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->BeginScene();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::EndScene(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->EndScene();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::Clear(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Count;
        optional<D3DRECT> pRects;
        DWORD Flags;
        D3DCOLOR Color;
        float Z;
        DWORD Stencil;
    } args;
    (void)args;
    rp(args.Count);
    rp(args.pRects);
    rp(args.Flags);
    rp(args.Color);
    rp(args.Z);
    rp(args.Stencil);
    HRESULT res = self->Clear(args.Count, opt2ptr(args.pRects), args.Flags, args.Color, args.Z, args.Stencil);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::SetTransform(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        D3DTRANSFORMSTATETYPE State;
        optional<D3DMATRIX> pMatrix;
    } args;
    (void)args;
    rp(args.State);
    rp(args.pMatrix);
    HRESULT res = self->SetTransform(args.State, opt2ptr(args.pMatrix));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetTransform(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        D3DTRANSFORMSTATETYPE State;
        optional<D3DMATRIX> pMatrix;
    } args;
    (void)args;
    rp(args.State);
    rp(args.pMatrix);
    HRESULT res = self->GetTransform(args.State, opt2ptr(args.pMatrix));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pMatrix) wp(*args.pMatrix);
}

void ProcBase<IDirect3DDevice9>::MultiplyTransform(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        D3DTRANSFORMSTATETYPE transform;
        optional<D3DMATRIX> matrix;
    } args;
    (void)args;
    rp(args.transform);
    rp(args.matrix);
    HRESULT res = self->MultiplyTransform(args.transform, opt2ptr(args.matrix));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::SetViewport(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DVIEWPORT9> pViewport;
    } args;
    (void)args;
    rp(args.pViewport);
    HRESULT res = self->SetViewport(opt2ptr(args.pViewport));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetViewport(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DVIEWPORT9> pViewport;
    } args;
    (void)args;
    rp(args.pViewport);
    HRESULT res = self->GetViewport(opt2ptr(args.pViewport));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pViewport) wp(*args.pViewport);
}

void ProcBase<IDirect3DDevice9>::SetMaterial(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DMATERIAL9> pMaterial;
    } args;
    (void)args;
    rp(args.pMaterial);
    HRESULT res = self->SetMaterial(opt2ptr(args.pMaterial));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetMaterial(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DMATERIAL9> pMaterial;
    } args;
    (void)args;
    rp(args.pMaterial);
    HRESULT res = self->GetMaterial(opt2ptr(args.pMaterial));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pMaterial) wp(*args.pMaterial);
}

void ProcBase<IDirect3DDevice9>::SetLight(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Index;
        optional<D3DLIGHT9> pLight;
    } args;
    (void)args;
    rp(args.Index);
    rp(args.pLight);
    HRESULT res = self->SetLight(args.Index, opt2ptr(args.pLight));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetLight(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Index;
        optional<D3DLIGHT9> pLight;
    } args;
    (void)args;
    rp(args.Index);
    rp(args.pLight);
    HRESULT res = self->GetLight(args.Index, opt2ptr(args.pLight));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pLight) wp(*args.pLight);
}

void ProcBase<IDirect3DDevice9>::LightEnable(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Index;
        BOOL Enable;
    } args;
    (void)args;
    rp(args.Index);
    rp(args.Enable);
    HRESULT res = self->LightEnable(args.Index, args.Enable);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetLightEnable(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Index;
        optional<BOOL> pEnable;
    } args;
    (void)args;
    rp(args.Index);
    rp(args.pEnable);
    HRESULT res = self->GetLightEnable(args.Index, opt2ptr(args.pEnable));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pEnable) wp(*args.pEnable);
}

void ProcBase<IDirect3DDevice9>::SetClipPlane(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Index;
        optional<float> pPlane;
    } args;
    (void)args;
    rp(args.Index);
    rp(args.pPlane);
    HRESULT res = self->SetClipPlane(args.Index, opt2ptr(args.pPlane));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetClipPlane(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Index;
        optional<float> pPlane;
    } args;
    (void)args;
    rp(args.Index);
    rp(args.pPlane);
    HRESULT res = self->GetClipPlane(args.Index, opt2ptr(args.pPlane));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pPlane) wp(*args.pPlane);
}

void ProcBase<IDirect3DDevice9>::SetRenderState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        D3DRENDERSTATETYPE State;
        DWORD Value;
    } args;
    (void)args;
    rp(args.State);
    rp(args.Value);
    HRESULT res = self->SetRenderState(args.State, args.Value);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetRenderState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        D3DRENDERSTATETYPE State;
        optional<DWORD> pValue;
    } args;
    (void)args;
    rp(args.State);
    rp(args.pValue);
    HRESULT res = self->GetRenderState(args.State, opt2ptr(args.pValue));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pValue) wp(*args.pValue);
}

void ProcBase<IDirect3DDevice9>::CreateStateBlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        D3DSTATEBLOCKTYPE Type;
        IDirect3DStateBlock9* ppSB;
    } args;
    (void)args;
    rp(args.Type);
    HRESULT res = self->CreateStateBlock(args.Type, &args.ppSB);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppSB));
}

void ProcBase<IDirect3DDevice9>::BeginStateBlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->BeginStateBlock();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::EndStateBlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DStateBlock9* ppSB;
    } args;
    (void)args;
    HRESULT res = self->EndStateBlock(&args.ppSB);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppSB));
}

void ProcBase<IDirect3DDevice9>::SetClipStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DCLIPSTATUS9> pClipStatus;
    } args;
    (void)args;
    rp(args.pClipStatus);
    HRESULT res = self->SetClipStatus(opt2ptr(args.pClipStatus));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetClipStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DCLIPSTATUS9> pClipStatus;
    } args;
    (void)args;
    rp(args.pClipStatus);
    HRESULT res = self->GetClipStatus(opt2ptr(args.pClipStatus));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pClipStatus) wp(*args.pClipStatus);
}

void ProcBase<IDirect3DDevice9>::GetTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Stage;
        IDirect3DBaseTexture9* ppTexture;
    } args;
    (void)args;
    rp(args.Stage);
    HRESULT res = self->GetTexture(args.Stage, &args.ppTexture);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppTexture));
}

void ProcBase<IDirect3DDevice9>::SetTexture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Stage;
        IDirect3DBaseTexture9* pTexture;
    } args;
    (void)args;
    rp(args.Stage);
    args.pTexture = procMap_->getPtr<IDirect3DBaseTexture9>(rp.operator()<ProxyId>());
    HRESULT res = self->SetTexture(args.Stage, args.pTexture);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetTextureStageState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Stage;
        D3DTEXTURESTAGESTATETYPE Type;
        optional<DWORD> pValue;
    } args;
    (void)args;
    rp(args.Stage);
    rp(args.Type);
    rp(args.pValue);
    HRESULT res = self->GetTextureStageState(args.Stage, args.Type, opt2ptr(args.pValue));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pValue) wp(*args.pValue);
}

void ProcBase<IDirect3DDevice9>::SetTextureStageState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Stage;
        D3DTEXTURESTAGESTATETYPE Type;
        DWORD Value;
    } args;
    (void)args;
    rp(args.Stage);
    rp(args.Type);
    rp(args.Value);
    HRESULT res = self->SetTextureStageState(args.Stage, args.Type, args.Value);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetSamplerState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Sampler;
        D3DSAMPLERSTATETYPE Type;
        optional<DWORD> pValue;
    } args;
    (void)args;
    rp(args.Sampler);
    rp(args.Type);
    rp(args.pValue);
    HRESULT res = self->GetSamplerState(args.Sampler, args.Type, opt2ptr(args.pValue));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pValue) wp(*args.pValue);
}

void ProcBase<IDirect3DDevice9>::SetSamplerState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD Sampler;
        D3DSAMPLERSTATETYPE Type;
        DWORD Value;
    } args;
    (void)args;
    rp(args.Sampler);
    rp(args.Type);
    rp(args.Value);
    HRESULT res = self->SetSamplerState(args.Sampler, args.Type, args.Value);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::ValidateDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<DWORD> pNumPasses;
    } args;
    (void)args;
    rp(args.pNumPasses);
    HRESULT res = self->ValidateDevice(opt2ptr(args.pNumPasses));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pNumPasses) wp(*args.pNumPasses);
}

void ProcBase<IDirect3DDevice9>::SetPaletteEntries(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT PaletteNumber;
        optional<PALETTEENTRY> pEntries;
    } args;
    (void)args;
    rp(args.PaletteNumber);
    rp(args.pEntries);
    HRESULT res = self->SetPaletteEntries(args.PaletteNumber, opt2ptr(args.pEntries));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetPaletteEntries(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT PaletteNumber;
        optional<PALETTEENTRY> pEntries;
    } args;
    (void)args;
    rp(args.PaletteNumber);
    rp(args.pEntries);
    HRESULT res = self->GetPaletteEntries(args.PaletteNumber, opt2ptr(args.pEntries));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pEntries) wp(*args.pEntries);
}

void ProcBase<IDirect3DDevice9>::SetCurrentTexturePalette(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT PaletteNumber;
    } args;
    (void)args;
    rp(args.PaletteNumber);
    HRESULT res = self->SetCurrentTexturePalette(args.PaletteNumber);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetCurrentTexturePalette(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<UINT> PaletteNumber;
    } args;
    (void)args;
    rp(args.PaletteNumber);
    HRESULT res = self->GetCurrentTexturePalette(opt2ptr(args.PaletteNumber));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.PaletteNumber) wp(*args.PaletteNumber);
}

void ProcBase<IDirect3DDevice9>::SetScissorRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<RECT> pRect;
    } args;
    (void)args;
    rp(args.pRect);
    HRESULT res = self->SetScissorRect(opt2ptr(args.pRect));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetScissorRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<RECT> pRect;
    } args;
    (void)args;
    rp(args.pRect);
    HRESULT res = self->GetScissorRect(opt2ptr(args.pRect));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pRect) wp(*args.pRect);
}

void ProcBase<IDirect3DDevice9>::SetSoftwareVertexProcessing(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        BOOL bSoftware;
    } args;
    (void)args;
    rp(args.bSoftware);
    HRESULT res = self->SetSoftwareVertexProcessing(args.bSoftware);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetSoftwareVertexProcessing(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    BOOL res = self->GetSoftwareVertexProcessing();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::SetNPatchMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        float nSegments;
    } args;
    (void)args;
    rp(args.nSegments);
    HRESULT res = self->SetNPatchMode(args.nSegments);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetNPatchMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    float res = self->GetNPatchMode();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::DrawPrimitive(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        D3DPRIMITIVETYPE PrimitiveType;
        UINT StartVertex;
        UINT PrimitiveCount;
    } args;
    (void)args;
    rp(args.PrimitiveType);
    rp(args.StartVertex);
    rp(args.PrimitiveCount);
    HRESULT res = self->DrawPrimitive(args.PrimitiveType, args.StartVertex, args.PrimitiveCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::DrawIndexedPrimitive(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        D3DPRIMITIVETYPE PrimitiveType;
        INT BaseVertexIndex;
        UINT MinVertexIndex;
        UINT NumVertices;
        UINT startIndex;
        UINT primCount;
    } args;
    (void)args;
    rp(args.PrimitiveType);
    rp(args.BaseVertexIndex);
    rp(args.MinVertexIndex);
    rp(args.NumVertices);
    rp(args.startIndex);
    rp(args.primCount);
    HRESULT res = self->DrawIndexedPrimitive(args.PrimitiveType, args.BaseVertexIndex, args.MinVertexIndex, args.NumVertices, args.startIndex, args.primCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT SrcStartIndex;
        UINT DestIndex;
        UINT VertexCount;
        IDirect3DVertexBuffer9* pDestBuffer;
        IDirect3DVertexDeclaration9* pVertexDecl;
        DWORD Flags;
    } args;
    (void)args;
    rp(args.SrcStartIndex);
    rp(args.DestIndex);
    rp(args.VertexCount);
    args.pDestBuffer = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    args.pVertexDecl = procMap_->getPtr<IDirect3DVertexDeclaration9>(rp.operator()<ProxyId>());
    rp(args.Flags);
    HRESULT res = self->ProcessVertices(args.SrcStartIndex, args.DestIndex, args.VertexCount, args.pDestBuffer, args.pVertexDecl, args.Flags);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::CreateVertexDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DVERTEXELEMENT9> pVertexElements;
        IDirect3DVertexDeclaration9* ppDecl;
    } args;
    (void)args;
    rp(args.pVertexElements);
    HRESULT res = self->CreateVertexDeclaration(opt2ptr(args.pVertexElements), &args.ppDecl);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDecl));
}

void ProcBase<IDirect3DDevice9>::SetVertexDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DVertexDeclaration9* pDecl;
    } args;
    (void)args;
    args.pDecl = procMap_->getPtr<IDirect3DVertexDeclaration9>(rp.operator()<ProxyId>());
    HRESULT res = self->SetVertexDeclaration(args.pDecl);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetVertexDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DVertexDeclaration9* ppDecl;
    } args;
    (void)args;
    HRESULT res = self->GetVertexDeclaration(&args.ppDecl);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDecl));
}

void ProcBase<IDirect3DDevice9>::SetFVF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        DWORD FVF;
    } args;
    (void)args;
    rp(args.FVF);
    HRESULT res = self->SetFVF(args.FVF);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetFVF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<DWORD> pFVF;
    } args;
    (void)args;
    rp(args.pFVF);
    HRESULT res = self->GetFVF(opt2ptr(args.pFVF));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pFVF) wp(*args.pFVF);
}

void ProcBase<IDirect3DDevice9>::CreateVertexShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<DWORD> pFunction;
        IDirect3DVertexShader9* ppShader;
    } args;
    (void)args;
    rp(args.pFunction);
    HRESULT res = self->CreateVertexShader(opt2ptr(args.pFunction), &args.ppShader);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppShader));
}

void ProcBase<IDirect3DDevice9>::SetVertexShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DVertexShader9* pShader;
    } args;
    (void)args;
    args.pShader = procMap_->getPtr<IDirect3DVertexShader9>(rp.operator()<ProxyId>());
    HRESULT res = self->SetVertexShader(args.pShader);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetVertexShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DVertexShader9* ppShader;
    } args;
    (void)args;
    HRESULT res = self->GetVertexShader(&args.ppShader);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppShader));
}

void ProcBase<IDirect3DDevice9>::SetVertexShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<float> pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.Vector4fCount);
    HRESULT res = self->SetVertexShaderConstantF(args.StartRegister, opt2ptr(args.pConstantData), args.Vector4fCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetVertexShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<float> pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.Vector4fCount);
    HRESULT res = self->GetVertexShaderConstantF(args.StartRegister, opt2ptr(args.pConstantData), args.Vector4fCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pConstantData) wp(*args.pConstantData);
}

void ProcBase<IDirect3DDevice9>::SetVertexShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<int> pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.Vector4iCount);
    HRESULT res = self->SetVertexShaderConstantI(args.StartRegister, opt2ptr(args.pConstantData), args.Vector4iCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetVertexShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<int> pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.Vector4iCount);
    HRESULT res = self->GetVertexShaderConstantI(args.StartRegister, opt2ptr(args.pConstantData), args.Vector4iCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pConstantData) wp(*args.pConstantData);
}

void ProcBase<IDirect3DDevice9>::SetVertexShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<BOOL> pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.BoolCount);
    HRESULT res = self->SetVertexShaderConstantB(args.StartRegister, opt2ptr(args.pConstantData), args.BoolCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetVertexShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<BOOL> pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.BoolCount);
    HRESULT res = self->GetVertexShaderConstantB(args.StartRegister, opt2ptr(args.pConstantData), args.BoolCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pConstantData) wp(*args.pConstantData);
}

void ProcBase<IDirect3DDevice9>::SetStreamSource(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StreamNumber;
        IDirect3DVertexBuffer9* pStreamData;
        UINT OffsetInBytes;
        UINT Stride;
    } args;
    (void)args;
    rp(args.StreamNumber);
    args.pStreamData = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    rp(args.OffsetInBytes);
    rp(args.Stride);
    HRESULT res = self->SetStreamSource(args.StreamNumber, args.pStreamData, args.OffsetInBytes, args.Stride);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetStreamSource(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StreamNumber;
        IDirect3DVertexBuffer9* ppStreamData;
        optional<UINT> pOffsetInBytes;
        optional<UINT> pStride;
    } args;
    (void)args;
    rp(args.StreamNumber);
    rp(args.pOffsetInBytes);
    rp(args.pStride);
    HRESULT res = self->GetStreamSource(args.StreamNumber, &args.ppStreamData, opt2ptr(args.pOffsetInBytes), opt2ptr(args.pStride));
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppStreamData));
    if (args.pOffsetInBytes) wp(*args.pOffsetInBytes);
    if (args.pStride) wp(*args.pStride);
}

void ProcBase<IDirect3DDevice9>::SetStreamSourceFreq(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StreamNumber;
        UINT Setting;
    } args;
    (void)args;
    rp(args.StreamNumber);
    rp(args.Setting);
    HRESULT res = self->SetStreamSourceFreq(args.StreamNumber, args.Setting);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetStreamSourceFreq(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StreamNumber;
        optional<UINT> pSetting;
    } args;
    (void)args;
    rp(args.StreamNumber);
    rp(args.pSetting);
    HRESULT res = self->GetStreamSourceFreq(args.StreamNumber, opt2ptr(args.pSetting));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pSetting) wp(*args.pSetting);
}

void ProcBase<IDirect3DDevice9>::SetIndices(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DIndexBuffer9* pIndexData;
    } args;
    (void)args;
    args.pIndexData = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    HRESULT res = self->SetIndices(args.pIndexData);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetIndices(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DIndexBuffer9* ppIndexData;
    } args;
    (void)args;
    HRESULT res = self->GetIndices(&args.ppIndexData);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppIndexData));
}

void ProcBase<IDirect3DDevice9>::CreatePixelShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        optional<DWORD> pFunction;
        IDirect3DPixelShader9* ppShader;
    } args;
    (void)args;
    rp(args.pFunction);
    HRESULT res = self->CreatePixelShader(opt2ptr(args.pFunction), &args.ppShader);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppShader));
}

void ProcBase<IDirect3DDevice9>::SetPixelShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DPixelShader9* pShader;
    } args;
    (void)args;
    args.pShader = procMap_->getPtr<IDirect3DPixelShader9>(rp.operator()<ProxyId>());
    HRESULT res = self->SetPixelShader(args.pShader);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetPixelShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DPixelShader9* ppShader;
    } args;
    (void)args;
    HRESULT res = self->GetPixelShader(&args.ppShader);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppShader));
}

void ProcBase<IDirect3DDevice9>::SetPixelShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<float> pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.Vector4fCount);
    HRESULT res = self->SetPixelShaderConstantF(args.StartRegister, opt2ptr(args.pConstantData), args.Vector4fCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetPixelShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<float> pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.Vector4fCount);
    HRESULT res = self->GetPixelShaderConstantF(args.StartRegister, opt2ptr(args.pConstantData), args.Vector4fCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pConstantData) wp(*args.pConstantData);
}

void ProcBase<IDirect3DDevice9>::SetPixelShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<int> pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.Vector4iCount);
    HRESULT res = self->SetPixelShaderConstantI(args.StartRegister, opt2ptr(args.pConstantData), args.Vector4iCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetPixelShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<int> pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.Vector4iCount);
    HRESULT res = self->GetPixelShaderConstantI(args.StartRegister, opt2ptr(args.pConstantData), args.Vector4iCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pConstantData) wp(*args.pConstantData);
}

void ProcBase<IDirect3DDevice9>::SetPixelShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<BOOL> pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.BoolCount);
    HRESULT res = self->SetPixelShaderConstantB(args.StartRegister, opt2ptr(args.pConstantData), args.BoolCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::GetPixelShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT StartRegister;
        optional<BOOL> pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    rp(args.StartRegister);
    rp(args.pConstantData);
    rp(args.BoolCount);
    HRESULT res = self->GetPixelShaderConstantB(args.StartRegister, opt2ptr(args.pConstantData), args.BoolCount);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pConstantData) wp(*args.pConstantData);
}

void ProcBase<IDirect3DDevice9>::DrawRectPatch(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Handle;
        optional<float> pNumSegs;
        optional<D3DRECTPATCH_INFO> pRectPatchInfo;
    } args;
    (void)args;
    rp(args.Handle);
    rp(args.pNumSegs);
    rp(args.pRectPatchInfo);
    HRESULT res = self->DrawRectPatch(args.Handle, opt2ptr(args.pNumSegs), opt2ptr(args.pRectPatchInfo));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::DrawTriPatch(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Handle;
        optional<float> pNumSegs;
        optional<D3DTRIPATCH_INFO> pTriPatchInfo;
    } args;
    (void)args;
    rp(args.Handle);
    rp(args.pNumSegs);
    rp(args.pTriPatchInfo);
    HRESULT res = self->DrawTriPatch(args.Handle, opt2ptr(args.pNumSegs), opt2ptr(args.pTriPatchInfo));
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::DeletePatch(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        UINT Handle;
    } args;
    (void)args;
    rp(args.Handle);
    HRESULT res = self->DeletePatch(args.Handle);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DDevice9>::CreateQuery(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(rp.operator()<ProxyId>());
    struct {
        D3DQUERYTYPE Type;
        IDirect3DQuery9* ppQuery;
    } args;
    (void)args;
    rp(args.Type);
    HRESULT res = self->CreateQuery(args.Type, &args.ppQuery);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppQuery));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DStateBlock9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DStateBlock9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
}

void ProcBase<IDirect3DStateBlock9>::Capture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->Capture();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DStateBlock9>::Apply(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->Apply();
    bytes::write_proc wp(dstBytes);
    wp(res);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSwapChain9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSwapChain9>::Present(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    struct {
        optional<RECT> pSourceRect;
        optional<RECT> pDestRect;
        HWND hDestWindowOverride;
        optional<RGNDATA> pDirtyRegion;
        DWORD dwFlags;
    } args;
    (void)args;
    rp(args.pSourceRect);
    rp(args.pDestRect);
    rp(args.hDestWindowOverride);
    rp(args.pDirtyRegion);
    rp(args.dwFlags);
    HRESULT res = self->Present(opt2ptr(args.pSourceRect), opt2ptr(args.pDestRect), args.hDestWindowOverride, opt2ptr(args.pDirtyRegion), args.dwFlags);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSwapChain9>::GetFrontBufferData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DSurface9* pDestSurface;
    } args;
    (void)args;
    args.pDestSurface = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    HRESULT res = self->GetFrontBufferData(args.pDestSurface);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSwapChain9>::GetBackBuffer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    struct {
        UINT iBackBuffer;
        D3DBACKBUFFER_TYPE Type;
        IDirect3DSurface9* ppBackBuffer;
    } args;
    (void)args;
    rp(args.iBackBuffer);
    rp(args.Type);
    HRESULT res = self->GetBackBuffer(args.iBackBuffer, args.Type, &args.ppBackBuffer);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppBackBuffer));
}

void ProcBase<IDirect3DSwapChain9>::GetRasterStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DRASTER_STATUS> pRasterStatus;
    } args;
    (void)args;
    rp(args.pRasterStatus);
    HRESULT res = self->GetRasterStatus(opt2ptr(args.pRasterStatus));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pRasterStatus) wp(*args.pRasterStatus);
}

void ProcBase<IDirect3DSwapChain9>::GetDisplayMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DDISPLAYMODE> pMode;
    } args;
    (void)args;
    rp(args.pMode);
    HRESULT res = self->GetDisplayMode(opt2ptr(args.pMode));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pMode) wp(*args.pMode);
}

void ProcBase<IDirect3DSwapChain9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
}

void ProcBase<IDirect3DSwapChain9>::GetPresentParameters(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DPRESENT_PARAMETERS> pPresentationParameters;
    } args;
    (void)args;
    rp(args.pPresentationParameters);
    HRESULT res = self->GetPresentParameters(opt2ptr(args.pPresentationParameters));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pPresentationParameters) wp(*args.pPresentationParameters);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexDeclaration9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexDeclaration9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
}

void ProcBase<IDirect3DVertexDeclaration9>::GetDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DVERTEXELEMENT9> pElement;
        optional<UINT> pNumElements;
    } args;
    (void)args;
    rp(args.pElement);
    rp(args.pNumElements);
    HRESULT res = self->GetDeclaration(opt2ptr(args.pElement), opt2ptr(args.pNumElements));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pElement) wp(*args.pElement);
    if (args.pNumElements) wp(*args.pNumElements);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexShader9 *self = procMap_->getPtr<IDirect3DVertexShader9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexShader9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexShader9 *self = procMap_->getPtr<IDirect3DVertexShader9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexShader9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexShader9 *self = procMap_->getPtr<IDirect3DVertexShader9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DPixelShader9 *self = procMap_->getPtr<IDirect3DPixelShader9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DPixelShader9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DPixelShader9 *self = procMap_->getPtr<IDirect3DPixelShader9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DPixelShader9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DPixelShader9 *self = procMap_->getPtr<IDirect3DPixelShader9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    rp(args.refguid);
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    rp(args.PriorityNew);
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->PreLoad();
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DTexture9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DRESOURCETYPE res = self->GetType();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::SetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        DWORD LODNew;
    } args;
    (void)args;
    rp(args.LODNew);
    DWORD res = self->SetLOD(args.LODNew);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::GetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLOD();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::GetLevelCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLevelCount();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::SetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        D3DTEXTUREFILTERTYPE FilterType;
    } args;
    (void)args;
    rp(args.FilterType);
    HRESULT res = self->SetAutoGenFilterType(args.FilterType);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::GetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DTEXTUREFILTERTYPE res = self->GetAutoGenFilterType();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::GenerateMipSubLevels(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->GenerateMipSubLevels();
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DTexture9>::GetLevelDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        UINT Level;
        optional<D3DSURFACE_DESC> pDesc;
    } args;
    (void)args;
    rp(args.Level);
    rp(args.pDesc);
    HRESULT res = self->GetLevelDesc(args.Level, opt2ptr(args.pDesc));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pDesc) wp(*args.pDesc);
}

void ProcBase<IDirect3DTexture9>::GetSurfaceLevel(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        UINT Level;
        IDirect3DSurface9* ppSurfaceLevel;
    } args;
    (void)args;
    rp(args.Level);
    HRESULT res = self->GetSurfaceLevel(args.Level, &args.ppSurfaceLevel);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppSurfaceLevel));
}

void ProcBase<IDirect3DTexture9>::LockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        UINT Level;
        optional<D3DLOCKED_RECT> pLockedRect;
        optional<RECT> pRect;
        DWORD Flags;
    } args;
    (void)args;
    rp(args.Level);
    rp(args.pLockedRect);
    rp(args.pRect);
    rp(args.Flags);
    HRESULT res = self->LockRect(args.Level, opt2ptr(args.pLockedRect), opt2ptr(args.pRect), args.Flags);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pLockedRect) wp(*args.pLockedRect);
}

void ProcBase<IDirect3DTexture9>::UnlockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        UINT Level;
    } args;
    (void)args;
    rp(args.Level);
    HRESULT res = self->UnlockRect(args.Level);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DTexture9>::AddDirtyRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(rp.operator()<ProxyId>());
    struct {
        optional<RECT> pDirtyRect;
    } args;
    (void)args;
    rp(args.pDirtyRect);
    HRESULT res = self->AddDirtyRect(opt2ptr(args.pDirtyRect));
    bytes::write_proc wp(dstBytes);
    wp(res);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    rp(args.refguid);
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    rp(args.PriorityNew);
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->PreLoad();
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DRESOURCETYPE res = self->GetType();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::SetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        DWORD LODNew;
    } args;
    (void)args;
    rp(args.LODNew);
    DWORD res = self->SetLOD(args.LODNew);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::GetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLOD();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::GetLevelCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLevelCount();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::SetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        D3DTEXTUREFILTERTYPE FilterType;
    } args;
    (void)args;
    rp(args.FilterType);
    HRESULT res = self->SetAutoGenFilterType(args.FilterType);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::GetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DTEXTUREFILTERTYPE res = self->GetAutoGenFilterType();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::GenerateMipSubLevels(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->GenerateMipSubLevels();
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::GetLevelDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        UINT Level;
        optional<D3DVOLUME_DESC> pDesc;
    } args;
    (void)args;
    rp(args.Level);
    rp(args.pDesc);
    HRESULT res = self->GetLevelDesc(args.Level, opt2ptr(args.pDesc));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pDesc) wp(*args.pDesc);
}

void ProcBase<IDirect3DVolumeTexture9>::GetVolumeLevel(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        UINT Level;
        IDirect3DVolume9* ppVolumeLevel;
    } args;
    (void)args;
    rp(args.Level);
    HRESULT res = self->GetVolumeLevel(args.Level, &args.ppVolumeLevel);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppVolumeLevel));
}

void ProcBase<IDirect3DVolumeTexture9>::LockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        UINT Level;
        optional<D3DLOCKED_BOX> pLockedVolume;
        optional<D3DBOX> pBox;
        DWORD Flags;
    } args;
    (void)args;
    rp(args.Level);
    rp(args.pLockedVolume);
    rp(args.pBox);
    rp(args.Flags);
    HRESULT res = self->LockBox(args.Level, opt2ptr(args.pLockedVolume), opt2ptr(args.pBox), args.Flags);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pLockedVolume) wp(*args.pLockedVolume);
}

void ProcBase<IDirect3DVolumeTexture9>::UnlockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        UINT Level;
    } args;
    (void)args;
    rp(args.Level);
    HRESULT res = self->UnlockBox(args.Level);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolumeTexture9>::AddDirtyBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DBOX> pDirtyBox;
    } args;
    (void)args;
    rp(args.pDirtyBox);
    HRESULT res = self->AddDirtyBox(opt2ptr(args.pDirtyBox));
    bytes::write_proc wp(dstBytes);
    wp(res);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    rp(args.refguid);
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    rp(args.PriorityNew);
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->PreLoad();
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DRESOURCETYPE res = self->GetType();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::SetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        DWORD LODNew;
    } args;
    (void)args;
    rp(args.LODNew);
    DWORD res = self->SetLOD(args.LODNew);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::GetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLOD();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::GetLevelCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLevelCount();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::SetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        D3DTEXTUREFILTERTYPE FilterType;
    } args;
    (void)args;
    rp(args.FilterType);
    HRESULT res = self->SetAutoGenFilterType(args.FilterType);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::GetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DTEXTUREFILTERTYPE res = self->GetAutoGenFilterType();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::GenerateMipSubLevels(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->GenerateMipSubLevels();
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::GetLevelDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        UINT Level;
        optional<D3DSURFACE_DESC> pDesc;
    } args;
    (void)args;
    rp(args.Level);
    rp(args.pDesc);
    HRESULT res = self->GetLevelDesc(args.Level, opt2ptr(args.pDesc));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pDesc) wp(*args.pDesc);
}

void ProcBase<IDirect3DCubeTexture9>::GetCubeMapSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        D3DCUBEMAP_FACES FaceType;
        UINT Level;
        IDirect3DSurface9* ppCubeMapSurface;
    } args;
    (void)args;
    rp(args.FaceType);
    rp(args.Level);
    HRESULT res = self->GetCubeMapSurface(args.FaceType, args.Level, &args.ppCubeMapSurface);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppCubeMapSurface));
}

void ProcBase<IDirect3DCubeTexture9>::LockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        D3DCUBEMAP_FACES FaceType;
        UINT Level;
        optional<D3DLOCKED_RECT> pLockedRect;
        optional<RECT> pRect;
        DWORD Flags;
    } args;
    (void)args;
    rp(args.FaceType);
    rp(args.Level);
    rp(args.pLockedRect);
    rp(args.pRect);
    rp(args.Flags);
    HRESULT res = self->LockRect(args.FaceType, args.Level, opt2ptr(args.pLockedRect), opt2ptr(args.pRect), args.Flags);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pLockedRect) wp(*args.pLockedRect);
}

void ProcBase<IDirect3DCubeTexture9>::UnlockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        D3DCUBEMAP_FACES FaceType;
        UINT Level;
    } args;
    (void)args;
    rp(args.FaceType);
    rp(args.Level);
    HRESULT res = self->UnlockRect(args.FaceType, args.Level);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DCubeTexture9>::AddDirtyRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(rp.operator()<ProxyId>());
    struct {
        D3DCUBEMAP_FACES FaceType;
        optional<RECT> pDirtyRect;
    } args;
    (void)args;
    rp(args.FaceType);
    rp(args.pDirtyRect);
    HRESULT res = self->AddDirtyRect(args.FaceType, opt2ptr(args.pDirtyRect));
    bytes::write_proc wp(dstBytes);
    wp(res);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexBuffer9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexBuffer9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    rp(args.refguid);
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexBuffer9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    rp(args.PriorityNew);
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexBuffer9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexBuffer9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->PreLoad();
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DVertexBuffer9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DRESOURCETYPE res = self->GetType();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexBuffer9>::Lock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DVertexBuffer9>::Unlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->Unlock();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVertexBuffer9>::GetDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DVERTEXBUFFER_DESC> pDesc;
    } args;
    (void)args;
    rp(args.pDesc);
    HRESULT res = self->GetDesc(opt2ptr(args.pDesc));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pDesc) wp(*args.pDesc);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DIndexBuffer9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DIndexBuffer9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    rp(args.refguid);
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DIndexBuffer9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    rp(args.PriorityNew);
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DIndexBuffer9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DIndexBuffer9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->PreLoad();
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DIndexBuffer9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DRESOURCETYPE res = self->GetType();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DIndexBuffer9>::Lock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DIndexBuffer9>::Unlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->Unlock();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DIndexBuffer9>::GetDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DINDEXBUFFER_DESC> pDesc;
    } args;
    (void)args;
    rp(args.pDesc);
    HRESULT res = self->GetDesc(opt2ptr(args.pDesc));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pDesc) wp(*args.pDesc);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSurface9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSurface9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    rp(args.refguid);
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSurface9>::SetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        DWORD PriorityNew;
    } args;
    (void)args;
    rp(args.PriorityNew);
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSurface9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSurface9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->PreLoad();
    bytes::write_proc wp(dstBytes);
}

void ProcBase<IDirect3DSurface9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DRESOURCETYPE res = self->GetType();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSurface9>::GetContainer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DSurface9>::GetDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DSURFACE_DESC> pDesc;
    } args;
    (void)args;
    rp(args.pDesc);
    HRESULT res = self->GetDesc(opt2ptr(args.pDesc));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pDesc) wp(*args.pDesc);
}

void ProcBase<IDirect3DSurface9>::LockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DLOCKED_RECT> pLockedRect;
        optional<RECT> pRect;
        DWORD Flags;
    } args;
    (void)args;
    rp(args.pLockedRect);
    rp(args.pRect);
    rp(args.Flags);
    HRESULT res = self->LockRect(opt2ptr(args.pLockedRect), opt2ptr(args.pRect), args.Flags);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pLockedRect) wp(*args.pLockedRect);
}

void ProcBase<IDirect3DSurface9>::UnlockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->UnlockRect();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DSurface9>::GetDC(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        optional<HDC> phdc;
    } args;
    (void)args;
    rp(args.phdc);
    HRESULT res = self->GetDC(opt2ptr(args.phdc));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.phdc) wp(*args.phdc);
}

void ProcBase<IDirect3DSurface9>::ReleaseDC(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(rp.operator()<ProxyId>());
    struct {
        HDC hdc;
    } args;
    (void)args;
    rp(args.hdc);
    HRESULT res = self->ReleaseDC(args.hdc);
    bytes::write_proc wp(dstBytes);
    wp(res);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolume9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolume9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
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
    bytes::read_proc rp(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(rp.operator()<ProxyId>());
    struct {
        GUID refguid;
    } args;
    (void)args;
    rp(args.refguid);
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DVolume9>::GetContainer(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void**");
}

void ProcBase<IDirect3DVolume9>::GetDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DVOLUME_DESC> pDesc;
    } args;
    (void)args;
    rp(args.pDesc);
    HRESULT res = self->GetDesc(opt2ptr(args.pDesc));
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pDesc) wp(*args.pDesc);
}

void ProcBase<IDirect3DVolume9>::LockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(rp.operator()<ProxyId>());
    struct {
        optional<D3DLOCKED_BOX> pLockedVolume;
        optional<D3DBOX> pBox;
        DWORD Flags;
    } args;
    (void)args;
    rp(args.pLockedVolume);
    rp(args.pBox);
    rp(args.Flags);
    HRESULT res = self->LockBox(opt2ptr(args.pLockedVolume), opt2ptr(args.pBox), args.Flags);
    bytes::write_proc wp(dstBytes);
    wp(res);
    if (args.pLockedVolume) wp(*args.pLockedVolume);
}

void ProcBase<IDirect3DVolume9>::UnlockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->UnlockBox();
    bytes::write_proc wp(dstBytes);
    wp(res);
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
    bytes::read_proc rp(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->AddRef();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DQuery9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DQuery9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(rp.operator()<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::write_proc wp(dstBytes);
    wp(res);
    wp(procMap_->getProxyID(args.ppDevice));
}

void ProcBase<IDirect3DQuery9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DQUERYTYPE res = self->GetType();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DQuery9>::GetDataSize(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(rp.operator()<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetDataSize();
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DQuery9>::Issue(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::read_proc rp(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(rp.operator()<ProxyId>());
    struct {
        DWORD dwIssueFlags;
    } args;
    (void)args;
    rp(args.dwIssueFlags);
    HRESULT res = self->Issue(args.dwIssueFlags);
    bytes::write_proc wp(dstBytes);
    wp(res);
}

void ProcBase<IDirect3DQuery9>::GetData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

} // namespace D3D9

} // namespace Server

