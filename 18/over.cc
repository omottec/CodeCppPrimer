//
// Created by qbb on 2020/11/24.
//

#include <string>
using std::string;

#include <iostream>

namespace libs_R_us {
    extern void print(int)
    { std::cout << "libs_R::print(int)" << std::endl; }

    extern void print(double)
    { std::cout << "libs_R::print(double)" << std::endl; }
}

void print(const std::string&)
{
    std::cout << "print(const std::string&)" << std::endl;
}

using namespace libs_R_us;

int main()
{
    int ival = 42;
    print("Value: ");
    print(ival);
    return 0;
}