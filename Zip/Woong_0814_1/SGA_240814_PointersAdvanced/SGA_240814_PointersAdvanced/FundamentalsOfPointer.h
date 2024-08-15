#pragma once

// 결과 출력 함수 (선언)
void ShowResult(int original, int opTerm, char opCode, int result);

// 포인터 변수를 사용하는 함수를 내용까지
// * 편의상 헤더 내에서 작성합니다. (권장x)

void AddPtr(int* baseTerm, int opTerm) // 선언에 쓰인 * : 메모리 주소
{
    int original = *baseTerm;       // 연산 전에 확인된 원래의 숫자를 한번 더 기록
                                    // (새 이름 = 새 위치 = 별개 변수 = 복사본)
    *baseTerm = *baseTerm + opTerm; // 변수 이름에 쓰인 * : 거기 있는 실제 값

    ShowResult(original, opTerm, '+', *baseTerm);
    // "원래 데이터의 사본에, 연산항을, 이렇게 계산했더니, 새로 바뀐 원본이 되었어요"
}

void SubtractPtr(int* baseTerm, int opTerm)
{
    int original = *baseTerm;
    *baseTerm = *baseTerm - opTerm;
    ShowResult(original, opTerm, '-', *baseTerm);
}

void MultiplyPtr(int* baseTerm, int opTerm)
{
    int original = *baseTerm;
    *baseTerm = *baseTerm * opTerm;
    ShowResult(original, opTerm, '*', *baseTerm);
}

void DividePtr(int* baseTerm, int opTerm)
{
    int original = *baseTerm;
    int remains = 0; // 나머지
    if (opTerm != 0)
    {
        remains = *baseTerm % opTerm;
        *baseTerm = *baseTerm / opTerm;
    }
    else
    {
        std::cout << "0으로 나눌 수 없습니다. 결과를 0으로 설정합니다." << std::endl;
        *baseTerm = 0;
    }
    ShowResult(original, opTerm, '/', *baseTerm);
    ShowResult(original, opTerm, '%', remains);
}

void ShowResult(int original, int opTerm, char opCode, int result)
{
    // 다른 함수에서 계산한 결과를 출력만 하는 함수
    // 메모리야 어디 있는 숫자 확인만 되면 되니까 포인터가 아니어도 된다

    std::cout << "------------------------" << std::endl;
    std::cout << opCode << " 연산 결과 출력" << std::endl;
    std::cout << original << " " << opCode << " " << opTerm << " = " << result << std::endl;
    std::cout << "------------------------" << std::endl;
}

void HomeWorkSample()
{
    // 과제 내용 : 포인터 사칙연산 만들어 써 보기

    int hwFirst = 100;
    int hwSecond = 33;

    //hwFirst 변수 내용 확인
    std::cout << "테스트 대상 숫자는 " << hwFirst << std::endl;

    AddPtr(&hwFirst, hwSecond);     //더하기
    MultiplyPtr(&hwFirst, hwSecond);//곱하기

    SubtractPtr(&hwFirst, hwSecond);//빼기
    DividePtr(&hwFirst, hwSecond);  //나누기

    // 변수 이름 앞에 & 연산자 : "그 데이터가 기록된 진짜 메모리 주소 위치"
    // ** 두 번째 매개변수(연산항) : 이 숫자는 안 바뀌어도 된다.
    //                             여기서 필요한 건 오직 숫자 그 자체뿐.
    //                             그러므로 포인터 변수가 아니어도 된다
    //                             (물론 포인터 변수여도 된다)

    // 사용한 함수의 최종 결과를 출력 (hwFirst 숫자는 바뀌었는가?)
    std::cout << "함수 연속 실행 후 최종 결과는 " << hwFirst << std::endl;
}