#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <list>
#include <deque>
#include <utility>
#include <sstream>
#include <memory>

using namespace std;

template <typename T>
void print(T t) {
    cout << t << "\n";
}

/**** test2  ****/
template <typename T>
int compare(const T &v1, const T &v2) {
    if(less<T>()(v1, v2)) return -1;
    if(less<T>()(v2, v1)) return 1;
    return 0;
}

/**** test3 ****/
class Sales_data {
friend bool operator<(const Sales_data&, const Sales_data&);
public:
    Sales_data(const string& s, double p): isbn(s), price(p) { }
    string isBn() const { return isbn; }
private:
    string isbn;
    double price;
};

bool operator<(const Sales_data& sd1, const Sales_data& sd2) {
    return sd1.isBn() < sd2.isBn();
}

void test3() {
    string s1("t1"), s2("t2");
    Sales_data sd1(s1, 4.56), sd2(s2, 8.92);
    print(compare(sd1, sd2));
    print(compare(s1, s2));
}

/**** test4 ****/
template <typename I, typename V>
I findV(I beg, I end, V value) {
    while(beg != end) {
        if(*beg == value) break;
        ++beg;
    }
    return beg;
}

void test4() {
    vector<int> v = {1, 2, 3, 4, 5};
    auto f = findV(v.begin(), v.end(), 3);
    cout << (f == v.end() ? "not found\n": "found\n");
    list<string> l = {"a", "b", "c", "d", "e"};
    auto fs = findV(l.begin(), l.end(), "sstr");
    cout << (fs == l.end() ? "not found\n": "found\n");
}

/**** test5 ****/
template<typename I>
void printArr(I const& i) {
    for(auto const& e : i) {
        cout << e << " ";
    }
    cout << endl;
}

void test5() {
    char c[] = {'a', 'b', 'c'};
    int i[] = {1, 2, 3};
    printArr(c);
    printArr(i);
}

/**** test6 ****/
/**
 *T(&arr)[s]
 *参数声明一个名为arr的变量,该变量是对一个数组类型T的引用
 *将数组传递给函数而不使其衰退为指针的方法
 *可以在函数中使用数组，就像在声明它的作用域中使用数组样
 */
template<typename T, unsigned s>
T* beginOf(T(&arr)[s]) {
    return arr;
}
template<typename T, unsigned s>
T* endOf(T(&arr)[s]) {
    return arr+s;
}

void test6() {
    string s[] = {"abc", "def", "ghi"};
    cout << *(beginOf(s)) << endl;
    cout << *(endOf(s) - 1) << endl;
}

/**** test7 ****/
template<typename T, unsigned s>
constexpr unsigned getSize(T(&arr)[s]) {
    return s;
}

void test7() {
    int i[] = {1, 2, 3};
    cout << getSize(i) << endl;
}

/***** test19And20 ****/
template<typename T>
void printCon19(T& t) {
    for(typename T::size_type scan = 0; scan < t.size(); ++scan) {
        cout << t[scan] << " ";
    }
    cout << endl;
}

template<typename T>
void printCon20(T& t) {
    for(auto scan = t.begin(); scan < t.end(); ++scan) {
        cout << *scan << " ";
    }
    cout << endl;
}

void test19And20() {
    vector<int> vi = {1, 2, 3, 4};
    deque<string> ds = {"hello", "world", "hahaha"};
    printCon19(vi);
    printCon19(ds);
    printCon20(vi);
    printCon20(ds);
}

void test37() {
    int a = 2;
    double b = 2.3;
    cout << max<double>(a, b) << endl;
}

void test39() {
    cout << compare<string>("abc", "aaaaaa") << endl;
}

/**** test 40 ****/
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0) {
    return *beg;
}

void test40() {
    vector<int> vi = {0, 1, 2, 3};
    auto target = fcn3(vi.begin(), vi.end());
    cout << target << endl;
    //非法
    /*
    vector<string> vs = {"z", "l", "f"};
    auto tar = fcn3(vs.begin(), vs.end());
    cout << tar << endl;
    */
    vector<char> vc = {'z', 'l', 'f'};
    auto tarc = fcn3(vc.begin(), vc.end());
    cout << tarc << endl;
}

