#include "stdafx.h"
#include "ProcBase.h"
#include "d3d9/InterfacesList.h"


namespace D3D9
{
namespace Server
{

#define FOR_X D3D9_LIST_FINAL_INTERFACES

#define CREATE_PROC_DEFINITION(name) \
    template<> \
    shared_ptr<IProc<name>> createProc(CreateProcArgs const &args) \
    { \
        return make_shared<ProcBase<name>>(args); \
    }

FOR_X(CREATE_PROC_DEFINITION)

#undef CREATE_PROC_DEFINITION
#undef FOR_X


} // namespace Client

} // namespace D3D9