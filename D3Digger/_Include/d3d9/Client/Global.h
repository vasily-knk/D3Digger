#pragma once

#include "IProxy.h"

namespace D3D9
{
namespace Client
{

struct IGlobal
    : Interface
{
    typedef unordered_map<IUnknown *, IProxyPtr<IUnknown>::Type> ProxyMapping;

    virtual ProxyMapping &proxyMapping() = 0;
    virtual ostream &log() = 0;
};

IGlobal &getGlobal();

} // namespace Client

} // namespace D3D9

#define LOG(str) getGlobal().log() << str << std::endl << std::flush;
