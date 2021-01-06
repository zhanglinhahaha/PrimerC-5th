#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include <typeinfo>
#include <vector>
#include <functional>
#include <algorithm>

class StrVec {
public:
    StrVec() : elements(NULL),first_free(NULL), cap(NULL) { }
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();
    void push_back(const std::string&);
    void push_back(std::string &&s) {
        chk_n_alloc();
        alloc.construct(first_free++, move(s));
    }
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    std::string *begin() const {return elements;}
    std::string *end() const {return first_free;}
    StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
        s.elements = s.first_free = s.cap = NULL;
    }
    StrVec& operator=(StrVec &&s) noexcept {
        if(this != &s) {
            free();
            elements = s.elements;
            first_free = s.first_free;
            cap = s.cap;
            s.elements = s.first_free = s.cap = NULL;
        }
        return *this;
    }
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc() {
        if(size() == capacity()) reallocate();
    }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string *elements; //数组首元素
    std::string *first_free; //数组第一个空闲元素
    std::string *cap; //数组尾后位置
};

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if(elements) {
        for(auto p = first_free; p != elements;) {
            alloc.destroy(--p);//1 析构函数
        }
        alloc.deallocate(elements, cap - elements);//释放内存
    }
}

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {free(); }

StrVec &StrVec::operator=(const StrVec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity); //分配内存
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++,move(*elem++)); 
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void *operator new(size_t size) {
    std::cout << "new\n";
    if(void *mem = malloc(size)) {
        return mem;
    }else {
        throw std::bad_alloc();
    }
}
void operator delete(void *mem) noexcept {
    std::cout << "delete\n";
    std::free(mem);
}

void test2() {
    StrVec s;
    s.push_back("zzz");
    s.push_back("lll");
    std::cout << *s.begin() << " " << s.size() << std::endl;
}

namespace t3 {
class A {
public:
    A() {std::cout << "A()\n";}
    virtual ~A() {std::cout << "~A()\n";}
};
class B : public A {
public:
    B() {std::cout << "B()\n";}
    virtual ~B() {std::cout << "~B()\n";}
};
class C : public B {
public:
    C() {std::cout << "C()\n";}
    virtual ~C() {std::cout << "~C()\n";}
};
class D : public B, public A {
public:
    D() {std::cout << "D()\n";}
    virtual ~D() {std::cout << "~D()\n";}
};

void test() {
    int type = -1;
    while(std::cin>> type && type != 0) {
        if (type == 1) {
            A *pa = new C;
            B *pb = dynamic_cast<B*> (pa);
            if(pb) {std::cout << "successful\n";}
        }else if(type == 2) {
            B *pb = new B;
            C *pc = dynamic_cast<C*> (pb);
            if(pc) {std::cout << "successful\n";}
        }else if(type == 3) {
            // A *pa = new D;
            // B *pb = dynamic_cast<B*> (pa);
        }else if(type == 4) {
            A *pa = new C;
            if(C* pc = dynamic_cast<C*> (pa)) {
                {std::cout << "successful\n";}
            }else {
                {std::cout << "failed\n";}
            }
        }else if(type == 5) {
            B b;
            A &ra = b;
            try {
                C &rc = dynamic_cast<C&> (ra);
                std::cout << "succeeful\n";
            } catch (std::bad_cast) {
                std::cout << "failed\n";
            }
        }
    }
}
}

namespace t9{
class Base {};
class Derived : public Base {};
void test1() {
    int arr[10];
    Derived d;
    Base *p = &d;
    std::cout << typeid(42).name() << ", "
              << typeid(arr).name() << ", "
              << typeid(std::string).name() << ", "
              << typeid(p).name() << ", "
              << typeid(d).name() << ", "
              << typeid(*p).name() << "\n";
              
}
class A {};
class B : public A {};
class C : public B {};
void test() {
    A* pa = new C;
    std::cout << typeid(pa).name() << "\n";
    C cobj;
    A& ra = cobj;
    std::cout << typeid(&ra).name() << "\n";
    B *pb = new B;
    A& ra1  = *pb;
    std::cout << typeid(ra1).name() << "\n";
}
}

namespace t11{
class Screen {
public:
    typedef std::string::size_type pos;
    Screen(int n) : cursor(n) {}
    pos cursor;
};
void test() {
    const std::string::size_type Screen::*pCur = &Screen::cursor;
    Screen s(18);
    auto pos = s.*pCur;
    std::cout << pos << std::endl;
}
}

