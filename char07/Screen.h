#include <string>
#include <iostream>

class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c):
        height(ht), width(wd), contents(ht * wd, c) {}
    friend class Window_mgr;
    Screen(pos ht = 0, pos wd = 0):
        cursor(0), height(ht), width(wd), contents(ht * wd, ' ') {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &clean(char = bkground);
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
private:
    static const char bkground = ' ';
    pos height = 0, width = 0;
    pos cursor = 0;
    std::string contents;
    void do_display(std::ostream &os) const { os << contents; }
};

char Screen::get(pos ht, pos wd) const {
    return contents[ht * width + wd];
}

Screen &Screen::clean(char c) {
    contents = std::string(height * width, c);
    return *this;
}

inline Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}


