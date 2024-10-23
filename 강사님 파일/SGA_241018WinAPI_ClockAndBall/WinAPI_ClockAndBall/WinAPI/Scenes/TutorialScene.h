#pragma once

// Ʃ�͸��� �� : ���� �����, �׸��� �츮�� ������ �ڵ��� ��,
//              �������� ù ȭ��

#include "Objects/Basic/Rect.h" // ������ -> ���ϸ� ������ ����
                                // �������� / �� ���� ����

#include "Objects/Basic/Circle.h" // �� �Ẹ��

class TutorialScene : public Scene
{
public:
    TutorialScene();    // ������ (����)
    ~TutorialScene();   // �Ҹ��� (��)

    virtual void Update() override; // ���ΰ�ħ
    virtual void Render(HDC hdc) override;  //ȭ��ǥ��

private:
    
    int count; // �� ���ο��� ����� ����

    //���� ���� ������
    Rect* rect; // �簢�� ��ü ���� (������ �ν��Ͻ�)
    Vector2 rectSize; // �簢���� ũ��

    Rect* rectOnScene; // �� �� �簢��
    Vector2 sceneRectSize; // �� �� �簢�� ũ��
    Vector2 sceneRectPosition;

    // �� �Ẹ��
    Circle* circle;
    float radius;

    Circle* circleOnScene;
};