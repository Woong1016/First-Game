#pragma once
class BallScene : public Scene
{
public:

    BallScene();
    ~BallScene();

    virtual void Update() override;
    virtual void Render(HDC hdc) override;

private:

    Ball* ball;

};

