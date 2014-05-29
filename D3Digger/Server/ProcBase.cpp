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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3D9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
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
    UINT res = self->GetAdapterCount();
    bytes::put<UINT>(res, dstBytes);
}

void ProcBase<IDirect3D9>::GetAdapterIdentifier(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        DWORD Flags;
        optional<D3DADAPTER_IDENTIFIER9> pIdentifier;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.Flags = g.get<DWORD>();
    HRESULT res = self->GetAdapterIdentifier(args.Adapter,args.Flags,opt2ptr(args.pIdentifier));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DADAPTER_IDENTIFIER9>>(args.pIdentifier, dstBytes);
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
    UINT res = self->GetAdapterModeCount(args.Adapter,args.Format);
    bytes::put<UINT>(res, dstBytes);
}

void ProcBase<IDirect3D9>::EnumAdapterModes(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DFORMAT Format;
        UINT Mode;
        optional<D3DDISPLAYMODE> pMode;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.Format = g.get<D3DFORMAT>();
    args.Mode = g.get<UINT>();
    HRESULT res = self->EnumAdapterModes(args.Adapter,args.Format,args.Mode,opt2ptr(args.pMode));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DDISPLAYMODE>>(args.pMode, dstBytes);
}

void ProcBase<IDirect3D9>::GetAdapterDisplayMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        optional<D3DDISPLAYMODE> pMode;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    HRESULT res = self->GetAdapterDisplayMode(args.Adapter,opt2ptr(args.pMode));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DDISPLAYMODE>>(args.pMode, dstBytes);
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
    HRESULT res = self->CheckDeviceType(args.Adapter,args.DevType,args.AdapterFormat,args.BackBufferFormat,args.bWindowed);
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->CheckDeviceFormat(args.Adapter,args.DeviceType,args.AdapterFormat,args.Usage,args.RType,args.CheckFormat);
    bytes::put<HRESULT>(res, dstBytes);
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
        optional<DWORD> pQualityLevels;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.DeviceType = g.get<D3DDEVTYPE>();
    args.SurfaceFormat = g.get<D3DFORMAT>();
    args.Windowed = g.get<BOOL>();
    args.MultiSampleType = g.get<D3DMULTISAMPLE_TYPE>();
    HRESULT res = self->CheckDeviceMultiSampleType(args.Adapter,args.DeviceType,args.SurfaceFormat,args.Windowed,args.MultiSampleType,opt2ptr(args.pQualityLevels));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<DWORD>>(args.pQualityLevels, dstBytes);
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
    HRESULT res = self->CheckDepthStencilMatch(args.Adapter,args.DeviceType,args.AdapterFormat,args.RenderTargetFormat,args.DepthStencilFormat);
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->CheckDeviceFormatConversion(args.Adapter,args.DeviceType,args.SourceFormat,args.TargetFormat);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3D9>::GetDeviceCaps(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3D9 *self = procMap_->getPtr<IDirect3D9>(g.get<ProxyId>());
    struct {
        UINT Adapter;
        D3DDEVTYPE DeviceType;
        optional<D3DCAPS9> pCaps;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.DeviceType = g.get<D3DDEVTYPE>();
    HRESULT res = self->GetDeviceCaps(args.Adapter,args.DeviceType,opt2ptr(args.pCaps));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DCAPS9>>(args.pCaps, dstBytes);
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
    HMONITOR res = self->GetAdapterMonitor(args.Adapter);
    bytes::put<HMONITOR>(res, dstBytes);
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
        optional<D3DPRESENT_PARAMETERS> pPresentationParameters;
        IDirect3DDevice9* ppReturnedDeviceInterface;
    } args;
    (void)args;
    args.Adapter = g.get<UINT>();
    args.DeviceType = g.get<D3DDEVTYPE>();
    args.hFocusWindow = g.get<HWND>();
    args.BehaviorFlags = g.get<DWORD>();
    args.pPresentationParameters = g.get<optional<D3DPRESENT_PARAMETERS>>();
    HRESULT res = self->CreateDevice(args.Adapter,args.DeviceType,args.hFocusWindow,args.BehaviorFlags,opt2ptr(args.pPresentationParameters),&args.ppReturnedDeviceInterface);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DPRESENT_PARAMETERS>>(args.pPresentationParameters, dstBytes);
    bytes::put<ProxyId>(procMap_->getProxyID(args.ppReturnedDeviceInterface), dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::TestCooperativeLevel(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->TestCooperativeLevel();
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetAvailableTextureMem(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    UINT res = self->GetAvailableTextureMem();
    bytes::put<UINT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::EvictManagedResources(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->EvictManagedResources();
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetDirect3D(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3D9* ppD3D9;
    } args;
    (void)args;
    HRESULT res = self->GetDirect3D(&args.ppD3D9);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppD3D9), dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetDeviceCaps(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DCAPS9> pCaps;
    } args;
    (void)args;
    HRESULT res = self->GetDeviceCaps(opt2ptr(args.pCaps));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DCAPS9>>(args.pCaps, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetDisplayMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        optional<D3DDISPLAYMODE> pMode;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    HRESULT res = self->GetDisplayMode(args.iSwapChain,opt2ptr(args.pMode));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DDISPLAYMODE>>(args.pMode, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetCreationParameters(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DDEVICE_CREATION_PARAMETERS> pParameters;
    } args;
    (void)args;
    HRESULT res = self->GetCreationParameters(opt2ptr(args.pParameters));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DDEVICE_CREATION_PARAMETERS>>(args.pParameters, dstBytes);
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
    HRESULT res = self->SetCursorProperties(args.XHotSpot,args.YHotSpot,args.pCursorBitmap);
    bytes::put<HRESULT>(res, dstBytes);
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
    self->SetCursorPosition(args.X,args.Y,args.Flags);
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
    BOOL res = self->ShowCursor(args.bShow);
    bytes::put<BOOL>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::CreateAdditionalSwapChain(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DPRESENT_PARAMETERS> pPresentationParameters;
        IDirect3DSwapChain9* pSwapChain;
    } args;
    (void)args;
    args.pPresentationParameters = g.get<optional<D3DPRESENT_PARAMETERS>>();
    HRESULT res = self->CreateAdditionalSwapChain(opt2ptr(args.pPresentationParameters),&args.pSwapChain);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DPRESENT_PARAMETERS>>(args.pPresentationParameters, dstBytes);
    bytes::put<ProxyId>(procMap_->getProxyID(args.pSwapChain), dstBytes);
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
    HRESULT res = self->GetSwapChain(args.iSwapChain,&args.pSwapChain);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.pSwapChain), dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetNumberOfSwapChains(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    UINT res = self->GetNumberOfSwapChains();
    bytes::put<UINT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::Reset(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DPRESENT_PARAMETERS> pPresentationParameters;
    } args;
    (void)args;
    HRESULT res = self->Reset(opt2ptr(args.pPresentationParameters));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DPRESENT_PARAMETERS>>(args.pPresentationParameters, dstBytes);
}

void ProcBase<IDirect3DDevice9>::Present(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<RECT> pSourceRect;
        optional<RECT> pDestRect;
        HWND hDestWindowOverride;
        optional<RGNDATA> pDirtyRegion;
    } args;
    (void)args;
    args.pSourceRect = g.get<optional<RECT>>();
    args.pDestRect = g.get<optional<RECT>>();
    args.hDestWindowOverride = g.get<HWND>();
    args.pDirtyRegion = g.get<optional<RGNDATA>>();
    HRESULT res = self->Present(opt2ptr(args.pSourceRect),opt2ptr(args.pDestRect),args.hDestWindowOverride,opt2ptr(args.pDirtyRegion));
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->GetBackBuffer(args.iSwapChain,args.iBackBuffer,args.Type,&args.ppBackBuffer);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppBackBuffer), dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetRasterStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        optional<D3DRASTER_STATUS> pRasterStatus;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    HRESULT res = self->GetRasterStatus(args.iSwapChain,opt2ptr(args.pRasterStatus));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DRASTER_STATUS>>(args.pRasterStatus, dstBytes);
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
    HRESULT res = self->SetDialogBoxMode(args.bEnableDialogs);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetGammaRamp(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        DWORD Flags;
        optional<D3DGAMMARAMP> pRamp;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    args.Flags = g.get<DWORD>();
    args.pRamp = g.get<optional<D3DGAMMARAMP>>();
    self->SetGammaRamp(args.iSwapChain,args.Flags,opt2ptr(args.pRamp));
}

void ProcBase<IDirect3DDevice9>::GetGammaRamp(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT iSwapChain;
        optional<D3DGAMMARAMP> pRamp;
    } args;
    (void)args;
    args.iSwapChain = g.get<UINT>();
    self->GetGammaRamp(args.iSwapChain,opt2ptr(args.pRamp));
    bytes::put<optional<D3DGAMMARAMP>>(args.pRamp, dstBytes);
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
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    args.Width = g.get<UINT>();
    args.Height = g.get<UINT>();
    args.Levels = g.get<UINT>();
    args.Usage = g.get<DWORD>();
    args.Format = g.get<D3DFORMAT>();
    args.Pool = g.get<D3DPOOL>();
    HRESULT res = self->CreateTexture(args.Width,args.Height,args.Levels,args.Usage,args.Format,args.Pool,&args.ppTexture,opt2ptr(args.pSharedHandle));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppTexture), dstBytes);
    bytes::put<optional<HANDLE>>(args.pSharedHandle, dstBytes);
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
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    args.Width = g.get<UINT>();
    args.Height = g.get<UINT>();
    args.Depth = g.get<UINT>();
    args.Levels = g.get<UINT>();
    args.Usage = g.get<DWORD>();
    args.Format = g.get<D3DFORMAT>();
    args.Pool = g.get<D3DPOOL>();
    HRESULT res = self->CreateVolumeTexture(args.Width,args.Height,args.Depth,args.Levels,args.Usage,args.Format,args.Pool,&args.ppVolumeTexture,opt2ptr(args.pSharedHandle));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppVolumeTexture), dstBytes);
    bytes::put<optional<HANDLE>>(args.pSharedHandle, dstBytes);
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
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    args.EdgeLength = g.get<UINT>();
    args.Levels = g.get<UINT>();
    args.Usage = g.get<DWORD>();
    args.Format = g.get<D3DFORMAT>();
    args.Pool = g.get<D3DPOOL>();
    HRESULT res = self->CreateCubeTexture(args.EdgeLength,args.Levels,args.Usage,args.Format,args.Pool,&args.ppCubeTexture,opt2ptr(args.pSharedHandle));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppCubeTexture), dstBytes);
    bytes::put<optional<HANDLE>>(args.pSharedHandle, dstBytes);
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
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    args.Length = g.get<UINT>();
    args.Usage = g.get<DWORD>();
    args.FVF = g.get<DWORD>();
    args.Pool = g.get<D3DPOOL>();
    HRESULT res = self->CreateVertexBuffer(args.Length,args.Usage,args.FVF,args.Pool,&args.ppVertexBuffer,opt2ptr(args.pSharedHandle));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppVertexBuffer), dstBytes);
    bytes::put<optional<HANDLE>>(args.pSharedHandle, dstBytes);
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
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    args.Length = g.get<UINT>();
    args.Usage = g.get<DWORD>();
    args.Format = g.get<D3DFORMAT>();
    args.Pool = g.get<D3DPOOL>();
    HRESULT res = self->CreateIndexBuffer(args.Length,args.Usage,args.Format,args.Pool,&args.ppIndexBuffer,opt2ptr(args.pSharedHandle));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppIndexBuffer), dstBytes);
    bytes::put<optional<HANDLE>>(args.pSharedHandle, dstBytes);
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
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    args.Width = g.get<UINT>();
    args.Height = g.get<UINT>();
    args.Format = g.get<D3DFORMAT>();
    args.MultiSample = g.get<D3DMULTISAMPLE_TYPE>();
    args.MultisampleQuality = g.get<DWORD>();
    args.Lockable = g.get<BOOL>();
    HRESULT res = self->CreateRenderTarget(args.Width,args.Height,args.Format,args.MultiSample,args.MultisampleQuality,args.Lockable,&args.ppSurface,opt2ptr(args.pSharedHandle));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppSurface), dstBytes);
    bytes::put<optional<HANDLE>>(args.pSharedHandle, dstBytes);
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
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    args.Width = g.get<UINT>();
    args.Height = g.get<UINT>();
    args.Format = g.get<D3DFORMAT>();
    args.MultiSample = g.get<D3DMULTISAMPLE_TYPE>();
    args.MultisampleQuality = g.get<DWORD>();
    args.Discard = g.get<BOOL>();
    HRESULT res = self->CreateDepthStencilSurface(args.Width,args.Height,args.Format,args.MultiSample,args.MultisampleQuality,args.Discard,&args.ppSurface,opt2ptr(args.pSharedHandle));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppSurface), dstBytes);
    bytes::put<optional<HANDLE>>(args.pSharedHandle, dstBytes);
}

