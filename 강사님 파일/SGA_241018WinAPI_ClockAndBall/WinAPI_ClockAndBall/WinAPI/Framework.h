#pragma once

// 앱에서 사용하는 각종 매크로, 포함된 기능 확인
// -> 비단 이 폴더(이 프레임워크)만이 아니라, 윈도우 API 기반
//    프로그래밍을 한다면 수시로 와서 확인할 필요가 있다!!!

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define CENTER_X (WIN_WIDTH * 0.5f)
#define CENTER_Y (WIN_HEIGHT * 0.5f)

#define DELTA Timer::Get()->GetElapsedTime()

// 키보드 관련 매크로
#define KEY_DOWN(k) Keyboard::Get()->Down(k)    // 키를 누를 때
#define KEY_UP(k) Keyboard::Get()->Up(k)        // 키에서 손을 뗄 때
#define KEY_PRESS(k) Keyboard::Get()->Press(k)  // 키를 누르고 있을 때

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

//Framework Header
#include "Framework/Utilities/Singleton.h"
#include "Framework/Utilities/Timer.h"
#include "Framework/Utilities/Keyboard.h"

#include "Framework/Math/Vector2.h"
#include "Framework/Math/GameMath.h"

using namespace GameMath;

//Object Header
#include "Objects/Basic/GameObject.h"
#include "Objects/Basic/Rect.h"
#include "Objects/Basic/Circle.h"
#include "Objects/Basic/Line.h"

#include "Objects/Spawn/SpawnObject.h"
#include "Objects/Spawn/SpawnManager.h"

#include "Objects/Clock/Clock.h"
#include "Objects/Ball/Ball.h"

//Scene Header
#include "Scenes/Scene.h"

//Manager Header
#include "Manager/GameManager.h"

extern Vector2 mousePos;