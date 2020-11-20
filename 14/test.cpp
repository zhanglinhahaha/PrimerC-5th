#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include <functional>

using namespace std;

class Sales_data;

istream& operator>>(istream &is, Sales_data& sd);
ostream& operator<<(ostream &os, const Sales_data& sd);

class Sales_data {
private:
    string isBn;
    double price;
public:
    Sales_data() = default;
    Sales_data(double p, string ib): isBn(ib), price(p) { }
    friend istream& operator>>(istream &is, Sales_data& sd);
    friend ostream& operator<<(ostream &os, const Sales_data& sd);
    Sales_data& operator+(const Sales_data& sd) {
        if(isBn == sd.isBn) {
            price += sd.price;
        }
        return *this;
    }
    Sales_data& operator+=(const Sales_data& sd) {
        if(isBn == sd.isBn)
            price += sd.price;
        return *this;
    }
};

istream& operator>>(istream &is, Sales_data& sd) {
    is >> sd.isBn >> sd.price;
    return is;
}
ostream& operator<<(ostream &os, const Sales_data& sd) {
    os << sd.isBn << " " << sd.price << endl;
    return os;
}

void test2() {
    Sales_data sd0(2.58, "zlbook");
    Sales_data sd1(3.96, "zlbook");
    Sales_data sd2(4.25, "zlbook");
    Sales_data sd3(1.47, "zl");
    Sales_data sd4;
    cout << sd0;
    cin >> sd4;
    cout << "ad2+sd0" << endl;
    sd2 + sd0;
    cout << sd0;
    cout << sd2;
    cout << "ad3+=sd0" << endl;
    sd3 += sd0;
    cout << sd0;
    cout << sd3;
}

template <typename T>
class ite {
public:
    T operator()(T t1, T t2, T t3) const {
        return t1 ? t2 : t3;
    }
};

void test34() {
    ite <int>i;
    ite <double>d;
    cout << i(0, 2, 3) << endl;
    cout << d(1.2, 2.3, 3.4) << endl;
}

class PrintString {
public:
    PrintString(istream &i): is(i) { }
    string operator()()const{
        string line;
        if(!getline(is, line)) line = "";
        return line;
    }
private:
    istream& is;
};

void test35() {
    PrintString ps(cin);
    cout << ps() << endl;
}

void test36() {
    PrintString ps(cin);
    vector<string> vs;
    while(1) {
        string line = ps();
        if(!line.empty())
            vs.push_back(line);
        else break;
    }
    for(auto s : vs) cout << s << " ";
    cout << endl;
}

template <typename T>
class equality {
public:
    bool operator()(T a, T b) const {
        return a == b;
    }
};

void test37() {
    vector<int> vi = {0, 1, 2, 3, 4, 2, 3, 2, 3};
    equality<int> ei;
    for_each(vi.begin(), vi.end(), [ei](int& i){if(ei(2, i)) i = 100;});
    for(auto i : vi) cout << i << " ";
    cout << endl;
}

class SizeComp{
public:
    SizeComp(size_t n): sz(n) { }
    bool operator()(const string& s) const {
        return s.size() == sz;
    }
private:
    size_t sz;
};

void test38() {
    ifstream fin("text.txt");
    string line;
    vector<string> vs;
    while(getline(fin, line) && !fin.eof()) {
        istringstream ss(line);
        string word;
        while(ss >> word) {
            vs.push_back(word);
        }
    }
    for(int i = 1; i < 11; ++i) {
        cout << i << ": " << count_if(vs.begin(), vs.end(), SizeComp(i)) << endl;
    }
}

void test39() {
    ifstream fin("text.txt");
    string line;
    vector<string> vs;
    while(getline(fin, line) && !fin.eof()) {
        istringstream ss(line);
        string word;
        while(ss >> word) {
            vs.push_back(word);
        }
    }
    cout << "1-9: " << count_if(vs.begin(), vs.end(), [](const string& s){return s.size()>0&&s.size()<10;}) << endl;
    cout << ">=10: " << count_if(vs.begin(), vs.end(), [](const string& s) {return s.size() >= 10;}) << endl;
}

class BigOpe {
public:
    bool operator()(const string& s1, const string& s2) const {
        return s1.size() < s2.size();
    }
    bool operator()(const string& s) {
        return s.size() >= 5;
    }
};
class PrintStr {
public:
    void operator()(const string& s) {
        cout << s << " ";
    }
};

