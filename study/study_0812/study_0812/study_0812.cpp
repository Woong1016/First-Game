

#include <iostream>

//void add(int x, int y);
void add2(int x, int y);
//void add3(int Xptr, int Yptr);
void add4(int x, int y);

int input;


int main()
{
    
    //add(500, 600);
    add2(1500, 2000);
    //add3( 20, 30 );
    add4(400, 300);
    
}

//void add(int x, int y)
//{
//    int XY;
//
//    XY = x + y;
//    
//    std::cout << "x + y 의 값     :"  << XY << std::endl;
//
//    int* xPtr = &x;
//    *xPtr = 800;
//    int* yPtr = &y;
//    *yPtr = 1000;
//
//    XY = x + y;
//
//    std::cout << " 포인터 변수를 사용해 값을 바꾼x + y 의 값     :" << XY << std::endl;
//
//}
void add2(int x, int y)
{
    

   x = x + y;

    std::cout << "x + y 의 값     :" << x<< std::endl;

  int* xPtr = &x;
    *xPtr = 800;
   int* yPtr = &y;
    *yPtr = 1000;

    x = x + y;

    std::cout << " 포인터 변수를 사용해 값을 바꾼x + y 의 값     :" << x << std::endl;

}
//void add3(int* Xptr , int* Yptr) // 포인터 변수끼리 더하거나 사칙연산은 불가능함
//{
//   
//    
//    
//}

void add4(int* x, int y)
{


    int X = *x + y;

    std::cout << " 포인터 변수를 사용해 값을 바꾼x + y 의 값  :" << X<< std::endl;

    *x = 560;

    

    std::cout << " 포인터 변수를 사용해 값을 바꾼x + y 의 값 2 :" << X << std::endl;


    



}
