#pragma once

void PointerPrincipals()
{
    // ������ ����


    // 0. ���� �������� �ǹ�

    // - ������ �ڷ���, �̸�, ������ �̷������
    // - �� �� '�̸�'�� �̸����� �ƴ� �� �̸��� ���� �޸� �ּұ����� ����Ų��
    // - ���� ������ �̸� �տ� & �����ڸ� �ٿ�, ������ �޸� �� ��ġ�� �� �� �ִ�

    // - ���� ������ ���� ���� ���� ��, �̸��� �ƴ� �޸� �ּҸ� ���ؼ��� �� �� �ִ�
    // - �̷��� �޸� �ּҸ� �Ű��� ������ �ٷ�� ���α׷����� ������ ���� ����,

    // - �ٿ��� '����Ŵ' Ȥ�� "������"��� �θ���.


    // 1. �������� ����

    // - ���� �տ� &�� ���̸� �޸��� �ּҸ� �� �� �ִ�
    //   �̸� ������� �Ѵ�.

    int a = 0;
    a; // 0�̶�� ��.
    &a; // 0�̶�� ���ڰ� �� �ִ� �޸� �ּҶ�� ��.

    // - �� �޸� �ּҸ� ������ ������ ������ ������ �����̴�.
    // - ������ ������ �����ϴ� ���� �ڷ��� �ڿ� *�� �ٿ��� �����Ѵ�.
    // - ������ ������ �ٿ� �����Ͷ���� �Ѵ�.

    int* aPtr = &a; // [int�� �ڷᰡ �ִ� ��]�� ������ �ϴ� ����
                    // ���⼭�� a�� ��, 0�� �ִ� �޸� �ּҸ� ������ �޴´�


    // 2. �������� ���� ȣ��

    // - ������ ������ ȣ���ϸ� �޸� �ּҰ� ���´�.

    aPtr; // a�� �ִ� �޸� �ּҶ�� ��.
          // &a�� ����.

    // - �ٸ� ������ ����� ������ ������ �ٽ� ȣ���� ��, �̸� �տ� *�� ���̸�
    //   �ش� �޸� �ּҿ� �ִ� ���� ������ ���� ���´�.
    //   �̷��� �޸� �ּ��� ���� ���� ���� ���� ��������� �Ѵ�.

    *aPtr; // [a�� �ִ� �޸� �ּ�...] [...�� ��ġ] �� �ִ� ���̶�� ��.
           // a�� ����.

    // ���� Ȯ���� ���� ���

    std::cout << "������ ���� Ȯ�� : ��¿�" << std::endl;
    
    std::cout << "------------------------" << std::endl;
    
    std::cout << "���� a :" << a << std::endl;            // ����
    std::cout << "���� a�� �ִ� �� :" << &a << std::endl;  // �޸� �ּ�
    
    std::cout << "------------------------" << std::endl;

    std::cout << "���� a�� ������ :" << aPtr << std::endl; // ������ ����
    std::cout << "�������� ���� ���� :" << *aPtr << std::endl; // ������

    std::cout << "------------------------" << std::endl;


	// �߰� ���� : �������� ���� �ǹ̸� �ٽ� ���ƺ���
	// "�ּ�" �̴� �׸��� �������� ������ ���̳� ô���� �ǹ̰� ����
	//(�׺��ٴ� ���� "��ǥ" �� ������ )

	// int = ���ڤ�
	
	// ������ int* = ���� �ƴ� (���� �����Ͱ� �ִ� ��ǻ���� ��򰡶� ��)


	// ���� �Ʒ� ������ �������� �ʴ´�.

	int* bptr = &a; // �����Ϳ� �̾� �� �ٸ� �����Ͱ� �ִٰ� �� ��
	// aptr = aPtr + bPtr; // �̷��� �����ͳ��� ��Ģ������ �� ���� ����

	// �������ڸ� ���빮�� ���빮�� ������ �� ���� �Ͱ� ���

	// ��� ��ǥ�μ��� �߰� ������ ����
	//bPtr = aPtr + 1; // �̰� �ǳ�? �翬�� �ȴ�.

	// �� ���� ���ڸ� ���빮���� �������� �� ���� ��
	// (���ǿ� �ִ� �ּҴ� �ƴ�����) �뷫 �ǹ̰� �����ϴ� �Ͱ� ����

	// �̺κ��� ���߿� ����

}
