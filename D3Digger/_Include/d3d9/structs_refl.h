#pragma once

#include "common/bytes.h"

template<typename T>
void process(bytes::read_proc &proc, optional<T> const &opt)
{
    optional<T> &dst = const_cast<optional<T> &>(opt);
    
    uint8_t init = proc.operator()<uint8_t>();
    if (init == 0)
        dst = boost::none;
    else
    {
        T temp;
        proc(temp);
        dst = temp;
    }
}

template<typename T>
void process(bytes::write_proc &proc, optional<T> const &opt)
{
    if (!opt)
        proc(uint8_t(0));
    else
    {
        proc(uint8_t(1));
        proc(*opt);
    }
}

template<typename Proc>
void process(Proc &proc, D3DRECT const &rect)
{
    proc(rect.x1);
    proc(rect.y1);
    proc(rect.x2);
    proc(rect.y2);
}

template<typename Proc>
void process(Proc &proc, RECT const &rect)
{
    proc(rect.left);
    proc(rect.top);
    proc(rect.right);
    proc(rect.bottom);
}

template<typename Proc>
void process(Proc &proc, D3DADAPTER_IDENTIFIER9 const &r)
{
    proc.array(r.Driver, MAX_DEVICE_IDENTIFIER_STRING);
    proc.array(r.Description, MAX_DEVICE_IDENTIFIER_STRING);
    proc.array(r.DeviceName, 32);
    
    proc(r.DriverVersion);

    proc(r.VendorId);
    proc(r.DeviceId);
    proc(r.SubSysId);                    
    proc(r.Revision);
    proc(r.DeviceIdentifier);
    proc(r.WHQLLevel);
}

template<typename Proc>
void process(Proc &proc, D3DDISPLAYMODE const &r)
{
    proc(r.Width);
    proc(r.Height);
    proc(r.RefreshRate);
    proc(r.BehaviorFlags);
}

template<typename Proc>
void process(Proc &proc, RGNDATA const &r)
{
    proc(r.rdh.dwSize);
    proc(r.rdh.iType);
    proc(r.rdh.nCount);
    proc(r.rdh.nRgnSize);
    proc(r.rdh.rcBound);

    // TODO: process buffer!
}

template<typename Proc>
void process(Proc &proc, HWND)
{
    // TODO: remove me!
}

template<typename Proc>
void process(Proc &proc, HMONITOR hwnd)
{
    // TODO: remove me!
}

template<typename Proc>
void process(Proc &proc, HDC hwnd)
{
    // TODO: remove me!
}

template<typename Proc>
void process(Proc &proc, HANDLE hwnd)
{
    // TODO: remove me!
}

template<typename Proc>
void process(Proc &proc, GUID const &r)
{
    proc(r.Data1);
    proc(r.Data2);
    proc(r.Data3);
    proc.array(r.Data4, 8);
}

