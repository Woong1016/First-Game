#pragma once

// 원 v2 : 반지름 설정할 수 있게

class Circle : public GameObject
{
public:
    Circle() = default;
    Circle(Vector2 pos, float radius);

    virtual void Render(HDC hdc) override;

    virtual bool IsCollision(const Vector2& point) const override;
    virtual bool IsCircleCollision(const Circle* circle) const override;
    virtual bool IsRectCollision(const Rect* rect) const override;

    float GetRadius() const { return radius; }
    void SerRadius(float radius) { this->radius = radius; }

protected:
    float radius = 0.0f;
};