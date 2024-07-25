
#include <iostream>
#include <stdlib.h> // 이건 정확히 뭔지 모름
#include <Windows.h>// 랜덤 쓰려면 이거

int main()
{
    srand(GetTickCount64());

    int input1;

    int random1 = rand() % 100;// 랜덤값 1부터 100 까지 하기 위해 100나누기 나머지 값만 출력하게

    int i = 0;

    int w = 101;
    

    std::cout << "랜덤 값이 결정되었습니다." << std::endl;
    std::cout << "1부터 100까지 랜덤으로 정해진 숫자를 맞춰주세요!" << std::endl;
    std::cout << "주어지는 기회는 총 10번입니다! " << std::endl;
    
    

    while(i< 10)
    {
        std::cin >> input1;

        if (input1 == w)
        {
            std::cout << "치트키를 사용하셨습니다. 정답을 공개합니다. " << std::endl;
            std::cout << "정답은 :" << random1 << "이였습니다!" << std::endl;
            return 0;

        }
       
        if (input1 != random1)
        {
            
            std::cout << "땡! 틀렸습니다!! " << std::endl;
            i++;
            int score1 = 10 - i;
            std::cout << "남은 기회는 : " << score1 << "번 입니다!" << std::endl;
            if (input1 < random1)
            {
                std::cout << "입력하신 숫자보다 랜덤값이 더 큽니다! " << std::endl;
            }
            else if (input1 > random1)
            {
                std::cout << "입력하신 숫자보다 랜덤값이 더 작습니다! " << std::endl;

            }
          
        
        }
        else if (input1 == random1)
        {
            std::cout << "정답입니다! " << std::endl;
            i++;
            std::cout << "정답은"<<random1 <<"입니다!"<< std::endl;
            std::cout << "총" << i <<"번 만에 맞추셨습니다!" << std::endl;

        }
        else if(i==10)
        {
            std::cout << "아쉽게도 맞추지 못하셨습니다.. " << std::endl;
            std::cout << "정답은 :"<< random1<< ": 이였습니다." << std::endl;
            return 0;
        }

       
        
    }
   
}

