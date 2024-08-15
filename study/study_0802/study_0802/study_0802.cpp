

#include <iostream>
#include <Windows.h>
#include <stdlib.h>

int main()
{
    srand(GetTickCount64());
    
    #include "H1.h"
  

    int playerscore = 0;
    int comscore = 0;


    for (int i = 0; i < 25; i++)
    {
        arr[i] = i + 1;
        arr2[i] = i + 1;
        comarr[i] = i + 1;

    }


    std::cout << "빙고 게임에 오신걸 환영합니다." << std::endl;
    system("pause");



    for (int i = 0; i < 100; i++)
    {

        int arrA = rand() % 24;
        int arrB = rand() % 24;
        int temp;

        temp = arr[arrA];
        arr[arrA] = arr[arrB];
        arr[arrB] = temp;
    }



    for (int i = 0; i < 100; i++)
    {
        int arrC = rand() % 24;
        int arrD = rand() % 24;
        int temp2;


        temp2 = arr2[arrC];
        arr2[arrC] = arr2[arrD];
        arr2[arrD] = temp2;
    }
    std::cout << "플레이어 1의 빙고판." << std::endl;
    for (int i = 0; i < 25; i++)
    {
        std::cout << arr[i] << "\t";
        if (i == 4 || i == 9 || i == 14 || i == 19)
        {
            std::cout << " \n";

        }

    }
    std::cout << "\n";
    std::cout << "컴퓨터의 빙고판." << std::endl;
    for (int i = 0; i < 25; i++)
    {
        std::cout << arr2[i] << "\t";
        if (i == 4 || i == 9 || i == 14 || i == 19)
        {
            std::cout << " \n";

        }

    }


    for(int i = 0 ; i < 30; i++ )
    {
        std::cout << " \n";
        std::cout << "==========================================================" << std::endl;

        std::cout << "플레이어가 번호를 입력할 차례입니다" << std::endl;
        std::cout << "번호를 입력해주세요." << std::endl;
        std::cin >> input;

        while (input > 0 || input <= 25)
        {

            if (input > 0 && input <= 25)
            {
                for (int i = 0; i < 25; i++)
                {
                    if (arr[i] == input)
                    {
                        arr[i] = 0;

                    }

                }
                for (int j = 0; j < 25; j++)
                {
                    if (arr2[j] == input)
                    {
                        arr2[j] = 0;

                    }
                }

                break;
            }
            else
            {
                std::cout << "값을 잘못 입력하셨습니다." << std::endl;
                std::cout << "다시 입력해주세요" << std::endl;
                std::cin >> input;
            }

        }
        for (int i = 0; i < 100; i++)
        {
            int compick = rand() % 25;
            int compick2 = rand() % 25;

            com = comarr[compick];
            comarr[compick] = comarr[compick2];
            comarr[compick2] = com;
    
        }

      

        std::cout << " \n";
        std::cout << "==========================================================" << std::endl;
        std::cout << "컴퓨터가 숫자를 골랐습니다." << std::endl;
        std::cout << "컴퓨터가 고른 숫자는 :" << com << "입니다." << std::endl;

        for (int i = 0; i < 25; i++)
        {
            if (arr[i] == com)
            {
                arr[i] = 0;

            }

        }
        for (int j = 0; j < 25; j++)
        {
            if (arr2[j] == com)
            {
                arr2[j] = 0;

            }
        }
        //arr[com] = 0;
        //arr2[com] = 0;

        system("pause");


        system("cls");
        std::cout << "플레이어 1의 빙고판." << std::endl;
        for (int i = 0; i < 25; i++)
        {
            std::cout << arr[i] << "\t";
            if (i == 4 || i == 9 || i == 14 || i == 19)
            {
                std::cout << " \n";

            }


        }
        std::cout << " \n";
        std::cout << " \n";
        std::cout << "컴퓨터의 빙고판." << std::endl;
        for (int i = 0; i < 25; i++)
        {

            std::cout << arr2[i] << "\t";
            if (i == 4 || i == 9 || i == 14 || i == 19)
            {
                std::cout << " \n";

            }


        }
        
       
        

        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && arr[4] == 0)
        {
            playerscore++;

        }
        else if (arr[5] == 0 && arr[6] == 0 && arr[7] == 0 && arr[8] == 0 && arr[9] == 0)
        {
            playerscore++;

        }
        else if (arr[10] == 0 && arr[11] == 0 && arr[12] == 0 && arr[13] == 0 && arr[14] == 0)
        {
            playerscore++;

        }
        else if (arr[15] == 0 && arr[16] == 0 && arr[17] == 0 && arr[18] == 0 && arr[19] == 0)
        {
            playerscore++;

        }
        else if (arr[20] == 0 && arr[21] == 0 && arr[22] == 0 && arr[23] == 0 && arr[24] == 0)
        {
            playerscore++;

        }
        //=========================================================================================

        else if (arr[0] == 0 && arr[5] == 0 && arr[10] == 0 && arr[15] == 0 && arr[20] == 0)
        {
            playerscore++;

        }
        else if (arr[1] == 0 && arr[6] == 0 && arr[11] == 0 && arr[16] == 0 && arr[21] == 0)
        {
            playerscore++;

        }
        else if (arr[2] == 0 && arr[7] == 0 && arr[12] == 0 && arr[17] == 0 && arr[22] == 0)
        {
            playerscore++;

        }
        else if (arr[3] == 0 && arr[8] == 0 && arr[13] == 0 && arr[18] == 0 && arr[23] == 0)
        {
            playerscore++;

        }
        else if (arr[4] == 0 && arr[9] == 0 && arr[14] == 0 && arr[19] == 0 && arr[24] == 0)
        {
            playerscore++;

        }

        //=========================================================================================


        else if (arr[0] == 0 && arr[6] == 0 && arr[12] == 0 && arr[18] == 0 && arr[24] == 0)
        {
            playerscore++;

        }
        else if (arr[4] == 0 && arr[8] == 0 && arr[12] == 0 && arr[16] == 0 && arr[20] == 0)
        {
            playerscore++;

        }


        //=========================================================================================


        if (arr2[0] == 0 && arr2[1] == 0 && arr2[2] == 0 && arr2[3] == 0 && arr2[4] == 0)
        {
            comscore++;

        }
        else if (arr2[5] == 0 && arr2[6] == 0 && arr2[7] == 0 && arr2[8] == 0 && arr2[9] == 0)
        {
            comscore++;

        }
        else if (arr2[10] == 0 && arr2[11] == 0 && arr2[12] == 0 && arr2[13] == 0 && arr2[14] == 0)
        {
            comscore++;

        }
        else if (arr2[15] == 0 && arr2[16] == 0 && arr2[17] == 0 && arr2[18] == 0 && arr2[19] == 0)
        {
            comscore++;

        }
        else if (arr2[20] == 0 && arr2[21] == 0 && arr2[22] == 0 && arr2[23] == 0 && arr2[24] == 0)
        {
            comscore++;

        }
        //============================================================================================
        else if (arr[0] == 0 && arr[5] == 0 && arr[10] == 0 && arr[15] == 0 && arr[20] == 0)
        {
            comscore++;

        }
        else if (arr[1] == 0 && arr[6] == 0 && arr[11] == 0 && arr[16] == 0 && arr[21] == 0)
        {
            comscore++;

        }
        else if (arr[2] == 0 && arr[7] == 0 && arr[12] == 0 && arr[17] == 0 && arr[22] == 0)
        {
            comscore++;

        }
        else if (arr[3] == 0 && arr[8] == 0 && arr[13] == 0 && arr[18] == 0 && arr[23] == 0)
        {
            comscore++;

        }
        else if (arr[4] == 0 && arr[9] == 0 && arr[14] == 0 && arr[19] == 0 && arr[24] == 0)
        {
            comscore++;

        }
        //============================================================================================
        else if (arr2[0] == 0 && arr2[6] == 0 && arr2[12] == 0 && arr2[18] == 0 && arr2[24] == 0)
        {
            comscore++;

        }
        else if (arr2[4] == 0 && arr2[8] == 0 && arr2[12] == 0 && arr2[16] == 0 && arr2[20] == 0)
        {
            comscore++;

        }








        std::cout << " \n";
        std::cout << "==========================================================" << std::endl;
        std::cout << "플레이어 점수 :" << playerscore << "컴퓨터 점수  :" << comscore << std::endl;





        if (playerscore == 10 || comscore == 10)
        {
            if (playerscore == 10)
            {
                std::cout << "==========================================================" << std::endl;
                std::cout << "플레이어 점수가 10점을 달성해 플레이어가 승리했습니다."<< std::endl;

                break;
            }
            else if (comscore == 10)
            {
                std::cout << "==========================================================" << std::endl;
                std::cout << "컴퓨터의 점수가 10점을 달성해 컴퓨터가 승리했습니다." << std::endl;

                break;
            }

        }

    }
   

}



 

   



