#include "Animal_virtual_baseVers.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

void print(const Bear &bear)
{
    cout << "print(const Bear&)" << endl;
    bear.print(cout);
}

void highlight(const Endangered &endangered)
{
    cout << "highlight(const Endangered &endangered)" << endl;
    endangered.highlight();
}

ostream& operator<<(ostream &os, const ZooAnimal&)
{
    return os << "ZooAnimal output operator" << endl;
}

int main()
{
    Panda ying_yang("ying_yang");
    print(ying_yang);
    highlight(ying_yang);
    cout << ying_yang << endl;
    Panda ling_ling = ying_yang;
    return 0;
}