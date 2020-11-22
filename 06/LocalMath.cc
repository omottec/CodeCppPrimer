#include "LocalMath.h"

int fact(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

int factorial(int val)
{
    if (val > 1)
        return val * factorial(val-1);
    return 1;
}