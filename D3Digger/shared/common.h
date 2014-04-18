#pragma once

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <d3d9.h>

#include <memory>
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::enable_shared_from_this;
using std::dynamic_pointer_cast;

#include <simex/common/event.h>
using boost::signals2::scoped_connection;

#include <functional>
using std::bind;
using std::function;

#include <unordered_set>
using std::unordered_set;

#include <set>
using std::set;

#include <cassert>
