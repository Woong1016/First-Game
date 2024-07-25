#include <iostream> 

int main()

{
	int WW = 0;
	int input_1;
	int input_2;

	std::cout << "1번 값을 입력해주세요." << std::endl;
	std::cin >> input_1;
	std::cout << "2번 값을 입력해주세요." << std::endl;
	std::cin >> input_2;


	int A = input_1 + input_2;
	std::cout << "1번과 2번 값을 더한 값은"<<A <<std::endl;

	
	int B = input_1 - input_2;
	std::cout << "1번에서 2번을 뺀 값"<<B << std::endl;
	
	int C = input_1 * input_2;
	std::cout << "1번과 2번을 곱한 값"<<C << std::endl;
	
	int D = input_1 / input_2;
	std::cout << "1번에서 2번을 나눈 값"<<D << std::endl;
	

	int E = input_1 % input_2;
	std::cout << "나머지 값" << E << std::endl;
	
	

	bool AA = input_1 < input_2;
	std::cout << "1번값보다 2번값이 더 큰가? :"<<AA << std::endl;
	bool BB = input_1 > input_2;
	std::cout << "2번값보다 1번값이 더 큰가? : " << BB << std::endl;
	bool CC = input_2 < input_1;
	std::cout << "2번값이 1번값보다 더 작은가?  :" << CC << std::endl;
	bool DD = input_2 > input_1;
	std::cout << "2번값이 1번값보다 더 큰가? : " << DD << std::endl;
	bool EE = input_2 >= input_1;
	std::cout << "2번값보다 1번값이 더 작거나 같은가? : " << EE << std::endl;
	bool FF = input_2 <= input_1;
	std::cout << "2번값보다 1번값이 더 크거나 같은가?? :" << FF << std::endl;
	bool GG = input_1 >= input_2;
	std::cout << "1번값보다 2번값이 더 작거나 같은가? :" << GG << std::endl;
	bool HH = input_1 >= input_2;
	std::cout << "1번값보다 2번 값이 더 크거나 같은가? : " << HH << std::endl;

	bool A1 = AA || BB;
	std::cout << "둘중 하나라도 True가 나온다면 True입니다. : " << A1 << std::endl;
	bool A2 = AA && BB; 
	std::cout << "둘중 하나라도 False가 나온다면 False입니다. : " << A2 << std::endl;
	bool A3 = !A1;
	std::cout << "나온 값의 반대로 나옵니다. : " << A3 << std::endl;
	bool A4 = CC == DD;
	std::cout << "일치합니다.. : " << A4 << std::endl;
	bool A5 = EE != FF;
	std::cout << "불일치합니다. : " << A5 << std::endl;

}



