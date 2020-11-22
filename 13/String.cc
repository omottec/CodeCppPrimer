#include <memory>
using std::uninitialized_copy;

#include <iostream>
using std::ostream;

#include "String.h"

// define the static allocator member
std::allocator<char> String::a;

// copy-assignment operator
String &String::operator=(const String &rhs)
{
    auto newp = a.allocate(rhs.sz);
    uninitialized_copy(rhs.p, rhs.p + rhs.sz, newp);

    if (p)
        a.deallocate(p, sz);
    p = newp;
    sz = rhs.sz;

    return *this;    
}

// move assignment operator
String &String::operator=(String &&rhs) noexcept
{   
    // explicit check for self-assignment
    if (this != &rhs) {
        if (p) a.deallocate(p, sz);
        p = rhs.p;
        sz = rhs.sz;
        rhs.p = 0;
        rhs.sz = 0;
    }
    return *this;
}

String &String::operator=(const char *cp)
{
    if (p) a.deallocate(p, sz);
    p = a.allocate(sz = strlen(cp));
    uninitialized_copy(cp, cp + sz, p);
    return *this;
}

String &String::operator=(char c)
{
    if (p) a.deallocate(p, sz);
    p = a.allocate(sz = 1);
    *p = c;
    return *this;
}

String &String::operator=(std::initializer_list<char> il)
{
    if (p) a.deallocate(p, sz);
    p = a.allocate(sz = il.size());
    uninitialized_copy(il.begin(), il.end(), p);
    return *this;
}


String add(const String &lhs, const String &rhs)
{
    String ret;
    ret.sz = lhs.size() + rhs.size();
    ret.p = String::a.allocate(ret.sz);
    uninitialized_copy(lhs.begin(), lhs.end(), ret.p);
    uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.size());
    return ret;
}

String operator+(const String &lhs, const String &rhs)
{
    return add(lhs, rhs);
}

ostream &print(std::ostream &os, const String &s)
{
    auto p = s.begin();
    while (p != s.end())
        os << *p++;
    return os;
}

ostream& operator<<(std::ostream &os, const String &s)
{
    return print(os, s);
}

String make_plural(size_t ctr, const String &word, const String &ending)
{
    return ctr > 1 ? add(word, ending) : word;
}

