#include "stdafx.h"
#include "checkProcResult.h"

namespace D3D9
{
namespace Server
{

void checkProcResult(HRESULT res)
{
    if (FAILED(res))
    {
        int aaa = 5;
    }
}


} // namespace Server

} // namespace D3D9