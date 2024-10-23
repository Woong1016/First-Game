// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN  
// 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#define WIN_WIDTH 1280
#define WIN_HEUGHT 720

#define CENTER_X (WIN_WIDTH * 0.5F)
#define CENTER_Y (WIN_HEIGT * 0.5F)


 
// Windows 헤더 파일
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

extern Vector2 mousePos;
