#include "nayounseok.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>


void nayounseok::Painting()
{
    nayounseok* nazzang = new nayounseok();

    int inputPainting;
	system("cls");
	std::cout << "�Ⱬ�ϰ� ���� ����� �׷��� �׸��� ���� �ɷ��ִ�." << std::endl;
	std::cout << "----------------------------------------------------------" <<std:: endl;
	std::cout << "�׸��� ���� ����ϰ� ���� ���̴� �� ����." << std::endl;
	std::cout << "��� �ڼ��� �鿩�� ����?" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "���ڷ� �Է����ּ���." << std::endl;
    std::cout << "| 1��: �Ӹ� | 2��: �� | 3��: �� | 4��: �ٸ� | 5��: ��� |" << std::endl;

    std::cin >> inputPainting;
    switch (inputPainting)
    {
    case 1: // �Ӹ��� ����
        std::cout << "���� ���ϰ� ������ �ִ°� ����� ���°� �ƴ� �� ����." << std::endl;
        std::cout << "���� ã�� �� �ִ°� ���� �� ����." << std::endl;
        system("pause");
        system("cls");
        nazzang->Painting();

    case 2:  // ������ ����

        std::cout << "���� ��� �þ��� �ִ�." << std::endl;
        std::cout << "���� ã�� �� �ִ°� ���� �� ����." << std::endl;
        system("pause");
        system("cls");
        nazzang->Painting();

    case 3: //�踦 ����

        std::cout << "������ �Դ����� ������ �谡 ������ �����ִ�.." << std::endl;
        std::cout << "�迡 ���� ������ �ִ�.." << std::endl;
        std::cout << "2 : 5 ��� ������ �ִ�. �������ϱ�" << std::endl;
        system("pause");
        system("cls");
        nazzang->Painting();

    case 4: // �ٸ��� �� ��

        std::cout << "�ٸ��� ������ ���. �� �ܿ� Ư������ ���� �� ����" << std::endl;
        std::cout << "���� ã�� �� �ִ°� ���� �� ����." << std::endl;
        system("pause");
        system("cls");
        nazzang->Painting();

    case 5: // ���

        return;

        


    default:
        std::cout << "��ȿ���� ���� ��ȣ�Դϴ�. �ٽ� �Է����ּ���" << std::endl;
        system("pause");
        system("cls");
        nazzang->Painting();
        
    }
}

void nayounseok::Bed()
{


    nayounseok* nazzang = new nayounseok();
    
    int inputBed;
    int scoreBed = 0;
    system("cls");
    std::cout << "������ �� �׿��ִ� ħ���." << std::endl;
    system("pause");
    std::cout << "��ǰ� �̺��� �ִµ� ���캼��?" << std::endl;
    std::cout << "| 1��: ����� ���캻��. | 2��: �̺��� ���캻��. | 3��: ħ�� ���� ���캻��. | 4��: ��� |" << std::endl;
    std::cin >> inputBed;

    switch (inputBed)
    {
    case 1: // ���
        std::cout << "��� �ȿ� ���� �ִ� �� ����..." << std::endl;
        std::cout << "����� ���Ƽ� ���� �� ���� �� ����.. �����?" << std::endl;
        std::cout << "| 1��: ����� ���´�. | 2��: ���� �ʴ´�. |" << std::endl;
        std::cin >> inputBed;
        if (inputBed == 1)
        {
            
            std::cout << "����� ������ ���� ������ ���Դ�..." << std::endl;
            std::cout << "�������� 1: 6 �̶�� ������ �ִ�.." << std::endl;

            system("pause");
            nazzang->Bed();
        }
        else
        {
            nazzang->Bed();
        }

    case 2:  // �̺�

        std::cout << "������ ���� ������ �̺��̴�. " << std::endl;
        std::cout << "���⼭�� �� �� ���� �� ����." << std::endl;
        system("pause");

        nazzang->Bed();

    case 3: //ħ�� ��

        std::cout << "ħ�� ���� ���� �������� ��ü�� �����ϴ�. " << std::endl;
        std::cout << "���� ���� ���� �� ���� �ʴ�." << std::endl;
        system("pause");
        nazzang->Bed();

    case 4:
        return;

    default:

        std::cout << "��ȿ���� ���� ��ȣ�Դϴ�. �ٽ� �Է����ּ���" << std::endl;
        system("pause");
        system("cls");
        nazzang->Bed();
    }
}

