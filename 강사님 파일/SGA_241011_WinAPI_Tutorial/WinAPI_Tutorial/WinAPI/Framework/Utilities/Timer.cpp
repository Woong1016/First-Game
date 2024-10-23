#include "Framework.h"

// Timer 클래스의 생성자
Timer::Timer()
{
    // CPU의 1초 동안의 진동수를 반환하는 함수 (즉, CPU 클럭 주기를 구함)
    QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);

    // 현재 시점의 CPU 진동수를 반환하는 함수 (현재 시간의 타임스탬프를 구함)
    QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);

    // 진동수를 통해 시간을 초 단위로 변환하는 스케일 계산
    timeScale = 1.0f / (float)periodFrequency;
}

Timer::~Timer()
{
    // 소멸자: 현재는 아무 작업도 하지 않음
}

// 매 프레임마다 호출되는 함수로 시간을 갱신함
void Timer::Update()
{
    // 현재 시간을 CPU 진동수로 반환함
    QueryPerformanceCounter((LARGE_INTEGER*)&curTime);

    // 지난 프레임과 현재 프레임 사이의 시간(초)을 계산함
    elapsedTime = (float)(curTime - lastTime) * timeScale;

    // 현재 시간을 다음 프레임 계산에 사용하기 위해 저장함
    lastTime = curTime;

    // 프레임 카운트를 증가시킴
    frameCount++;

    // 1초 누적 시간에 경과 시간을 더함
    oneSecCount += elapsedTime;

    // 1초가 경과하면 FPS를 계산하고 초기화함
    if (oneSecCount >= 1.0f)
    {
        // 초당 프레임 수(FPS)를 저장함
        frameRate = frameCount;

        // 프레임 카운트를 0으로 초기화함
        frameCount = 0;

        // 1초 누적 시간을 초기화함
        oneSecCount = 0.0f;
    }
}

// FPS와 Delta Time(경과 시간)을 화면에 출력하는 함수
void Timer::Render(HDC hdc)
{
    // FPS를 출력하기 위한 문자열을 생성함
    wstring str = L"FPS : " + to_wstring(frameRate);

    // 화면의 (0, 0) 좌표에 FPS를 출력함
    TextOut(hdc, 0, 0, str.c_str(), (int)str.length());

    // 경과 시간을 출력하기 위한 문자열을 생성함
    str = L"Delta : " + to_wstring(elapsedTime);

    // 화면의 (0, 20) 좌표에 Delta Time을 출력함
    TextOut(hdc, 0, 20, str.c_str(), (int)str.length());
}
