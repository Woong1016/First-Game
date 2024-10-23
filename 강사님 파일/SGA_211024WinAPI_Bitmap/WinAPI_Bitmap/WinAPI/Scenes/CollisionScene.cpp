#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
    hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
    hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));

    Vector2 center(CENTER_X, CENTER_Y);

    //objects.push_back(new Circle(center, 50));
    //objects.push_back(new Circle(center, 70));
    objects.push_back(new Rect(center, Vector2(200, 100)));
    objects.push_back(new Rect(center, Vector2(100, 200)));
}

CollisionScene::~CollisionScene()
{
    DeleteObject(hRedBrush);
    DeleteObject(hBlueBrush);

    for (GameObject* object : objects)
        delete object;
}

void CollisionScene::Update()
{
    objects[0]->pos = mousePos;
        
    //isCollision = objects[0]->IsCollision(objects[1]);
    Vector2 overlapSize;
    if (objects[0]->IsRectCollision((Rect*)objects[1], &overlapSize))
    {
        if (overlapSize.x > overlapSize.y)//상하 충돌
        {
            if (objects[0]->pos.y > objects[1]->pos.y)
            {
                objects[1]->pos.y -= overlapSize.y;
            }
            else
            {
                objects[1]->pos.y += overlapSize.y;
            }
        }
        else//좌우 충돌
        {
            if (objects[0]->pos.x > objects[1]->pos.x)
            {
                objects[1]->pos.x -= overlapSize.x;
            }
            else
            {
                objects[1]->pos.x += overlapSize.x;
            }
        }
    }
}

void CollisionScene::Render(HDC hdc)
{
    if (isCollision)
        SelectObject(hdc, hRedBrush);
    else
        SelectObject(hdc, hBlueBrush);

    for (GameObject* object : objects)
        object->Render(hdc);
}
