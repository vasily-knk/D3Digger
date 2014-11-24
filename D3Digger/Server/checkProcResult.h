#pragma once

namespace D3D9
{
namespace Server
{

template<typename T>
void checkProcResult(T const &)
{
}

void checkProcResult(HRESULT res);

    
} // namespace Server

} // namespace D3D9