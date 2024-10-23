#pragma once

class Circle : public GameObject
{
public:
    //생성자 / 소멸자
    Circle() = default; // "기본 c++ 클래스 생성자를 쓰겠다"
    Circle(Vector2 pos, float radius);  // 위치와 반지름으로 만들기

    // 게임오브젝트에서 상속받은 인터페이스

    virtual void Render(HDC hdc) override; // 출력

    //충돌
    virtual bool IsCollision(const Vector2& point) const override; // 점과 겹칠 경우
    virtual bool IsCollision(const Rect* rect) const override;  // 사각형과 겹칠 경우
    virtual bool IsCollision(const Circle* circle) const override;  // 같은 원끼리 겹칠 경우

    float GetRadius() const { return radius; }   // 겟터
    float& SetRadius() { return radius; }        // 셋터

public:

    float radius = 0.0f;    // 반지름

};

