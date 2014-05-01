#pragma once

#include "ProxyBase.h"

struct ProxyImplDevice;
typedef intrusive_ptr<ProxyImplDevice> ProxyImplDevicePtr;
struct ProxyImplIndexBuffer;
struct ProxyImplVertexBuffer;
struct ProxyImplTexture;


template<typename T>
struct ProxyImplHelper;