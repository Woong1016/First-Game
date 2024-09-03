// study_0902.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstring>
int main()
{
    char* word = new char[129];
    char* word2 = new char[129];
    char* Status = new char[129];
    char* name = new char[129];
    char* wordRemains = NULL;
    
    strcpy_s(name, 20, "박,진,웅");//Name : SOFIA,
    strcpy_s(Status, 50, "안,녕,하,세,요");//: HP: 150,MP:100,STR:10,DEF:10,LUk:100
    
    std::cout << name << std::endl;
    std::cout << Status << std::endl;
    strcat_s(name, 70, Status);
    std::cout << name << std::endl;
    
    word = strtok_s(name, ",", &wordRemains);
    word2 = strtok_s(wordRemains, ",", &wordRemains);

    
     
    for (int i = 0; i < 5; i++)
    {
       // std::cout << word << wordRemains<<std::endl;

        std::cout << wordRemains << std::endl;
    }
   
   
    
    

    
   


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
