#include <iostream>
#include <string>

int main()
{
    int v1(1024);   // direct-initialization, functional form
    int v2{1024};  // direct-initailization, list initializer form
    int v3 = 1024;  // copy-initialization
    int v4 = {1024};    // copy-initialization, list initializer form
    std::cout << "v1:" << v1 << ", v2:" << v2 << ", v3:" << v3 << ", v4:" << v4 << std::endl;

    // alternative ways to initialize string from a character string literal
    std::string titleA = "C++ Primer, 5th Ed.";
    std::string titleB("C++ Primer, 5th Ed.");
    std::string all_nines(10, '9');
    std::cout << titleA << std::endl;
    std::cout << titleB << std::endl;
    std::cout << all_nines << std::endl;

    return 0;
}