void nayounseok::Chair()
{
    system("cls");
    std::cout << "������ڴ�. ������ ������� �� ������ �ϳ� ���Ҵ�." << std::endl;
    std::cout << "ȥ�ڼ� �����̰� �ִ�.. ������ �ȵ� �� ����." << std::endl;
    system("pause");
    return;
}

void nayounseok::Drawer()
{
    nayounseok* nazzang = new nayounseok();

    system("cls");
    int inputDrawar;
    std::cout << "������ ���� ���� �������̴�.." << std::endl;
    std::cout << "�������� �����غ���?" << std::endl;
    std::cout << "| 1��: ù��° ĭ | 2��: �ι�° ĭ | 3��: ����° ĭ | 4��: ��� |" << std::endl;
    std::cin >> inputDrawar;

    switch (inputDrawar)
    {
    case 1: // ù��° ĭ
        std::cout << "���� ���� ���������� �ִ�.." << std::endl;
        std::cout << "�ƺ�, ����, ū�Ƶ�, ���� �Ƶ�� ���̴� �����̴�. " << std::endl;
        std::cout << "�ٵ� ���� ������ ���� �Ⱥ������� ���� �Ƶ��� ���� �Ⱬ�ϰ� �����ִ°� ���δ�." << std::endl;
        system("pause");
        nazzang->Bed();
        

        
    case 2:  // �ι�° ĭ

        std::cout << "�ƹ��͵� ���� �� ����.. " << std::endl;
        
        system("pause");

        nazzang->Bed();

    case 3: //����° ĭ

        std::cout << "������ �����ϴ�.. " << std::endl;
        std::cout << "���� ���� ���� �� ���� �ʴ�." << std::endl;
        
        system("pause");
        std::cout << "������ ���� �ޱ׶� �Ÿ���. " << std::endl;
        std::cout << "���� õ�忡 �ٿ��� �ִ� ������ ��������." << std::endl;
        std::cout << "4: 0 �̶�� �����ִ�. " << std::endl;
        system("pause");
        nazzang->Bed();

    case 4: 

        return;
    default:

        std::cout << "��ȿ���� ���� ��ȣ�Դϴ�. �ٽ� �Է����ּ���" << std::endl;
        system("pause");
        system("cls");
        nazzang->Bed();
    }
}




void nayounseok::Rug()
{
    
  

    nayounseok* nazzang = new nayounseok();

    system("cls");
    
    
        std::cout << "������ ī���̴�" << std::endl;
        system("pause");
        std::cout << "ī�� ���� �����غ��� ������ �ִ�." << std::endl;
        system("pause");
        std::cout << "3: 8 �̶�� �����ִ�." << std::endl;
        system("pause");
  }
    

  
    
   


void nayounseok::Door()
{

    nayounseok* nazzang = new nayounseok();

    int input;

    system("cls");

    std::cout << "�� �߰��� ������ ���δ�." << std::endl;
    std::cout << "������ �β������̴� 4�ڸ� ��й�ȣ �ڹ��谡 �ɷ��ִ�. " << std::endl;
    std::cout << "4�ڸ� ��ȣ�� �Է��غ���." << std::endl;
    std::cin >> input;

    if (input == 6580)
    {
        system("cls");

        std::cout << "���� ���ȴ�.. ������� �𸣴� �������� " << std::endl;
        std::cout << "���ΰ� ���� �� ���� ������ �پ���." << std::endl;
        std::cout << "�ڿ��� ������ ���Ѻ��� �ü��� ����������" << std::endl;
        std::cout << "�����ϰ� �ո� ���� �޷ȴ�," << std::endl;
        system("pause");
        std::cout << "THE END" << std::endl;
        system("pause");
        exit(0);
    }
    else
    {
        std::cout << "�ڹ���� ��½���� �ʴ´�.. " << std::endl;
        std::cout << "�ٽ� �õ��غ���.." << std::endl;
        system("pause");
        nazzang->Door();

    }

}
