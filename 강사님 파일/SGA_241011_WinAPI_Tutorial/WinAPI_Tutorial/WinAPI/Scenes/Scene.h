#pragma once


// ��: ���� �߻� Ŭ���� 
//. ��Ģ�� �����ϴ� �������̽�
class Scene
{
public:

	//. �׷��Ƿ� �� ���� ��ӹ޴� ��� Ŭ������...

    virtual void Update() = 0;	// ���ΰ�ħ ����� �־�� �ϰ�
    virtual void Render(HDC hdc) = 0;	// ȭ�� ǥ�� ��ɵ� �־�� �Ѵ�.
};