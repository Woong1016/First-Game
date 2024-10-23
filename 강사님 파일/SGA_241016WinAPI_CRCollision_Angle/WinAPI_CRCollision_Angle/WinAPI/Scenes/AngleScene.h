#pragma once

class AngleScene : public Scene
{
public:
    AngleScene();    // 생성자 (시작)
    ~AngleScene();   // 소멸자 (끝)

    virtual void Update() override; // 새로고침
    virtual void Render(HDC hdc) override;  //화면표시

private:
    
    Line* line; // 선

    // 선에 길이를 정해주기 위한 추가 변수
    // 내가 가진 것 : 선이 원래 찍히는 가로, 세로 좌표 (마우스 커서)
    // 필요한 것 : 선에 정해져야 할 길이, 그리고 각도

    float length = 300.0f;
    
    float pi = 3.14159; // 파이
    float angle = pi * 0.25f;    // 기본 각도

    // 각도가 왜 갑자기 3.14를 직접 곱하는가?
    // -> 각도가 0부터 360까지 숫자가 아닌 건가?!

    // 윈도우 API에서는 각도를 계산할 때, 360도를 기준으로 하지 않는다
    // 대신에 1단위 = 원주율(3.14) 대비 1인 각도로 계산한다
    // -> 약 60도 비슷한 각도가 윈도우 API에서 1단위가 된다.

    // 이 각도 작법을 호도법이라고 하고, 단위의 이름은 라디안이라고 한다
};

