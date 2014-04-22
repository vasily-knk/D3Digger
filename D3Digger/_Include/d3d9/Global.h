#pragma once

#include "IProxy.h"

struct Global
{
    Global()
        : log("d3d9_log.txt")
    {

    }
    unordered_map<IUnknown *, shared_ptr<IProxy<IUnknown>>> mapping;
    ofstream log;
};

Global &getGlobal();

#define LOG(str) getGlobal().log << str << std::endl << std::flush;