
#include <iostream>

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

	char c[15] = "제육볶음냠냠";
	std::cout << C << std::endl;
	std::cout << c << std::endl;

	


	int j = 200;

	const int* J = &j;

	//*J = 500; const 사용으로 값 변환 불가능
 
	int i = 100;

	int* I = &i;

	*I = 300;

	// const를 사용하지 않은 포인터 변수는 가능


}

