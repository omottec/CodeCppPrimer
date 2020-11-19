#ifndef STRCONVS_H
#define STRCONVS_H
#include <string>
#include <cstdio>
#include <cstdlib>

inline std::string to_string(int i)
{
    char buf[100];
    std::printf(buf, "%2d", i);
    return buf;
}

inline double stodouble(const std::string &s, std::size_t * = 0)
{
    char **buf = 0;
    return std::strtod(s.c_str(), buf);
}
#endif