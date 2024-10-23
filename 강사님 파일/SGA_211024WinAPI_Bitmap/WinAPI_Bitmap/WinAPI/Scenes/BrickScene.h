#pragma once
class BrickScene : public Scene
{
public:

    BrickScene();
    ~BrickScene();

    virtual void Update() override;
    virtual void Render(HDC hdc) override;

private:

    // ���� (�ӽ�, ������ ��ġ)
    int brickAmount = 3; //���� �� ��
    vector<Brick*> bricks; // <- �� ���Ͱ� �ʿ� ���� Ǯ�� �Ŵ��� ��� (�����غ�����!)

};

