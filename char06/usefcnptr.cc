#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int min_element(vector<int>::iterator, vector<int>::iterator);

// pointer to function
int (*pf) (vector<int>::iterator, vector<int>::iterator) = min_element;

int main()
{
    vector<int> ivec = {2,-3,9,3,5};
    cout << "direct call: " << min_element(ivec.begin(), ivec.end()) << endl;
    cout << "indirect call: " << pf(ivec.begin(), ivec.end()) << endl;
    cout << "indirect call: " << (*pf)(ivec.begin(), ivec.end()) << endl;
    return 0;
}

int min_element(vector<int>::iterator beg, 
    vector<int>::iterator end)
{
    int minVal = 0;
    while (beg != end)
    {
        if (minVal > *beg)
            minVal = *beg;
        ++beg;
    }
    return minVal;
}
