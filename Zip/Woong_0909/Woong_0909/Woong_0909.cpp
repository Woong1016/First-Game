
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string input;
    string name ="홍은빈은 변태다";
    
    cout << "홍은빈에 대한 암호를 대시오" << endl;
    cin >> input;

    if (input == name)
    {
        cout << "진리를 아는자군.. 들어와라.." << endl;


    }
    else if(input !=name)
    {
        cout << "이단자군.. 꺼져라.. 다시기회를 주지" << endl;
         cin >> input;
    }

    


}

// 오늘 저녁은 샐러드랑 요거트  ??
//SGA_240909_STL_List (pre) 보기

