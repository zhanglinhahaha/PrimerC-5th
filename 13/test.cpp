#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct X {
    X() {cout << "X()" << endl;}
    X(const X&) {cout << "X(const X&)" << endl;}
    X& operator=(const X&) {cout << "operator=(const X&)" << endl;}
    ~X() {cout << "~X()" << endl;}
};
void t1(X x) { }
void t2(X &x) { }

void test13() {
    X x0;
    cout << "拷贝构造函数" << endl;
    X x1 = x0;
    cout << "拷贝赋值运算符" << endl;
    X x2;
    x2 = x0;
    cout << "调用非引用的参数" << endl;
    t1(x0);
    cout << "调用引用参数" << endl;
    t2(x0);
    cout << "析构函数" << endl;
}

static int id = 0;
class numbered {
public:
    int mysn;
    numbered() {
        mysn = id++;
    }
    numbered(const numbered&) {
        mysn = id++;
    }
};
void f(numbered s) {cout << s.mysn << endl;}
void f0(numbered &s) {cout << s.mysn << endl;}
void test15() {
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
}
void test16() {
    numbered a, b = a, c = b;
    f0(a); f0(b); f0(c);
}

static int ID = 0;
class Employee {
public:
    string name;
    int isbn;
    Employee() {
        isbn = ID++;
    }
    Employee(string s) {
        name = s;
        isbn = ID++;
    }
    Employee(const Employee& e) {
        name = e.name;
        isbn = ID++;
    }
    Employee& operator=(const Employee& e) {
        name = e.name;
        isbn = ID++;
        return *this;
    }
};

class HasPtr{
private:
    int num;
    string *str = NULL;
public:
    friend void swap(HasPtr &hp0, HasPtr &hp1) {
        cout << "HasPtr swap" << endl;
        using std::swap;
        swap(hp0.str, hp1.str);
        swap(hp0.num, hp1.num);
    }
    HasPtr() {}
    HasPtr(int i, string s): num(i), str(new string(s)) { cout << "()" << endl; }
    HasPtr(const HasPtr &p): num(p.num), str(new string(*(p.str))) { cout << "(const&)" << endl; }
    HasPtr& operator=(const HasPtr &p) {
        cout << "operator=" << endl;
        num = p.num;
        str = new string(*(p.str));
        return *this;
    }
    bool operator<(const HasPtr &hp) {
        return num < hp.num;
    }
    void input() {
        cout << num << " " << str << endl;
    }
};

void test22() {
    HasPtr hp0 = HasPtr(0, "zl");
    HasPtr hp1 = hp0;
    HasPtr hp2;
    hp2 = hp0;
    hp0.input();
    hp1.input();
    hp2.input();
}

void test30() {
    HasPtr hp0 = HasPtr(0, "zl0");
    HasPtr hp1 = HasPtr(1, "zl1");
    hp0.input();
    hp1.input();
    swap(hp0, hp1);
    hp0.input();
    hp1.input();
}

void test31() {
    HasPtr hp0 = HasPtr(0, "zl0");
    HasPtr hp1 = HasPtr(1, "zl0");
    HasPtr hp2 = HasPtr(2, "zl0");
    cout << "init vector" << endl;
    vector<HasPtr> vhp = {hp2, hp0, hp1};
    cout << "sort begin()" << endl;
    sort(vhp.begin(), vhp.end());
}
int main() {
    test31();
    return 0;
}
