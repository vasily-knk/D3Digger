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
    void CreateVertexDeclaration(BytesPtr srcBytes, BytesPtr dstBytes) override;
};

} // namespace Server

} // namespace D3D9