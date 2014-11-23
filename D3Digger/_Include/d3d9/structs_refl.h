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

template<typename T>
void process(bytes::read_proc &proc, vector<T> const &vec)
{
    vector<T> &dst = const_cast<vector<T>&>(vec);

    uint32_t size;
    proc(size);
    dst.resize(size);
    proc.array(dst.data(), size);
}

template<typename T>
void process(bytes::write_proc &proc, vector<T> const &vec)
{
    uint32_t size = vec.size();
    proc(size);
    proc.array(vec.data(), size);
}



/*
template<typename Proc>
void process(Proc &proc, void*)
{
    throw std::runtime_error("void* is not serializable");
}
*/



/*
inline void process(bytes::write_proc &proc, optional<HANDLE> const &val)
{
    process<HANDLE>(proc, val);
    assert(!val);
}

inline void process(bytes::read_proc &proc, optional<HANDLE> const &val)
{
    process<HANDLE>(proc, val);
    assert(!val);
}*/


template<typename Proc>
void process(Proc &proc, HWND const &h)
{
    // TODO: remove me!
    proc.array(reinterpret_cast<char const*>(&h), sizeof(h));
}

template<typename Proc>
void process(Proc &proc, HMONITOR const &h)
{
    // TODO: remove me!
    proc.array(reinterpret_cast<char const*>(&h), sizeof(h));
}

