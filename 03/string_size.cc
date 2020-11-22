#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

string str1;    // empty string
string str2(str1);  // str2 is a copy of str1

int main()
{
    string str("The expense of spirit\n");
    cout << "The size of " << str << "is " << str.size() 
         << " characters, including the newline" << endl;
    cout << "The size of " << str1 << "is " << str1.size() 
         << " characters, including the newline" << endl;
}