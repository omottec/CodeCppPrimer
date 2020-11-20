#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

#include <algorithm>
using std::for_each;

#include <functional>
using namespace std::placeholders;
using std::bind;
using std::ref;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iterator>
using std::istream_iterator;

ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}

int main()
{
    string s;
    vector<string> words;
    while (cin >> s)
        words.push_back(s);
    
    for_each(words.begin(), words.end(), bind(print, ref(cout), _1, ' '));
    cout << endl;

    ofstream os("data/outFile1");
    for_each(words.begin(), words.end(), 
        bind(print, ref(os), _1, ' '));
    os << endl;

    ifstream is("data/outFile1");
    istream_iterator<string> in(is), eof;
    for_each(in, eof, 
        bind(print, ref(cout), _1, '\n'));
    cout << endl;

    return 0;
}