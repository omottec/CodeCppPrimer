#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <cstdlib>  // for EXIT_FAILURE

#include "TextQuery.h"
#include "make_plural.h"

void runQuery(ifstream &infile)
{
    TextQuery tq(infile);
    tq.display_map();
    while (true) {
        cout << "enter word to look for, or q to quit:" << endl;
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char **argv)
{
    ifstream infile;
    // open return void, so we use the comma operator 
    // to check the state of infile after the open
    if (argc < 2 || !(infile.open(argv[1]), infile)) {
        cerr << "No input file!" << endl;
        return EXIT_FAILURE;
    }
    runQuery(infile);
    return 0;
}
