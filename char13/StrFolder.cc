#include <iostream>
using std::cerr;
using std::endl;

#include "StrFolder.h"

void swap(Message &lhs, Message &rhs)
{
    // not stictly needed in this case, but good habit
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

Folder::~Folder()
{
    remove_from_Msgs();
}

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder::Folder(Folder &&f)
{
    move_Messages(&f);
}

Folder &Folder::operator=(const Folder &f)
{
    remove_from_Msgs();
    msgs = f.msgs;
    add_to_Messages(f);
    return *this;
}


Folder &Folder::operator=(Folder &&f)
{
    if (this != &f) {
        remove_from_Msgs();
        move_Messages(&f);
    }
    return *this;
}

void Folder::save(Message &m)
{
    msgs.insert(&m);
    m.addFldr(this);
}

void Folder::remove(Message &m)
{
    msgs.erase(&m);
    m.remFldr(this);
}

void Folder::debug_print()
{
    cerr << "Folder contains " << msgs.size() << " messages" << endl;
    int ctr = 1;
    for (auto m : msgs)
        cerr << "Message " << ctr++ << ":\n\t" << m->contents << endl;
}

void Folder::move_Messages(Folder *f)
{
    msgs = std::move(f->msgs); // move the set from f to this
    f->msgs.clear(); // ensure that destroying f is harmless
    for (auto m : msgs) {
        m->remFldr(f); // remove the pointer to the old Folder
        m->addFldr(f); // insert pointer to this Folder
    }
}

void Folder::remove_from_Msgs()
{
    while (!msgs.empty())
        (*msgs.begin())->remove(*this);
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto msg : f.msgs)
        msg->addFldr(this);
}


Message::Message(const Message &m):  // copy constructor
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message &Message::operator=(const Message &rhs)// copy assignment
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message() // destructor
{
    remove_from_Folders();
}

Message::Message(Message &&m) : // move constructor
contents(std::move(m.contents))
{
    move_Folders(&m);
}

Message &Message::operator=(Message &&rhs)  // move assignment
{
    if (this != &rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::debug_print()
{
    cerr << "Message:\n\t" << contents << endl;
    cerr << "Appears in " << folders.size() << " Foloders" << endl;
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
    folders.clear();  
}