#include <iostream>
using std::cout;
using std::endl;

#include "TextQuery.h"
#include "Query.h"

int main(int argc, char** argv)
{
    TextQuery file = get_file(argc, argv);
    do {
        string sought;
        if (!get_word(sought)) break;
        Query name(sought);
        const auto resutls = name.eval(file);
        cout << "\nExecuting Query for: " << name << endl;
        print(cout, resutls) << endl;
    } while (true);
    return 0;
}