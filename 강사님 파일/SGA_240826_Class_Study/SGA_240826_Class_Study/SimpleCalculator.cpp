#include "SimpleCalculator.h"

void SimpleCalculator::InputNumber()
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "�ܼ� ��� ����� �����մϴ�." << std::endl;
    std::cout << "���� ���� ���ʷ� �Է����ּ���." << std::endl;
    std::cout << "----------------------------" << std::endl;
    
    std::cout << "ù ��° ���� : ";
    std::cin >> first;
    
    std::cout << "�� ��° ���� : ";
    std::cin >> second;
}

void SimpleCalculator::SelectOps()
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "������ ������ ���ڷ� �������ּ���." << std::endl;
    std::cout << "1 : ����, 2 : ����, 3 : ����, 4 : ������ " << std::endl;
    std::cout << "----------------------------" << std::endl;

    std::cout << "���� �ڵ� : ";
    std::cin >> operation;

    ShowResult(); // �Է� �޾����� ��ٸ� �� ���� �״�� ������� ����
}

int SimpleCalculator::Add()
{
    return first + second;
}

int SimpleCalculator::Subtract()
{
    return first - second;
}

int SimpleCalculator::Multiply()
{
    return first * second;
}

int SimpleCalculator::Divide()
{
    if (second == 0) return 0;
    else return first / second;
}

int SimpleCalculator::Remains()
{
    if (second == 0) return 0;
    else return first % second;
}

void SimpleCalculator::ShowResult()
{
    // �Է��� �߸��Ǹ� ����
    if (operation < 1 || operation > 4)
    {
        std::cout << "���� ���� �Է��� �߸��Ǿ����ϴ�." << std::endl;
        return; // void������ ������ '��ȯ ��� ���� return' : �Լ� ����������
    }

    int result = 0; // ��� ����� ���� ���� ����
    char opChar = ' '; // ������ �ؽ�Ʈ ����� ���� ���� ����

    // ���� ������ ���� ���� ��� �ֱ�

    switch (operation)
    {
    case ADD: // �������� �̸��� �θ��� = ��ǻ�ʹ� ���⿡ ������ ���ڷ� �����Ѵ�
              // * ���������� �̸��� ����ϸ� ���ڰ� ������ ������ Ȯ�� ����

        result = Add(); // ���� ����� ��ȯ�޾� ����
        opChar = '+';
        break;

    case SUBTRACT:
        result = Subtract();
        opChar = '-';
        break;

    case MULT:
        result = Multiply();
        opChar = '*';
        break;

    case DIVIDE:
        result = Divide();
        opChar = '/';
        break;
    }

    // �Է¹��� ����� ���ڸ� ���....�ϱ� ���� �������� ���� (�������� 0�� ���)

    if (operation == DIVIDE && second == 0) // �Ͽ��� �� ���ڰ� ����
    {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "0���� ������� �� �� �����ϴ�." << std::endl;
        std::cout << "��꿡 �����ϰ� ����� 0�Դϴ�." << std::endl;
    }
    else
    {
        // �׸��� ��¥�� ���
        // -> first�� second��... �ٸ� ������ �ۿ��� �� ���̴µ�?
        
        // : �� ���̴� �� first��� ������ �� ��ü�� (=���ٱ�)
        //   �ش� �����͸� ����ϴ� �� main()�� �ƴ϶�, �� �Լ�, �ٽ� ����
        //   �� �Լ��� ������ '�ܼ� ���� Ŭ����' ����(?)�̴�

        // ����Ϳ��� main�� �ƴ�, �� Ŭ������ ������ ������ ����� ������ ��
        // -> ���� ��� ���忡�� �ƹ�ư ���ڰ� ������ ���� ��

        std::cout << "-----------------------------" << std::endl;
        std::cout << first << " " << opChar << " " << second;
        std::cout << " = " << result << std::endl;

        if (operation == DIVIDE) // �������̶�� �������� ����ϰ� ����غ���
        {
            int remains = Remains();
            std::cout << "�������� " << remains << std::endl;
        }
    }

}
