#pragma once

class Brick : public Rect
{
public:

    Brick(Vector2 pos, Vector2 size);
    ~Brick();

    void Update();
    void Reflect(Vector2 overlapSize); // 반사 시 적용할 함수

private:

    // 벽돌의 "움직임"에 필요한 것

    bool isMovable; // 움직이긴 할 건가?
    
    float angle;    // 각도는 필요
    float speed;    // 속력도 필수

    Vector2 direction;  // 진행 방향
    
};

