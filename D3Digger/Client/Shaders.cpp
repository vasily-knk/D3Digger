#include "stdafx.h"
#include "Shaders.h"

namespace D3D9
{
namespace Client
{

size_t getShaderSize(DWORD const *bytecode)
{
    DWORD end_token = 0x0000FFFF;
    size_t size = 0;
    for (DWORD const *p = bytecode; *p != end_token; ++size, ++p) {}

    return size + 1;
}

} // namespace Client

} // namespace D3D9
