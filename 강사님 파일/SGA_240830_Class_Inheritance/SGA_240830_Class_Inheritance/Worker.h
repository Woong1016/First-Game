   #pragma once

#include "Citizen.h" // �ù� ����

class Worker : public Citizen // �뵿�ڴ� �ù��� �ڽ� Ŭ����
{
public:

    int payment; // ����
    void Work(); //���ϱ�

    void GoDoctor(); // "���� ����" �׷��� �θ� Ŭ������ ö�ڰ� ����.
                     // -> �θ��� �Լ� ����� �� �Լ��� ����δ�.

    void Drive(); // �� �����ϱ⵵ �������̵��ϱ�
};

  