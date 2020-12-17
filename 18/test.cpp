#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <string>

using namespace std;

namespace t1 {
void test1() {
    int n;
    while(cin >> n && n != 0) {
        range_error r("error");
        if(n == 1) throw r;
        exception *p = &r;
        if(n == 2) throw *p;
        throw p;
    }
}

class Array {
public:
    Array(int n): ptr(new int[n]) { }
    ~Array() { delete[] ptr;}
private:
    int *ptr;
};

void test2(int *b, int *e) {
    vector<int> v(b, e);
    //int *p = new int(v.size());
    //1:
    shared_ptr<int> p(new int[v.size()], [](int *p) {delete[] p;});
    //2:
    Array p1(v.size());
    ifstream in("ints");
}
}

namespace t2 {
void test4() {
    try {
        exception e;
        runtime_error r("runtime_error test");
        overflow_error o("overflow_error test");
        int n;
        cin >> n;
        if(n == 0) throw e;
        else if(n == 1) throw r;
        throw o;
    }catch(overflow_error eobj) {
        cerr << "overflow_error catch" << endl;
    }catch(const runtime_error &re) {
        cerr << "runtime_error catch" << endl;
    }catch(exception) {
        cerr << "exception catch" << endl;
    }
}
void test5() {
    try{
        range_error r("range_error test");
        exception *p = &r;
        int n;
        cin >> n;
        if(n == 0 ) throw r;
        else if(n == 1) throw *p;
        throw p;
    }catch(range_error &r) {
        cerr << r.what() << " catch range_error" << endl;
    }catch(exception) {
        cerr << "catch exception" << endl;
    }catch(exception*) {
        cerr << "catch exception*" << endl;
    }
}

class exceptionType { };
typedef int EXCPTYPE;
void test6() {
    exceptionType* et;
    EXCPTYPE i;
    range_error o("range_error");
    try {
        int n;cin >> n;
        if(n == 0) throw et;
        else if(n == 1) throw i;
        throw o;
    }catch(EXCPTYPE) {
        cerr << "EXCPTYPE catch" << endl;
    }catch(exceptionType*) {
        cerr << "exceptionType* catch" << endl;
    }catch(...) {
        cerr << "... catch" << endl;
    }
}

}

namespace t3 {
class isbn_mismatch : public logic_error {
public:
    isbn_mismatch(const string &s, const string &lhs, const  string &rhs)
        : logic_error(s), left(lhs), right(rhs) { }
    string left, right;
};
class Sales_data {
friend class isbn_mismatch;
public:
    Sales_data(string s, double d): isBn(s), units_sold(d) { }
    Sales_data& operator+=(const Sales_data& sd) {
        if(isbn() != sd.isbn()) throw isbn_mismatch("wrong isbns", isbn(), sd.isbn());
        units_sold += sd.units_sold;
        return *this;
    }
    string isbn() const { return isBn; }
    double us() const { return units_sold; }
private:
    string isBn;
    double units_sold = 0.0;
};
ostream& operator<<(ostream& os, const Sales_data& sd) {
    os << sd.isbn() << " " << sd.us() << endl;
    return os;
}
void test9() {
    Sales_data sd0("TLBB", 12.5), sd1("TLBB", 11), sd2("SDYXZ", 10);
    sd0+=sd1;
    cout << sd0;
    try{
        sd0+=sd2;
    }catch(isbn_mismatch &s) {
        cerr << s.what() << '\t' << s.left << '\t'<< s.right << endl;
    }
    sd1+=sd2;
}
}

namespace Exercise {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}
int ivar = 0;
/*
using Exercise::ivar;
using Exercise::dvar;
using Exercise::limit;
using namespace Exercise;
*/
void test17() {
/*
using Exercise::ivar;
using Exercise::dvar;
using Exercise::limit;
using namespace Exercise;
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
*/
}

class A {
public:
A() { std::cout << "A\n"; }
};
class B: public A {
public:
B() { std::cout << "B\n"; }
};
class C: public B {
public:
C() { std::cout << "C\n"; }
};
class X {
public:
X() { std::cout << "X\n"; }
};
class Y {
public:
Y() { std::cout << "Y\n"; }
};
class Z: public X, public Y {
public:
Z() { std::cout << "Z\n"; }
};
class MI: public C, public Z {
public:
MI() { std::cout << "MI\n"; }
};

void test22() {
    MI m;
}

class D : public X, public C {
public:
    D() {std::cout << "D\n"; }
};
void test23() {
    D *pd = new D;
    X *px = pd;
    A *pa = pd;
    B *pb = pd;
    C *pc = pd;
}

