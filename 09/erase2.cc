#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int temp[] = {0,1,2,3,4,5,6,7,8,9};
    list<int> lst(temp, temp + sizeof(temp)/sizeof(*temp));

    cout << "initail list:";
    for (auto it = lst.begin(); it != lst.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // erase the odd elements in lst
    list<int>::iterator it = lst.begin();
    while (it != lst.end())
        if (*it % 2)
            it = lst.erase(it);
        else
            ++it;

    cout << "after erasing odd elements from list:";
    for (auto it = lst.begin(); it != lst.end(); ++it)
        cout << *it << " ";
    cout << endl;
}