#include "Student.h"

void Student::GoAcadamy()
{
	std::cout << "�п����� �ʹ� ���� ������" << std::endl;


}

void Student::GoDoctorAsCitizen()
{
	GoDoctor(); // �θ� Ŭ���� (=�ù� )��� �Ẹ��

	// �߰� Ȯ�� : Ȥ�� �θ��� �θ� (=�ΰ��� ��Ī ) ��ɵ� ������?
	Workout(); // �ȴ� ! �л�-> �ù� -> �ΰ����μ� �ΰ� �Լ� ���� ȣ�� ����
}
