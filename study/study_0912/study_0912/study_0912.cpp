
#include <map>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

//using namespace std;//이거 사용하면 st::string으로 안해도 됨
int main()
{
    int test1(int input);
    int test2(int input);
    
    std::map<int, std::string>test;
   
    std::pair<int, std::string>pair1 = { 1, "박" };
    std::pair<int, std::string>pair2 = { 2, "진" };
    std::pair<int, std::string>pair3 = { 3, "웅" };
    std::pair<int, std::string>pair4 = { 4, "돼" };
    std::pair<int, std::string>pair5 = { 5, "지" };
    
    test.insert(pair1);
    test.insert(pair2);
    test.insert(pair3);
    test.insert(pair4);
    test.insert(pair5);



    test1(5);
    test2(0);
    

}

int test1(int input)
{
    std::map<int, std::string>test;

    std::pair<int, std::string>pair0 = { 0, "박" };
    std::pair<int, std::string>pair1 = { 1, "진" };
    std::pair<int, std::string>pair2 = { 2, "웅" };
    std::pair<int, std::string>pair3 = { 3, "돼" };
    std::pair<int, std::string>pair4 = { 4, "지" };

    test.insert(pair0);
    test.insert(pair1);
    test.insert(pair2);
    test.insert(pair3);
    test.insert(pair4);


    for (int i = 0; i < input; ++i)
    {
        std::cout << test[i] ;

    }

    return 0;
}
int test2(int input)
{
    std::map<int, std::string>test;

    std::pair<int, std::string>pair0 = { 0, "박" };
    std::pair<int, std::string>pair1 = { 1, "진" };
    std::pair<int, std::string>pair2 = { 2, "웅" };
    std::pair<int, std::string>pair3 = { 3, "돼" };
    std::pair<int, std::string>pair4 = { 4, "지" };

    test.insert(pair0);
    test.insert(pair1);
    test.insert(pair2);
    test.insert(pair3);
    test.insert(pair4);


    std::cout << test[input] << std::endl;



    return 0;
}