void ProcBase<IDirect3DDevice9>::UpdateSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* pSourceSurface;
        optional<RECT> pSourceRect;
        IDirect3DSurface9* pDestinationSurface;
        optional<POINT> pDestPoint;
    } args;
    (void)args;
    args.pSourceSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pSourceRect = g.get<optional<RECT>>();
    args.pDestinationSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pDestPoint = g.get<optional<POINT>>();
    HRESULT res = self->UpdateSurface(args.pSourceSurface,opt2ptr(args.pSourceRect),args.pDestinationSurface,opt2ptr(args.pDestPoint));
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->UpdateTexture(args.pSourceTexture,args.pDestinationTexture);
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->GetRenderTargetData(args.pRenderTarget,args.pDestSurface);
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->GetFrontBufferData(args.iSwapChain,args.pDestSurface);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::StretchRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* pSourceSurface;
        optional<RECT> pSourceRect;
        IDirect3DSurface9* pDestSurface;
        optional<RECT> pDestRect;
        D3DTEXTUREFILTERTYPE Filter;
    } args;
    (void)args;
    args.pSourceSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pSourceRect = g.get<optional<RECT>>();
    args.pDestSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pDestRect = g.get<optional<RECT>>();
    args.Filter = g.get<D3DTEXTUREFILTERTYPE>();
    HRESULT res = self->StretchRect(args.pSourceSurface,opt2ptr(args.pSourceRect),args.pDestSurface,opt2ptr(args.pDestRect),args.Filter);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::ColorFill(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* pSurface;
        optional<RECT> pRect;
        D3DCOLOR color;
    } args;
    (void)args;
    args.pSurface = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    args.pRect = g.get<optional<RECT>>();
    args.color = g.get<D3DCOLOR>();
    HRESULT res = self->ColorFill(args.pSurface,opt2ptr(args.pRect),args.color);
    bytes::put<HRESULT>(res, dstBytes);
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
        optional<HANDLE> pSharedHandle;
    } args;
    (void)args;
    args.Width = g.get<UINT>();
    args.Height = g.get<UINT>();
    args.Format = g.get<D3DFORMAT>();
    args.Pool = g.get<D3DPOOL>();
    HRESULT res = self->CreateOffscreenPlainSurface(args.Width,args.Height,args.Format,args.Pool,&args.ppSurface,opt2ptr(args.pSharedHandle));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppSurface), dstBytes);
    bytes::put<optional<HANDLE>>(args.pSharedHandle, dstBytes);
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
    HRESULT res = self->SetRenderTarget(args.RenderTargetIndex,args.pRenderTarget);
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->GetRenderTarget(args.RenderTargetIndex,&args.ppRenderTarget);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppRenderTarget), dstBytes);
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
    HRESULT res = self->SetDepthStencilSurface(args.pNewZStencil);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetDepthStencilSurface(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DSurface9* ppZStencilSurface;
    } args;
    (void)args;
    HRESULT res = self->GetDepthStencilSurface(&args.ppZStencilSurface);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppZStencilSurface), dstBytes);
}

