#pragma once
class ClockScene : public Scene
{
public:
    ClockScene();
    ~ClockScene();

    virtual void Update() override; // ���ΰ�ħ
    virtual void Render(HDC hdc) override;  //ȭ��ǥ��

private:

    Clock* clock;
};

