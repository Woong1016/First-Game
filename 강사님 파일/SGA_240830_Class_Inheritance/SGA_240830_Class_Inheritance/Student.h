#pragma once

#include "Citizen.h" // �ù� Ŭ���� �����ϱ�
                     // (�ù� �ȿ� �ִ� �ΰ��� �ڵ� �����ϱ�)

class Student : public Citizen // public �θ� ��� : ���� �����̶�� �ĵ� OK
{

public:

    bool inCourse;  // ������ ������ ������ ���ΰ�?
    void GoAcademy(); // �п� ����

    void GoDoctorAsCitizen(); // �θ� Ŭ���� ��� ����

    // private, protected�� ���� �� �ᵵ �ɵ�
};

