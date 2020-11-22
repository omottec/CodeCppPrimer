#include <string>
using std::string;

#include <cctype>
using std::islower;
using std::isupper;
using std::isalpha;
using std::isspace;
using std::tolower;
using std::toupper;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string s("Hello World!!!");
    // punct_cnt has the same type that s.size returns
    decltype(s.size()) punct_cnt = 0;

    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt << " punctuation characters in " << s << endl;

    // convert s to uppercase
    string orig = s;
    for (auto &c : s)   // c is a reference, so this assignment changes the char in s
        c = toupper(c);
    cout << s << endl;

    // convert first word in s to uppercase
    s = orig;
    decltype(s.size()) index = 0;
    while (index != s.size() && !isspace(s[index]))
    {
        // s[index] returns a reference so we can change the underlying character
        s[index] = toupper(s[index]);
        ++index;
    }
    cout << s << endl;

    return 0;
}