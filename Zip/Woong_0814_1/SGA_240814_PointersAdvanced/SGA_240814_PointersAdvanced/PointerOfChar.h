#pragma once

void PointerOfChar()
{
    // ���� �ð��� �츮�� �˾ƺ�... ���� �̻��� �����͸� �˾ƺ��ô�.

    char c = 'A'; // ����� ���̴� ���� ����

    char* cPtr = &c; // �׸��� ����� ���̴� ���� ������

    // �� �� ���� �� ����. ������ ����� �غ���?

    std::cout << "----------------------------" << std::endl;
    std::cout << "���ڸ� ����� ������ ���� Ȯ��" << std::endl;
    std::cout << "----------------------------" << std::endl;

    std::cout << "���� c�� �� : " << c << std::endl;
    std::cout << "���� c�� �ּ� : " << &c << std::endl;
    std::cout << "���� c�� ������ : " << cPtr << std::endl;
    std::cout << "�������� ���� ���� : " << *cPtr << std::endl;
}