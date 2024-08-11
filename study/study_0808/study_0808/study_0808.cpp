#include <iostream>
#include <Windows.h>
#include <stdlib.h>

int main()
{
    srand(GetTickCount64());

    int input;
    int arr[25];
    int arr2[25];

    // 빙고판 초기화
    for (int i = 0; i < 25; i++)
    {
        arr[i] = i + 1;   // 플레이어의 빙고판
        arr2[i] = i + 1;  // 컴퓨터의 빙고판
    }

    std::cout << "빙고 게임에 오신걸 환영합니다." << std::endl;
    system("pause");

    // 플레이어 빙고판 섞기
    for (int i = 0; i < 100; i++)
    {
        int arrA = rand() % 25;
        int arrB = rand() % 25;
        int temp = arr[arrA];
        arr[arrA] = arr[arrB];
        arr[arrB] = temp;
    }

    // 컴퓨터 빙고판 섞기
    for (int i = 0; i < 100; i++)
    {
        int arrC = rand() % 25;
        int arrD = rand() % 25;
        int temp2 = arr2[arrC];
        arr2[arrC] = arr2[arrD];
        arr2[arrD] = temp2;
    }

    // 플레이어의 빙고판 출력
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

    // 컴퓨터의 빙고판 출력
    std::cout << "컴퓨터의 빙고판." << std::endl;
    for (int i = 0; i < 25; i++)
    {
        std::cout << arr2[i] << "\t";
        if (i == 4 || i == 9 || i == 14 || i == 19)
        {
            std::cout << " \n";
        }
    }
    std::cout << "\n==========================================================" << std::endl;


    std::cout << "플레이어가 번호를 입력할 차례입니다." << std::endl;
    std::cout << "번호를 입력해주세요: ";
    std::cin >> input;

    // 입력된 번호를 플레이어의 빙고판에서 0으로 바꾸기
    //bool found = false;
    for (int i = 0; i < 25; i++)
    {
        if (arr[i] == input)
        {
            arr[i] = 0;  // 숫자를 0으로 변경
            //found = true;
            //break;
        }
    }


    system("cls");
    std::cout << "플레이어 1의 빙고판 (업데이트됨):" << std::endl;
    for (int i = 0; i < 25; i++)
    {
        std::cout << arr[i] << "\t";
        if (i == 4 || i == 9 || i == 14 || i == 19)
        {
            std::cout << " \n";
        }
    }

    // 빙고 종료 조건을 설정하거나 다음 입력을 기다릴 수 있음

}