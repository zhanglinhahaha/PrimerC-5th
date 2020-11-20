#include "ConstStrBlobPtr.h"
#include <cstring>
#include <memory>

void test1() {
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }
    cout << b1.size() << endl;
}

vector<int>* write(vector<int>* v) {
    int n;
    while(cin >> n && n != -1) {
        v->push_back(n);
    }
    return v;
}
void read(vector<int> *v) {
    for(auto i = v->begin(); i != v->end(); ++i) cout << *i << " ";
    cout << endl;
}
vector<int>* creat() {
    vector<int> *v = new vector<int>;
    return v;
}
void test6() {
    vector<int> *v = write(creat());
    read(v);
    delete(v);
}

shared_ptr<vector<int>> creatPtr() {
    auto p = make_shared<vector<int>>();
    return p;
}
shared_ptr<vector<int>> writePtr(shared_ptr<vector<int>> p) {
    int n;
    while(cin >> n && n != -1) p->push_back(n);
    return p;
}
void readPtr(shared_ptr<vector<int>> p) {
    for(auto i = p->begin(); i != p->end(); ++i) cout << *i << " ";
    cout << endl;
}
void test7() {
    auto p = writePtr(creatPtr());
    readPtr(p);
}

void process(shared_ptr<int> ptr) {
}
void test12() {
    auto p = new int(5);
    auto sp = make_shared<int>(5);
    process(sp);
    cout << *sp << endl;
    //process(new int());
    //process(p);
    process(shared_ptr<int>(p));
    cout << *p << endl;
}

void test16() {
    unique_ptr<int> q1(new int(1));
    cout << *q1 << endl;
    unique_ptr<int> q2(q1.release());//release将q1置空
    cout << *q2 << endl;
    unique_ptr<int> q3(new int(3));
    cout << *q3 << endl;
    q2.reset(q3.release());//reset释放了q2原来指向的内存
    cout << *q2 << endl;
}

void test17() {
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;
    //IntP p0(ix);
    //IntP p1(pi);
    IntP p2(pi2);
    //IntP p3(&ix);
    IntP p4(new int(2048));
    IntP p5(p2.get());
    //p2.reset();
    cout << "*p0" << "*p1" << *p2 << "*p3" << *p4 << *p5 << endl;
}

void test20() {
    StrBlob *file = new StrBlob();
    string name;
    int n = 0;
    while(cin >> name && name != "q") {
        file->push_back(name);
        n++;
    }
    auto p = file->begin();
    while(n != 0) {
        cout << p.deref() << endl;
        p.incr();
        n--;
    }
}

void test21() {
    const char *c1 = "hello,";
    const char *c2 = "world!";
    char *res = new char[strlen(c1)+strlen(c2)+1];
    strcpy(res, c1);
    strcat(res, c2);
    cout << res << endl;
    string s1 = "HELLO,";
    string s2 = "WORLD!";
    s1 = s1.append(s2);
    res = &s1[0];
    cout << res << endl;
}

void test22() {
    char *r = new char[3];
    char c;
    char *q = r;
    int n = 0;
    while(cin >> c && c != 'q') {
        *q++ = c;
        n++;
    }
    char *s = r;
    while(s != q) {
        cout << *s++ << endl;
    }
    delete[] r;
}

void test26() {
    int n = 10;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    string s;
    auto q = p;
    while(cin >> s && q != p + n && s != "q") {
        alloc.construct(q++, s);
    }
    const size_t size = q - p;
    cout << size << endl;
    while(q != p)
        alloc.destroy(--q);
    alloc.deallocate(p, n);
}

int main() {
    test22();
    return 0;
}
