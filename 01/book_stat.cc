#include <iostream>
#include "Sales_item.h"
// g++ -std=c++17 -o book_stat.o book_stat.cc
// ./book_stat.o < book_sales
int main()
{
    Sales_item total;
    if (std::cin >> total) {
        Sales_item trans;
        while (std::cin >> trans)
        {
            if (total.isbn() == trans.isbn())
                total += trans;
            else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}