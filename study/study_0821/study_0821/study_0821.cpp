
#include <iostream>
#include "헤더.h"
#include  <stdlib.h>

void ChampionJax();
void ChampionYasuo();
void ChampionYone();
int main()
{
    int input;
    for (int i = 0; i < 20; i++)
    {
        
       

        std::cout << "원하는 챔피언의 번호를 입력하면 정보가 나옵니다." << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << "1번. Jax" << '\t';
        std::cout << "2번. Yasuo" << '\t';
        std::cout << "3번. Yone" << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cin >> input;

        if (input == 1)
        {
            system("cls");
            ChampionJax();
        }
        else if(input == 2)
        {
            system("cls");
            ChampionYasuo();
        }
        else if (input == 3)
        {
            system("cls");
           ChampionYone();


        }
        else
        {
            system("cls");
            std::cout << "번호가 맞지 않습니다. 다시 입력해주세요." << std::endl;
            std::cout << "=========================================================================" << std::endl;
            std::cout << "원하는 챔피언의 번호를 입력하면 정보가 나옵니다." << std::endl;
            std::cout << "=========================================================================" << std::endl;
            std::cout << "1번. Jax" << '\t';
            std::cout << "2번. Yasuo" << '\t';
            std::cout << "3번. Yone" << std::endl;
            std::cout << "=========================================================================" << std::endl;

            std::cin >> input;
        }

    }
   
}
void ChampionJax()
{
    char input2;
    const char* JaxName = "Jax";
    Jax.age = 2000; // 캐릭터의 나이
    Jax.hitPoint = 700 ; // hp , 체력
    Jax.hitPointRestore = 6; // 체력 재생
    Jax.atk= 78 ;	// 공격력
    Jax.atkSpeed = 1.20f;	// 공격 속도
    Jax.def = 50;		// 방어력
    Jax.res= 60; // 마법 저항력
    Jax.range= 5.0f; // 사거리
    Jax.moveSpeed= 4.0f; // 이동속도

    std::cout << "캐릭터의 이름은 :" << JaxName << " 입니다." << std::endl;
    std::cout<<"캐릭터의 나이는 :" << Jax.age <<" 입니다." <<  std::endl;
    std::cout << "캐릭터의 체력은 :" << Jax.hitPoint << " 입니다." << std::endl;
    std::cout << "캐릭터의 체력재생력은 :" << Jax.hitPointRestore << " 입니다." << std::endl;
    std::cout << "캐릭터의 공격력은 :" << Jax.atk << " 입니다." << std::endl;
    std::cout << "캐릭터의 공격속도는 :" << Jax.atkSpeed << " 입니다." << std::endl;
    std::cout << "캐릭터의 방어력은 :" << Jax.def << " 입니다." << std::endl;
    std::cout << "캐릭터의 마법저항력은 :" << Jax.res << " 입니다." << std::endl;
    std::cout << "캐릭터의 공격사거리는 :" << Jax.range << " 입니다." << std::endl;
    std::cout << "캐릭터의 이동속도는 :" << Jax.moveSpeed << " 입니다." << std::endl;
    if (Jax_ == 0)
    {
        std::cout << "==============================================================" << std::endl;
        std::cout << "Jax의 기타 및 특징" << std::endl;
        std::cout << "Jax는 삶은 달걀을 좋아합니다." << std::endl;
    }

    std::cout << '\n';
    std::cout <<"초기 화면으로 돌아가려면 e를 입력해주세요." << std::endl;
    

    while (true)
    {
        std::cin >> input2;
        if (input2 == 'e')
        {
            system("cls");
            main();
        }
        else
        {
            system("cls");
            std::cout << "일치하지 않습니다. 다시 입력하세요" << std::endl;
            //std::cin >> input2;
        }
    }
   

}
void ChampionYasuo()
{
    char input2;
    const char* YasuoName = "Yasuo";
    Yasuo.age = 32; // 캐릭터의 나이
    Yasuo.hitPoint = 600; // hp , 체력
    Yasuo.hitPointRestore = 6; // 체력 재생
    Yasuo.atk = 70;	// 공격력
    Yasuo.atkSpeed = 1.50f;	// 공격 속도
    Yasuo.def = 50;		// 방어력
    Yasuo.res = 60; // 마법 저항력
    Yasuo.range = 6.0f; // 사거리
    Yasuo.moveSpeed = 4.0f; // 이동속도

    std::cout << "캐릭터의 이름은 :" << YasuoName << " 입니다." << std::endl;
    std::cout << "캐릭터의 나이는 :" << Yasuo.age << " 입니다." << std::endl;
    std::cout << "캐릭터의 체력은 :" << Yasuo.hitPoint << " 입니다." << std::endl;
    std::cout << "캐릭터의 체력재생력은 :" << Yasuo.hitPointRestore << " 입니다." << std::endl;
    std::cout << "캐릭터의 공격력은 :" << Yasuo.atk << " 입니다." << std::endl;
    std::cout << "캐릭터의 공격속도는 :" << Yasuo.atkSpeed << " 입니다." << std::endl;
    std::cout << "캐릭터의 방어력은 :" << Yasuo.def << " 입니다." << std::endl;
    std::cout << "캐릭터의 마법저항력은 :" << Yasuo.res << " 입니다." << std::endl;
    std::cout << "캐릭터의 공격사거리는 :" << Yasuo.range << " 입니다." << std::endl;
    std::cout << "캐릭터의 이동속도는 :" << Yasuo.moveSpeed << " 입니다." << std::endl;
    if (Yosuo_ == 1)
    {
        std::cout << "==============================================================" << std::endl;
        std::cout << "Yosuo의 기타 및 특징" << std::endl;
        std::cout << "Yosuo는 바람의 검술을 사용합니다." << std::endl;
    }
    std::cout << '\n';
    std::cout << "초기 화면으로 돌아가려면 e를 입력해주세요." << std::endl;

    while (true)
    {
        std::cin >> input2;
        if (input2 == 'e')
        {
            system("cls");
            main();
        }
        else
        {
            system("cls");
            std::cout << "일치하지 않습니다. 다시 입력하세요" << std::endl;
            //std::cin >> input2;
        }
    }

}
void ChampionYone()
{
    char input2;
    const char* YoneName = "Yone";
    Yone.age = 2000; // 캐릭터의 나이
    Yone.hitPoint = 700; // hp , 체력
    Yone.hitPointRestore = 6; // 체력 재생
    Yone.atk = 78;	// 공격력
    Yone.atkSpeed = 1.20f;	// 공격 속도
    Yone.def = 50;		// 방어력
    Yone.res = 60; // 마법 저항력
    Yone.range = 5.0f; // 사거리
    Yone.moveSpeed = 4.0f; // 이동속도

    std::cout << "캐릭터의 이름은 :" << YoneName << " 입니다." << std::endl;
    std::cout << "캐릭터의 나이는 :" << Yone.age << " 입니다." << std::endl;
    std::cout << "캐릭터의 체력은 :" << Yone.hitPoint << " 입니다." << std::endl;
    std::cout << "캐릭터의 체력재생력은 :" << Yone.hitPointRestore << " 입니다." << std::endl;
    std::cout << "캐릭터의 공격력은 :" << Yone.atk << " 입니다." << std::endl;
    std::cout << "캐릭터의 공격속도는 :" << Yone.atkSpeed << " 입니다." << std::endl;
    std::cout << "캐릭터의 방어력은 :" << Yone.def << " 입니다." << std::endl;
    std::cout << "캐릭터의 마법저항력은 :" << Yone.res << " 입니다." << std::endl;
    std::cout << "캐릭터의 공격사거리는 :" << Yone.range << " 입니다." << std::endl;
    std::cout << "캐릭터의 이동속도는 :" << Yone.moveSpeed << " 입니다." << std::endl;
    if (Yone_ == 2)
    {
        std::cout << "==============================================================" << std::endl;
        std::cout << "Yone의 기타 및 특징" << std::endl;
        std::cout << "Yone는 Yosuo의 형입니다." << std::endl;
    }

    std::cout << '\n';
    std::cout << "초기 화면으로 돌아가려면 e를 입력해주세요." << std::endl;

    while (true)
    {
        std::cin >> input2;
        if (input2 == 'e')
        {
            system("cls");
            main();
        }
        else
        {
            system("cls");
            std::cout << "일치하지 않습니다. 다시 입력하세요" << std::endl;
            //std::cin >> input2;
        }
    }
}
