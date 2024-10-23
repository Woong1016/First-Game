#include "Framework.h"

Rect::Rect(Vector2 pos, Vector2 size)
    : GameObject(pos), size(size)
{
}

Rect::Rect(float left, float top, float right, float bottom)
{
    pos.x = (left + right) * 0.5f;
    pos.y = (top + bottom) * 0.5f;

    size.x = abs(right - left);
    size.y = abs(bottom - top);
}

void Rect::Render(HDC hdc)
{
    if (!isActive)
        return;

    int left = (int)(pos.x - size.x * 0.5f);
    int right = (int)(pos.x + size.x * 0.5f);
    int top = (int)(pos.y - size.y * 0.5f);
    int bottom = (int)(pos.y + size.y * 0.5f);

    Rectangle(hdc, left, top, right, bottom);
}

bool Rect::IsCollision(const Vector2& point) const
{
    if (!isActive)
        return false;

    if (point.x > Left() && point.x < Right())
    {
        if (point.y > Top() && point.y < Bottom())
            return true;
    }

    return false;
}

bool Rect::IsRectCollision(const Rect* rect) const
{
    if (!isActive) return false;
    if (!rect->isActive) return false;

    if (rect->Left() < Right() && rect->Right() > Left())
    {
        if (rect->Top() < Bottom() && rect->Bottom() > Top())
        {
            return true;
        }
    }

    return false;
}

// 충돌 영역 크기까지 구하는 함수
// 충돌 영역의 가로, 세로 크기를 각각 구한다
// -> 충돌 영역의 가로가 크면 수평 충돌. 세로가 크면 수직 충돌.
bool Rect::IsRectCollision(IN const Rect* rect, OUT Vector2* overlapSize) const
{
    if (!isActive) return false;
    if (!rect->isActive) return false;

    float left = max(rect->Left(), Left()); // max, min : 둘 중 큰 것/ 작은 것을 반환하는 윈도우 함수
    float right = min(rect->Right(), Right());
    float top = max(rect->Top(), Top());
    float bottom = min(rect->Bottom(), Bottom());

    // 충돌 영역의 x, y 크기를 저장한다 (충돌에 사용)
    overlapSize->x = right - left;
    overlapSize->y = bottom - top;

    if (overlapSize->x > 0 && overlapSize->y > 0) // 일단 충돌 영역이 '무'가 아닌 것만으로도
        return true;                              // 충돌은 한 게 맞고,
                                                  // 함수 실행 후, overlapSize의 크기로
                                                  // 두 사각형의 (혹은 어쩌면 원과의)
                                                  // 위치관계 파악 가능 (위아래냐, 양옆이냐)

    return false;
}

bool Rect::IsCircleCollision(const Circle* circle) const
{
    if (!isActive) return false;
    if (!circle->isActive) return false;

    //십자가 범위
    if (circle->pos.x > Left() && circle->pos.x < Right() ||
        circle->pos.y > Top() && circle->pos.y < Bottom())
    {
        Vector2 size(circle->GetRadius() * 2, circle->GetRadius() * 2);
        Rect temp(circle->pos, size);

        if (IsRectCollision(&temp))
            return true;
        else
            return false;
    }

    //십자가 밖 범위(대각선 범위)
    Vector2 edges[4];
    edges[0] = { Left(), Top() };
    edges[1] = { Left(), Bottom() };
    edges[2] = { Right(), Top() };
    edges[3] = { Right(), Bottom() };

    for (Vector2 edge : edges)
    {
        if (circle->IsCollision(edge))
            return true;
    }

    return false;
}
