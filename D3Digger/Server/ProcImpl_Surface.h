#include "ProcImpl.h"

namespace D3D9
{

namespace Server
{

template<>
struct ProcImpl<IDirect3DSurface9>
    : ProcBase<IDirect3DSurface9>
{
    typedef ProcBase<IDirect3DSurface9> Base;
	
    ProcImpl(CreateProcArgs const &args); 

    void LockRect(BytesPtr srcBytes, BytesPtr dstBytes) override;
    void UnlockRect(BytesPtr srcBytes, BytesPtr dstBytes) override;
};


} // namespace Server

} // namespace D3D9