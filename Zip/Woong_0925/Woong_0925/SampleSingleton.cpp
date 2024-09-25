#include "SampleSingleton.h"

SampleSingleton* SampleSingleton::Get()
{
	// �� Ŭ������ ���� ������ �����͸� �ۿ��� ȣ���ϰ� ���ִ� �Լ�

	// �ش� �������� �̸��� ������� Ȯ�� : ���⼭�� instance

	//���� instance�� �ִ��� ���������� Ȯ��

	if (instance == nullptr) // nullptr : �����Ͱ� ���ų� �����Ͱ� �����ͷ� 
							// �� instance�� nullptr: ���� �������� ����
							// ���� ���� instance�� ����

	{
		// instance�� �������� �ʴ´ٸ� -> ���� �ϳ� ����� 

		//instance = new SampleSingleton(30); // �μ��� �ϳ� �ְ� ����

	}

	// instance �� �����ٸ� ���ٿ��� ��������� ��
	//instance�� �ִٸ� static���� Ȯ���ϰ� �����ϰ� ������ ��

	// �׷��Ƿ� �� �����͸� ��ȯ�ϸ� �ȴ�

	return instance;
}

void SampleSingleton::Delete()
{
	// �Ҹ��ڸ� �ۿ��� �θ��ų� �������� ���ϴϱ�
	//�ۿ��� �� �����͸� �����޶�� ��û�� �� �ֵ���

	delete instance; // delete : ���þ� �� �ϳ�. ���� ǥ���ϸ� �������� �Ҵ� ������ 
					// ��Ȯ���� " �� �޸𸮴� ���� ������ �����ϱ� ����� ������"
					// �׷��� �����ʹ� ���⵵ , �ȳ��⵵ ������ ,��ǻ�ʹ� ������ �� �ּҿ�
					// �ʿ��ϸ� �ٸ� �����͸� �� �� �ִ�.

	instance = nullptr; // �� ���� ���� ���� �����Ͱ� �ƴ϶�� ����

	// �̷��� Ŭ������ ������ �Ҹ��ڸ� �θ��� �ʾƵ�
	// �ܺο��� Ŭ������ �ٷ� ������ ���ص�
	// instance�����ʹ� ���� ���� �ִ�.


}

SampleSingleton::SampleSingleton()
{
	//�ν��Ͻ��� ��¥ ������
	// ���� instance�� �������� �ʾ��� �� , Get�Լ��� ���ؼ��� ȣ��


	data = 0; 
}

//SampleSingleton::SampleSingleton(int input)
//{
//	data = input; 
//}

SampleSingleton::~SampleSingleton()
{
	//���� ������ �� Ŭ������ ��ü�� ���� �Ҹ��� �� ������ ��

	// ������ ���� �ʴ´�.
}
