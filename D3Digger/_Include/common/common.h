#pragma once

#define STRICT
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <SDKDDKVer.h>

#include <d3d9.h>
#include <dxerr.h>
#include <D3dx9tex.h>
#include <atlbase.h>

#include <memory>
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::enable_shared_from_this;
using std::dynamic_pointer_cast;

#include <cstdint>

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
using std::istream;
using std::ostream;

#include <utility>
using std::pair;
using std::make_pair;

#include <string>
using std::string;
#include <sstream>
using std::stringstream;

#include <iostream>

#include <iomanip>
#include <algorithm>
#include <numeric> 

#include <thread>
typedef std::thread Thread;
namespace this_thread = std::this_thread;

#include <boost/asio.hpp>
typedef boost::asio::io_service IOService;

#include <boost/assign.hpp>

#include <boost/optional.hpp>
using boost::optional;
using boost::none;

#include <boost/intrusive_ptr.hpp>
using boost::intrusive_ptr;

#include <boost/filesystem.hpp>
#include <boost/signals2/signal.hpp>

#include <boost/foreach.hpp>

#include <type_traits>

#include <mutex>
using std::mutex;

#include <condition_variable>
using std::condition_variable;

using boost::noncopyable;
using std::runtime_error;

#include <boost/unordered_map.hpp>

#include "interface.h"
#include "opt_ptr.h"
#include "logger/logger.hpp"