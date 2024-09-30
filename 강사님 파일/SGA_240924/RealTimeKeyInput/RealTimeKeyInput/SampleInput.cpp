#include "SampleInput.h"

SampleInput::SampleInput()
{
	number = 0;
	input = 0;

    Run(); // �׳� ��������ڸ��� �˾Ƽ� ����ǵ��� �Ѵ�.
}

SampleInput::~SampleInput()
{
}

void SampleInput::Run()
{
	while (true)
	{
		number++;
		std::cout << "���� ��� Ƚ���� ����մϴ� : " << number << std::endl;

		if (RealTimeKeyInput::KeyPressed()) // "Ű�� ���ȴ°�?"
		{
			input = RealTimeKeyInput::ReadKeyPressed(); // ���� Ű �ڵ� �ޱ�

			std::cout << "------------------------------------" << std::endl;

			std::cout << "Ű �Է��� �޾� ����� �Ͻ� �����մϴ�." << std::endl;
			std::cout << "�Է��� Ű : " << input << std::endl;

			system("pause");
			std::cout << "------------------------------------" << std::endl;

			if (input == 27) // esc Ű�� ���� ��Ȳ
			{
				std::cout << "ESC�� �Է��ϼ����Ƿ� ���� ��Ĩ�ϴ�." << std::endl;
				break;
			}
		}
	}
}