void ProcBase<IDirect3DDevice9>::BeginScene(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->BeginScene();
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::EndScene(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->EndScene();
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::Clear(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Count;
        optional<D3DRECT> pRects;
        DWORD Flags;
        D3DCOLOR Color;
        float Z;
        DWORD Stencil;
    } args;
    (void)args;
    args.Count = g.get<DWORD>();
    args.pRects = g.get<optional<D3DRECT>>();
    args.Flags = g.get<DWORD>();
    args.Color = g.get<D3DCOLOR>();
    args.Z = g.get<float>();
    args.Stencil = g.get<DWORD>();
    HRESULT res = self->Clear(args.Count,opt2ptr(args.pRects),args.Flags,args.Color,args.Z,args.Stencil);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetTransform(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DTRANSFORMSTATETYPE State;
        optional<D3DMATRIX> pMatrix;
    } args;
    (void)args;
    args.State = g.get<D3DTRANSFORMSTATETYPE>();
    args.pMatrix = g.get<optional<D3DMATRIX>>();
    HRESULT res = self->SetTransform(args.State,opt2ptr(args.pMatrix));
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetTransform(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DTRANSFORMSTATETYPE State;
        optional<D3DMATRIX> pMatrix;
    } args;
    (void)args;
    args.State = g.get<D3DTRANSFORMSTATETYPE>();
    HRESULT res = self->GetTransform(args.State,opt2ptr(args.pMatrix));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DMATRIX>>(args.pMatrix, dstBytes);
}

void ProcBase<IDirect3DDevice9>::MultiplyTransform(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DTRANSFORMSTATETYPE transform;
        optional<D3DMATRIX> matrix;
    } args;
    (void)args;
    args.transform = g.get<D3DTRANSFORMSTATETYPE>();
    args.matrix = g.get<optional<D3DMATRIX>>();
    HRESULT res = self->MultiplyTransform(args.transform,opt2ptr(args.matrix));
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetViewport(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DVIEWPORT9> pViewport;
    } args;
    (void)args;
    args.pViewport = g.get<optional<D3DVIEWPORT9>>();
    HRESULT res = self->SetViewport(opt2ptr(args.pViewport));
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetViewport(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DVIEWPORT9> pViewport;
    } args;
    (void)args;
    HRESULT res = self->GetViewport(opt2ptr(args.pViewport));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DVIEWPORT9>>(args.pViewport, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetMaterial(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DMATERIAL9> pMaterial;
    } args;
    (void)args;
    args.pMaterial = g.get<optional<D3DMATERIAL9>>();
    HRESULT res = self->SetMaterial(opt2ptr(args.pMaterial));
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetMaterial(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DMATERIAL9> pMaterial;
    } args;
    (void)args;
    HRESULT res = self->GetMaterial(opt2ptr(args.pMaterial));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DMATERIAL9>>(args.pMaterial, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetLight(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        optional<D3DLIGHT9> pLight;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    args.pLight = g.get<optional<D3DLIGHT9>>();
    HRESULT res = self->SetLight(args.Index,opt2ptr(args.pLight));
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetLight(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        optional<D3DLIGHT9> pLight;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    HRESULT res = self->GetLight(args.Index,opt2ptr(args.pLight));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DLIGHT9>>(args.pLight, dstBytes);
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
    HRESULT res = self->LightEnable(args.Index,args.Enable);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetLightEnable(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        optional<BOOL> pEnable;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    HRESULT res = self->GetLightEnable(args.Index,opt2ptr(args.pEnable));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<BOOL>>(args.pEnable, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetClipPlane(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        optional<float> pPlane;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    args.pPlane = g.get<optional<float>>();
    HRESULT res = self->SetClipPlane(args.Index,opt2ptr(args.pPlane));
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetClipPlane(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Index;
        optional<float> pPlane;
    } args;
    (void)args;
    args.Index = g.get<DWORD>();
    HRESULT res = self->GetClipPlane(args.Index,opt2ptr(args.pPlane));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<float>>(args.pPlane, dstBytes);
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
    HRESULT res = self->SetRenderState(args.State,args.Value);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetRenderState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        D3DRENDERSTATETYPE State;
        optional<DWORD> pValue;
    } args;
    (void)args;
    args.State = g.get<D3DRENDERSTATETYPE>();
    HRESULT res = self->GetRenderState(args.State,opt2ptr(args.pValue));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<DWORD>>(args.pValue, dstBytes);
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
    HRESULT res = self->CreateStateBlock(args.Type,&args.ppSB);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppSB), dstBytes);
}

void ProcBase<IDirect3DDevice9>::BeginStateBlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->BeginStateBlock();
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::EndStateBlock(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DStateBlock9* ppSB;
    } args;
    (void)args;
    HRESULT res = self->EndStateBlock(&args.ppSB);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppSB), dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetClipStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DCLIPSTATUS9> pClipStatus;
    } args;
    (void)args;
    args.pClipStatus = g.get<optional<D3DCLIPSTATUS9>>();
    HRESULT res = self->SetClipStatus(opt2ptr(args.pClipStatus));
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetClipStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DCLIPSTATUS9> pClipStatus;
    } args;
    (void)args;
    HRESULT res = self->GetClipStatus(opt2ptr(args.pClipStatus));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DCLIPSTATUS9>>(args.pClipStatus, dstBytes);
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
    HRESULT res = self->GetTexture(args.Stage,&args.ppTexture);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppTexture), dstBytes);
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
    HRESULT res = self->SetTexture(args.Stage,args.pTexture);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetTextureStageState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Stage;
        D3DTEXTURESTAGESTATETYPE Type;
        optional<DWORD> pValue;
    } args;
    (void)args;
    args.Stage = g.get<DWORD>();
    args.Type = g.get<D3DTEXTURESTAGESTATETYPE>();
    HRESULT res = self->GetTextureStageState(args.Stage,args.Type,opt2ptr(args.pValue));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<DWORD>>(args.pValue, dstBytes);
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
    HRESULT res = self->SetTextureStageState(args.Stage,args.Type,args.Value);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetSamplerState(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        DWORD Sampler;
        D3DSAMPLERSTATETYPE Type;
        optional<DWORD> pValue;
    } args;
    (void)args;
    args.Sampler = g.get<DWORD>();
    args.Type = g.get<D3DSAMPLERSTATETYPE>();
    HRESULT res = self->GetSamplerState(args.Sampler,args.Type,opt2ptr(args.pValue));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<DWORD>>(args.pValue, dstBytes);
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
    HRESULT res = self->SetSamplerState(args.Sampler,args.Type,args.Value);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::ValidateDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<DWORD> pNumPasses;
    } args;
    (void)args;
    HRESULT res = self->ValidateDevice(opt2ptr(args.pNumPasses));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<DWORD>>(args.pNumPasses, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetPaletteEntries(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT PaletteNumber;
        optional<PALETTEENTRY> pEntries;
    } args;
    (void)args;
    args.PaletteNumber = g.get<UINT>();
    args.pEntries = g.get<optional<PALETTEENTRY>>();
    HRESULT res = self->SetPaletteEntries(args.PaletteNumber,opt2ptr(args.pEntries));
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetPaletteEntries(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT PaletteNumber;
        optional<PALETTEENTRY> pEntries;
    } args;
    (void)args;
    args.PaletteNumber = g.get<UINT>();
    HRESULT res = self->GetPaletteEntries(args.PaletteNumber,opt2ptr(args.pEntries));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<PALETTEENTRY>>(args.pEntries, dstBytes);
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
    HRESULT res = self->SetCurrentTexturePalette(args.PaletteNumber);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetCurrentTexturePalette(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<UINT> PaletteNumber;
    } args;
    (void)args;
    HRESULT res = self->GetCurrentTexturePalette(opt2ptr(args.PaletteNumber));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<UINT>>(args.PaletteNumber, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetScissorRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<RECT> pRect;
    } args;
    (void)args;
    args.pRect = g.get<optional<RECT>>();
    HRESULT res = self->SetScissorRect(opt2ptr(args.pRect));
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetScissorRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<RECT> pRect;
    } args;
    (void)args;
    HRESULT res = self->GetScissorRect(opt2ptr(args.pRect));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<RECT>>(args.pRect, dstBytes);
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
    HRESULT res = self->SetSoftwareVertexProcessing(args.bSoftware);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetSoftwareVertexProcessing(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    BOOL res = self->GetSoftwareVertexProcessing();
    bytes::put<BOOL>(res, dstBytes);
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
    HRESULT res = self->SetNPatchMode(args.nSegments);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetNPatchMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    float res = self->GetNPatchMode();
    bytes::put<float>(res, dstBytes);
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
    HRESULT res = self->DrawPrimitive(args.PrimitiveType,args.StartVertex,args.PrimitiveCount);
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->DrawIndexedPrimitive(args.PrimitiveType,args.BaseVertexIndex,args.MinVertexIndex,args.NumVertices,args.startIndex,args.primCount);
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->ProcessVertices(args.SrcStartIndex,args.DestIndex,args.VertexCount,args.pDestBuffer,args.pVertexDecl,args.Flags);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::CreateVertexDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<D3DVERTEXELEMENT9> pVertexElements;
        IDirect3DVertexDeclaration9* ppDecl;
    } args;
    (void)args;
    args.pVertexElements = g.get<optional<D3DVERTEXELEMENT9>>();
    HRESULT res = self->CreateVertexDeclaration(opt2ptr(args.pVertexElements),&args.ppDecl);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDecl), dstBytes);
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
    HRESULT res = self->SetVertexDeclaration(args.pDecl);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetVertexDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DVertexDeclaration9* ppDecl;
    } args;
    (void)args;
    HRESULT res = self->GetVertexDeclaration(&args.ppDecl);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDecl), dstBytes);
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
    HRESULT res = self->SetFVF(args.FVF);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetFVF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<DWORD> pFVF;
    } args;
    (void)args;
    HRESULT res = self->GetFVF(opt2ptr(args.pFVF));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<DWORD>>(args.pFVF, dstBytes);
}

