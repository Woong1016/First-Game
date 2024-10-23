#pragma once
class BrickScene : public Scene
{
public:

    BrickScene();
    ~BrickScene();

    virtual void Update() override;
    virtual void Render(HDC hdc) override;

private:

    // 벽돌 (임시, 빠르게 배치)
    int brickAmount = 3; //벽돌 세 개
    vector<Brick*> bricks; // <- 이 벡터가 맵에 들어가면 풀링 매니저 사용 (도전해보세요!)

};

