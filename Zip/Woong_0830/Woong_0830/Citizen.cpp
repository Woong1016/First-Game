#include "Citizen.h"

void Citizen::Subway()
{
	std::cout << "이 사람은 지하철을 탑니다" <<std::endl;

}

void Citizen::WorkoutAsHuman()
{
	// Human 클래스의 보호 데이터 써보기

	weight = 92; // 체중 설정
	std::cout << " 체중 최고점 : " << weight << std::endl;

	Workout(); // 부모 클래스 함수 불러오기
}

void Citizen::Driver()
{
	std::cout << "이 사람은 운전을 합니다" << std::endl;

}

void Citizen::GoDoctor()
{
	std::cout << "이 사람은 병원을 갑니다." << std::endl;

}

// 하핳하하하ㅏ하하하하하하하ㅏ하ㅏ하핳하하하 저보다 나이가 많거나 어릴줄 알았는데 이게

// 갑자기 정신이 혼미해요 저랑 동갑이였다니.. 제가 나이가 많을 줄 알았는데..

//한강가겠습니다 숨참고 럽다이브 이미 늦었습니다 여린 제마음을 갈기갈기 찢으셨습니다 

// 하하하하하 나는 늙은이야 헤헤헤헤 나는 28살이야 하하하하하하하하하 
