#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::for_each;
using std::transform;

void print(int i) { cout << i << " "; }
unsigned absInt(int i) { return i < 0 ? -i : i; }

int main()
{
    vector<int> vi;
    int i;
    while (cin >> i)
        vi.push_back(i);
    // pass a function to for_each to print each element in vi
    for_each(vi.begin(), vi.end(), print);
    cout << endl;

    vector<int> orig = vi;
    transform(vi.begin(), vi.end(), vi.begin(), absInt);
    for_each(vi.begin(), vi.end(), print);
    cout << endl;
    for_each(orig.begin(), orig.end(), print);
    cout << endl;
}