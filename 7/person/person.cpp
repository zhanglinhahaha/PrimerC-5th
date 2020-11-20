#include <iostream>
#include <string>

struct Person {
    Person() = default;
    Person(std::string n) : name(n) {}
    Person(std::string n, std::string a) : name(n), addr(a) {}
    std::string name = "zl";
    std::string addr = "ss";
    std::string getName() const {return name;}
    std::string getAddr() const {return addr;}
};

std::ostream &print(std::ostream&, const Person&);
std::istream &read(std::istream&, Person&);

std::istream &read(std::istream &is, Person &people) {
    is >> people.name >> people.addr;
    return is;
}

std::ostream &print(std::ostream &os, const Person &people) {
    os << people.name << people.addr <<"\n";
    return os;
}


class People {
friend std::ostream &print1(std::ostream&, const People&);
friend std::istream &read1(std::istream&, People&);
public:
    People() = default;
    People(std::string n) : name(n) {}
    People(std::string n, std::string a) : name(n), addr(a) {}
    std::string getName() const {return name;}
    std::string getAddr() const {return addr;}
private:
    std::string name = "zl";
    std::string addr = "ss";
};

std::ostream &print1(std::ostream&, const People&);
std::istream &read1(std::istream&, People&);

std::istream &read1(std::istream &is, People &people) {
    is >> people.name >> people.addr;
    return is;
}

std::ostream &print1(std::ostream &os, const People &people) {
    os << people.name << people.addr <<"\n";
    return os;
}


void test1() {
    Person zl;
    std::cout << zl.getName() << " " << zl.getAddr() <<"\n";
    Person zzl("zzl");
    print(std::cout, zzl);
    Person zzzl("zzzl", "chj");
    print(std::cout, zzzl);
    Person ljm;
    read(std::cin, ljm);
    print(std::cout, ljm);
}

void test2() {
    People zl;
    std::cout << zl.getName() << " " << zl.getAddr() <<"\n";
    People zzl;
    read1(std::cin, zzl);
    print1(std::cout, zzl);
}

int main() {
    test2();
    return 0;
}
