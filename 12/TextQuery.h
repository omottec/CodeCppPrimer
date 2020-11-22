#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <memory>
#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <set>
using std::set;

#include <memory>
using std::shared_ptr;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include "QueryResult.h"

class QueryResult;
class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
    void display_map();
private:
    shared_ptr<vector<string>> file;
    // maps each word to the set of the lines in which that the word appears
    map<string, shared_ptr<set<line_no>>> wm;     
    // canonicalizes text: removes punctuation and makes everything lower case
    static string cleanup_str(const string&);
};
#endif