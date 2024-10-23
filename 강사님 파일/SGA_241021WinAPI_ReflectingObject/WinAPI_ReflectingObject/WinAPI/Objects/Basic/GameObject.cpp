#include "Framework.h"

bool GameObject::IsCollision(const GameObject* object)
{
    // 매개변수로 받은 상대 객체를 Circle로 형변환 시도해보기

    const Circle* circle = dynamic_cast<const Circle*>(object);

    if (circle != nullptr)  // 형변환이 됐으면 = 원이면
        return IsCircleCollision(circle);   // 원 충돌

    const Rect* rect = dynamic_cast<const Rect*>(object);

    if (rect != nullptr) //사각형 형변환이 되면 = 사각형
        return IsRectCollision(rect);   // 사각형 충돌

    // 종류별로 원 / 사각형 / 혹은 다른 방식으로 충돌 판정 시도

    return false;
}
