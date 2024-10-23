#pragma once

class Clock
{
public:
    Clock();
    ~Clock();

    void Update();  // 갱신
    void Render(HDC hdc);   // 출력 (+ 어디에 그릴 것인가?)


private:

    // 선 세 개 : 시침, 분침, 초침
    Line* lineHour;
    Line* lineMinute;
    Line* lineSecond;

    // 각 침의 길이
    float lengthHour = 100;
    float lengthMinute = 200;
    float lengthSecond = 150;

    // 시계가 있어야 하는 곳, 선의 시작점
    Vector2 position;

    // 시계 바탕 원
    Circle* background;

    // 시계의 크기, 반지름
    float clockSize;

    // 제일 중요한 것 : 시간 정보
    SYSTEMTIME st_time; // 시간 구조체

    void GetTime();  // 시간을 얻고 시계 정보 정하기

    // 침의 종점, 각도 정보
    float angleHour;
    float angleMinute;
    float angleSecond;
    Vector2 endHour;    // 선의 종점
    Vector2 endMinute;
    Vector2 endSecond;

};

