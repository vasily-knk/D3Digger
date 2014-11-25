#include "stdafx.h"
#include "checkProcResult.h"

namespace D3D9
{
namespace Server
{

void checkProcResult(HRESULT res, char const *fn_name)
{
    //LogDebug("call: " << fn_name);
    if (FAILED(res))
    {
        char const *error = DXGetErrorStringA(res);
        LogWarn(fn_name << " failed: " << error);
        if (string("D3D9::Server::ProcBase<struct IDirect3D9>::CreateDevice") == string(fn_name))
        {
            int aaa = 5;
        }
    }
}


} // namespace Server

} // namespace D3D9