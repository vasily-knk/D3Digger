#pragma once

#include "ProxyBase.h"

template<typename T>
struct ProxyImpl
{
    typedef typename ProxyBase<T> Type;
};