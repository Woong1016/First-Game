#pragma once

namespace CustomNameSpace1
{

	//���� �����̽� �ӿ� �Լ� �ۼ��ϱ�
	int Operation(int x, int y) // ����̶�� �̸��� �Լ�
	{
		return x + y;
	}
	//�ۼ��� �Լ��� CustomNameSpace1�� �̸��ӿ� ���Եȴ�
	int Mult(int x, int y) // ����̶�� �̸��� �Լ�
	{
		return x + y;
	}
}// ; ���ʿ�


namespace CustomNameSpace2

{
	int Operation(int x, int y) // ���� �Ȱ��� �̸��� �Լ�
	{

		return x - y;
	}

	// ���� �ۼ��� �Լ��� CustomBNamespace1�� �̸��ӿ� ���Եȴ�
	//�ۼ��ϴ� �Լ��� �󸶵��� �߰� ����
	
}


