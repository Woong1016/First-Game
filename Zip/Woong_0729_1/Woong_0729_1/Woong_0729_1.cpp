

#include <iostream>

int main()
{
	int input;
	int input2;

	std::cout << "당신의 나이를 입력해주세요" << std::endl;
	std::cin >> input;
	if (input == 24)
	{
		std::cout << "나이를 보아하니 혹시 박진웅입니까?" << std::endl;
		std::cin >> input2;
		if (input2 == 1)
		{
			std::cout << "당신은 곧 25살 아저씨입니다." << std::endl;
		}
		else if (input2 != 2)
		{
			std::cout << " 뭐여 당신 누구여" << std::endl;

		}
	}
	else
	{
		std::cout << "누구세요?" << std::endl;
	}
}

