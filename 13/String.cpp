#include <iostream>
#include <cstring>
#include <memory>
#include <vector>
using namespace std;

class String {
public:
    String(): sz(0), p(NULL){ }
    //接受C风格字符串构造函数
    String(const char *cp): sz(strlen(cp)), p(alloc.allocate(sz)) {
        uninitialized_copy(cp, cp + sz, p);
    }
    String(const String &s): sz(s.sz), p(alloc.allocate(sz)) {
        cout << "调用拷贝构造" << endl;
        uninitialized_copy(s.p, s.p + sz, p);
    }
    String& operator=(const String &s) {
        cout << "调用拷贝赋值" << endl;
        auto newp = alloc.allocate(s.sz);
        uninitialized_copy(s.p, s.p + s.sz, newp);
        if(p) alloc.deallocate(p, sz);
        sz = s.sz;
        p = newp;
        return *this;

    }
    //移动构造函数
    String(String&& s) noexcept : sz(s.sz), p(s.p){
        cout << "调用移动构造" << endl;
        s.p = NULL;
    }
    //移动赋值运算符
    String& operator=(String &&s) {
        cout << "调用移动赋值" << endl;
        if(this != &s) {
            sz = s.sz;
            p = s.p;
            s.p = NULL;
        }
        return *this;
    }
    void input() {
        auto newp = p;
        for(size_t i = 0; i < sz; ++i, ++newp) {
            cout << *newp;
        }
        cout << endl;
    }
    ~String(){delete p;}
private:
    static allocator<char> alloc;
    size_t sz;
    char *p;
};

allocator<char> String::alloc;

int main() {
    /*
    String s("sssss");
    s.input();
    const char *p = "zlfight";
    String s1(p);
    s1.input();
    s = s1;
    s.input();
    */
    vector<String> vs;
    //vs.reserve(16);
    String s("test");
    for(int i = 0; i < 10; ++i) {
    cout << "vs.size(): " << vs.size() << ", vs.capacity(): " << vs.capacity() << endl;
    cout << "push_back start()" << endl;
        vs.push_back(s);
    cout << "push_back end()" << endl;
    }
    return 0;
}
