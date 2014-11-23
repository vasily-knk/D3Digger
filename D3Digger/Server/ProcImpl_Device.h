#include "ProcImpl.h"

namespace D3D9
{

namespace Server
{

template<>
struct ProcImpl<IDirect3DDevice9>
    : ProcBase<IDirect3DDevice9>
{
    typedef ProcBase<IDirect3DDevice9> Base;
	
    ProcImpl(CreateProcArgs const &args); 

    void Clear(BytesPtr srcBytes, BytesPtr dstBytes) override;

    void CreateTexture              (BytesPtr srcBytes, BytesPtr dstBytes) override;
    void CreateVolumeTexture        (BytesPtr srcBytes, BytesPtr dstBytes) override;
    void CreateCubeTexture          (BytesPtr srcBytes, BytesPtr dstBytes) override;
    void CreateVertexBuffer         (BytesPtr srcBytes, BytesPtr dstBytes) override;
    void CreateIndexBuffer          (BytesPtr srcBytes, BytesPtr dstBytes) override;
    void CreateRenderTarget         (BytesPtr srcBytes, BytesPtr dstBytes) override;
    void CreateDepthStencilSurface  (BytesPtr srcBytes, BytesPtr dstBytes) override;
    void CreateOffscreenPlainSurface(BytesPtr srcBytes, BytesPtr dstBytes) override;
};

} // namespace Server

} // namespace D3D9