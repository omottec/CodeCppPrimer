#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

void printVec(const vector<int> &vi)
{
    vector<int>::const_iterator iter = vi.begin();
    while (iter != vi.end())
        cout << *iter++ << endl;
}

int main()
{
    // remove even-valued elements and insert a duplicate of odd-valued elments
    int temp[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vi(temp, temp + sizeof(temp)/sizeof(*temp));
    printVec(vi);

    vector<int>::iterator iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            iter += 2;
        } else {
            iter = vi.erase(iter);
        }
    }
    printVec(vi);
}