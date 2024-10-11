#pragma once

//. Ʃ�丮�� �� : ���� �����, �׸��� �츮�� ������ �ڵ�����, 
//				�������� ù ȭ��

#include "Objects/Basic/Rect.h"; // ������ -> ���ϸ� ������ ����
								// �������� / �� ���а���

class TutorialScene : public Scene
{
public:
    TutorialScene();	// ������(����)
    ~TutorialScene();	// �Ҹ���(��)

    virtual void Update() override;	// . ���ΰ�ħ
    virtual void Render(HDC hdc) override;	//. ȭ��ǥ��

private:
    
    int count; //. �� ���ο��� ����� ����
	
	Rect* rect; // �簢�� ��ü ����  (������ �ν��Ͻ�)

	Vector2 rectsize; // �簢���� ũ��
};