#pragma once

#include "targetver.h"

//Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN

//Windows Header Files:
#include <windows.h>
#include "Shlwapi.h"

//STD:
#include <ctime>
#include <vector>
#include <strsafe.h>
#include <iostream>
#include <sstream>
#include <functional>

//C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <SDL/SDL.H>

//Urho3D Library
#include <Urho3D\Urho3DAll.h>

using namespace Urho3D;

#include "globals.h"