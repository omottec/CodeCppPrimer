#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <stdexcept>
using std::runtime_error;

void process(ifstream &is)
{
    string s;
    while (is >> s)
        cout << s << endl;
}

// ./fileIO.o "buf.cc" "clearIO.cc"
int main(int argc, char* argv[])
{
    // for each file passed to the program
    for (auto p = argv + 1; p != argv + argc; ++p) {
        ifstream input(*p); // create input and open the file       
        if (input)
            process(input);
        else
            cerr << "couldn't open:" + string(*p);
    } // input goes out of scope and is destroyed on each iteration

    auto p = argv + 1, end = argv + argc;

    ifstream input;
    while (p != end) {
        input.open(*p);  // open the file, automatically clears the stream
        if (input)
            process(input);
        else
            cout << "couldn't open: " << string(*p);
        input.close();
        ++p;
    }
}