void ProcBase<IDirect3DDevice9>::CreateVertexShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<DWORD> pFunction;
        IDirect3DVertexShader9* ppShader;
    } args;
    (void)args;
    args.pFunction = g.get<optional<DWORD>>();
    HRESULT res = self->CreateVertexShader(opt2ptr(args.pFunction),&args.ppShader);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppShader), dstBytes);
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
    HRESULT res = self->SetVertexShader(args.pShader);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetVertexShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DVertexShader9* ppShader;
    } args;
    (void)args;
    HRESULT res = self->GetVertexShader(&args.ppShader);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppShader), dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetVertexShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<float> pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<optional<float>>();
    args.Vector4fCount = g.get<UINT>();
    HRESULT res = self->SetVertexShaderConstantF(args.StartRegister,opt2ptr(args.pConstantData),args.Vector4fCount);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetVertexShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<float> pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.Vector4fCount = g.get<UINT>();
    HRESULT res = self->GetVertexShaderConstantF(args.StartRegister,opt2ptr(args.pConstantData),args.Vector4fCount);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<float>>(args.pConstantData, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetVertexShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<int> pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<optional<int>>();
    args.Vector4iCount = g.get<UINT>();
    HRESULT res = self->SetVertexShaderConstantI(args.StartRegister,opt2ptr(args.pConstantData),args.Vector4iCount);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetVertexShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<int> pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.Vector4iCount = g.get<UINT>();
    HRESULT res = self->GetVertexShaderConstantI(args.StartRegister,opt2ptr(args.pConstantData),args.Vector4iCount);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<int>>(args.pConstantData, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetVertexShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<BOOL> pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<optional<BOOL>>();
    args.BoolCount = g.get<UINT>();
    HRESULT res = self->SetVertexShaderConstantB(args.StartRegister,opt2ptr(args.pConstantData),args.BoolCount);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetVertexShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<BOOL> pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.BoolCount = g.get<UINT>();
    HRESULT res = self->GetVertexShaderConstantB(args.StartRegister,opt2ptr(args.pConstantData),args.BoolCount);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<BOOL>>(args.pConstantData, dstBytes);
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
    HRESULT res = self->SetStreamSource(args.StreamNumber,args.pStreamData,args.OffsetInBytes,args.Stride);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetStreamSource(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StreamNumber;
        IDirect3DVertexBuffer9* ppStreamData;
        optional<UINT> pOffsetInBytes;
        optional<UINT> pStride;
    } args;
    (void)args;
    args.StreamNumber = g.get<UINT>();
    HRESULT res = self->GetStreamSource(args.StreamNumber,&args.ppStreamData,opt2ptr(args.pOffsetInBytes),opt2ptr(args.pStride));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppStreamData), dstBytes);
    bytes::put<optional<UINT>>(args.pOffsetInBytes, dstBytes);
    bytes::put<optional<UINT>>(args.pStride, dstBytes);
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
    HRESULT res = self->SetStreamSourceFreq(args.StreamNumber,args.Setting);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetStreamSourceFreq(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StreamNumber;
        optional<UINT> pSetting;
    } args;
    (void)args;
    args.StreamNumber = g.get<UINT>();
    HRESULT res = self->GetStreamSourceFreq(args.StreamNumber,opt2ptr(args.pSetting));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<UINT>>(args.pSetting, dstBytes);
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
    HRESULT res = self->SetIndices(args.pIndexData);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetIndices(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DIndexBuffer9* ppIndexData;
    } args;
    (void)args;
    HRESULT res = self->GetIndices(&args.ppIndexData);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppIndexData), dstBytes);
}

