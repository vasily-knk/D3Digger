#pragma once

namespace D3D9
{
namespace Server
{

template<typename T>
void checkProcResult(T const &, char const *)
{
}

void checkProcResult(HRESULT res, char const *fn_name);

#define CHECK_PROC_RESULT(x) checkProcResult(x, __FUNCTION__)

    
} // namespace Server

} // namespace D3D9