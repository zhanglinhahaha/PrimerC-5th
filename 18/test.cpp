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
*/
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
}

int main() {
    test17();
    return 0;
}
