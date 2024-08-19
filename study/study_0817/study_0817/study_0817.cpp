
#include <iostream>
#include <Windows.h> 
#include <stdlib.h>



int main()
{
	srand(GetTickCount64());
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	for (int i = 0; i < 100; i++)
	{
		int rand1 = rand() % 10;
		int rand2 = rand() % 10;
		int rand3;

		rand3 = arr[rand1];
		arr[rand1] = arr[rand2];
		arr[rand2] = rand3;
	}
	for (int i = 0; i < 10; i++ )
	{
		std::cout << arr[i] << std::endl;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int i = 0; i < 9; i++)
		{

			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i];

				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
	
	/*if (arr[0] > arr[1]) // 실패작
		int temp;

		arr[0] = temp;
		arr[1] = arr[0];
		temp = arr[1];
		


	}*/
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	

}




