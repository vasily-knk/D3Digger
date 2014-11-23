#include "stdafx.h"
#include "ProcBase.h"
#include "d3d9/InterfacesList.h"

#include "ProcImpl_Device.h"
#include "ProcImpl_VB.h"
#include "ProcImpl_IB.h"
#include "ProcImpl_Surface.h"
#include "ProcImpl_Query.h"


namespace D3D9
{
namespace Server
{

#define FOR_X(X) \
    X(IDirect3D9                 ) \
    X(IDirect3DSwapChain9        ) \
    X(IDirect3DVolumeTexture9    ) \
    X(IDirect3DCubeTexture9      ) \
    X(IDirect3DStateBlock9       ) \
    X(IDirect3DVertexDeclaration9) \
    X(IDirect3DVertexShader9     ) \
    X(IDirect3DPixelShader9      ) \
    X(IDirect3DVolume9           ) \
    X(IDirect3DTexture9          ) 

#define CREATE_PROC_DEFINITION(name) \
    template<> \
    shared_ptr<IProc<name>> createProc(CreateProcArgs const &args) \
    { \
        return make_shared<ProcBase<name>>(args); \
    }

FOR_X(CREATE_PROC_DEFINITION)

#undef CREATE_PROC_DEFINITION
#undef FOR_X

#define FOR_X(X) \
    X(IDirect3DDevice9           ) \
    X(IDirect3DVertexBuffer9     ) \
    X(IDirect3DIndexBuffer9      ) \
    X(IDirect3DQuery9            ) \
    X(IDirect3DSurface9          ) 

#define CREATE_PROC_DEFINITION(name) \
    template<> \
    shared_ptr<IProc<name>> createProc(CreateProcArgs const &args) \
    { \
        return make_shared<ProcImpl<name>>(args); \
    }

FOR_X(CREATE_PROC_DEFINITION)

#undef CREATE_PROC_DEFINITION
#undef FOR_X



} // namespace Client

} // namespace D3D9