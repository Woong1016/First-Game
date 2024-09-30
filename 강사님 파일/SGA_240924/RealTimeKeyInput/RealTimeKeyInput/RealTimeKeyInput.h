#pragma once

// 실시간 키 입력 확인하는 클래스
#include <conio.h> // 콘솔 입출력 기능 사용

class RealTimeKeyInput
{

public: // 어디서든 부를 수 있는 데이터

    // 정적 함수 : 객체로 만들지 않고 직접 호출로 사용 가능

    static bool KeyPressed() // "키를 눌렀는가?" 하는 것을 판단하는 함수
    {
        return _kbhit();     // _kbhit() 기능을 소개합니다 :
                             // 키보드에 눌린 키가 있는지 확인하는 c++ 기능
                             // 정확하게는 키보드 입력으로 인해, 컴퓨터가 받은
                             // 키 문자 코드가 있는지를 확인하는 것
                             // 그러므로 화살표 같은 특수 문자나 한글을 입력할 경우
                             // 문자 코드가 2바이트가 되어 입력이 두 번 들어간다
    }
    
    static int ReadKeyPressed()
    {
        int result = _getch();  // _getch() : 눌린 키가 무엇인지 읽는 기능
        return result;          // 반환
    }

};