void ProcBase<IDirect3DDevice9>::CreatePixelShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        optional<DWORD> pFunction;
        IDirect3DPixelShader9* ppShader;
    } args;
    (void)args;
    args.pFunction = g.get<optional<DWORD>>();
    HRESULT res = self->CreatePixelShader(opt2ptr(args.pFunction),&args.ppShader);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppShader), dstBytes);
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
    HRESULT res = self->SetPixelShader(args.pShader);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetPixelShader(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        IDirect3DPixelShader9* ppShader;
    } args;
    (void)args;
    HRESULT res = self->GetPixelShader(&args.ppShader);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppShader), dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetPixelShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<float> pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<optional<float>>();
    args.Vector4fCount = g.get<UINT>();
    HRESULT res = self->SetPixelShaderConstantF(args.StartRegister,opt2ptr(args.pConstantData),args.Vector4fCount);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetPixelShaderConstantF(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<float> pConstantData;
        UINT Vector4fCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.Vector4fCount = g.get<UINT>();
    HRESULT res = self->GetPixelShaderConstantF(args.StartRegister,opt2ptr(args.pConstantData),args.Vector4fCount);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<float>>(args.pConstantData, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetPixelShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<int> pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<optional<int>>();
    args.Vector4iCount = g.get<UINT>();
    HRESULT res = self->SetPixelShaderConstantI(args.StartRegister,opt2ptr(args.pConstantData),args.Vector4iCount);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetPixelShaderConstantI(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<int> pConstantData;
        UINT Vector4iCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.Vector4iCount = g.get<UINT>();
    HRESULT res = self->GetPixelShaderConstantI(args.StartRegister,opt2ptr(args.pConstantData),args.Vector4iCount);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<int>>(args.pConstantData, dstBytes);
}

void ProcBase<IDirect3DDevice9>::SetPixelShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<BOOL> pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.pConstantData = g.get<optional<BOOL>>();
    args.BoolCount = g.get<UINT>();
    HRESULT res = self->SetPixelShaderConstantB(args.StartRegister,opt2ptr(args.pConstantData),args.BoolCount);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::GetPixelShaderConstantB(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT StartRegister;
        optional<BOOL> pConstantData;
        UINT BoolCount;
    } args;
    (void)args;
    args.StartRegister = g.get<UINT>();
    args.BoolCount = g.get<UINT>();
    HRESULT res = self->GetPixelShaderConstantB(args.StartRegister,opt2ptr(args.pConstantData),args.BoolCount);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<BOOL>>(args.pConstantData, dstBytes);
}

void ProcBase<IDirect3DDevice9>::DrawRectPatch(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Handle;
        optional<float> pNumSegs;
        optional<D3DRECTPATCH_INFO> pRectPatchInfo;
    } args;
    (void)args;
    args.Handle = g.get<UINT>();
    args.pNumSegs = g.get<optional<float>>();
    args.pRectPatchInfo = g.get<optional<D3DRECTPATCH_INFO>>();
    HRESULT res = self->DrawRectPatch(args.Handle,opt2ptr(args.pNumSegs),opt2ptr(args.pRectPatchInfo));
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DDevice9>::DrawTriPatch(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DDevice9 *self = procMap_->getPtr<IDirect3DDevice9>(g.get<ProxyId>());
    struct {
        UINT Handle;
        optional<float> pNumSegs;
        optional<D3DTRIPATCH_INFO> pTriPatchInfo;
    } args;
    (void)args;
    args.Handle = g.get<UINT>();
    args.pNumSegs = g.get<optional<float>>();
    args.pTriPatchInfo = g.get<optional<D3DTRIPATCH_INFO>>();
    HRESULT res = self->DrawTriPatch(args.Handle,opt2ptr(args.pNumSegs),opt2ptr(args.pTriPatchInfo));
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->DeletePatch(args.Handle);
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->CreateQuery(args.Type,&args.ppQuery);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppQuery), dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DStateBlock9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DStateBlock9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
}

