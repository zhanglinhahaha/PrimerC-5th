#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <deque>

using namespace std;

bool test4(vector<int>::iterator begin, const vector<int>::iterator end, int n) {
    while(begin != end) {
        if(*begin == n) return true;
        begin++;
    }
    return false;
}

void test6() {
    list<int> lst;
    auto begin = lst.begin();
    auto end = lst.end();
    while(begin != end) cout << *begin++ << endl;
}

void test13() {
    list<int> lst = {0, 1, 2, 3, 4};
    vector<int> ive = {4, 3, 2, 1, 0};
    vector<double> dve(lst.begin(), lst.end());
    vector<double> dve2(ive.begin(), ive.end());
    for(auto d : dve) cout << d << " ";
    cout << endl;
    for(auto d : dve2) cout << d << " ";
    cout << endl;
}

void test14() {
    list<char*> lst = {"a", "aa", "aaa"};
    vector<string> sve(lst.begin(), lst.end());
    for(auto s : sve) cout << s << endl;
}

bool test15(vector<int> ive1, vector<int> ive2) {
    auto bive1 = ive1.cbegin();
    auto bive2 = ive2.cbegin();
    while(bive1 != ive1.cend() && bive2 != ive2.cend()) {
        if(*bive1 != *bive2) return false;
        bive1++;
        bive2++;
    }
    if(bive1 == ive1.cend() && bive2 == ive2.cend()) return true;
    else return false;
}

void test18() {
    string s;
    deque<string> ds;
    while(cin >> s && s != "q") {
        ds.push_back(s);
    }
    for(auto s : ds) cout << s << endl;
}

void test20() {
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "全部数：" << endl;
    for(auto d : lst) cout << d << " ";
    cout << endl;
    deque<int> d1, d2;
    auto begin = lst.cbegin();
    while(begin != lst.cend()) {
        if(*begin % 2 == 0) d1.push_back(*begin);
        else d2.push_back(*begin);
        begin++;
    }
    cout << "偶数：" << endl;
    for(auto d : d1) cout << d << " ";
    cout << endl;
    cout << "奇数：" << endl;
    for(auto d : d2) cout << d << " ";
    cout << endl;
}

void test24() {
    vector<int> ive = {0, 1, 2};
    vector<int> ivetmp;
    cout << ive[0] << " " << ive.front() << " " << *ive.begin() << endl;
    cout << ivetmp[0] << " " << ivetmp.front() << " " << *ivetmp.begin() << endl;
}

void test26() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec;
    ivec.assign(ia, ia + 11);
    list<int> ilst;
    ilst.assign(ia, ia + 11);
    auto vbegin = ivec.begin();
    auto lbegin = ilst.begin();
    for(int i = 0; i < 11; i++) {
        if(*vbegin % 2 == 0) {
            vbegin = ivec.erase(vbegin);
        }else {
            vbegin++;
        }
        if(*lbegin % 2 == 1) {
            lbegin = ilst.erase(lbegin);
        }else {
            lbegin++;
        }
    }
    for(auto i : ivec) cout << i << " ";
    cout << endl;
    for(auto i : ilst) cout << i << " ";
    cout << endl;
}

void test27() {
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();
    auto begin = flst.begin();
    while(begin != flst.end()) {
        if(*begin % 2) {
            begin = flst.erase_after(prev);
        }else {
            prev = begin++;
        }
    }
    for(int i : flst) cout << i << " ";
    cout << endl;
}

void Inser(forward_list<string> &flst, string ser, string in) {
    auto prev = flst.before_begin();
    auto begin = flst.begin();
    while(begin != flst.end()) {
        if(*begin == ser) {
            flst.insert_after(begin,in);
            return;
        }
        prev=begin++;
    }
    flst.insert_after(prev, in);
    return;
}
void test28() {
    forward_list<string> flst = {"I", "am", "ITer"};
    string ser, in;
    cin >> ser >> in;
    Inser(flst, ser, in);
    for(auto s : flst) cout << s << " ";
    cout << endl;
    cin >> ser >> in;
    Inser(flst, ser, in);
    for(auto s : flst) cout << s << " ";
    cout << endl;
}

