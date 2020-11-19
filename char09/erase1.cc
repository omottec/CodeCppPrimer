#include <algorithm>
using std::find;

#include <string>
using std::string;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main()
{
    list<string> slist;
    string s;
    while (cin >> s)
        slist.push_back(s);

    list<string>::iterator iter = find(slist.begin(), slist.end(), "Quasimodo");
    if (iter != slist.end())
        slist.erase(iter);
    
    list<string> orig = slist;
    slist.clear();
    cout << "after clear, size is: " << slist.size() << endl;

    slist = orig;
    slist.erase(slist.begin(), slist.end());
    cout << "after erase begin to end, size is: " << slist.size() << endl;

    slist = orig;
    list<string>::iterator elem1 = slist.begin(), elem2 = slist.end();
    elem1 = slist.erase(elem1, elem2);
    cout << "after erase elem1 to elem2, size is: " << slist.size() << endl;

    if (elem1 != elem2)
        cout << "somethings wrong" << endl;
    else
        cout << "okay, they're equal" << endl;
}