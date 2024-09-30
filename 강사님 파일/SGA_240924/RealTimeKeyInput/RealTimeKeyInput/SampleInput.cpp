#include "SampleInput.h"

SampleInput::SampleInput()
{
	number = 0;
	input = 0;

    Run(); // 그냥 만들어지자마자 알아서 실행되도록 한다.
}

SampleInput::~SampleInput()
{
}

void SampleInput::Run()
{
	while (true)
	{
		number++;
		std::cout << "연산 경과 횟수를 기록합니다 : " << number << std::endl;

		if (RealTimeKeyInput::KeyPressed()) // "키가 눌렸는가?"
		{
			input = RealTimeKeyInput::ReadKeyPressed(); // 눌린 키 코드 받기

			std::cout << "------------------------------------" << std::endl;

			std::cout << "키 입력을 받아 기록을 일시 정지합니다." << std::endl;
			std::cout << "입력한 키 : " << input << std::endl;

			system("pause");
			std::cout << "------------------------------------" << std::endl;

			if (input == 27) // esc 키를 누른 상황
			{
				std::cout << "ESC를 입력하셨으므로 앱을 마칩니다." << std::endl;
				break;
			}
		}
	}
}
