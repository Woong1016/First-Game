#include "Cstr.h"

void Cstr::Run()
{
    // ���� ������ ���� �����
    char* word = new char[129];

    // �� ���� ���� ���� �����ϱ�
    const char* newWord = "��ī��, ������, ���̸�, ���α�, ������, �ߵ���";
    int length = strlen(newWord);

    // ������ ���� �� ���ڸ� ���� ������ �����ϱ�
    strcpy_s(word, length + 1, newWord);

    // ���ڸ� �ڸ� �������� �� �� �����
    char* remains = NULL;

    // ���ڸ� �߶� ���ο� ���ڿ� �����

    char* wordSplit = strtok_s(word, ",", &remains); // �� �� �߸���
    std::cout << wordSplit << std::endl;

    wordSplit = strtok_s(remains, ",", &remains); // �ڸ� �� �� �ڸ���
    std::cout << wordSplit << std::endl;

    // �� �ڵ带 ������ ����ŭ �ݺ��ϰų�
    for (int i = 0; i < 4; ++i) {}

    // �� �ڵ带 "������ ����"�� �� �̻� ���� ���� ������ �ݺ��ϰų�...
    while (remains != "") {}
    while (remains) {} // �̷��� �ٿ��� �� ���� (�ǹ̰� ����)

    // {} ���� ������ (Ȥ�� while ������ �´��� Ȯ��) -> ���� �ϼ�
}
