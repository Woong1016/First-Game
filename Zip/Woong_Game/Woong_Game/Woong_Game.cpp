

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <vector>

#include "main.h"
#include "nayounseok.h"




using namespace std; 
int main()
{

    nayounseok* nazzang = new nayounseok();

	cout << "당신은 어지러운 머리를 붙잡고 일어납니다." << endl;
	system("pause");
    cout << "----------------------------------------------------------" << endl;
	cout << "처음보는 환경에 당황한 당신은 주위를 둘러보지만 한번도 본적 없는 집입니다. " << endl;
	cout << "당신은 어지러운 상태였지만 빨리 이곳을 탈출부터 하자는 생각으로 자리에서 일어납니다." << endl;
    cout << "----------------------------------------------------------" << endl;
	system("pause");
    cout << "----------------------------------------------------------" << endl;
	cout << "아무키나 누르면 게임이 시작됩니다." << endl;


	while (true)
	{
        system("cls");
        std::cout << "##########################################################\n";
        std::cout << "#     [그림]                 _________                   #\n";
        std::cout << "#                            |        |                  #\n";
        std::cout << "#                            |  침대  |                  #\n";
        std::cout << "#                            |_______ |                  #\n";
        std::cout << "#                                                        #\n";
        std::cout << "#         _________                     ________         #\n";
        std::cout << "#        |         |                   |        |        #\n";
        std::cout << "#        |  의자   |                   | 서랍장 |        #\n";
        std::cout << "#        |_________|                   |________|        #\n";
        std::cout << "#                                                        #\n";
        std::cout << "#    카펫                         ____                   #\n";
        std::cout << "#                                |    |                  #\n";
        std::cout << "#                                | 문 |                  #\n";
        std::cout << "#                                |____|                  #\n";
        std::cout << "##########################################################\n";

        cout << "탐색하고 싶은 사물의 이름을 입력하면 살펴볼 수 있습니다. " << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "아이템을 입력하면 현재 자신의 아이템을 확인할 수 있습니다. " << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "무엇을 할까? " << endl;

        
        cin >> input;

        
        if (input == painting)
        {
            nazzang->Painting();
            
        }
        else if (input == bed)
        {
            nazzang->Bed();
        }
        else if (input == chair)
        {

            
            nazzang->Chair();

           
        }


        else if (input == drawar)
        {
            nazzang->Drawer();
        }


        else if (input == rug)
        {   
            system("pause");
       
          if (scorerug == 0)
          {
            
            nazzang->Rug();
            scorerug++;
          }
          else if (scorerug > 0)
          {
            std::cout << "쪽지에는 3: 8 이라고 적혀있다." << std::endl;
            system("pause");
           }
         
        }



        else if (input == door)
        {
            
            nazzang->Door();

            
        }


        else
        {
            
            cout << "잘못 입력 하셨습니다. 다시 확인해주세요. " << endl;
            system("pause");
        }


	}




}

