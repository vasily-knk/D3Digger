#include "stdafx.h"
#include "d3d9/Global.h"
#include "ProxyBase.h"

Global &getGlobal()
{
    static Global global;
    return global;
}

void logMethod(const char *interfaceName, const char *methodName)
{
    (void)interfaceName;
    (void)methodName;
}

void LogQI(REFIID)
{
}

/*
template<>
HRESULT checkReturn(HRESULT const &val, const char *interfaceName, const char *methodName)
{
    if (!SUCCEEDED(val))
    {
        LOG("Error: " << interfaceName << "." << methodName);
    }
    return val;
}
*/