template<typename Proc>
void process(Proc &proc, HDC const &h)
{
    // TODO: remove me!
    proc.array(reinterpret_cast<char const*>(&h), sizeof(h));
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
    proc(r.Driver);
    proc(r.Description);
    proc(r.DeviceName);
    
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
    proc(r.Format);
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
void process(Proc &proc, LARGE_INTEGER const &r)
{
    proc.array(reinterpret_cast<const char*>(&r), sizeof(r));
}

template<typename Proc>
void process(Proc &proc, GUID const &r)
{
    proc(r.Data1);
    proc(r.Data2);
    proc(r.Data3);
    proc(r.Data4);
}

template<typename Proc>
void process(Proc &proc, POINT const &r)
{
    proc(r.x);
    proc(r.y);
}

template<typename Proc>
void process(Proc &proc, D3DVSHADERCAPS2_0 const &r)
{
    proc(r.Caps);
    proc(r.DynamicFlowControlDepth);
    proc(r.NumTemps);
    proc(r.StaticFlowControlDepth);
}

template<typename Proc>
void process(Proc &proc, D3DPSHADERCAPS2_0 const &r)
{
    proc(r.Caps);
    proc(r.DynamicFlowControlDepth);
    proc(r.NumTemps);
    proc(r.StaticFlowControlDepth);
    proc(r.NumInstructionSlots);
}

template<typename Proc>
void process(Proc &proc, D3DOVERLAYCAPS const &r)
{
    proc(r.Caps);
    proc(r.MaxOverlayDisplayWidth);
    proc(r.MaxOverlayDisplayHeight);
}

template<typename Proc>
void process(Proc &proc, D3DCONTENTPROTECTIONCAPS const &r)
{
    proc(r.Caps);
    proc(r.KeyExchangeType);
    proc(r.BufferAlignmentStart);
    proc(r.BlockAlignmentSize);
    proc(r.ProtectedMemorySize);
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
    proc(r.MaxTextureWidth);
    proc(r.MaxTextureHeight);
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
    proc(r.red  );
    proc(r.green);
    proc(r.blue );
} 

template<typename Proc>
void process(Proc &proc, D3DMATRIX const &r)
{
    proc.array(reinterpret_cast<char const*>(&r), sizeof(r));
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

template<typename Proc>
void process(Proc &proc, D3DVECTOR const &r) {
    proc(r.x);
    proc(r.y);
    proc(r.z);
} 

template<typename Proc>
void process(Proc &proc, D3DCOLORVALUE const &r) {
    proc(r.r);
    proc(r.g);
    proc(r.b);
    proc(r.a);
} 

template<typename Proc>
void process(Proc &proc, D3DCLIPSTATUS9 const &r) {
    proc(r.ClipUnion);
    proc(r.ClipIntersection);
} 

template<typename Proc>
void process(Proc &proc, D3DMATERIAL9 const &r) {
    proc(r.Diffuse);        /* Diffuse color RGBA */
    proc(r.Ambient);        /* Ambient color RGB */
    proc(r.Specular);       /* Specular 'shininess' */
    proc(r.Emissive);       /* Emissive color RGB */
    proc(r.Power);          /* Sharpness if specular highlight */
} 

template<typename Proc>
void process(Proc &proc, D3DVERTEXELEMENT9 const &r)
{
    proc(r.Stream);     // Stream index
    proc(r.Offset);     // Offset in the stream in bytes
    proc(r.Type);       // Data type
    proc(r.Method);     // Processing method
    proc(r.Usage);      // Semantics
    proc(r.UsageIndex); // Semantic index
} 

template<typename Proc>
void process(Proc &proc, D3DVERTEXBUFFER_DESC const &r)
{
    proc(r.Format);
    proc(r.Type);
    proc(r.Usage);
    proc(r.Pool);
    proc(r.Size);
    proc(r.FVF);
} 

template<typename Proc>
void process(Proc &proc, D3DINDEXBUFFER_DESC const &r)
{
    proc(r.Format);
    proc(r.Type);
    proc(r.Usage);
    proc(r.Pool);
    proc(r.Size);
} 


/* Surface Description */
template<typename Proc>
void process(Proc &proc, D3DSURFACE_DESC const &r)
{
    proc(r.Format);
    proc(r.Type);
    proc(r.Usage);
    proc(r.Pool);
    proc(r.MultiSampleType);
    proc(r.MultiSampleQuality);
    proc(r.Width);
    proc(r.Height);
} 

template<typename Proc>
void process(Proc &proc, D3DVOLUME_DESC const &r)
{
    proc(r.Format);
    proc(r.Type);
    proc(r.Usage);
    proc(r.Pool);
    proc(r.Width);
    proc(r.Height);
    proc(r.Depth);
} 

/* Structure for LockRect */

template<typename Proc>
void process(Proc &proc, D3DLOCKED_RECT const &r)
{
    throw std::runtime_error("D3DLOCKED_RECT is not supposed to be serialized");
/*
    proc(r.Pitch);
    proc(r.pBits);
*/
} 


/* Structures for LockBox */
template<typename Proc>
void process(Proc &proc, D3DBOX const &r)
{
    proc(r.Left);
    proc(r.Top);
    proc(r.Right);
    proc(r.Bottom);
    proc(r.Front);
    proc(r.Back);
} 


template<typename Proc>
void process(Proc &proc, D3DLOCKED_BOX const &r)
{
    throw std::runtime_error("D3DLOCKED_RECT is not supposed to be serialized");
/*
    proc(r.RowPitch);
    proc(r.SlicePitch);
    proc(r.pBits);
*/
} 


/* Structures for LockRange */
template<typename Proc>
void process(Proc &proc, D3DRANGE const &r)
{
    proc(r.Offset);
    proc(r.Size);
} 

/* Structures for high order primitives */
template<typename Proc>
void process(Proc &proc, D3DRECTPATCH_INFO const &r)
{
    proc(r.StartVertexOffsetWidth);
    proc(r.StartVertexOffsetHeight);
    proc(r.Width);
    proc(r.Height);
    proc(r.Stride);
    proc(r.Basis);
    proc(r.Degree);
} 

template<typename Proc>
void process(Proc &proc, D3DTRIPATCH_INFO const &r)
{
    proc(r.StartVertexOffset);
    proc(r.NumVertices);
    proc(r.Basis);
    proc(r.Degree);
} 

template<typename Proc>
void process(Proc &proc, D3DRESOURCESTATS const &r)
{
    proc(r.bThrashing);             /* indicates if thrashing */
    proc(r.ApproxBytesDownloaded);  /* Approximate number of bytes downloaded by resource manager */
    proc(r.NumEvicts);              /* number of objects evicted */
    proc(r.NumVidCreates);          /* number of objects created in video memory */
    proc(r.LastPri);                /* priority of last object evicted */
    proc(r.NumUsed);                /* number of objects set to the device */
    proc(r.NumUsedInVidMem);        /* number of objects set to the device, which are already in video memory */
    proc(r.WorkingSet);             /* number of objects in video memory */
    proc(r.WorkingSetBytes);        /* number of bytes in video memory */
    proc(r.TotalManaged);           /* total number of managed objects */
    proc(r.TotalBytes);             /* total number of bytes of managed objects */
} 

template<typename Proc>
void process(Proc &proc, D3DDEVINFO_RESOURCEMANAGER const &r)
{
#ifndef WOW64_ENUM_WORKAROUND
    proc.array(r.stats, D3DRTYPECOUNT);
#else
    proc.array(r.stats, 8);
#endif
} 

template<typename Proc>
void process(Proc &proc, D3DDEVINFO_D3DVERTEXSTATS const &r)
{
    proc(r.NumRenderedTriangles);       /* total number of triangles that are not clipped in this frame */
    proc(r.NumExtraClippingTriangles);  /* Number of new triangles generated by clipping */
} 


template<typename Proc>
void process(Proc &proc, D3DDEVINFO_VCACHE const &r) {
    proc(r.Pattern);                    /* bit pattern, return value must be FOUR_CC('C', 'A', 'C', 'H') */
    proc(r.OptMethod);                  /* optimization method 0 means longest strips, 1 means vertex cache based */
    proc(r.CacheSize);                  /* cache size to optimize for  (only required if type is 1) */
    proc(r.MagicNumber);                /* used to determine when to restart strips (only required if type is 1)*/
} 

template<typename Proc>
void process(Proc &proc, D3DDEVINFO_D3D9PIPELINETIMINGS const &r)
{
    proc(r.VertexProcessingTimePercent);
    proc(r.PixelProcessingTimePercent);
    proc(r.OtherGPUProcessingTimePercent);
    proc(r.GPUIdleTimePercent);
} 

template<typename Proc>
void process(Proc &proc, D3DDEVINFO_D3D9INTERFACETIMINGS const &r)
{
    proc(r.WaitingForGPUToUseApplicationResourceTimePercent);
    proc(r.WaitingForGPUToAcceptMoreCommandsTimePercent);
    proc(r.WaitingForGPUToStayWithinLatencyTimePercent);
    proc(r.WaitingForGPUExclusiveResourceTimePercent);
    proc(r.WaitingForGPUOtherTimePercent);
} 

template<typename Proc>
void process(Proc &proc, D3DDEVINFO_D3D9STAGETIMINGS const &r)
{
    proc(r.MemoryProcessingPercent);
    proc(r.ComputationProcessingPercent);
} 

template<typename Proc>
void process(Proc &proc, D3DDEVINFO_D3D9BANDWIDTHTIMINGS const &r)
{
    proc(r.MaxBandwidthUtilized);
    proc(r.FrontEndUploadMemoryUtilizedPercent);
    proc(r.VertexRateUtilizedPercent);
    proc(r.TriangleSetupRateUtilizedPercent);
    proc(r.FillRateUtilizedPercent);
} 

template<typename Proc>
void process(Proc &proc, D3DDEVINFO_D3D9CACHEUTILIZATION const &r)
{
    proc(r.TextureCacheHitRate); // Percentage of cache hits
    proc(r.PostTransformVertexCacheHitRate);
} 

template<typename Proc>
void process(Proc &proc, D3DLIGHT9 const &r)
{
    proc(r.Type);            /* Type of light source */
    proc(r.Diffuse);         /* Diffuse color of light */
    proc(r.Specular);        /* Specular color of light */
    proc(r.Ambient);         /* Ambient color of light */
    proc(r.Position);         /* Position in world space */
    proc(r.Direction);        /* Direction in world space */
    proc(r.Range);            /* Cutoff range */
    proc(r.Falloff);          /* Falloff */
    proc(r.Attenuation0);     /* Constant attenuation */
    proc(r.Attenuation1);     /* Linear attenuation */
    proc(r.Attenuation2);     /* Quadratic attenuation */
    proc(r.Theta);            /* Inner angle of spotlight cone */
    proc(r.Phi);              /* Outer angle of spotlight cone */
}

template<typename Proc>
void process(Proc &proc, PALETTEENTRY const &r)
{
    proc(r.peRed);
    proc(r.peGreen);
    proc(r.peBlue);
    proc(r.peFlags);
}

