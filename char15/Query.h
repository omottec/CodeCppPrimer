#ifndef QUERY_H
#define QUERY_H

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include "TextQuery.h"

class Query_base {
friend class Query;
public:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    // eval returns the QueryResult that matches this Query
    virtual QueryResult eval(const TextQuery&) const = 0;
    // rep is a string representation of the query
    virtual string rep() const = 0;
};

class Query {
friend Query operator~(const Query&);
friend Query operator|(const Query&, const Query&);
friend Query operator&(const Query&, const Query&);
public:
    Query(const string&); // builds a new WordQuery
    QueryResult eval(const TextQuery&) const { return q->eval(); }
    string rep() const { return q->rep(); }
private:
    Query(shared_ptr<Query_base> query) : q(query) {}
    shared_ptr<Query_base> q;
};

inline ostream &operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}

class WordQuery : public Query_base {
friend class Query;
    string query_word;
    WordQuery(const string &s) : query_word(s) {}
    string rep() const { return query_word; }
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
};

inline
Query::Query(const string &s) : q(new WordQuery(s)) {}

class NotQuery : public Query_base {
    friend Query operator~(const Query&);
    Query query;
    NotQuery(const Query &q) : query(q) {}
    // concrete class: NotQuery defines all inherited pure virtaul functions
    QueryResult eval(const TextQuery&) const;
    string rep() const { return "~(" + query.rep() + ")"; }
};

class BinaryQuery : public Query_base {
protected:
    // abstract class: BinaryQuery doesn't define eval
    BinaryQuery(const Query &l, const Query &r, string s) 
        : lhs(l), rhs(r), opSym(s) {}
    string rep() const 
    { 
        return "(" + lhs.rep() 
                + " " + opSym + " " 
                + rhs.rep() + ")" ; 
    }
    Query lhs, rhs;
    string opSym;
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &l, const Query &r) 
        : BinaryQuery(l, r, "&") {}
    QueryResult eval(const TextQuery &t) const;
};

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &l, const Query &r) 
        : BinaryQuery(l, r, "|") {}
    QueryResult eval(const TextQuery &t) const;    
};

inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}
inline Query operator|(const Query &l, const Query &r)
{
    return shared_ptr<Query_base>(new OrQuery(l, r));
}
inline Query operator&(const Query &l, const Query &r)
{
    return shared_ptr<Query_base>(new AndQuery(l, r));
}

ifstream &open_file(ifstream&, const string&);
TextQuery get_file(int, char**); 
bool get_word(string&);
bool get_words(string&, string&);
ostream &print(ostream&, const QueryResult&); 

#endif