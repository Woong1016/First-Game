#pragma once

void PointerOfChar()
{
    // 지난 시간에 우리가 알아본... 조금 이상한 포인터를 알아봅시다.

    char c = 'A'; // 평범해 보이는 문자 변수

    char* cPtr = &c; // 그리고 평범해 보이는 문자 포인터

    // 별 거 없을 것 같죠. 하지만 출력을 해보면?

    std::cout << "----------------------------" << std::endl;
    std::cout << "문자를 사용한 포인터 변수 확인" << std::endl;
    std::cout << "----------------------------" << std::endl;

    std::cout << "문자 c의 값 : " << c << std::endl;
    std::cout << "문자 c의 주소 : " << &c << std::endl;
    std::cout << "문자 c의 포인터 : " << cPtr << std::endl;
    std::cout << "포인터의 실제 내용 : " << *cPtr << std::endl;
}