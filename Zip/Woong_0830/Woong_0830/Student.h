#pragma once
#include "Citizen.h"// �ù� Ŭ���� �����ϱ�
					// (�ù� �ȿ� �ִ� �ΰ��� �ڵ� �����ϱ�)


class Student : public Citizen //public �θ���: ���� �����̶�� �ĵ� ok



{
public : 

	bool inCourse; // ������ ������ ������ ���ΰ�?
	void GoAcadamy(); 

	void GoDoctorAsCitizen();


	// privat , protected �� ���� �Ƚᵵ �� ��






};

