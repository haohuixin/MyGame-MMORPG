#pragma once

#include "targetver.h"

//Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE

//Windows Header Files:
#include <windows.h>
#include "Shlwapi.h"

//STD:
#include <ctime>
#include <vector>
#include <strsafe.h>
#include <iostream>
#include <sstream>
#include <deque>
#include <cstdint>
#include <tuple>
#include <stack>
#include <chrono>
#include <queue>
#include <list>
#include <typeinfo>

//C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//Boost
#include <boost/preprocessor.hpp>

//Urho3D Library
#include <Urho3D\Urho3DAll.h>

//Bson
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/types.hpp>

//MongoDB
#include <mongocxx/client.hpp>
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/instance.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::sub_array;

using namespace Urho3D;

#include "globals.h"