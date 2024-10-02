#include "nayounseok.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>


void nayounseok::Painting()
{
    nayounseok* nazzang = new nayounseok();

    int inputPainting;
	system("cls");
	std::cout << "기괴하게 생긴 사람이 그려진 그림이 벽에 걸려있다." << std::endl;
	std::cout << "----------------------------------------------------------" <<std:: endl;
	std::cout << "그림을 보니 희미하게 무언가 보이는 것 같다." << std::endl;
	std::cout << "어디를 자세히 들여다 볼까?" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "숫자로 입력해주세요." << std::endl;
    std::cout << "| 1번: 머리 | 2번: 팔 | 3번: 배 | 4번: 다리 | 5번: 취소 |" << std::endl;

    std::cin >> inputPainting;
    switch (inputPainting)
    {
    case 1: // 머리를 볼때
        std::cout << "얼굴이 심하게 찢어져 있는게 사람의 형태가 아닌 것 같다." << std::endl;
        std::cout << "딱히 찾을 수 있는건 없는 것 같다." << std::endl;
        system("pause");
        system("cls");
        nazzang->Painting();

    case 2:  // 팔쪽을 볼때

        std::cout << "팔이 길게 늘어져 있다." << std::endl;
        std::cout << "딱히 찾을 수 있는건 없는 것 같다." << std::endl;
        system("pause");
        system("cls");
        nazzang->Painting();

    case 3: //배를 볼때

        std::cout << "무엇을 먹는지는 모르지만 배가 굉장히 쳐져있다.." << std::endl;
        std::cout << "배에 뭐가 적혀져 있다.." << std::endl;
        std::cout << "2 : 5 라고 적혀져 있다. 무슨뜻일까" << std::endl;
        system("pause");
        system("cls");
        nazzang->Painting();

    case 4: // 다리를 볼 때

        std::cout << "다리가 굉장히 얇다. 그 외에 특이점은 없는 것 같다" << std::endl;
        std::cout << "딱히 찾을 수 있는건 없는 것 같다." << std::endl;
        system("pause");
        system("cls");
        nazzang->Painting();

    case 5: // 취소

        return;

        


    default:
        std::cout << "유효하지 않은 번호입니다. 다시 입력해주세요" << std::endl;
        system("pause");
        system("cls");
        nazzang->Painting();
        
    }
}

void nayounseok::Bed()
{


    nayounseok* nazzang = new nayounseok();
    
    int inputBed;
    int scoreBed = 0;
    system("cls");
    std::cout << "먼지가 꽤 쌓여있는 침대다." << std::endl;
    system("pause");
    std::cout << "쿠션과 이불이 있는데 살펴볼까?" << std::endl;
    std::cout << "| 1번: 쿠션을 살펴본다. | 2번: 이불을 살펴본다. | 3번: 침대 밑을 살펴본다. | 4번: 취소 |" << std::endl;
    std::cin >> inputBed;

    switch (inputBed)
    {
    case 1: // 쿠션
        std::cout << "쿠션 안에 무언가 있는 것 같다..." << std::endl;
        std::cout << "쿠션은 낡아서 찢을 수 있을 것 같다.. 찢어볼까?" << std::endl;
        std::cout << "| 1번: 쿠션을 찢는다. | 2번: 찢지 않는다. |" << std::endl;
        std::cin >> inputBed;
        if (inputBed == 1)
        {
            
            std::cout << "쿠션을 찢으니 작은 쪽지가 나왔다..." << std::endl;
            std::cout << "쪽지에는 1: 6 이라고 적혀져 있다.." << std::endl;

            system("pause");
            nazzang->Bed();
        }
        else
        {
            nazzang->Bed();
        }

    case 2:  // 이불

        std::cout << "먼지가 쌓인 오래된 이불이다. " << std::endl;
        std::cout << "여기서는 쉴 수 없을 것 같다." << std::endl;
        system("pause");

        nazzang->Bed();

    case 3: //침대 밑

        std::cout << "침대 밑은 죽은 바퀴벌레 시체가 가득하다. " << std::endl;
        std::cout << "딱히 뭐가 있을 것 같진 않다." << std::endl;
        system("pause");
        nazzang->Bed();

    case 4:
        return;

    default:

        std::cout << "유효하지 않은 번호입니다. 다시 입력해주세요" << std::endl;
        system("pause");
        system("cls");
        nazzang->Bed();
    }
}