void biggies(vector<string> &words, vector<string>::size_type sz) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    stable_sort(words.begin(), words.end(),
                [](const string &s1, const string &s2){return s1.size() < s2.size();});
    auto wc = find_if(words.begin(), words.end(),
                [sz](string &s){return s.size() >= sz;});
    auto count = words.end() - wc;
    cout << count << " "<< (count > 1 ? "words" : "word") << " of length "
         << sz << " or longger" << endl;
    for_each(wc, words.end(), [](string &s){ cout << s << " ";});
    cout << endl;

}

void test40() {
    vector<string> sve = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    cout << "lambda" << endl;
    biggies(sve, 5);
    cout << "class" << endl;
    sort(sve.begin(), sve.end());
    auto end_unique = unique(sve.begin(), sve.end());
    sve.erase(end_unique, sve.end());
    stable_sort(sve.begin(), sve.end(), BigOpe());
    auto wc = find_if(sve.begin(), sve.end(), BigOpe());
    auto count = sve.end() - wc;
    cout << count << " "<< (count > 1 ? "words" : "word") << " of length 5"
         << " or longger" << endl;
    for_each(wc, sve.end(), PrintStr());
    cout << endl;
}

/**
*template<class Operation, class T>
*binder2nd<Operation> bind2nd (const Operation& op, const T& x) {
*   return binder2nd<Operation>(op, typename Operation::second_argument_type(x));
*}
*template<class Operation, class T>
*binder1st<Operation> bind1st (const Operation& op, const T& x) {
*   return binder1st<Operation>(op, typename Operation::first_argument_type(x));
*}
*bind2nd 表示 op(const T& t, x)
*bind1st 表示 op(x, const T& t)
*x为调用的时候里面的值，t为该函数捕捉到的值
*/
void test42() {
    vector<int> vi = {0, 1, 1038, 2022, 5, 1111, 100};
    vector<string> vs = {"pooh", "pooh", "test", "pooh"};
    auto sum = count_if(vi.begin(), vi.end(), bind2nd(greater<int>(), 1024));
    cout << sum << endl;
    auto first = find_if(vs.begin(), vs.end(), bind2nd(not_equal_to<string>(), "pooh"));
    cout << *first << endl;
    transform(vi.begin(), vi.end(), vi.begin(), bind2nd(multiplies<int>(), 2));
    for(auto i : vi) cout << i << " ";
    cout << endl;
}

void test43() {
    modulus<int> mo;
    cout << 3%9<< " " << 9%3 << endl;
    cout << mo(3, 9)<< " " << mo(9, 3) << endl;
    vector<int> vi = {3, 6, 9, 12 ,15 ,18 ,21};
    for(auto i : vi) cout << i << " ";
    cout << endl << "please input a number :\n";
    int num;
    while(cin >> num && num != 0) {
        int res = count_if(vi.begin(), vi.end(), bind2nd(modulus<int>(), num));
        //cout << res << endl;
        if(res == 0) {
            cout << "could" << endl;
        }else {
            cout << "couldn't" << endl;
        }
    }
}

int add(int i, int j) {return i+j;}
auto mod = [](int i, int j) {return i % j;};
struct divide {
    int operator()(int i, int j) {
        return i / j;
    }
};
void test44() {
    map<string, function<int(int, int)>> binops = {
        {"+", add},
        {"-", minus<int>()},
        {"/", divide()},
        {"%", mod},
        {"*", [](int i, int j) { return i * j;} }
    };
    cout << "10+2=: " << binops["+"](10,2) << endl;
    cout << "10-2=: " << binops["-"](10,2) << endl;
    cout << "10/2=: " << binops["/"](10,2) << endl;
    cout << "10%2=: " << binops["%"](10,2) << endl;
    cout << "10*2=: " << binops["*"](10,2) << endl;
}

class Date {
public:
    Date(int y, int m, int d): year(y), month(m), day(d) { }
    explicit operator bool() const {
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return month>0 && month<12 && day>0 && day <= month0[month] && year > 0;
        else
            return month>0 && month<12 && day>0 && day <= month1[month] && year > 0;
    }
private:
    int year, month, day;
    int month0[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int month1[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
};

void test49() {
    Date b(1997,7,24);
    cout << static_cast<bool>(b) << endl;
    Date b1(1997,-7,24);
    cout << static_cast<bool>(b1) << endl;
}

int main() {
    test49();
    return 0;
}
