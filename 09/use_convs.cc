#include "StrConvs.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
    int i = 42;
    string s = to_string(i);
    double d = stodouble(s);
    cout << "i=" << i << " s=" << s << " d=" << d << endl;

    string s2 = "pi = 3.14";
    d = stodouble(s2.substr(s2.find_first_of("+-.0123456789")));
    cout << "d:" << d << " s2:" << s2 << endl;
    return 0;
}