#include "Citizen.h"

void Citizen::Subway()
{
    std::cout << "이 사람은 지하철을 탑니다." << std::endl;
}

void Citizen::WorkoutAsHuman()
{
    // Human 클래스의 보호 데이터 써보기

    weight = 100; // 체중 설정
    std::cout << "체중 최고점 : " << weight << std::endl;
    
    Workout();  // 부모 클래스 함수 불러오기
}

void Citizen::Driver()
{
    std::cout << "이 사람은 자동차를 몹니다." << std::endl;
}

void Citizen::GoDoctor()
{
    std::cout << "이 사람은 병원에 갑니다." << std::endl;
}