template<typename Proc>
void process(Proc &proc, D3DCAPS9 const &r)
{
    proc(r.DeviceType);
    proc(r.AdapterOrdinal);
    proc(r.Caps);
    proc(r.Caps2);
    proc(r.Caps3);
    proc(r.PresentationIntervals);
    proc(r.CursorCaps);
    proc(r.DevCaps);
    proc(r.PrimitiveMiscCaps);
    proc(r.RasterCaps);
    proc(r.ZCmpCaps);
    proc(r.SrcBlendCaps);
    proc(r.DestBlendCaps);
    proc(r.AlphaCmpCaps);
    proc(r.ShadeCaps);
    proc(r.TextureCaps);
    proc(r.TextureFilterCaps);          // D3DPTFILTERCAPS for IDirect3DTexture9's
    proc(r.CubeTextureFilterCaps);      // D3DPTFILTERCAPS for IDirect3DCubeTexture9's
    proc(r.VolumeTextureFilterCaps);    // D3DPTFILTERCAPS for IDirect3DVolumeTexture9's
    proc(r.TextureAddressCaps);         // D3DPTADDRESSCAPS for IDirect3DTexture9's
    proc(r.VolumeTextureAddressCaps);   // D3DPTADDRESSCAPS for IDirect3DVolumeTexture9's
    proc(r.LineCaps);                   // D3DLINECAPS
    proc(r.MaxTextureWidth, MaxTextureHeight);
    proc(r.MaxVolumeExtent);
    proc(r.MaxTextureRepeat);
    proc(r.MaxTextureAspectRatio);
    proc(r.MaxAnisotropy);
    proc(r.MaxVertexW);
    proc(r.GuardBandLeft);
    proc(r.GuardBandTop);
    proc(r.GuardBandRight);
    proc(r.GuardBandBottom);
    proc(r.ExtentsAdjust);
    proc(r.StencilCaps);
    proc(r.FVFCaps);
    proc(r.TextureOpCaps);
    proc(r.MaxTextureBlendStages);
    proc(r.MaxSimultaneousTextures);
    proc(r.VertexProcessingCaps);
    proc(r.MaxActiveLights);
    proc(r.MaxUserClipPlanes);
    proc(r.MaxVertexBlendMatrices);
    proc(r.MaxVertexBlendMatrixIndex);
    proc(r.MaxPointSize);
    proc(r.MaxPrimitiveCount);          // max number of primitives per DrawPrimitive call
    proc(r.MaxVertexIndex);
    proc(r.MaxStreams);
    proc(r.MaxStreamStride);            // max stride for SetStreamSource
    proc(r.VertexShaderVersion);
    proc(r.MaxVertexShaderConst);       // number of vertex shader constant registers
    proc(r.PixelShaderVersion);
    proc(r.PixelShader1xMaxValue);      // max value storable in registers of ps.1.x shaders
    proc(r.DevCaps2);
    proc(r.MaxNpatchTessellationLevel);
    proc(r.Reserved5);
    proc(r.MasterAdapterOrdinal);       // ordinal of master adaptor for adapter group
    proc(r.AdapterOrdinalInGroup);      // ordinal inside the adapter group
    proc(r.NumberOfAdaptersInGroup);    // number of adapters in this adapter group (only if master)
    proc(r.DeclTypes);                  // Data types, supported in vertex declarations
    proc(r.NumSimultaneousRTs);         // Will be at least 1
    proc(r.StretchRectFilterCaps);      // Filter caps supported by StretchRect
    proc(r.VS20Caps);
    proc(r.PS20Caps);
    proc(r.VertexTextureFilterCaps);    // D3DPTFILTERCAPS for IDirect3DTexture9's for texture, used in vertex shaders
    proc(r.MaxVShaderInstructionsExecuted); // maximum number of vertex shader instructions that can be executed
    proc(r.MaxPShaderInstructionsExecuted); // maximum number of pixel shader instructions that can be executed
    proc(r.MaxVertexShader30InstructionSlots); 
    proc(r.MaxPixelShader30InstructionSlots);
}

template<typename Proc>
void process(Proc &proc, D3DPRESENT_PARAMETERS const &r)
{
    proc(r.BackBufferWidth);
    proc(r.BackBufferHeight);
    proc(r.BackBufferFormat);
    proc(r.BackBufferCount);
    proc(r.MultiSampleType);
    proc(r.MultiSampleQuality);
    proc(r.SwapEffect);
    proc(r.hDeviceWindow);
    proc(r.Windowed);
    proc(r.EnableAutoDepthStencil);
    proc(r.AutoDepthStencilFormat);
    proc(r.Flags);
    proc(r.FullScreen_RefreshRateInHz);
    proc(r.PresentationInterval);
}

template<typename Proc>
void process(Proc &proc, D3DDEVICE_CREATION_PARAMETERS const &r)
{
    proc(r.AdapterOrdinal);
    proc(r.DeviceType);
    proc(r.hFocusWindow);
    proc(r.BehaviorFlags);
}

template<typename Proc>
void process(Proc &proc, D3DRASTER_STATUS const &r)
{
    proc(r.InVBlank);
    proc(r.ScanLine);
}

template<typename Proc>
void process(Proc &proc, D3DGAMMARAMP const &r)
{
    proc.array(red  , 256);
    proc.array(green, 256);
    proc.array(blue , 256);
} 

template<typename Proc>
void process(Proc &proc, D3DMATRIX const &r)
{
    // TODO: Implement
}

template<typename Proc>
void process(Proc &proc, D3DVIEWPORT9 const &r)
{
    proc(r.X);
    proc(r.Y);            /* Viewport Top left */
    proc(r.Width);
    proc(r.Height);       /* Viewport Dimensions */
    proc(r.MinZ);         /* Min/max of clip Volume */
    proc(r.MaxZ);
};
