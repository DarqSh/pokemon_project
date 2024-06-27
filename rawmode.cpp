#include <iostream>

int main()
{
    char c;
    do
    {
        std::cin >> c;
        std::cout << "hello " << std::endl;
    }while(c == 9);

    return 0;
}
