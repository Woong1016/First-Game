
#include <vector>
#include <iostream>
#include <string>
#include "study.h"
#include <cstdlib>


using namespace std;
int main()
{
	int input;

	
	std::vector<string>data = { "피카츄","야돈","박진웅","피츄","리자몽","꼬부기" };
	std::vector<string>data1 = { "empty","empty","empty","empty","empty","empty" };
	std::vector<string>data2;
	vector<string>::iterator it;


	for (int i = 0; i < 6;++i)
		{
		vec.push_back(i);
		inven.push_back(i);

		}
	
	cout << "플레이어" << "\t" << "보관함"<<"\n" << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << vec[i]<<":"<<data1[i] << "\t" << "\t";
		cout << inven[i]<<":"<<data [i]<<  "\n" << endl;
		 
	}

	cout << "보관함에서 꺼낼 포켓몬의 번호를 입력해주세요" << endl;

	cin >> input;

	if (input >= 0 && input <= vec.size())
	{
		cout <<input<< "을(를) 보관함에서 꺼냅니다." << endl;
		it = data1.begin();

		data1.insert(it + 0, data[input]);

		it = data1.begin();
		data1.erase(it + 5);
		
		data[input] = "empty";

		cout << "아무키나 누르세요." << endl;
		system("pus");

		system("cls");
		for (int i = 0; i < 6; i++)
		{
			cout << vec[i] << ":" << data1[i] << "\t" << "\t";
			cout << inven[i] << ":" << data[i] << "\n" << endl;

		}
		cout << "보관함에서 꺼낼 포켓몬의 번호를 입력해주세요" << endl;

	}
	else
	{
		cout << "입력한 값이 올바르지 않습니다. 다시 입력하세요." << endl;
		cin >> input;
	}

	

}

