
#include <iostream>
#include <Windows.h>
#include <stdlib.h>


int main()
{
    int player[12] = { 1,2,3,4,5,6,7,8,9,1,5,10 };
    int banker[12] = { 1,2,3,4,5,6,7,8,9,1,5,10 };

    int playerscore = 0;
    int bankerscore = 0;

    int playerinput;
    int playerchoice;


    srand(GetTickCount64());

    int randompick1 = rand() % 12;
    int randompick2 = rand() % 12;
    int randompick3 = rand() % 12;
    int randompick4 = rand() % 12;
    int randompick5 = rand() % 12;
    int randompick6 = rand() % 12;


    int bankerpluscard = banker[randompick5];
    int playerpluscard = player[randompick6];


    int playercard = player[randompick1] + player[randompick2];
    int bankercard = player[randompick3] + player[randompick4];


    std::cout << "======================================================================================" << std::endl;
    std::cout << "바카라에서는 카드를 두장 뽑아 두카드의 숫자를 합칩니다. 두카드의 합중" << std::endl;
    std::cout << "누가 더 높은 카드의 합을 가지고 있는지를 맞추면 되는 게임입니다." << std::endl;
    std::cout << "두장을 뽑는데 두 카드의 합이 10이 넘으면 합에서 10을 뺍니다." << std::endl;
    std::cout << "두패의 카드의 합이 5이하라면 카드를 한장 더 뽑을 수 있게 됩니다." << std::endl;
    std::cout << "======================================================================================" << std::endl;


    while (playerscore <= 3 && bankerscore <= 3)

    {
        std::cout << "게임을 시작하겠습니다." << std::endl;
        std::cout << "======================================================================================" << std::endl;
        std::cout << "현재 플레이어의 점수는 : "<< playerscore << std::endl;
        std::cout << "======================================================================================" << std::endl;
        std::cout << "현재 뱅커의 점수는 : " << bankerscore << std::endl;
        std::cout << "======================================================================================" << std::endl;
        if (bankercard >= 10)
        {
            std::cout << "뱅커의 패 합이 10을 넘어서 10을 빼겠습니다." << std::endl;
            bankercard = bankercard - 10;

        }
        else if (bankercard <= 5)
        {

            std::cout << "뱅커가 카드 한장을 새로 뽑았습니다." << std::endl;
            std::cout << "======================================================================================" << std::endl;
            std::cout << bankercard << std::endl;
            std::cout << bankerpluscard << std::endl;
            bankercard = bankercard + bankerpluscard;
            std::cout << bankercard << std::endl;
            if (bankercard >= 10)
            {
                while (bankercard > 10)
                {
                    bankercard = bankercard - 10;
                }
                std::cout << bankercard << std::endl;
            }

        }

        std::cout << "뱅커의 패가 정해졌습니다." << std::endl;
        std::cout << "======================================================================================" << std::endl;

        std::cout << "플레이어 패를 확인해주십시오." << std::endl;
        std::cout << "======================================================================================" << std::endl;
        std::cout << "첫번째 패 : " << player[randompick1] << "두번째 패 : " << player[randompick2] << std::endl;
        std::cout << "======================================================================================" << std::endl;
        std::cout << "현재 패의 값은 : " << playercard << "입니다." << std::endl;
        std::cout << "======================================================================================" << std::endl;
        if (playercard >= 10)
        {
            std::cout << "패의 합이 10 이상이기에 10을 빼겠습니다." << std::endl;
            playercard = playercard - 10;
            std::cout << "현재 패의 값은 : " << playercard << "입니다." << std::endl;
            std::cout << "======================================================================================" << std::endl;




        }
        else if (playercard <= 5)
        {

            std::cout << "플레이어의 두 패의 합이 5 이하입니다." << std::endl;
            std::cout << "카드를 한장 더 뽑으시겠습니까?" << std::endl;
            std::cout << "뽑는걸 원한다면 1을 원하지 않는다면 2를 입력해주세요." << std::endl;
            std::cout << "======================================================================================" << std::endl;
            std::cin >> playerinput;
            if (playerinput == 1)
            {
                std::cout << "뽑은 카드는 :"<< playerpluscard << "입니다." << std::endl;
                std::cout << "======================================================================================" << std::endl;

                playercard = playercard + playerpluscard;
                std::cout << "뽑은 카드와 합친 값은 :" << playercard << "입니다." << std::endl;
                while (playercard > 10)
                {
                    std::cout << "패의 합이 10을 넘기에 한자리 수가 될때까지 빼겠습니다.    " << std::endl;
                    std::cout << "======================================================================================" << std::endl;
                    playercard = playercard - 10;
                    std::cout << "현재 패의 값은 : " << playercard << "입니다." << std::endl;
                    std::cout << "======================================================================================" << std::endl;
                }
            }

            else if (playerinput == 2)
            {
                std::cout << "카드를 뽑지않고 그대로 진행합니다." << std::endl;
                std::cout << "======================================================================================" << std::endl;

            }
            else if (playerinput >= 3)
            {
                while (playerinput >= 3)
                {
                    std::cout << "잘못 입력 하셨습니다. 1번이나 2번을 입력해주세요." << std::endl;
                    std::cout << "======================================================================================" << std::endl;
                    std::cin >> playerinput;

                }
            }

        }

        std::cout << "선택할 시간입니다." << std::endl;
        std::cout << "======================================================================================" << std::endl;
        std::cout << "자신의 패가 더 높을 것 같다면 1번을 입력해주시고 " << std::endl;
        std::cout << "======================================================================================" << std::endl;
        std::cout << "뱅커의 패가 더 높을 것 같다면 2번을 입력해주세요 ." << std::endl;
        std::cout << "======================================================================================" << std::endl;
        std::cout << "그리고 둘다 비겼다라고 생각되면 3번을 입력해주세요 ." << std::endl;
        std::cout << "======================================================================================" << std::endl;
        std::cin >> playerchoice;


        if (playerchoice == 1)
        {
            if (playercard > bankercard)
            {
                std::cout << "플레이어 패 : " << playercard << "뱅커 패 :" << bankercard << std::endl;
                std::cout << "======================================================================================" << std::endl;
                std::cout << "플레이어 승! 정답입니다! " << std::endl;
                std::cout << "======================================================================================" << std::endl;
                playerscore++;

            }
            else if (playercard < bankercard)
            {
                std::cout << "플레이어 패 : " << playercard << "뱅커 패 :" << bankercard << std::endl;
                std::cout << "======================================================================================" << std::endl;
                std::cout << "뱅커의 승! 아쉽지만 오답입니다. " << std::endl;
                std::cout << "======================================================================================" << std::endl;
                bankerscore++;

            }

        }
        else if (playerchoice == 2)
        {
            if (playercard < bankercard)
            {
                std::cout << "플레이어 패 : " << playercard << "뱅커 패 :" << bankercard << std::endl;
                std::cout << "======================================================================================" << std::endl;
                std::cout << "플레이어 승! 정답입니다! " << std::endl;
                std::cout << "======================================================================================" << std::endl;
                playerscore++;

            }
            else if (playercard > bankercard)
            {
                std::cout << "플레이어 패 : " << playercard << "뱅커 패 :" << bankercard << std::endl;
                std::cout << "======================================================================================" << std::endl;
                std::cout << "뱅커의 승! 아쉽지만 오답입니다. " << std::endl;
                std::cout << "======================================================================================" << std::endl;
                bankerscore++;

            }

        }
        else if (playerchoice == 3)
        {
            if (playercard == bankercard)
            {
                std::cout << "플레이어 패 : " << playercard << "뱅커 패 :" << bankercard << std::endl;
                std::cout << "======================================================================================" << std::endl;
                std::cout << "플레이어 승! 정답입니다! " << std::endl;
                std::cout << "======================================================================================" << std::endl;
                playerscore++;

            }
            else if (playercard != bankercard)
            {
                std::cout << "플레이어 패 : " << playercard << "뱅커 패 :" << bankercard << std::endl;
                std::cout << "======================================================================================" << std::endl;
                std::cout << "뱅커의 승! 아쉽지만 오답입니다. " << std::endl;
                std::cout << "======================================================================================" << std::endl;
                bankerscore++;

            }
        }

        else if (playerchoice >= 4)
        {
            while (playerchoice >= 4)
            {
                std::cout << "잘못 입력 하셨습니다. 1번이나 2번을 입력해주세요." << std::endl;
                std::cout << "======================================================================================" << std::endl;
                std::cin >> playerchoice;

            }
        }
        



        if (playerscore == 3 || bankerscore == 3)
        {
            if (playerscore == 3)
            {
                std::cout << "플레이어가 먼저 3점을 달성하였으므로 게임을 종료합니다." << std::endl;
                return 0;
            }
            else if (bankerscore == 3)
            {
                std::cout << "뱅커가 먼저 3점을 달성하였으므로 게임을 종료합니다." << std::endl;
                return 0;
            }
        }
    }
   

}



