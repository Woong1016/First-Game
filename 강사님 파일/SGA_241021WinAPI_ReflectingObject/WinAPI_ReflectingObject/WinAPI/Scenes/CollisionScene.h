#pragma once

// v2 Æ©ÅÍ¸®¾ó : Ãæµ¹ ¾À

class CollisionScene : public Scene
{
public:
    CollisionScene();
    ~CollisionScene();

    virtual void Update() override;
    virtual void Render(HDC hdc) override;

private:
    vector<GameObject*> objects;

    HBRUSH hRedBrush;
    HBRUSH hBlueBrush;

    bool isCollision = false;
};