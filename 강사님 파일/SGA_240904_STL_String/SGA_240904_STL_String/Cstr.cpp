#include "Cstr.h"

void Cstr::Run()
{
    // 문자 포인터 변수 만들기
    char* word = new char[129];

    // 새 문자 만들어서 길이 측정하기
    const char* newWord = "피카츄, 라이츄, 파이리, 꼬부기, 버터플, 야도란";
    int length = strlen(newWord);

    // 위에서 만든 새 문자를 원래 변수에 복붙하기
    strcpy_s(word, length + 1, newWord);

    // 문자를 자른 나머지가 들어갈 곳 만들기
    char* remains = NULL;

    // 문자를 잘라서 새로운 문자열 만들기

    char* wordSplit = strtok_s(word, ",", &remains); // 한 번 잘린다
    std::cout << wordSplit << std::endl;

    wordSplit = strtok_s(remains, ",", &remains); // 자른 걸 또 자른다
    std::cout << wordSplit << std::endl;

    // 위 코드를 정해진 수만큼 반복하거나
    for (int i = 0; i < 4; ++i) {}

    // 위 코드를 "나머지 문자"가 더 이상 남지 않을 때까지 반복하거나...
    while (remains != "") {}
    while (remains) {} // 이렇게 줄여쓸 수 있음 (의미가 통함)

    // {} 안의 내용은 (혹은 while 조건이 맞는지 확인) -> 각자 완성
}
