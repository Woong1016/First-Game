#pragma once
class AngleScene : public Scene
{

public:
	AngleScene();    // ������ (����)
	~AngleScene();   // �Ҹ��� (��)

	virtual void Update() override; // ���ΰ�ħ
	virtual void Render(HDC hdc) override;  //ȭ��ǥ��


private:
	//���� �����ؼ� �׷��� ���

	Line* line; //��

	// ���� ���̸� �����ֱ� ���� �߰� ����
	// ���� ���� ��: ���� ���� ������ ���� , ���� ��ǥ (���콺 Ŀ��)
	// �ʿ��� �� : ���� �������� �� ���� , �׸��� ����

	float lenth = 300.0f; 
	float pi = 3.14159; // ����
	float angle = pi * -0.25f;
};

