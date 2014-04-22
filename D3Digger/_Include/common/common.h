#pragma once

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN       

#include <d3d9.h>
#include <D3dx9tex.h>
#include <atlbase.h>

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
#include <unordered_map>
using std::unordered_map;

#include <set>
using std::set;

#include <cassert>

#include <vector>
using std::vector;

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::endl;

#include <utility>
using std::pair;
using std::make_pair;

#include <string>
using std::string;
#include <sstream>
using std::stringstream;

#include <iomanip>

#include "interface.h"

