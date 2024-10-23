#pragma once

class Ball : public Circle
{
    // 원 = 2D 속 공

    // 형상의 데이터는 부모 클래스 밑에 다 있으니까...

    // 이 '공'이 물체로서 가졌으면 좋을 만한 데이터를 궁리해보자

public:
    Ball(Vector2 pos, float radius); // 생성자에서 위치와 반지름이 필수
    ~Ball();

    void Update();

private:

    // float pi = 3.14159; 불필요
    
    float angle; // 각도
    float speed; // 움직인다고 치면, 속력이 있을 것

    // 공이 가야 할 다음 위치... 즉 방향을 추가 변수로 지정
    // 속력은 아니다 (속력에서 아래 변수가 나오는 것)

    Vector2 direction;  // "방향"
};

