#include "TextQuery.h"
#include "make_plural.h"

#include <cstddef>

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <set>
using std::set;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <utility>

TextQuery::TextQuery(ifstream &is): file(new vector<string>) 
{
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            word = cleanup_str(word);
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it)
        if (!ispunct(*it))
            ret += tolower(*it);
    return ret;
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream& print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    return os;
}

void TextQuery::display_map()
{
    auto bg = wm.cbegin();
    while (bg != wm.cend()) {
        cout << bg->first << ":[";
        auto lines_sp = bg->second;
        auto bg1 = lines_sp->begin();
        while (bg1 != lines_sp->end()) {
            cout << (*bg1 + 1);
            if (++bg1 != lines_sp->end())
                cout << ",";
        }
        cout << "]" << endl;
        ++bg;
    }
}