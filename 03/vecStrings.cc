#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main()
{
    vector<string> text;
    string s;
    while (getline(cin, s)) // read the entire input file
        text.push_back(s);
    cout << "text size: " << text.size() << endl;

    // print each line in text up to the first blank line
    for (auto it = text.cbegin(); 
        it != text.cend() && !(*it).empty();
        it++)
        cout << *it << endl;

    for (auto it = text.cbegin(); 
        it != text.end() && !it->empty();
        it++)
        cout << *it << endl;
}