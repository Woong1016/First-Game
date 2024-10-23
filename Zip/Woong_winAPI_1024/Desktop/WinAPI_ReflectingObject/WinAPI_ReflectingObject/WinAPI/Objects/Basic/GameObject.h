#pragma once

// 게임오브젝트 v2
// 접근지정자를 public으로
// 충돌 보강 (오브젝트 충돌을 단일 명칭으로, 객체별 충돌은 따로 계산)

class Rect;
class Circle;

class GameObject
{
public:
    GameObject() = default;
    GameObject(Vector2 pos) : pos(pos) {}
    ~GameObject() = default;

    virtual void Update() {}
    virtual void Render(HDC hdc) = 0;

    virtual bool IsCollision(const GameObject* object);

    virtual bool IsCollision(const Vector2& point) const = 0;
    virtual bool IsRectCollision(const Rect* rect) const = 0;
    virtual bool IsCircleCollision(const Circle* circle) const = 0;

    // 렉트 충돌 2형 : 충돌 영역 크기를 추가 계산 (렉트 클래스에서 확인)
    // 매개변수에서 IN, OUT은 코드상 의미가 없는 정의 전용 매크로
    // = 사람 보라고 만들었거나, 이 매크로가 "있다는" 사실만으로 코드가 달라져야 할 때 쓰는 매크로
    //   (지금 경우에는 전자. IN : 들어가는 매개변수란 뜻. OUT : 함수 결과가 여기에도 저장된단 뜻)
    virtual bool IsRectCollision(IN const Rect* rect, OUT Vector2* overlapSize) const { return false; }

public:
    string tag;                 // "태그" = 분류명이라는 변수 추가
    bool isActive = true;
    Vector2 pos;
};