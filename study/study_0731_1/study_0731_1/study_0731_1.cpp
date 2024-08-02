#include <iostream>

int AA(int a,int b );
void BB(int c, int d);


int main()
{
	
	AA(30, 20);	// int
	
	BB(140,10);		// void 

	//std::cout << AA(30,20) << std::endl; // 매개변수 지정 일단 실행만하기 위해 실행만 진행

	//std::cout << BB(30, 20) << std::endl; // void 에서는 return에 변수 설정 및
											// 호출이 가능하지 않음

}
int AA(int a , int b)
{
	std::cout << "a+b의 값은 :"  << std::endl;


	int aa = a + b;

	std::cout << "a+b의 값은 :" << aa<< std::endl;
	
	int bb = a - b;

	std::cout << "a-b의 값은 :" << bb << std::endl;

	int cc = a * b;

	std::cout << "a * b의 값은 :" << cc << std::endl;

	bool dd = a < b;

	std::cout << "a보다 b의 값이 더 높은가? :" << dd << std::endl;

	return 0;

}
void BB(int c, int d)
{
	

	int aa = c + d;

	std::cout << "c+d의 값은 :" << aa << std::endl;

	int bb = c - d;

	std::cout << "c-d의 값은 :" << bb << std::endl;

	int cc = c * d;

	std::cout << "c * d의 값은 :" << cc << std::endl;

	bool dd = c < d;

	std::cout << "c보다 d의 값이 더 높은가? :" << dd << std::endl;

	//return ; // void 에는 굳이 return 이 필요없다. 굳이 쓰고 싶다면 
				// 변수 선언하지 말고 return;만
}