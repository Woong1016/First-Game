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

    Ball* rectOnScene; // 씬 속 사각형
    Vector2 sceneRectSize; // 씬 속 사각형 크기
    Vector2 sceneRectPosition;
};

