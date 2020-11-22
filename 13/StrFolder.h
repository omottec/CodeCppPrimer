#ifndef STRFOLDER_H
#define STRFOLDER_H

#include "String.h"
#include <set>

class Folder;

class Message {
friend void swap(Message&, Message&);
friend class Folder;
public:
    // folders is implicitly initialized to the empty set
    explicit Message(const String &str = "")
        : contents(str) {}

    Message(const Message&);    // copy constructor
    Message &operator=(const Message&); // copy assignment
    ~Message(); // destructor
    Message(Message&&); // move constructor
    Message &operator=(Message&&);  // move assignment

    void save(Folder&);
    void remove(Folder&);
    void debug_print();
    
private:
    String contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void move_Folders(Message*);
    void remove_from_Folders();
    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};
void swap(Message&, Message&);

class Folder {
friend void swap(Message&, Message&);
friend class Message;
public:
    ~Folder();
    Folder(const Folder&);
    Folder(Folder&&);
    Folder &operator=(const Folder&);
    Folder &operator=(Folder&&);
    Folder() = default;
    void save(Message&);
    void remove(Message&);
    void debug_print();

private:
    std::set<Message*> msgs;
    // add this Folder to each Message
    void add_to_Messages(const Folder&);
    // remove this Folder to each Message
    void remove_from_Msgs();
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
    // move Message pointers to point to this Folder
    void move_Messages(Folder*);
};
#endif