namespace t18{
void test() {
    std::vector<std::string>  vs = {"11", "", "22", "", "33", "", "44"};
    int size = count_if(vs.begin(), vs.end(), std::mem_fn(&std::string::empty));
    auto it = find_if(vs.begin(), vs.end(), std::bind(&std::string::empty, std::placeholders::_1));
    std::cout << "size: " << size << " , it = " << *(it+1) << std::endl;
}
class Sales_data {
    double price;
public:
    Sales_data(double p) : price(p) { }
    double get_pri() {return price;}
};
void test1() {
    Sales_data sd(8.0), sd1(12.5), sd2(22.5), sd3(10);
    std::vector<Sales_data> vsd = {sd, sd1, sd2, sd3};
    double M = 11;
    auto f = std::mem_fn(&Sales_data::get_pri);
    auto it = find_if(vsd.begin(), vsd.end(), [&](Sales_data& s) {return f(s)>M; });
    std::cout << it->get_pri() << std::endl;
}
}

namespace t21 {
class Token {
public:
    Token(): tok(INT), ival(0) { }
    Token(const Token& t): tok(t.tok) { copyUnion(t); }
    Token &operator=(const Token&);
    ~Token(){ if(tok == STR) sval.std::string::~string(); }
    Token &operator=(const std::string&);
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
    void print() {
        switch(tok) {
            case Token::INT: std::cout << ival <<"\n"; break;
            case Token::CHAR: std::cout << cval <<"\n"; break;
            case Token::DBL: std::cout << dval <<"\n"; break;
            case Token::STR: std::cout << sval <<"\n"; break;
        }
    }

    //t23
    Token(Token&& t) :tok(std::move(t.tok)) { moveUnion(std::move(t)); }
    Token& operator=(Token&&);
private:
    enum {INT, CHAR, DBL, STR} tok;
    union {
        char cval;
        int ival;
        double dval;
        std::string sval;
    };
    void copyUnion(const Token&);
    void moveUnion(const Token&&);
};

Token &Token::operator=(int i) {
    if(tok == STR) sval.std::string::~string();
    ival = i;
    tok = INT;
    return *this;
}
Token &Token::operator=(char i) {
    if(tok == STR) sval.std::string::~string();
    cval = i;
    tok = CHAR;
    return *this;
}
Token &Token::operator=(double i) {
    if(tok == STR) sval.std::string::~string();
    dval = i;
    tok = DBL;
    return *this;
}
Token &Token::operator=(const std::string& s) {
    if(tok == STR) sval = s;
    else new(&sval) std::string(s);
    tok = STR;
    return *this;
}
void Token::copyUnion(const Token& t) {
    switch(t.tok) {
        case Token::INT: ival = t.ival; break;
        case Token::CHAR: cval = t.cval; break;
        case Token::DBL: dval = t.dval; break;
        case Token::STR: new(&sval) std::string(t.sval); break;
    }
}
Token &Token::operator=(const Token& t) {
    if(tok == STR && t.tok != STR) sval.std::string::~string();
    if(tok == STR && t.tok == STR) sval = t.sval;
    else copyUnion(t);
    tok = t.tok;
    return *this;
}

//t23
Token& Token::operator=(Token&& t){
    if (this != &t) {
        if(tok == STR) sval.std::string::~string();
        moveUnion(std::move(t));
        std::move(t.tok);
    }
    return *this;
}
void Token::moveUnion(const Token&& t){
    switch (t.tok) {
    case Token::INT:ival = t.ival; break;
    case Token::CHAR:cval = t.cval; break;
    case Token::DBL:dval = t.dval; break;
    case Token::STR: new(&sval)std::string(std::move(t.sval)); break;
    }
}

void test() {
    Token t;
    t.print();
    t = 1;
    t.print();
    t = 1.56;
    t.print();
    t = 'z';
    t.print();
    t = "'zzz'";
    t.print();
}
}

namespace t26{
extern "C" int compute(int *, int) { printf("C\n");}
double compute(double *, double) {std::cout << "C++\n"; }
void test() { 
    int i = 1;
    double d = 1.2;
    compute(&i, i);
    compute(&d, d);
}
}

int main() {
    t26::test();
    return 0;
}

