#pragma once
#include "Singleton.h" // ���� ���� ���ø� �̱��� ����
class SampleData : public Singleton<SampleData>
							// ���ø��̱��� Ŭ������ ��ӹ��� =
							// �� �ڽ��� �̱������θ� ���� ������ Ŭ����

{				
	SampleData(); // �����ڿ� �Ű����� ������ ����
					// -> �̱��� (�θ�Ŭ����) �� �����Ƿ�
	~SampleData();

	int GetData(int index)
	{
		return myData[index];
	}

	void SetData(int index, int value) 
	{
		myData[index] = value;
	}

private:
	
	int myData[10]; // ���� 10��





};

