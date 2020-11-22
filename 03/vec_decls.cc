#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

int main()
{
    // list initialization, articles has 3 elements
    vector<string> articles = {"a", "an", "the"};

    vector<string> svec;    // default initialization; svec has no elements
    vector<int> ivec;
    vector<vector<string>> file;
    vector<vector<int>> vecOfvec;

    // all four vectors has size 0
    cout << svec.size() << " " 
         << ivec.size() << " "
         << file.size() << " "
         << vecOfvec.size() << " "
         << endl;
    
    vector<int> ivec2(10);
    vector<int> ivec3(10, -1);
    vector<string> svec2(10);
    vector<string> svec3(10, "hi!");
    cout << ivec2.size() << " " 
         << ivec3.size() << " "
         << svec2.size() << " "
         << svec3.size() << " "
         << endl;

    vector<string> v1(10);
    vector<string> v2{10};
    vector<string> v3(10, "hi");
    vector<string> v4{10, "hi"};
    cout << v1.size() << " " 
         << v2.size() << " "
         << v3.size() << " "
         << v4.size() << " "
         << endl;

    vector<string> vs1{"hi"};
    vector<string> vs2{10};
    vector<string> vs3{10, "hi"};
    cout << vs1.size() << " " 
         << vs2.size() << " "
         << vs3.size() << " "
         << endl;

    vector<int> v5(10, 1);
    vector<int> v6{10, 1};
    cout << v5.size() << " " << v6.size() << " " << endl;

    vector<int> alt_v3 = {10};
    vector<int> alt_v4 = {10, 1};
    cout << alt_v3.size() << " " << alt_v4.size() << " " << endl;

    return 0;
}