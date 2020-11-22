#include <iostream>
using std::cout;
using std::endl;

#include "LocalMath.h"

// g++ -std=c++11 LocalMath.cc fact.cc -o fact.o
int main()
{
    cout << factorial(5) << endl;
    cout << fact(5) << endl;
    cout << factorial(0) << endl;
    cout << fact(0) << endl;
    return 0;
}