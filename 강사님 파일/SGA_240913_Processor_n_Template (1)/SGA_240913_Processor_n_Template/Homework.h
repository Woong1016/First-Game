#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

// 과제 풀이 요약 (아래쪽 코드 다 보고 돌아와서 읽어주세요.)

// 1. 맵은 두 데이터로 이루어진 한 쌍의 조합을 원소로 삼는 집합입니다.
//    여기서 데이터의 한 쌍을 "페어"라고 하고, 페어의 첫 번째 값을 key
//    두 번째 값을 value로 지칭하기도 합니다.
// 2. 맵은 페어를 짜서 추가함으로써 원소를 더할 수 있습니다.
// 3. 맵은 벡터, 리스트와 같은 자료 구조이므로 반복자와 일부 함수(추가)가 동일
// 4. 맵은 [] 연산자가 일반적인 경우와 다릅니다.
//    맵에는 메모리, 순번의 개념이 강하게 다루어지지 않습니다.
// 
// 5. 맵은 한 데이터(번호, id, 커맨드 등)로
//    다른 데이터(문자, 이름, 필살기 등)를 호출하려고 할 때 편리합니다.
// 6. 맵은 많고 큰 데이터를 메모리 공간에 얽매이지 않고 추가, 삭제할 때 편합니다.
// 7. 맵은 느립니다.
// 8. 맵은 한 번 추가한 key를 바꿀 수 없습니다.
// 9. 맵은 key를 중복해서 입력할 수 없습니다. 중복된 값은 무시됩니다.
//    value는 서로 다른 key와 조합한다면 중복할 수 있습니다.


class Homework
{
public:
    Homework();     // 생성자
    ~Homework();    // 소멸자

    //실행
    void Run();     // main에서는 이거만 실행하면 됩니다.

private:

    // 자료구조
    std::map<int, std::string> dic;

    // 행동들
    void ShowAllWord();                 // 목록 출력
    int GetInput();                     // 입력 받기 (숫자 : 행동)
    int GetNumber();                    // 입력 받기 (숫자 : 삭제시 번호)
    std::string GetString();            // 입력 받기 (문자)

    void AddWord(std::string word);     // 단어 추가
    void RemoveIndex(int index);        // 단어 삭제 (목록 번호로)

    // 추가 응용 기능 알아보기
    bool IsValid(std::string word);     // 적절성 판단 (목록에 중복이 있는가)
    void RemoveWord(std::string word);  // 단어 삭제 (직접 입력)
};

