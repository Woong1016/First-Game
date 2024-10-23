#pragma once

// 클래스 전방 선언 (클래스 이름이 나와도 컴퓨터가 헷갈리지 않게)
class Rect;     // 현재 구현된 클래스 : 직사각형 (Rectangle)
class Circle;   // 아직 안 만든 클래스 = 앞으로 만들 클래스 : 원

class GameObject
{
public:
    GameObject() = default;
    GameObject(Vector2 pos) : pos(pos) {}
    ~GameObject() = default;

    // 게임 오브젝트에서 필수인 것 : 무조건 "표시"를 정의해야 한다
    virtual void Render(HDC hdc) = 0;

    // 하나 더. "충돌"을 만들어야 한다
    // 충돌 : 데이터가 나타내는 그래픽이 서로 겹쳤음을 감지하는 함수 코드
    //        액션, RPG, 스포츠, 그 외 각종 게임에서 판정을 판단할 때 사용
    virtual bool IsCollision(const Vector2& point) const = 0;
    virtual bool IsCollision(const Rect* rect) const = 0;
    virtual bool IsCollision(const Circle* circle) const = 0;

    // 이 게임오브젝트의 위치를 나타내는 겟터들
    Vector2& Pos() { return pos; }       // 자료형 + * : 포인터
    bool& Active() { return isActive; }  // 자료형 + & : 해당 데이터(실체)
                                         // = 복제 데이터 등이 아니고 정확히 그 데이터를 쓰겠단 뜻
                                         // 해석하기 따라서는 변수에 두 번째 이름을 지어준다고도 볼 수 있다
                                         // 다른 말로, Pos()를 불러서 수정하면 pos가 바뀐다!!

public:
    bool isActive = true;                // Active : 활성화 여부
                                         // 활성화가 꺼지면 데이터는 게임 속에 있어도
                                         // 화면에 보이지 않게 하거나, 연산의 대상으로 삼지 않을 수 있다
                                         // 예 : 밴한 캐릭터 스테이터스, 비행기 게임의 방어막

    Vector2 pos;
};