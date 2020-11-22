#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Query.h"
#include "TextQuery.h"

int main(int argc, char** argv)
{
    TextQuery file = get_file(argc, argv);
    do {
        string sought1, sought2, sought3;
        if (!get_words(sought1, sought2)) break;
        cout << "\nenter third word:";
        cin >> sought3;
        Query q = Query(sought1) & Query(sought2) | Query(sought3);
        cout << "\nExecuting Query for: " << q << endl;
        auto results = q.eval(file);
        print(cout, results);

        results = Query(sought1).eval(file);
        cout << "\nExecuting Query for: " << Query(sought1) << endl;
        print(cout, results) << endl;

        results = Query(sought2).eval(file);
        cout << "\nExecuting Query for: " << Query(sought2) << endl;
        print(cout, results) << endl;

        results = Query(sought3).eval(file);
        cout << "\nExecuting Query for: " << Query(sought3) << endl;
        print(cout, results) << endl;
    } while (true);
    return 0;    
}