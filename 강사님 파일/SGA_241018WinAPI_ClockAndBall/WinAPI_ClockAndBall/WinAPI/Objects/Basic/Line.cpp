#include "Framework.h"
#include "Line.h"

Line::Line(Vector2 start, Vector2 end)
    : GameObject(start), end(end)
{
    // 게임 물체로서의 위치 = 시작점으로 간주
    // 종점은 따로 관리
}

void Line::Render(HDC hdc)
{
    // 여기서 전에 썼던 'moveto' 'lineto' 사용
    MoveToEx(hdc, pos.x, pos.y, nullptr);
    LineTo(hdc, end.x, end.y);
}

// 충돌은 계산 안 함 (모두 false)
bool Line::IsCollision(const Vector2& point) const
{
    return false;
}

bool Line::IsCollision(const Rect* rect) const
{




    return false;
}

bool Line::IsCollision(const Circle* circle) const
{
    return false;
}
