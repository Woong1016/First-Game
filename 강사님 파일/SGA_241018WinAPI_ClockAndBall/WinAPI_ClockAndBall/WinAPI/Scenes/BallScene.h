#pragma once

#include "Objects/Basic/Rect.h"


class BallScene : public Scene
{




public:
    BallScene();
    ~BallScene();

    virtual void Update() override;
    virtual void Render(HDC hdc) override;

private:

    Ball* ball;

    Ball* rectOnScene; // �� �� �簢��
    Vector2 sceneRectSize; // �� �� �簢�� ũ��
    Vector2 sceneRectPosition;
};

