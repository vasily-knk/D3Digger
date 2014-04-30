#pragma once

#include "IProxy.h"

struct IGlobal
    : Interface
{
    typedef unordered_map<IUnknown *, IProxyPtr<IUnknown>::Type> ProxyMapping;

    virtual ProxyMapping &proxyMapping() = 0;
    virtual ostream &log() = 0;
};

IGlobal &getGlobal();

#define LOG(str) getGlobal().log() << str << std::endl << std::flush;
