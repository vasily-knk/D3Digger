#pragma once

#include "IProxy.h"

struct IGlobal
    : Interface
{
    typedef unordered_map<IUnknown *, shared_ptr<IProxy<IUnknown>>> ProxyMapping;

    virtual ProxyMapping &proxyMapping() = 0;
    virtual ostream &log() = 0;
};

IGlobal &getGlobal();

#define LOG(str) getGlobal().log() << str << std::endl << std::flush;
