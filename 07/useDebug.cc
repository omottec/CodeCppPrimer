#include <iostream>
using std::cerr;
using std::endl;

#include "Debug.h"

int mian()
{
    constexpr Debug io_sub(false, true, false);
    if (io_sub.any())   // equivalent to if(true)
        cerr << "print appropriate err msg" << endl;

    constexpr Debug prod(false);
    if (prod.any()) // equivalent to if(false)
        cerr << "print an error message" << endl;

    IO_Subsystem ioErrs;
    if (ioErrs.default_debug()) // if (false || debug.any())
        cerr << "print message 3" << endl;
    ioErrs.set_debug(true);
    if (ioErrs.default_debug()) // if (false || debug.any())
        cerr << "print message 4" << endl;
    ioErrs.set_debug(false);

    HW_Subsystem hw;
    hw.set_debug(true);
    if (ioErrs.default_debug() || hw.default_debug())
        cerr << "print message 5" << endl;

}