void ProcBase<IDirect3DStateBlock9>::Capture(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->Capture();
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DStateBlock9>::Apply(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DStateBlock9 *self = procMap_->getPtr<IDirect3DStateBlock9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->Apply();
    bytes::put<HRESULT>(res, dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DSwapChain9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DSwapChain9>::Present(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        optional<RECT> pSourceRect;
        optional<RECT> pDestRect;
        HWND hDestWindowOverride;
        optional<RGNDATA> pDirtyRegion;
        DWORD dwFlags;
    } args;
    (void)args;
    args.pSourceRect = g.get<optional<RECT>>();
    args.pDestRect = g.get<optional<RECT>>();
    args.hDestWindowOverride = g.get<HWND>();
    args.pDirtyRegion = g.get<optional<RGNDATA>>();
    args.dwFlags = g.get<DWORD>();
    HRESULT res = self->Present(opt2ptr(args.pSourceRect),opt2ptr(args.pDestRect),args.hDestWindowOverride,opt2ptr(args.pDirtyRegion),args.dwFlags);
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->GetFrontBufferData(args.pDestSurface);
    bytes::put<HRESULT>(res, dstBytes);
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
    HRESULT res = self->GetBackBuffer(args.iBackBuffer,args.Type,&args.ppBackBuffer);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppBackBuffer), dstBytes);
}

void ProcBase<IDirect3DSwapChain9>::GetRasterStatus(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        optional<D3DRASTER_STATUS> pRasterStatus;
    } args;
    (void)args;
    HRESULT res = self->GetRasterStatus(opt2ptr(args.pRasterStatus));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DRASTER_STATUS>>(args.pRasterStatus, dstBytes);
}

void ProcBase<IDirect3DSwapChain9>::GetDisplayMode(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        optional<D3DDISPLAYMODE> pMode;
    } args;
    (void)args;
    HRESULT res = self->GetDisplayMode(opt2ptr(args.pMode));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DDISPLAYMODE>>(args.pMode, dstBytes);
}

void ProcBase<IDirect3DSwapChain9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
}

void ProcBase<IDirect3DSwapChain9>::GetPresentParameters(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSwapChain9 *self = procMap_->getPtr<IDirect3DSwapChain9>(g.get<ProxyId>());
    struct {
        optional<D3DPRESENT_PARAMETERS> pPresentationParameters;
    } args;
    (void)args;
    HRESULT res = self->GetPresentParameters(opt2ptr(args.pPresentationParameters));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DPRESENT_PARAMETERS>>(args.pPresentationParameters, dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DVertexDeclaration9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DVertexDeclaration9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
}

void ProcBase<IDirect3DVertexDeclaration9>::GetDeclaration(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexDeclaration9 *self = procMap_->getPtr<IDirect3DVertexDeclaration9>(g.get<ProxyId>());
    struct {
        optional<D3DVERTEXELEMENT9> pElement;
        optional<UINT> pNumElements;
    } args;
    (void)args;
    HRESULT res = self->GetDeclaration(opt2ptr(args.pElement),opt2ptr(args.pNumElements));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DVERTEXELEMENT9>>(args.pElement, dstBytes);
    bytes::put<optional<UINT>>(args.pNumElements, dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DVertexShader9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexShader9 *self = procMap_->getPtr<IDirect3DVertexShader9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DVertexShader9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexShader9 *self = procMap_->getPtr<IDirect3DVertexShader9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DPixelShader9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DPixelShader9 *self = procMap_->getPtr<IDirect3DPixelShader9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DPixelShader9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DPixelShader9 *self = procMap_->getPtr<IDirect3DPixelShader9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DTexture9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DTexture9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
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
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::put<HRESULT>(res, dstBytes);
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
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DTexture9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DTexture9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
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
    D3DRESOURCETYPE res = self->GetType();
    bytes::put<D3DRESOURCETYPE>(res, dstBytes);
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
    DWORD res = self->SetLOD(args.LODNew);
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DTexture9>::GetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLOD();
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DTexture9>::GetLevelCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLevelCount();
    bytes::put<DWORD>(res, dstBytes);
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
    HRESULT res = self->SetAutoGenFilterType(args.FilterType);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DTexture9>::GetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DTEXTUREFILTERTYPE res = self->GetAutoGenFilterType();
    bytes::put<D3DTEXTUREFILTERTYPE>(res, dstBytes);
}

void ProcBase<IDirect3DTexture9>::GenerateMipSubLevels(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->GenerateMipSubLevels();
}

void ProcBase<IDirect3DTexture9>::GetLevelDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        optional<D3DSURFACE_DESC> pDesc;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    HRESULT res = self->GetLevelDesc(args.Level,opt2ptr(args.pDesc));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DSURFACE_DESC>>(args.pDesc, dstBytes);
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
    HRESULT res = self->GetSurfaceLevel(args.Level,&args.ppSurfaceLevel);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppSurfaceLevel), dstBytes);
}

