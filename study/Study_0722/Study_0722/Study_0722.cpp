
#include <iostream>

int player1;
int player2;

int score1;
int score2;

int main()
{
	while (score1 < 10 && score2 < 10)// 10보다 작을때 계속 진행하게 함 이유는 여러변수가 생길 수 있기에 10점 설정
		// 3점 먼저 달성시 게임은 끝남
	{
		std::cout << "---------------------------------------------------------------------" << std::endl;
		std::cout << "player1  현재 score :" << score1 << std::endl;
		std::cout << "player2  현재 score :" << score2 << std::endl;
		std::cout << "---------------------------------------------------------------------" << std::endl;
		std::cout << "1(가위),2(바위),3(보) 중에 골라주세요 ." << std::endl;
		std::cout << "---------------------------------------------------------------------" << std::endl;
		std::cout << "Player1의 숫자를 입력해주세요." << std::endl;
		std::cin >> player1;
		switch (player1)
		{
		case 1:
			std::cout << " 가위를 선택하셨습니다." << std::endl;
			break;
		case 2:
			std::cout << " 바위를 선택하셨습니다." << std::endl;
			break;
		case 3:
			std::cout << " 보를 선택하셨습니다." << std::endl;

			return 0;
		}

		std::cout << "Player2의 숫자를 입력해주세요." << std::endl;
		std::cin >> player2;

		switch (player2)
		{
		case 1:
			std::cout << " 가위를 선택하셨습니다." << std::endl;
			break;
		case 2:
			std::cout << " 바위를 선택하셨습니다." << std::endl;
			break;
		case 3:
			std::cout << " 보를 선택하셨습니다." << std::endl;

			return 0;
		}
		
		
		
		if (player1 < 1 || player1 > 3)
		{
			std::cout << " player1 :  잘못된 값을 입력해 1점 깎입니다. " << std::endl;
			score1--;	
		}
		else if (player2 < 1 || player2 > 3)
		{
			std::cout << " player2 :  잘못된 값을 입력해 1점 깎입니다. " << std::endl;
			score2--;
		}
		if (player1 == 1)
		{
			
			if (player2 == 1)
			{
				std::cout << " 비겼습니다! " << std::endl;

			}
			else if (player2 == 2)
			{
				std::cout << " player1이 졌습니다. " << std::endl;
				std::cout << " player2의 점수가 1점 추가됩니다. " << std::endl;
				score2++;
			}
			else if (player2 == 3)
			{
				std::cout << " player2가 졌습니다. " << std::endl;
				std::cout << " player1의 점수가 1점 추가됩니다. " << std::endl;
				score1++;
			}
			

		}
		if (player1 == 2)
		{
			if (player2 == 1)
			{
				std::cout << " player2가 졌습니다. " << std::endl;
				std::cout << " player1의 점수가 1점 추가됩니다. " << std::endl;
				score1++;

			}
			else if (player2 == 2)
			{
				std::cout << " 비겼습니다! " << std::endl;
			}
			else if (player2 == 3)
			{
				std::cout << " player1이 졌습니다. " << std::endl;
				std::cout << " player2의 점수가 1점 추가됩니다. " << std::endl;
				score2++;
			}
		}
		if (player1 == 3)
		{
			if (player2 == 1)
			{
				std::cout << " player1이 졌습니다. " << std::endl;
				std::cout << " player2의 점수가 1점 추가됩니다. " << std::endl;
				score2++;

			}
			else if (player2 == 2)
			{
				std::cout << " player2가 졌습니다. " << std::endl;
				std::cout << " player1의 점수가 1점 추가됩니다. " << std::endl;
				score1++;
			}
			else if (player2 == 3)
			{
				std::cout << " 비겼습니다! " << std::endl;
			}
		}
		
		if (score1 == 3)
		{
			std::cout << " -------------------------------------------------------------------------" << std::endl;
			std::cout << " Player1 : 3점을 먼저 달성해 승리하였습니다. " << std::endl;
			return 0;
		}
		else if (score2 == 3)
		{
			std::cout << " -------------------------------------------------------------------------" << std::endl;
			std::cout << " Player2 : 3점을 먼저 달성해 승리하였습니다." << std::endl;
			return 0;
		}

	}

}