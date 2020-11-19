#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string numbers("0123456789"), name("r2d2");
    string::size_type pos = name.find_first_of(numbers);
    if (pos != string::npos)
        cout << "found number at index: " << pos 
             << " element is " << name[pos] << endl;
    else
        cout << "no number in: " << name << endl;

    pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
        cout << "found number at index: " << pos 
             << " element is " << name[pos] << endl;
        ++pos;
    }

    string river("Mississippi");
    string::size_type first_pos = river.find("is");
    string::size_type last_pos = river.rfind("is");
    cout << "find return: " << first_pos 
         << " rfind return: " << last_pos << endl;
    
    string dept("03714p3");
    pos = dept.find_first_not_of(numbers);
    cout << "first_not return: " << pos << endl;

    return 0;
}