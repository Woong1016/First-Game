#include "Student.h"

void Student::GoAcadamy()
{
	std::cout << "학원가기 너무 좋다 ㅎㅎㅎ" << std::endl;


}

void Student::GoDoctorAsCitizen()
{
	GoDoctor(); // 부모 클래스 (=시민 )기능 써보기

	// 추가 확인 : 혹시 부모의 부모 (=인간을 지칭 ) 기능도 써질까?
	Workout(); // 된다 ! 학생-> 시민 -> 인간으로서 인간 함수 역시 호출 가능
}
