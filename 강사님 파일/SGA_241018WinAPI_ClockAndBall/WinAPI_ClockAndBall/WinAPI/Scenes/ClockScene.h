#pragma once
class ClockScene : public Scene
{
public:
    ClockScene();
    ~ClockScene();

    virtual void Update() override; // 새로고침
    virtual void Render(HDC hdc) override;  //화면표시

private:

    Clock* clock;
};

