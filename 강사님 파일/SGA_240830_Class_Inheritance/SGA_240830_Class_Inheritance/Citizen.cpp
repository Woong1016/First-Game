#include "Citizen.h"

void Citizen::Subway()
{
    std::cout << "�� ����� ����ö�� ž�ϴ�." << std::endl;
}

void Citizen::WorkoutAsHuman()
{
    // Human Ŭ������ ��ȣ ������ �Ẹ��

    weight = 100; // ü�� ����
    std::cout << "ü�� �ְ��� : " << weight << std::endl;
    
    Workout();  // �θ� Ŭ���� �Լ� �ҷ�����
}

void Citizen::Driver()
{
    std::cout << "�� ����� �ڵ����� ���ϴ�." << std::endl;
}

void Citizen::GoDoctor()
{
    std::cout << "�� ����� ������ ���ϴ�." << std::endl;
}
