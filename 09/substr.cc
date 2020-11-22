#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::out_of_range;

int main()
{
    try {
        string s("hello world");
        cout << s.substr(0, 5) << endl;
        cout << s.substr(6) << endl;
        cout << s.substr(6, 11) << endl;
        cout << s.substr(12) << endl;
    } catch (out_of_range) {
        cout << "catch out_of_range" << endl;
    }
    return 0;
}