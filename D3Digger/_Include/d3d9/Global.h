#pragma once

#include "IProxy.h"

struct Global
{
    unordered_map<IUnknown *, shared_ptr<IProxy<IUnknown>>> mapping;
};

Global &getGlobal();
