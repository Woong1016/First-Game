

#include <iostream>
#include "Human.h"
#include "Knight.h"
#include "thief.h"
int main()
{
    
    Human* human1 = new Human();  // 기본적인 인간 기본 스텟

    human1->Print();

    for (int i = 0; i < 3; i++)
    {
        std::cout << "\n";

    }

    Thief* thief = new Thief(); // 도적스텟과 이름 및 성별
   
    thief->Print();
    thief->Thiefskill1();
    thief->Thiefskill2();
    thief->Thiefskill3();

    for (int i = 0; i < 3; i++)
    {
        std::cout << "\n";

    }
    

    Knight* knight = new Knight();  // 기사 스텟과 클래스 따로 기사 캐릭터 인적사항 클래스 따로
    knight->Print();
    knight->Knightskill1();
    knight->Knightskill2();
    knight->Knightskill3();


}

