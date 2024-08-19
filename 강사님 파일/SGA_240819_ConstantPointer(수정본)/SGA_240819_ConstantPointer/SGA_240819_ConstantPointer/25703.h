#include <iostream>

void ExampleCode25703()
{
    // 입력 받기
    int N;
    std::cin >> N; // 꼭 필요한 입력 외에 다른 불필요한 부분이 있으면 안 됨

    // 무조건 출력하는 문장
    std::cout << "int a;" << std::endl;

    // 이 다음 줄부터가 실제로 숫자에 따라 바뀌는 문장
    for (int i = 0; i < N; ++i)
    {
        std::cout << "int "; // 무조건 들어가는 첫 글자

        for (int j = 0; j <= i; ++j)
        {
            std::cout << "*"; // 포인터 연산자의 개수 = 반복문 순서만큼
        }

        std::cout << "ptr";
        if (i > 0) std::cout << i + 1; // ptr 다음이 몇인지가 i에 의해 결정

        // 포인터가 참조할 대상
        std::cout << " = &";
        if (i == 0) std::cout << "a;"; // 첫 번째 포인터는 변수를 참조
        else if (i == 1) std::cout << "ptr;"; // 두 번째는 첫 번째(숫자x)참조
        else std::cout << "ptr" << i << ";";  // 세 번째부터 이전(숫자o) 참조

        std::cout << std::endl; // 줄 바꾸기

        // 정리 : 문제 자체는 반복문에 대한 응용, 간접적으로 배열에 대한 이해
        //        다만 작성하고 확인하는 과정에서 포인터의 형태를 복습 가능
    }
}