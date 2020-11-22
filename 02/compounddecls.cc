#include <iostream>
int main()
{
    // i is an int; p is a pointer to int; r is a reference to int
    int i = 1024, *p = &i, &r = i;
    // three ways to print the value of i
    std::cout << i << " " << *p << " " << r << std::endl;

    int j = 42, *p2 = &j;
    int *&pref = p2;    // pref is a reference to the pointer p2
    // print value of j, which is the int to which p2 points
    // pref refers to a pointer, assigning &i to pref makes p2 points to i
    pref = &i;
    std::cout << *pref << std::endl;
    *pref = 0;  // changes i to 0
    return 0;
}