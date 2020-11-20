#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reset(int &val) {
    val = 0;
}

bool isUp(const string &s) {
    auto length = s.size();
    for(decltype(length) i = 0; i != length; i++) {
        if(isupper(s[i])) return false;
    }
    return true;
}

void toLow(string &s) {
    auto length = s.size();
    for(decltype(length) i = 0; i != length; i++) {
        if(isupper(s[i])) s[i] = tolower(s[i]);
    }
    cout << s << endl;
}

void t() {
    string s;
    int n;
    while(cin >> s) {
        cout << isUp(s) << endl;
        toLow(s);
    }
}

int bigger(int val, int *pval) {
    return (val > *pval)? val : *pval;
}

//指引用,交换指针的地址
void swapD(int *&pv1, int *&pv2) {
    int *tmp = pv1;
    pv1 = pv2;
    pv2 = tmp;
}

//指引用,交换指针指向的对象
void swapDv(int *&pv1, int *&pv2) {
    int tmp = *pv1;
    *pv1 = *pv2;
    *pv2 = tmp;
}

//使用指针,交换指针指向的对象
void swapPv(int **pv1, int **pv2) {
    int tmp = **pv1;
    **pv1 = **pv2;
    **pv2 = tmp;
}

//使用指针,交换指针的地址
void swapP(int **pv1, int **pv2) {
    int *tmp = *pv1;
    *pv1 = *pv2;
    *pv2 = tmp;
    cout << **pv1 << **pv2 <<endl;
}

void dobigger() {
    int *v1, *v2;
    int m, n, types;
    while(cin >> m >> n >> types) {
        v1 = &m, v2 = &n;
        cout << bigger(*v1, v2) << endl;
        cout << "before swap : " << *v1 << " " << *v2 << endl;
        switch(types) {
            case 0: swapD(v1, v2);break;
            case 1: swapDv(v1, v2);break;
            case 2: swapP(&v1, &v2);break;
            case 3: swapPv(&v1, &v2);break;
            default: break;
        }
        cout << "after swap : " << *v1 << " " << *v2 << endl;
    }
}

void count(const string &s, char c) {
    cout << c << endl;
}

void print(const int (&ia)[10]) {
    for(int i : ia) {
        cout << i << endl;
    }
}

void doprint() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(a);
}

void dsum(initializer_list<int> il) {
    int sum = 0;
    for(auto iter = il.begin(); iter != il.end(); iter++) {
        sum += *iter;
    }
    cout << sum << endl;
}

void dosum() {
    dsum({1, 2, 3, 4, 5});
    dsum({10, 10, 10, 10, 10, 10, 10, 10, 10, 10});
}

bool str_subrange(const string &str1, const string &str2) {
    if(str1.size() == str2.size()) return str1 == str2;
    auto size = (str1.size() > str2.size())? str2.size() : str1.size();
    for(decltype(size) i = 0; i != size; i++) {
        if(str1[i] != str2[i])
            return 0;
    }
}

int &get(int *arry, int index) {return arry[index]; }

void doget() {
    int ia[10];
    for(int i = 0; i != 10; i++)
        get(ia, i) = i;
    for(auto i : ia) {
        cout << i << endl;
    }
}

void ou(vector<int>::iterator iter, vector<int>::iterator end) {
    cout << *iter <<endl;
    iter++;
    if(iter != end) {
        ou(iter, end);
    }
}

void doou() {
    vector<int> ia = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ou(ia.begin(), ia.end());
}

string (*reStr())[10] {}

void make_plural(const string &s, char c = 's') {
    auto iter = s.crbegin();
    if(*iter == c) cout << s << endl;
    else cout << s+c <<endl;
}

void domake() {
    string s;
    while(cin >> s) {
        make_plural(s);
    }
}

int vecAdd(int v1, int v2) {
    return v1 + v2;
}

int vecSub(int v1, int v2) {
    return v1 - v2;
}

int vecMul(int v1, int v2) {
    return v1 * v2;
}

int vecDiv(int v1, int v2) {
    return v1 / v2;
}

typedef decltype(vecAdd) *vec;
void dovec() {
    int v1, v2;
    vector<vec> v;
    v.push_back(vecAdd);
    v.push_back(vecSub);
    v.push_back(vecMul);
    v.push_back(vecDiv);
    while(cin >> v1 >> v2) {
        cout << "Add : " << v[0](v1, v2) << endl;
        cout << "Sub : " << v[1](v1, v2) << endl;
        cout << "Mul : " << v[2](v1, v2) << endl;
        cout << "Div : " << v[3](v1, v2) << endl;
    }
}

void testzl() {
    vector<int> v = {0, 1, 2, 3};
    cout << v[0] << endl;
}

int main() {
    testzl();
    return 0;
}