/**** test 41 ****/
template <typename TL, typename TR>
auto sum(TL l, TR r) -> decltype(l + r) {
    return l + r;
}

void test41() {
    cout << sum(12345678987654321, 12345678987654321) << endl;
}

/**** test 47 ****/
template<typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void g(int&& i, int& j) {
    cout << i++ << " " << j++ << endl;
}

void test47() {
    int i = 1, j = 2;
    flip(g, j, 1);
    cout << i << " " << j << endl;
}

/**** test 48 ****/
template <typename T> string debug_rep(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> string debug_rep(T *p) {
    ostringstream ret;
    ret << "pointer: " << p;
    if(p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer" ;
    return ret.str();
}

void test48() {
    string s("hi");
    cout << debug_rep(s) << endl;
    cout << debug_rep(&s) << endl;
}

/**** test 49&50 ****/
template <typename T> void f(T t) {
    cout << "f(T t)" << endl;
}
template <typename T> void f(const T *t) {
    cout << "f(const T *t)" << endl;
}
template <typename T> void g(T t) {
    cout << "g(T t)" << endl;
}
template <typename T> void g(T *t) {
    cout << "g(T *t)" << endl;
}

void test49() {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42);g(p);g(ci);g(p2);
    cout << "*****" << endl;
    f(42);f(p);f(ci);f(p2);
}

/**** test 51&52 ****/
template<typename T, typename... Args>
void foo(const T &t, const Args& ... args) {
    cout << sizeof...(Args) << " " << sizeof...(args) << endl;
}

void test51() {
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow";
    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");
}

/**** test 53&54&55 ****/
template <typename T> ostream &printt(ostream &os, const T &t) {
    return os << t << "\n";
}
template <typename T, typename... Args>
ostream &printt(ostream &os, const T &t, const Args&... args) {
    os << t << ", ";
    return printt(os, args...);
}

void test53() {
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow";
    const char* c = "hello";
    cout << "1:\n";
    printt(cout, i);
    cout << "2:\n";
    printt(cout, i, d);
    cout << "5:\n";
    printt(cout, i, d, s, c);
}

/**** test 56 ****/
template <typename T> string debug_repp(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... args) {
    return printt(os, debug_repp(args)...);
}

void test56() {
    errorMsg(cerr, "other", 1, 3.15);
}

/**** test 61 ****/
template <typename T, typename... Args>
auto make_share(Args&&... args) -> shared_ptr<T> {
    return shared_ptr<T>(new T(forward<Args>(args)...));
}

void test61() {
    auto n = make_share<int>(42);
    cout << *n << endl;
    auto s = make_share<string>(10, 'c');
    cout << *s << endl;
}

/**** test 63&64 ****/
template <typename T> size_t count(vector<T> const& v, T value) {
    size_t counts = 0;
    for(auto t : v)
        if(t == value) ++counts;
    return counts;
}

template <> size_t count(vector<const char*> const& v, const char* value) {
    size_t counts = 0;
    for(auto t : v)
        if(t == value) ++counts;
    return counts;
}

void test63() {
    vector<int> vi = {0, 1, 2, 2, 2, 3, 4};
    vector<double> vd = {0.1, 0.2, 0.2, 0.3};
    vector<string> vs = {"a", "ab", "ab", "abc"};
    string s = "ab";
    cout << count(vi, 2) << " " << count(vd, 0.2) << " " << count(vs, s) << endl;
    vector<const char*> vcc = {"a", "ab", "ab", "abc"};
    cout << count(vcc, "ab") << endl;
}

/**** test 65 ****/
template<>
string debug_rep(const char* s) {
    ostringstream ret;
    cout << "<>const char*: \n";
    ret << s;
    return ret.str();
}

template<>
string debug_rep(char* s) {
    ostringstream ret;
    cout <<"<>char*: \n";
    ret << s;
    return ret.str();
}

void test65() {
    char p[] = "abcd";
    cout << debug_rep(p) << endl;
    const char* pp = "zxcv";
    cout << debug_rep(pp) << endl;
}

int main() {
    test65();
    return 0;
}

