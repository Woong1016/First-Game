
#include <list>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int test1(std::list<int>::iterator it, int x);
    int test2(std::list<int>::iterator it, int y, int input);
    int test3(std::list<int>::iterator it, int z);
    

    std::list<int>test;
   

    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    std::list<int>::iterator it ;

    it = test.begin();


    cout << "현재 push_back으로 추가되어 있는 숫자들 " << endl;
    for (; it != test.end(); it++)
    {
        cout << *it << endl;
      }

    test1(it,2 );
    test2(it, 2, 4000);
    test3(it, 2);
}

int test1(std::list<int>::iterator it, int x)
{


    std::list<int>test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    it = test.begin();

    for (int i = 0 ; i < x; i++) 
    {
        ++it;
    }

    cout << x << "번째 인덱스 값은" << *it << "입니다" << endl;
    
    
      
    return 0;
}

int test2(std::list<int>::iterator it, int y, int input)
// 매개변수 x는 몇번째에 넣을건지 정하기위해 선언 input은 내가 넣고 싶은 수
{
    std::list<int>test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    it = test.begin();

    for (int i = 0; i < y; i++)
    {
        ++it;
    }

    test.emplace(it, input);

    it = test.begin();

    cout << "현재 emplace를 써서 제대로 들어갔는지 확인 " << endl;
    for (; it != test.end(); it++)
    {
        cout << *it << endl;
    }
    


    return 0;
}

int test3(std::list<int>::iterator it, int z)
//z는 몇번째 함수를 지울건지에 대한 매개변수
{
    std::list<int>test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    it = test.begin();
    
    for (int i = 0; i < z; i++)
    {
        ++it;
    }

    test.erase(it);

    cout << z << "번째에 추가된 함수가 삭제되었습니다. " << endl;

    cout << "삭제된 후 " << endl;

    it = test.begin();

    for (; it != test.end(); it++)
    {
        cout << *it << endl;
    }


    return 0;
}