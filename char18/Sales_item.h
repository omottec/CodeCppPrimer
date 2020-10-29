#ifndef SALESITEM_H
#define SALESITEM_H

#include <iostream>
#include <string>
#include "bookexcept.h"

class Sales_item {
friend std::istream& operator>>(std::istream&, Sales_item&);
friend std::ostream& operator<<(std::ostream&, Sales_item&);
public:
    Sales_item() = default;
    // operations on Sales_item objects
    // member binary operator: left-hand operand bound to implicit this pointer
    Sales_item& operator+=(const Sales_item&);

    // operations on Sales_item objects
    std::string isbn() const { return bookNo; }
    double avg_price() const;
private:
    std::string bookNo; // implicity initialized to the empty string
    unsigned units_sold = 0;    // explicity initialized
    double revenue = 0.0;
};

// assumes that both objects refer to the same ISBN
Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
    if (isbn() != rhs.isbn())
        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// nonmember binary operator: must declare a parameter for each operand
Sales_item operator+(const Sales_item&, const Sales_item&);

// assume that both objects refer to the same ISBN
Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
    if (lhs.isbn() != rhs.isbn())
        throw isbn_mismatch("wrong isbns", lhs.isbn(), rhs.isbn());
    Sales_item ret(lhs);    // copy (|lhs|) into a local object that we'll return
    ret += rhs; // add in the contents of (|rhs|)
    return ret; // return (|ret|) by value
}

std::istream& operator>>(std::istream& in, Sales_item& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else
        s = Sales_item();   // input failed: reset object to default state
    return in;
}

std::ostream& operator<<(std::ostream& out, Sales_item& s)
{
    out << s.isbn() << " " << s.units_sold << " " << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}
#endif