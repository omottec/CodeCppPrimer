#ifndef DEBUG_H
#define DEBUG_H
class Debug {
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o): 
        hw(h), io(i), other(o) {}
    constexpr bool any() { return hw || io || other; }
    constexpr bool hardware() { return hw || io; }
    constexpr bool app() { return other; }

    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }

private:
    bool hw;    // hardware errors
    bool io;    // io errors
    bool other; // other errors
};

class HW_Subsystem {
public:
    HW_Subsystem(): debug(false) {} // by default no debugging
    bool field_debug() { return debug.any(); }
    bool default_debug() { return debug.any() && enable.any(); }
    void set_debug(bool b) { debug.set_hw(b); }
private:
    Debug debug;
    constexpr static Debug enable{true, false, false};
};

class IO_Subsystem {
public:
    IO_Subsystem(): debug(false) {} // by default no debugging
    bool field_debug() { return debug.any(); }
    bool default_debug() { return debug.any() && enable.any(); }
    void set_debug(bool b) { debug.set_io(b); }
private:
    Debug debug;
    constexpr static Debug enable{true, false, true};
};
#endif