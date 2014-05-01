#pragma once

#include "d3d9/Global.h"

struct GlobalImpl
    : IGlobal
{
    GlobalImpl()
        : log_("d3d9_log.txt")
    {

    }

    ~GlobalImpl()
    {
        assert(proxyMapping_.empty());
    }

    ProxyMapping &proxyMapping() override
    {
        return proxyMapping_;
    }

    ostream &log() override 
    {
        return log_;
    }

private:
    ProxyMapping proxyMapping_;
    ofstream log_;
};