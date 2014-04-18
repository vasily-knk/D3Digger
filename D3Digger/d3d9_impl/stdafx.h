// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <d3d9.h>

#include <memory>
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::enable_shared_from_this;
using std::dynamic_pointer_cast;

#include <unordered_set>
using std::unordered_set;

#include <set>
using std::set;

#include <cassert>
