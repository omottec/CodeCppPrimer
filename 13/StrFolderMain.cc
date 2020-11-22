#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include "String.h"
#include "StrFolder.h"

int main()
{
    String s1("constents1");
    String s2("constents2");
    String s3("constents3");
    String s4("constents4");
    String s5("constents5");
    String s6("constents6");

    // all new message, no copies yet
    Message m1(s1);
    Message m2(s2);
    Message m3(s3);
    Message m4(s4);
    Message m5(s5);
    Message m6(s6);

    Folder f1;
    Folder f2;

    m1.save(f1); m3.save(f1); m5.save(f1);
    m1.save(f2);
    m2.save(f2); m4.save(f2); m6.save(f2);

    m1.debug_print();
    f2.debug_print();

    // create some copies
    Message c1(m1);
    Message c2(m2);
    Message c4(m4);
    Message c6(m6);

    m1.debug_print();
    f2.debug_print();

    // now some assignment
    m2 = m3;
    m4 = m5;
    m6 = m3;
    m1 = m5;
    m1.debug_print();
    f2.debug_print();

    // finally, self-assignment
    m2 = m2;
    m1 = m1;
    m1.debug_print();
    f2.debug_print();


    vector<Message> vm;
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m1);

    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m2);

    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m3);

    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m4);

    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m5);

    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m6);

    vector<Folder> vf;
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f1);

    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f2);

    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder(f1));

    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder(f2));

    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder());

    Folder f3;
    f3.save(m6);
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f3);

    return 0;
}