// SGA_240809_SampleErrorScenario.cpp

// 이 파일은 8월 12일에 진행할 진도 과정의
// 필요성을 이해하기 위한 가짜 오류를 고의로 일으킵니다.

// 현상에 대한 정답 힌트...는 이미 우리가 배운 사실 속에 있습니다.

// (복습 속 힌트 : "변수는 자료형, 자료의 이름, 진짜 숫자라는
//                 서로 다른 존재의 조합으로 이루어져 있습니다.")

// * 이 부분에 대해 예습하실 분은... 다음 키워드를 한번 검색해주세요.

// "C++" 그리고 "포인터"

#include <iostream>

// 함수 선언

void ChangeFromThisTo(int from, int to);
// -> from, to라는 숫자 둘을 받아, from을 to로 바꾸는 함수...로 계획

int main()
{
    int firstNumber = 100; // 첫 숫자는 100
    int lastNumber = 9999; // 마지막 숫자는 9999

    // main() 내의 변수가 잘 만들어졌음을 확인하기 위한 출력

    std::cout << "앱에서 만든 첫 번째 숫자 : " << firstNumber << std::endl;
    std::cout << "앱에서 만든 바꾸려는 숫자 : " << lastNumber << std::endl;

    // 숫자 바꾸기 함수 실행

    ChangeFromThisTo(firstNumber, lastNumber); // 첫 숫자를 마지막 숫자로!

    // 함수 실행에 대한 최종 결과도 출력

    std::cout << "최종 결과 확인 : " << firstNumber << std::endl;

    // 예상 결과 : 함수 실행을 통해 100이 9999로 바뀐다

    // 자 실행해봅시다!
}

void ChangeFromThisTo(int from, int to)
{
    // 변수가 잘 들어왔음을 확인하기 위한 출력

    std::cout << "매개변수 from 자리에 받은 인수 : " << from << std::endl;
    std::cout << "매개변수   to 자리에 받은 인수 : " << to << std::endl;

    // 함수의 본래 목적인 "from을 to로 바꾸는 연산"

    from = to;

    // 이 연산이 잘 됐음을 확인하기 위한 출력
    std::cout << "함수 실행 결과, from은 이제부터 : " << from << std::endl;

    // -> 매개변수가 잘 들어왔는지, 연산이 잘 됐는지 모두 확인 가능
    // 이 함수를 main()에서 사용하면 from이 to로 바뀝니다........... 맞죠?
}