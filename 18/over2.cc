#include <iostream>

namespace AW {
    int print(int i)
    {
        std::cout << "AW::print(int)" << std::endl;
        return i;
    }
}

namespace Primer {
    double print(double d)
    {
        std::cout << "Primer::print(double)" << std::endl;
        return d;
    }
}

using namespace AW;
using namespace Primer;

int main()
{
    print(1);
    print(3.1);
    return 0;
}