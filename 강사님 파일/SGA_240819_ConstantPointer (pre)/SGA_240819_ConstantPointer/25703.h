#include <iostream>

void ExampleCode25703()
{
    int N;
    std::cin >> N;

    std::cout << "int a;" << std::endl;

    for (int i = 0; i < N; ++i)
    {
        std::cout << "int ";

        for (int j = 0; j <= i; ++j)
        {
            std::cout << "*";
        }

        std::cout << "ptr";
        if (i > 0) std::cout << i + 1;

        std::cout << " = &";
        if (i == 0) std::cout << "a;";
        else if (i == 1) std::cout << "ptr;";
        else std::cout << "ptr" << i << ";";

        std::cout << std::endl;
    }
}