#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <set>
using std::set;

#include <memory>
using std::shared_ptr;

#include <iostream>
using std::ostream;

class QueryResult {
friend ostream &print(ostream&, const QueryResult&); 
public:
    typedef vector<string>::size_type line_no;
    typedef set<line_no>::const_iterator line_it;
    QueryResult(string s, 
                shared_ptr<set<line_no>> p,
                shared_ptr<vector<string>> f) :
        sougth(s), lines(p), file(f) {}
    set<line_no>::size_type size() const { return lines->size(); }
    line_it begin() const { return lines->begin(); }
    line_it end() const { return lines->end(); }
    shared_ptr<vector<string>> get_file() { return file; }
private:
    string sougth;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream &print(ostream&, const QueryResult&); 

#endif