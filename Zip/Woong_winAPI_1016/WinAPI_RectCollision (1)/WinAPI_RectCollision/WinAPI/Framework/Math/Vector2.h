#pragma once

struct Vector2  // 2차원 벡터
{
    // 벡터 : 윈도우에서 말하는 벡터는 자료 구조가 아니라 "방향을 가진 직선"
    //        중고등학교 수학에서 보던 그게 맞는다.
    
    // 2차원 벡터 : 가로와 세로 (높이는 없는) 벡터

    // 구조체의 멤버
    float x = 0.0f;     // 가로
    float y = 0.0f;     // 세로

    Vector2() = default;    // 기본 생성자
    Vector2(float x, float y) : x(x), y(y) {};  // 매개변수가 있을 때

    // ...구조체인데, 생성자라고?
    // -> 현재는 구조체도 클래스가 할 수 있는 건 다 할 수 있다.
    //    그냥 구조체를 쓰는 사람이 주로 데이터 집합으로 쓰는 것뿐

    // 아래 코드는 연산자 오버라이드라고 하며,
    // +, -, * 같은 연산자에 새로운 의미를 부여한다
    // (벡터1) + (벡터2) 같은 계산을 가능하게 한다는 뜻

    // * 아래 연산은 벡터의 수학적 계산을 코드로 나타낸 것.
    //   벡터 계산에 대해 알아보고 다시 돌아와서 살펴보기

    Vector2 operator+(const Vector2& value) const
    {
        return Vector2(x + value.x, y + value.y);
    }
    Vector2 operator-(const Vector2& value) const
    {
        return Vector2(x - value.x, y - value.y);
    }
    Vector2 operator*(const float& value) const
    {
        return Vector2(x * value, y * value);
    }
    Vector2 operator/(const float& value) const
    {
        return Vector2(x / value, y / value);
    }

    void operator+=(const Vector2& value)
    {
        x += value.x;
        y += value.y;
    }
    void operator-=(const Vector2& value)
    {
        x -= value.x;
        y -= value.y;
    }
    void operator*=(const float& value)
    {
        x *= value;
        y *= value;
    }
    void operator/=(const float& value)
    {
        x /= value;
        y /= value;
    }

    // 두 벡터(위치) 사이의 거리를 찾아내는 함수
    float Length() const
    {
        return sqrt(x * x + y * y);
    }
};