void ProcBase<IDirect3DTexture9>::LockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        optional<D3DLOCKED_RECT> pLockedRect;
        optional<RECT> pRect;
        DWORD Flags;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    args.pRect = g.get<optional<RECT>>();
    args.Flags = g.get<DWORD>();
    HRESULT res = self->LockRect(args.Level,opt2ptr(args.pLockedRect),opt2ptr(args.pRect),args.Flags);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DLOCKED_RECT>>(args.pLockedRect, dstBytes);
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
    HRESULT res = self->UnlockRect(args.Level);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DTexture9>::AddDirtyRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DTexture9 *self = procMap_->getPtr<IDirect3DTexture9>(g.get<ProxyId>());
    struct {
        optional<RECT> pDirtyRect;
    } args;
    (void)args;
    args.pDirtyRect = g.get<optional<RECT>>();
    HRESULT res = self->AddDirtyRect(opt2ptr(args.pDirtyRect));
    bytes::put<HRESULT>(res, dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
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
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::put<HRESULT>(res, dstBytes);
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
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
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
    D3DRESOURCETYPE res = self->GetType();
    bytes::put<D3DRESOURCETYPE>(res, dstBytes);
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
    DWORD res = self->SetLOD(args.LODNew);
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::GetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLOD();
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::GetLevelCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLevelCount();
    bytes::put<DWORD>(res, dstBytes);
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
    HRESULT res = self->SetAutoGenFilterType(args.FilterType);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::GetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DTEXTUREFILTERTYPE res = self->GetAutoGenFilterType();
    bytes::put<D3DTEXTUREFILTERTYPE>(res, dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::GenerateMipSubLevels(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->GenerateMipSubLevels();
}

void ProcBase<IDirect3DVolumeTexture9>::GetLevelDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        optional<D3DVOLUME_DESC> pDesc;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    HRESULT res = self->GetLevelDesc(args.Level,opt2ptr(args.pDesc));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DVOLUME_DESC>>(args.pDesc, dstBytes);
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
    HRESULT res = self->GetVolumeLevel(args.Level,&args.ppVolumeLevel);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppVolumeLevel), dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::LockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        optional<D3DLOCKED_BOX> pLockedVolume;
        optional<D3DBOX> pBox;
        DWORD Flags;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    args.pBox = g.get<optional<D3DBOX>>();
    args.Flags = g.get<DWORD>();
    HRESULT res = self->LockBox(args.Level,opt2ptr(args.pLockedVolume),opt2ptr(args.pBox),args.Flags);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DLOCKED_BOX>>(args.pLockedVolume, dstBytes);
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
    HRESULT res = self->UnlockBox(args.Level);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DVolumeTexture9>::AddDirtyBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolumeTexture9 *self = procMap_->getPtr<IDirect3DVolumeTexture9>(g.get<ProxyId>());
    struct {
        optional<D3DBOX> pDirtyBox;
    } args;
    (void)args;
    args.pDirtyBox = g.get<optional<D3DBOX>>();
    HRESULT res = self->AddDirtyBox(opt2ptr(args.pDirtyBox));
    bytes::put<HRESULT>(res, dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
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
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::put<HRESULT>(res, dstBytes);
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
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
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
    D3DRESOURCETYPE res = self->GetType();
    bytes::put<D3DRESOURCETYPE>(res, dstBytes);
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
    DWORD res = self->SetLOD(args.LODNew);
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::GetLOD(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLOD();
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::GetLevelCount(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetLevelCount();
    bytes::put<DWORD>(res, dstBytes);
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
    HRESULT res = self->SetAutoGenFilterType(args.FilterType);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::GetAutoGenFilterType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DTEXTUREFILTERTYPE res = self->GetAutoGenFilterType();
    bytes::put<D3DTEXTUREFILTERTYPE>(res, dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::GenerateMipSubLevels(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    self->GenerateMipSubLevels();
}

void ProcBase<IDirect3DCubeTexture9>::GetLevelDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        UINT Level;
        optional<D3DSURFACE_DESC> pDesc;
    } args;
    (void)args;
    args.Level = g.get<UINT>();
    HRESULT res = self->GetLevelDesc(args.Level,opt2ptr(args.pDesc));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DSURFACE_DESC>>(args.pDesc, dstBytes);
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
    HRESULT res = self->GetCubeMapSurface(args.FaceType,args.Level,&args.ppCubeMapSurface);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppCubeMapSurface), dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::LockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        D3DCUBEMAP_FACES FaceType;
        UINT Level;
        optional<D3DLOCKED_RECT> pLockedRect;
        optional<RECT> pRect;
        DWORD Flags;
    } args;
    (void)args;
    args.FaceType = g.get<D3DCUBEMAP_FACES>();
    args.Level = g.get<UINT>();
    args.pRect = g.get<optional<RECT>>();
    args.Flags = g.get<DWORD>();
    HRESULT res = self->LockRect(args.FaceType,args.Level,opt2ptr(args.pLockedRect),opt2ptr(args.pRect),args.Flags);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DLOCKED_RECT>>(args.pLockedRect, dstBytes);
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
    HRESULT res = self->UnlockRect(args.FaceType,args.Level);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DCubeTexture9>::AddDirtyRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DCubeTexture9 *self = procMap_->getPtr<IDirect3DCubeTexture9>(g.get<ProxyId>());
    struct {
        D3DCUBEMAP_FACES FaceType;
        optional<RECT> pDirtyRect;
    } args;
    (void)args;
    args.FaceType = g.get<D3DCUBEMAP_FACES>();
    args.pDirtyRect = g.get<optional<RECT>>();
    HRESULT res = self->AddDirtyRect(args.FaceType,opt2ptr(args.pDirtyRect));
    bytes::put<HRESULT>(res, dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DVertexBuffer9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DVertexBuffer9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
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
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::put<HRESULT>(res, dstBytes);
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
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DVertexBuffer9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DVertexBuffer9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
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
    D3DRESOURCETYPE res = self->GetType();
    bytes::put<D3DRESOURCETYPE>(res, dstBytes);
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
    HRESULT res = self->Unlock();
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DVertexBuffer9>::GetDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVertexBuffer9 *self = procMap_->getPtr<IDirect3DVertexBuffer9>(g.get<ProxyId>());
    struct {
        optional<D3DVERTEXBUFFER_DESC> pDesc;
    } args;
    (void)args;
    HRESULT res = self->GetDesc(opt2ptr(args.pDesc));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DVERTEXBUFFER_DESC>>(args.pDesc, dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DIndexBuffer9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DIndexBuffer9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
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
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::put<HRESULT>(res, dstBytes);
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
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DIndexBuffer9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DIndexBuffer9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
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
    D3DRESOURCETYPE res = self->GetType();
    bytes::put<D3DRESOURCETYPE>(res, dstBytes);
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
    HRESULT res = self->Unlock();
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DIndexBuffer9>::GetDesc(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DIndexBuffer9 *self = procMap_->getPtr<IDirect3DIndexBuffer9>(g.get<ProxyId>());
    struct {
        optional<D3DINDEXBUFFER_DESC> pDesc;
    } args;
    (void)args;
    HRESULT res = self->GetDesc(opt2ptr(args.pDesc));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DINDEXBUFFER_DESC>>(args.pDesc, dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DSurface9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DSurface9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
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
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::put<HRESULT>(res, dstBytes);
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
    DWORD res = self->SetPriority(args.PriorityNew);
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DSurface9>::GetPriority(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetPriority();
    bytes::put<DWORD>(res, dstBytes);
}

void ProcBase<IDirect3DSurface9>::PreLoad(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
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
    D3DRESOURCETYPE res = self->GetType();
    bytes::put<D3DRESOURCETYPE>(res, dstBytes);
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
        optional<D3DSURFACE_DESC> pDesc;
    } args;
    (void)args;
    HRESULT res = self->GetDesc(opt2ptr(args.pDesc));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DSURFACE_DESC>>(args.pDesc, dstBytes);
}

void ProcBase<IDirect3DSurface9>::LockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        optional<D3DLOCKED_RECT> pLockedRect;
        optional<RECT> pRect;
        DWORD Flags;
    } args;
    (void)args;
    args.pRect = g.get<optional<RECT>>();
    args.Flags = g.get<DWORD>();
    HRESULT res = self->LockRect(opt2ptr(args.pLockedRect),opt2ptr(args.pRect),args.Flags);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DLOCKED_RECT>>(args.pLockedRect, dstBytes);
}

void ProcBase<IDirect3DSurface9>::UnlockRect(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->UnlockRect();
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DSurface9>::GetDC(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DSurface9 *self = procMap_->getPtr<IDirect3DSurface9>(g.get<ProxyId>());
    struct {
        optional<HDC> phdc;
    } args;
    (void)args;
    HRESULT res = self->GetDC(opt2ptr(args.phdc));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<HDC>>(args.phdc, dstBytes);
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
    HRESULT res = self->ReleaseDC(args.hdc);
    bytes::put<HRESULT>(res, dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DVolume9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DVolume9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
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
    HRESULT res = self->FreePrivateData(args.refguid);
    bytes::put<HRESULT>(res, dstBytes);
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
        optional<D3DVOLUME_DESC> pDesc;
    } args;
    (void)args;
    HRESULT res = self->GetDesc(opt2ptr(args.pDesc));
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DVOLUME_DESC>>(args.pDesc, dstBytes);
}

void ProcBase<IDirect3DVolume9>::LockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        optional<D3DLOCKED_BOX> pLockedVolume;
        optional<D3DBOX> pBox;
        DWORD Flags;
    } args;
    (void)args;
    args.pBox = g.get<optional<D3DBOX>>();
    args.Flags = g.get<DWORD>();
    HRESULT res = self->LockBox(opt2ptr(args.pLockedVolume),opt2ptr(args.pBox),args.Flags);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<optional<D3DLOCKED_BOX>>(args.pLockedVolume, dstBytes);
}

void ProcBase<IDirect3DVolume9>::UnlockBox(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DVolume9 *self = procMap_->getPtr<IDirect3DVolume9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    HRESULT res = self->UnlockBox();
    bytes::put<HRESULT>(res, dstBytes);
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
    ULONG res = self->AddRef();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DQuery9>::Release(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    ULONG res = self->Release();
    bytes::put<ULONG>(res, dstBytes);
}

void ProcBase<IDirect3DQuery9>::GetDevice(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(g.get<ProxyId>());
    struct {
        IDirect3DDevice9* ppDevice;
    } args;
    (void)args;
    HRESULT res = self->GetDevice(&args.ppDevice);
    bytes::put<HRESULT>(res, dstBytes);bytes::put<ProxyId>(procMap_->getProxyID(args.ppDevice), dstBytes);
}

void ProcBase<IDirect3DQuery9>::GetType(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    D3DQUERYTYPE res = self->GetType();
    bytes::put<D3DQUERYTYPE>(res, dstBytes);
}

void ProcBase<IDirect3DQuery9>::GetDataSize(BytesPtr srcBytes, BytesPtr dstBytes)
{
    bytes::getter g(srcBytes);
    IDirect3DQuery9 *self = procMap_->getPtr<IDirect3DQuery9>(g.get<ProxyId>());
    struct {
        ;
    } args;
    (void)args;
    DWORD res = self->GetDataSize();
    bytes::put<DWORD>(res, dstBytes);
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
    HRESULT res = self->Issue(args.dwIssueFlags);
    bytes::put<HRESULT>(res, dstBytes);
}

void ProcBase<IDirect3DQuery9>::GetData(BytesPtr srcBytes, BytesPtr dstBytes)
{
    throw std::runtime_error("Method has unsupported arg: void*");
}

} // namespace D3D9

} // namespace Server

