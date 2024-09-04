// study_0902.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstring>
int main()
{
    char* word = new char[129];
    char* word1 = new char[129];
    char* word2= new char[129];
    char* word3 = new char[129];
    char* word4 = new char[129];
    char* word5 = new char[129];

    char* wordRemains = NULL;
    char* wordRemains1 = NULL;
    char* wordRemains2 = NULL;
    char* wordRemains3 = NULL;
    char* wordRemains4 = NULL;
    char* wordRemains5 = NULL;
    //char* word1 = new char[129]
       
    char* Status = new char[129];
    char* name = new char[129];
    
    
    for (int i = 0; i < 7; i++)
    {
        word[i];
        wordRemains[i];
    }

    
    
    strcpy_s(name, 20, "Name : SOFIA,");//Name : SOFIA,
    strcpy_s(Status, 50, "HP: 150,MP:100,STR:500,DEF:10,LUk:100");//: HP: 150,MP:100,STR:10,DEF:10,LUk:100
    
    std::cout << name << std::endl;
    std::cout << Status << std::endl;
    strcat_s(name, 70, Status);
    std::cout << name << std::endl;
    
    word = strtok_s(name, ",", &wordRemains);
    std::cout << word << std::endl;
    word1 = strtok_s(wordRemains, ",", &wordRemains1);
    std::cout << word1 << std::endl;
    word2 = strtok_s(wordRemains1, ",", &wordRemains2);
    std::cout << word2 << std::endl;
    word3 = strtok_s(wordRemains2, ",", &wordRemains3);
    std::cout << word3 << std::endl;
    word4 = strtok_s(wordRemains3, ",", &wordRemains4);
    std::cout << word4 << std::endl;
    word5 = strtok_s(wordRemains4, ",", &wordRemains5);
    std::cout << word5 << std::endl;
    //for (int i = 1; i < 7; i++)
    //{

    //    
    //   //std::cout << word[i] <<std::endl;
    //   
    //    
    //}
   
   
    
    

    
   


}

/*for (int i = 0; i < 7; i++)
    {
        word[i];

        for (int j = 0; j - i < 7; j++)
        {
            word = strtok_s(wordRemains[i], ",", &wordRemains2);

        }
        
    }*/