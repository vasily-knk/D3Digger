#pragma once

#include "IProxy.h"

struct Global
{
    Global()
        : log("d3d9_log.txt")
        , numTextures(0)
    {

    }
    unordered_map<IUnknown *, shared_ptr<IProxy<IUnknown>>> mapping;
    ofstream log;
    size_t numTextures;
};

Global &getGlobal();

#define LOG(str) getGlobal().log << str << std::endl << std::flush;