void test31() {
    list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while(iter != vi.cend()) {
        if(*iter % 2) {
            iter = vi.insert(iter, *iter);
            iter++;
            iter++;
        }else {
            iter = vi.erase(iter);
        }
    }
    for(auto i : vi) cout << i << " ";
    cout << endl;
}

void test38() {
    vector<int> vec;
    vec.reserve(10);
    cout << vec.size() << " " << vec.capacity() << endl;
    while(vec.size() != vec.capacity()) {
        vec.push_back(1);
    }
    cout << vec.size() << " " << vec.capacity() << endl;
    vec.push_back(1);
    cout << vec.size() << " " << vec.capacity() << endl;
}

void test41() {
    vector<char> vec = {'s', 't', 'r', 'i', 'n', 'g'};
    string s;
    for(auto c : vec) s += c;
    cout << s << endl;
}

void Rep(string &s, string oldVal, string newVal) {
    auto begin = s.begin();
    while(begin != s.end()) {
        if(*begin == oldVal[0] ) {
            string tmp(begin, begin + oldVal.size());
            if(tmp == oldVal) {
                begin = s.insert(begin, newVal.begin(), newVal.end());
                begin += newVal.size();
                s.erase(begin, begin + oldVal.size());
            }
            else begin++;
        }
        else begin++;
    }
}
void Rep2(string &s, string oldVal, string newVal) {
    auto begin = s.begin();
    while(begin != s.end()) {
        if(*begin == oldVal[0] ) {
            string tmp(begin, begin + oldVal.size());
            if(tmp == oldVal) {
                s.replace(begin, begin + oldVal.size(), newVal);
                begin += newVal.size();
            }
            else begin++;
        }
        else begin++;
    }
}
void test43() {
    string s = "tho, go out.";
    Rep2(s, "tho", "though");
    cout << s << endl;
}

void Add(string &name, string pre, string nex) {
    auto begin = name.begin();
    name.insert(begin, pre.begin(), pre.end());
    name.append(nex);
}
void Add2(string &name, string pre, string nex) {
    name.insert(name.size(), nex);
    name.insert(0, pre);
}
void test45() {
    string name("aqiang");
    Add2(name, "Mr.", "|||");
    cout << name << endl;
}

void test47() {
    string s = "ab2c3d7R4E6";
    string num = "0123456789";
    cout << s << endl;
    auto pos = s.find_first_of(num);
    do{
        cout << s[pos] << " ";
        pos++;
        pos = s.find_first_of(num, pos);
    }while(pos != string::npos);
    cout << endl;
    auto p = s.find_first_not_of(num);
    do{
        cout << s[p] << " ";
        p++;
        p = s.find_first_not_of(num, p);
    }while(p != string::npos);
    cout << endl;
}

void test48() {
    string numbers("0123456789"), name("r2d2");
    cout << numbers.find(name) << endl;
}

int main() {
    /*
    vector<int> v;
    for(int i = 0; i < 10; ++i) v.push_back(i);
    auto begin = v.begin();
    auto end = v.end();
    int n;
    while(cin >> n && n != 0)
        cout << test4(begin, end, n) << endl;
    vector<int> v1 = {0,1,2};
    vector<int> v2 = {0,1,2};
    cout << test15(v1,v2) << endl;
    vector<int> t = {0, 1, 2, 3, 4};
    auto begin = t.begin();
    begin++;
    cout << *begin << endl;
    begin = t.insert(begin,10);
    begin += 2;
    cout << *begin << endl;
    for(auto i : t) cout << i << " ";
    cout << endl;
    */
    test48();
    return 0;
}
