#pragma once

class Circle; // 전방 선언 : 앞으로 이런 이름의 클래스가 있을 거라고 미리 말해두는 것
              //             변수나 함수의 전방 선언과 같다

class Rect : public GameObject
{
public:
    Rect() = default;
    Rect(Vector2 pos, Vector2 size);
    Rect(float left, float top, float right, float bottom);
    
    virtual void Render(HDC hdc) override;

    virtual bool IsCollision(const Vector2& point) const override;
    virtual bool IsCollision(const Rect* rect) const override;
    virtual bool IsCollision(const Circle* circle) const override;

    // 위치와 크기를 주면, 그에 따라 자동으로 상하좌우 변의 위치를 재계산한다
    // Rectangle(hdc, 왼쪽, 위쪽, 오른쪽, 아래쪽) 작성하던 것을 아래 함수로 대체
    float Left() const { return pos.x - size.x * 0.5f; }
    float Right() const { return pos.x + size.x * 0.5f; }
    float Top() const { return pos.y - size.y * 0.5f; }
    float Bottom() const { return pos.y + size.y * 0.5f; }
        
    Vector2 GetSize() const { return size; } // 사이즈 겟터 (상수)
    Vector2& SetSize() { return size; }      // 사이즈 셋터 (상수 아님)

protected:    
    Vector2 size;    
};