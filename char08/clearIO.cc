#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

void read()
{
    // turn on both fail and bad bits
    cin.setstate(cin.badbit | cin.failbit | cin.eofbit);
}

void off()
{
    // turns off failbit and badbit but all other bits unchanged
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
}

int main()
{
    cout << "before read" << endl;
    if (cin.good()) cout << "cin good" << endl;
    if (cin.bad()) cout << "cin bad" << endl;
    if (cin.fail()) cout << "cin fail" << endl;
    if (cin.eof()) cout << "cin eof" << endl;

    read();
    cout << "after read" << endl;
    if (cin.good()) cout << "cin good" << endl;
    if (cin.bad()) cout << "cin bad" << endl;
    if (cin.fail()) cout << "cin fail" << endl;
    if (cin.eof()) cout << "cin eof" << endl;    

    off();
    cout << "after off" << endl;
    if (cin.good()) cout << "cin good" << endl;
    if (cin.bad()) cout << "cin bad" << endl;
    if (cin.fail()) cout << "cin fail" << endl;
    if (cin.eof()) cout << "cin eof" << endl;  
    return 0;
}