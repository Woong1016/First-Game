
#include <iostream>
#include <Windows.h> 
#include <stdlib.h>


int main()
{
	int A = 1000;
	const int a = 2000;

	int B = 500;
	const int b = 5000;


	std::cout << A + B << std::endl;
	std::cout << A + a << std::endl;
	std::cout << A + b << std::endl;
	std::cout << A + A << std::endl;
	

	const char* C = "오늘 저녁밥은 제육볶음이다.";

	//char c[15] = "제육볶음냠냠";
	std::cout << C << std::endl;
	//std::cout << c << std::endl;

	


	int j = 200;

	const int* J = &j;

	//*J = 500; const 사용으로 값 변환 불가능
 
	int i = 100;

	int* I = &i;

	*I = 300;

	// const를 사용하지 않은 포인터 변수는 가능


	// A. int a = 0; 이라는 변수를 생성
// B. int* aPtr = &a; 변수도 생성

// C. const int* aCP; 라고 적어보기
// D. int* const aPC; 라고 적어보기
// 
// E. aCP, aPC를 선언한 줄에 각각 값을 넣어 할당해보기
//    (예 : const int* aCP = &a;)
// F. 할당된 값을 다시 불러 바꿔보기
// G. 만들어진 '상수와 포인터를 같이 쓴 변수'를 역참조해보기
// H. 역참조한 코드를 다시 바꿔 보기
//    (예 : *aCP = 100;)




	int u = 500;
	int* uPtr = &u;

	const int* uPC = &u;
	int* const  PCu = &u;

	//*uPC = 8000; // 상수 선언때문에 안됨
	*PCu = 900;// 뭐야 왜 되는건디

	//??? 이게 되네


}

int main2()
{

	int input;
	char a = '*';
	std::cin >> input;
	if (1 <= input)
	{

		std::cout << "int a;" << std::endl;
		std::cout << "int *ptr = &a;" << std::endl;




		if (2 <= input)
		{
			std::cout << "int **ptr2 = &ptr;" << std::endl;

			if (3 <= input)
			{
				std::cout << "int ***ptr3 = &ptr2;" << std::endl;

				for (int i = 4; i <= input; i++)
				{
					std::cout << "int ";

					for (int j = 0; j < i; j++)
					{
						std::cout << a;
					}
					std::cout << "ptr" << i << " = " << "&ptr" << i - 1 << ";" << std::endl;
				}


			}
		}

	}

}

#include <iostream>
#include <Windows.h> 
#include <stdlib.h>



int main3()
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
	for (int i = 0; i < 10; i++)
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





