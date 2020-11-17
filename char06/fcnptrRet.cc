#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);

string::size_type sumLength(const string &s1, const string &s2)
{
    return s1.size() + s2.size();
}

string::size_type largerLength(const string &s1, const string &s2)
{
    return s1.size() > s2.size() ? s1.size() : s2.size();
}

// three ways to declare getFcn
// 1. use decltype for the return type
decltype(sumLength) *getFun(const string &);

// 2. use trailing return type
auto getFun(const string&) -> string::size_type(*)(const string&, const string&);

// 3. direct definition
string::size_type (*getFun(const string&))(const string&, const string&);

// define getFun
decltype(sumLength) *getFun(const string &fetch)
{
    if (fetch == "sum")
        return sumLength;
    return largerLength;
}

int main()
{
    // "sum" is the argument to getFun
    // ("hello", "world") are arguments to the function getFun returns
    cout << getFun("sum")("hello", "world") << endl;
    cout << getFun("larger")("hello", "world") << endl;
}