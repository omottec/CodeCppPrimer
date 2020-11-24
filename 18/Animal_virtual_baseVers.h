#include <string>
using std::string;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

class Endangered {
public:
    enum Status { critical, environment, improving };
    Endangered(Status stat = improving): animal_status(stat) {
        cout << "Endangered::Endangered" << endl;
    }
    virtual ~Endangered()
        { cout << "Endangered::~Endangered" << endl; }
    virtual ostream& print(ostream&) const
        { return cout << "Endangered::print" << endl; }
    virtual void highlight() const
        { cout << "Endangered::highlight" << endl; }
private:
    Status animal_status;
};

class ZooAnimal;
extern ostream& operator<<(ostream&, const ZooAnimal&);

class ZooAnimal {
public:
    ZooAnimal() = default;
    ZooAnimal(string animal, bool exhibit, string family):
        nm(animal), exhibit_stat(exhibit), fam_name(family) {
        cout << "ZooAnimal::ZooAnimal" << endl;
    }
    virtual ~ZooAnimal()
        { cout << "ZooAnimal::~ZooAnimal" << endl; }
    virtual ostream& print(ostream&) const
        { return cout << "ZooAnimal::print" << endl; }
    virtual int population() const
    {
        cout << "ZooAnimal::population" << endl;
        return 0;
    }

    // accessors
    string name() const { return nm; }
    string family_name() const { return fam_name; }
    bool onExhibit() const { return exhibit_stat; }
protected:
    string nm;
    bool exhibit_stat = false;
    string fam_name;
private:
};

class Raccoon : public virtual ZooAnimal {
public:
    Raccoon() = default;
    Raccoon(string name, bool onExhibit= true);
    virtual ostream& print(ostream&) const
        { return cout << "Raccoon::print" << endl; }
    bool pettable() const { return pettable_flag; }
    void pettable(bool petval) { pettable_flag = petval; };
    virtual ~Raccoon() { cout << "Raccoon::~Raccoon" << endl; }
protected:
    bool pettable_flag = false;
};

class Bear : public virtual ZooAnimal {
public:
    enum DanceType { two_left_feet, macarena, fandango };
    Bear(string name, bool onExhibit=true);
    virtual ostream& print(ostream&) const
        { return cout << "Bear::print" << endl; }
    virtual string isA() const
    {
        cout << "Bear::isA" << endl;
        return "Bear";
    }
    int mumble(int)
    {
        cout << "Bear::mumble" << endl;
        return 0;
    }
    void dance(DanceType) const
        { cout << "Bear::dance" << endl; }
    virtual ~Bear() { cout << "Bear::~Bear" << endl; }
protected:
    Bear(): dance_flag(two_left_feet) {}
private:
    string name;
    DanceType dance_flag;
};

class Panda : public Bear, public Raccoon, public Endangered {
public:
    Panda() = default;
    Panda(string name, bool onExhibit = true);
    virtual ostream& print(ostream&) const
        { return cout << "Panda::print" << endl; }
    bool sleeping() const { return sleeping_flag; }
    void sleeping(bool newval) { sleeping_flag = newval; }
    ~Panda() { cout << "Panda::~Panda" << endl; }
protected:
    bool sleeping_flag = false;
};

Bear::Bear(string name, bool onExhibit):
    ZooAnimal(name, onExhibit, "Bear") {
    cout << "Bear::Bear" << endl;
}
Raccoon::Raccoon(string name, bool onExhibit):
    ZooAnimal(name, onExhibit, "Raccoon") {
    cout << "Raccoon::Raccoon" << endl;
}
Panda::Panda(string name, bool onExhibit):
    ZooAnimal(name, onExhibit, "Panda"),
    Bear(name, onExhibit),
    Raccoon(name, onExhibit),
    Endangered(Endangered::critical),
    sleeping_flag(false) {
        cout << "Panda::Panda" << endl;
    }