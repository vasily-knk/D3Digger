#include "ProcImpl.h"

namespace D3D9
{

namespace Server
{

template<>
struct ProcImpl<IDirect3DQuery9>
    : ProcBase<IDirect3DQuery9>
{
    typedef ProcBase<IDirect3DQuery9> Base;
	
    ProcImpl(CreateProcArgs const &args); 
    void GetData(BytesPtr srcBytes, BytesPtr dstBytes);
};

} // namespace Server

} // namespace D3D9