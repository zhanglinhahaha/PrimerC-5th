#include <iostream>

using namespace std;

class Base {
public:
    virtual int fcn() { cout << "Base fcn()" << endl; }
};

class D1 : public Base {
public:
    int fcn(int i) { cout << "D1 fcn(int)" << endl; }
    //int fcn() override { cout << "D1 fcn()" << endl; }
    virtual void f2() { cout << "D1 f2()" << endl; }
};

class D2 : public D1 {
public:
    int fcn(int i) {cout << "D2 fcn(int)" << endl; }
    int fcn() { cout << "D2 fcn()" << endl; }
    void f2() { cout << "D2 f2()" << endl; }
};

int main() {
    Base bobj; D1 d1ogj; D2 d2obj;
    Base *bp1 = &bobj, *bp2 = &d1ogj, *bp3 = &d2obj;
    bp1->fcn(); //Base::fcn()
    bp2->fcn(); //Base::fcn()
    bp3->fcn(); //D2::fcn()

    D1 *d1p = &d1ogj; D2 *d2p = &d2obj;
//    bp2->f2(); //Base has no member named f2
    d1p->f2(); //D1::f2()
    d2p->f2(); //D2::f2()

    Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
//    p1->fcn(43); //no matching function for call to Base::fcn(int)
    p2->fcn(43); //D1::fcn(int)
    p3->fcn(43); //D2::fcn(int)
    return 0;
}