void nayounseok::Chair()
{
    system("cls");
    std::cout << "흔들의자다. 나무로 만들어진 것 같은데 꽤나 낡았다." << std::endl;
    std::cout << "혼자서 움직이고 있다.. 만지면 안될 것 같다." << std::endl;
    system("pause");
    return;
}

void nayounseok::Drawer()
{
    nayounseok* nazzang = new nayounseok();

    system("cls");
    int inputDrawar;
    std::cout << "먼지가 쌓인 나무 서랍장이다.." << std::endl;
    std::cout << "서랍장을 조사해볼까?" << std::endl;
    std::cout << "| 1번: 첫번째 칸 | 2번: 두번째 칸 | 3번: 세번째 칸 | 4번: 취소 |" << std::endl;
    std::cin >> inputDrawar;

    switch (inputDrawar)
    {
    case 1: // 첫번째 칸
        std::cout << "물에 번진 가족사진이 있다.." << std::endl;
        std::cout << "아빠, 엄마, 큰아들, 작은 아들로 보이는 사진이다. " << std::endl;
        std::cout << "다들 물에 번져서 얼굴은 안보이지만 작은 아들은 유독 기괴하게 웃고있는게 보인다." << std::endl;
        system("pause");
        nazzang->Bed();
        

        
    case 2:  // 두번째 칸

        std::cout << "아무것도 없는 것 같다.. " << std::endl;
        
        system("pause");

        nazzang->Bed();

    case 3: //세번째 칸

        std::cout << "먼지만 가득하다.. " << std::endl;
        std::cout << "딱히 뭐가 있을 것 같진 않다." << std::endl;
        
        system("pause");
        std::cout << "서랍이 조금 달그락 거린다. " << std::endl;
        std::cout << "서랍 천장에 붙여져 있던 쪽지가 떨어졌다." << std::endl;
        std::cout << "4: 0 이라고 적혀있다. " << std::endl;
        system("pause");
        nazzang->Bed();

    case 4: 

        return;
    default:

        std::cout << "유효하지 않은 번호입니다. 다시 입력해주세요" << std::endl;
        system("pause");
        system("cls");
        nazzang->Bed();
    }
}




void nayounseok::Rug()
{
    
  

    nayounseok* nazzang = new nayounseok();

    system("cls");
    
    
        std::cout << "더러운 카펫이다" << std::endl;
        system("pause");
        std::cout << "카펫 밑을 조사해보니 쪽지가 있다." << std::endl;
        system("pause");
        std::cout << "3: 8 이라고 적혀있다." << std::endl;
        system("pause");
  }
    

  
    
   


void nayounseok::Door()
{

    nayounseok* nazzang = new nayounseok();

    int input;

    system("cls");

    std::cout << "꽤 견고한 문으로 보인다." << std::endl;
    std::cout << "문고리에 두꺼워보이는 4자리 비밀번호 자물쇠가 걸려있다. " << std::endl;
    std::cout << "4자리 번호를 입력해보자." << std::endl;
    std::cin >> input;

    if (input == 6580)
    {
        system("cls");

        std::cout << "문이 열렸다.. 어딘지도 모르는 곳이지만 " << std::endl;
        std::cout << "도로가 나올 때 까지 무작정 뛰었다." << std::endl;
        std::cout << "뒤에서 누군가 지켜보는 시선이 느껴졌지만" << std::endl;
        std::cout << "무시하고 앞만 보고 달렸다," << std::endl;
        system("pause");
        std::cout << "THE END" << std::endl;
        system("pause");
        exit(0);
    }
    else
    {
        std::cout << "자물쇠는 꿈쩍하지 않는다.. " << std::endl;
        std::cout << "다시 시도해보자.." << std::endl;
        system("pause");
        nazzang->Door();

    }

}
