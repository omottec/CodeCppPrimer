#include <iostream>
int main()
{
    int i = 42;
    std::cout << i << std::endl;    // prints 42
    if (i)
        i = 0;
    std::cout << i << std::endl;    // prints 0

    bool b = 42;
    std::cout << b << std::endl;    // prints 1
    int j = b;
    std::cout << j << std::endl;    // prints 1

    double pi = 3.14;
    std::cout << pi << std::endl;   // prints 3.14
    j = pi;
    std::cout << j << std::endl;    // prints 3

    unsigned char c = -1;
    i = c;
    std::cout << i << std::endl;    // prints 255

    return 0;
}