namespace t25{

class Base1 {
public:
    virtual void print() { std::cout << "Base1\n"; }
    virtual ~Base1() { std::cout << "~Base1\n"; }
};
class Base2 {
public:
    virtual void print() { std::cout << "Base2\n"; }
    virtual ~Base2() { std::cout << "~Base2\n"; }
};
class D1 : public Base1 {
public:
    virtual void print() { std::cout << "D1\n"; }
    virtual ~D1() { std::cout << "~D1\n"; }
};
class D2 : public Base2 {
public:
    virtual void print() { std::cout << "D2\n"; }
    virtual ~D2() { std::cout << "~D2\n"; }
};
class MI : public D1, public D2{
public:
    virtual void print() { std::cout << "MI\n"; }
    virtual ~MI() { std::cout << "~MI\n"; }
};

void test25() {
    Base1 *pb1 = new MI;
    Base2 *pb2 = new MI;
    D1 *pd1 = new MI;
    D2 *pd2 = new MI;
    std::cout << "---->>> a <<<----\n";
    pb1->print();
    std::cout << "---->>> b <<<----\n";
    pd1->print();
    std::cout << "---->>> c <<<----\n";
    pd2->print();
    std::cout << "---->>> d <<<----\n";
    delete pb2;
    std::cout << "---->>> e <<<----\n";
    delete pd1;
    std::cout << "---->>> f <<<----\n";
    delete pd2;
}
}

namespace t28 {
struct Base {
    void bar(int i) { std::cout <<"Base_bar\n"; }
protected:
    int ival = 0;
};
struct Derived1 : virtual public Base {
    void bar(char c) { std::cout << "Derived1_bar\n"; }
    void foo(char c) { std::cout << "Derived1_foo\n"; }
protected:
    char cval = 'a';
};
struct Derived2 : virtual public Base {
    void foo(int i) { std::cout << "Derived2_foo\n"; }
protected:
    int ival = 1;
    char cval = 'b';
};
class VMI : public Derived1, public Derived2 {
public:
    void show() {
        std::cout << "Base --> " << Base::ival << " <--\n"
                  << "Derived1 --> " << Derived1::cval << " <--\n"
                  << "Derived2 --> " << Derived2::cval << ival << " <--\n";
        int i = 0;
        char a = 'a';
        bar(i);
        Base::bar(i);
        bar(a);
        Derived1::foo(a);
        Derived2::foo(i);
    }
};
void test() {
    VMI vm;
    vm.show();
}
}

namespace t29{
class Class {
public:
    Class() { std::cout << "Class()\n"; }
};
class Base : public Class {
public:
    Base() { std::cout << "Base()\n"; }
    Base(const Base& base) {cout << "Base(const Base&)\n";}
    Base(int i) { std::cout << "Base(int)\n"; }
};
class D1 : virtual public Base {
public:
    D1() { std::cout << "D1()\n"; }
    D1(const D1& d): Base(d) {cout << "D1(const D1&)\n";}
    D1(int i): Base(i) { std::cout << "D1(int)\n"; }
};
class D2 : virtual public Base {
public:
    D2() { std::cout << "D2()\n"; }
    D2(const D2& d): Base(d) {cout << "D2(const D2&)\n";}
    D2(int i): Base(i) { std::cout << "D2(int)\n"; }
};
class MI : public D1, public D2 {
public:
    MI() { std::cout << "MI()\n"; }
    MI(const MI& m): D1(m), D2(m) {cout << "MI(const MI&)\n";}
    MI(int i): D1(i), D2(i) { std::cout << "MI(int)\n"; }
};
class Final : public MI, public Class {
public:
    Final() { std::cout << "Final()\n"; }
    Final(const Final& f): MI(f), Class(), Base(f) {cout << "Final(const Final&)\n";}
    Final(int i): MI(i), Class(), Base(i) { std::cout << "Final(int)\n"; }
};

void test() {
    std::cout << "--->>> a <<<---\n";
    Final f;
    std::cout << "--->>> c <<<---\n";
    Base *pb;
    Class *pc;
    MI *pmi;
    D2 *pd2;
    std::cout << "--->>> ca <<<---\n";
    //pb = new Class;
    std::cout << "--->>> cb <<<---\n";
    //pc = new Final;
    std::cout << "--->>> cc <<<---\n";
    //pmi = pb;
    std::cout << "--->>> cd <<<---\n";
    pd2 = pmi;
}

void test30() {
    Final f = Final(1);
    std::cout << "---- >>>> <<<< ----\n";
    Final f1 = f;
}
}

int main() {
    t29::test30();
    return 0;
}
