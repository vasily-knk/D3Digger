#include "stdafx.h"
#include "ProxyBase.h"
#include "GlobalImpl.h"

IGlobal &getGlobal()
{
    static GlobalImpl global;
    return global;
}

void logMethod(const char *interfaceName, const char *methodName)
{
    (void)interfaceName;
    (void)methodName;
    //LOG(interfaceName << "." << methodName);
}

void LogQI(REFIID)
{
}

