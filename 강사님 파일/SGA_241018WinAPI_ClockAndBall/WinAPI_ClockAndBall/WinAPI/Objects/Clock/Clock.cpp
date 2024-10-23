#include "Framework.h"
#include "Clock.h"

Clock::Clock()
{
    position = { CENTER_X, CENTER_Y };

    lineHour = new Line();
    lineMinute = new Line();
    lineSecond = new Line();

    lineHour->pos = position;
    lineMinute->pos = position;
    lineSecond->pos = position;

    clockSize = 300.0f;
    background = new Circle(position, clockSize);

    // 첫 번째로 시간을 얻기
    GetLocalTime(&st_time); // 수행하면 시간을 얻은 후, 매개변수로 받는 변수의 위치(포인터)에 저장

    // 변수 1차 초기화 (각도, 종점도)
    angleHour = 0;
    angleMinute = 0;
    angleSecond = 0;

    endHour = { 0, 0 };
    endMinute = { 0, 0 };
    endSecond = { 0, 0 };

    // 정보를 얻고, 최초의 시계 설정
    GetTime();
}

Clock::~Clock()
{
}

void Clock::Update()
{
    GetTime(); // 매시 매초 시간을 재계산
}

void Clock::Render(HDC hdc)
{

    // 시계 출력 = 배경, 시침, 분침, 초침 순으로 렌더해주면 된다

    background->Render(hdc);

    // 이 사이로 글자나 눈금이 있으면 시침 밑에 그려진다

    lineHour->Render(hdc);
    lineMinute->Render(hdc);
    lineSecond->Render(hdc);

    // 이 위로 글자나 눈금이 있으면 시침 위에 그려진다

    wstring str = to_wstring(angleHour);
    TextOut(hdc, 0, 300, str.c_str(), str.length());

    str = to_wstring(st_time.wSecond);
    TextOut(hdc, 0, 320, str.c_str(), str.length());

}

void Clock::GetTime()
{
    // 시간을 다시 얻고, 이어서 각 침의 위치 정하기

    GetLocalTime(&st_time); // 시간 재확인 (매번 해야 되니까)

    // 구조체 안에 있는 시, 분 초 정보를 가지고 각도를 정하면 된다

    // 제일 먼저, 호도법 계산을 위한 준비
    float pi = 3.14159f;    // 여기에 숫자를 곱하면 그에 맞는 '원' 정보가 나온다

    // ------------------------------------------------------------------------

    // 시간 각도
    angleHour = (pi * 2) * ((float)st_time.wHour / 12) - 0.5f * pi;
    // 한 바퀴에 12시간
    // - 0.5pi = 90도
    // ** float으로 형변환해서 계산 오류가 없도록 했습니다. (10-18)

    /*
    
    // 시침그리기
    endHour.x = cos(-angleHour) * lengthHour;       // -1을 곱해서 시계 방향 움직임으로
    endHour.y = -sin(-angleHour) * lengthHour;
    lineHour->end = endHour + lineHour->pos;    // 시침의 종점은 방금 계산한 이거

    // 분 각도
    angleMinute = (pi * 2) * ((float)st_time.wMinute / 60) - 0.5f * pi;
    // 분침그리기
    endMinute.x = cos(-angleMinute) * lengthMinute;
    endMinute.y = -sin(-angleMinute) * lengthMinute;
    lineMinute->end = endMinute + lineMinute->pos;

    // 초 각도
    angleSecond = (pi * 2) * ((float)st_time.wSecond / 60) - 0.5f * pi;
    // 초침그리기
    endSecond.x = cos(-angleSecond) * lengthSecond;
    endSecond.y = -sin(-angleSecond) * lengthSecond;
    lineSecond->end = endSecond + lineSecond->pos;

    */

    //-------------------------------------------------------------------


    // * 심화!!

    // 위쪽 코드는 시계 바늘 방향을 칼같이 n시, n분, n초만 그려줍니다.
    // 그런데 현실의 시침, 분침은 각각 분, 초의 영향을 같이 받습니다.

    // 그러므로 해당 정보를 시침, 분침에도 모두 대응해서 그려주고자 합니다.
    
    // 그러기 위해서는 먼저 참조 대상이 되는 초침부터 만든 후,
    // 초침을 참조하면서 분침을, 다시 분침을 참고하면서 시침을 만들어주면 됩니다.

    // 초 각도 : 초침 먼저!
    angleSecond = (pi * 2) * ((float)st_time.wSecond / 60) - 0.5f * pi;
    
    // 초침그리기
    endSecond.x = cos(-angleSecond) * lengthSecond;
    endSecond.y = -sin(-angleSecond) * lengthSecond;
    lineSecond->end = endSecond + lineSecond->pos;


    // 분 각도
    angleMinute = (pi * 2) * ((float)st_time.wMinute / 60) - 0.5f * pi; // 원래 각도
    angleMinute += angleSecond / 60; // 초침이 한 바퀴면 분침이 1/60바퀴

    // 분침그리기
    endMinute.x = cos(-angleMinute) * lengthMinute;
    endMinute.y = -sin(-angleMinute) * lengthMinute;
    lineMinute->end = endMinute + lineMinute->pos;


    // 시간 각도
    angleHour = (pi * 2) * ((float)st_time.wHour / 12) - 0.5f * pi;
    // 한 바퀴에 12시간. -0.5pi = 90도
    // ** float으로 형변환해서 계산 오류가 없도록 했습니다. (10-18)
    angleHour += angleMinute / 12; // 분침이 한 바퀴면 시침은 1/12바퀴


    // 시침그리기
    endHour.x = cos(-angleHour) * lengthHour;       // -1을 곱해서 시계 방향 움직임으로
    endHour.y = -sin(-angleHour) * lengthHour;
    lineHour->end = endHour + lineHour->pos;    // 시침의 종점은 방금 계산한 이거

    





}
