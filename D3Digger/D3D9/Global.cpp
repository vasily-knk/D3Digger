#include "stdafx.h"
#include "d3d9/Global.h"

Global &getGlobal()
{
    static Global global;
    return global;
}