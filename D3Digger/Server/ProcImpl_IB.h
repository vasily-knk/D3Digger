#include "ProcImpl.h"

namespace D3D9
{

namespace Server
{

template<>
struct ProcImpl<IDirect3DIndexBuffer9>
    : ProcBase<IDirect3DIndexBuffer9>
{
    typedef ProcBase<IDirect3DIndexBuffer9> Base;
	
    ProcImpl(CreateProcArgs const &args); 

    void Lock(BytesPtr srcBytes, BytesPtr dstBytes) override;
    void Unlock(BytesPtr srcBytes, BytesPtr dstBytes) override;
};


} // namespace Server

} // namespace D3D9