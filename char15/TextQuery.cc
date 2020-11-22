#include "TextQuery.h"
#include "make_plural.h"

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cout;
using std::endl;

TextQuery::TextQuery(ifstream &ifs) : file(new vector<string>)
{
    string text;
    while (getline(ifs, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            word = cleanup_str(word);
            auto &lines = wm[word];
            if (!lines) lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(cleanup_str(sought));
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

void TextQuery::display_map()
{
    auto iter = wm.cbegin(), iter_end = wm.cend();
    for (; iter != iter_end; ++iter) {
        cout << "word: " << iter->first << " {";
        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin(), loc_iter_end = text_locs->cend();
        while (loc_iter != loc_iter_end) {
            cout << (*loc_iter + 1);
            if (++loc_iter != loc_iter_end)
                cout << ", ";
        }
        cout << "}\n";
    }
    cout << endl;
}

string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it)
        if (!ispunct(*it))
            ret += tolower(*it);
    return ret;
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sougth << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " 
           << *(qr.file->begin() + num) << endl;
    return os;
}