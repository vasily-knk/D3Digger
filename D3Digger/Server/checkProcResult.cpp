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
    }
}


} // namespace Server

} // namespace D3D9