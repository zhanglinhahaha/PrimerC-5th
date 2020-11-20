#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <functional>
#include <fstream>
#include <iterator>

using namespace std;

void test1() {
    vector<int> ive = {0, 1, 2, 3, 4, 4, 4, 5};
    int val;
    while(cin >> val && val != 99) {
        cout << count(ive.begin(), ive.end(), val) << endl;
    }
}

void test2() {
    list<string> ive = {"a", "aa", "aaa", "a", "aa", "a", "b", "c"};
    string val;
    while(cin >> val && val != "q") {
        cout << count(ive.begin(), ive.end(), val) << endl;
    }
}

void test3() {
    vector<double> ive = {0, 1, 2, 3, 4, 4, 4, 5.8};
    cout << accumulate(ive.begin(), ive.end(), 0) << endl;
}

void t() {
    char ch[] = "zhang";
    string s = "zhang";
    char ch2[] = "zhang";
    cout << ch << " " << s << " " << ch2 << endl;
    cout << &ch << " " << &s << " " << &ch2 << endl;
    cout << (ch == ch2) << " " << (ch == s) << " " << (&ch == &ch2) << endl;
}

void test6() {
    vector<int> ive(10);
    fill_n(ive.begin(), ive.size(), 0);
    for(auto i : ive) {
        cout << i << " ";
    }
    cout << endl;
}

void test7() {
    list<int> lst; int i;
    while(cin >> i && i != 0)
        lst.push_back(i);
    vector<int> vec;
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

void test7_2() {
    vector<int> vec;
    //reserve预留空间，没有创建元素对象
    //resize改变容器大小，并且创建对象
    vec.resize(10);
    fill_n(vec.begin(), 10, 0);
    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

void test8() {
    vector<int> ive = {0, 1, 2, 3, 4, 4, 4, 5};
    replace(ive.begin(), ive.end(), 4, 3);
    for(auto i : ive) {
        cout << i << " ";
    }
    cout << endl;
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void test9() {
    vector<string> sve = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    sort(sve.begin(), sve.end());
    auto end_unique = unique(sve.begin(), sve.end());
    sve.erase(end_unique, sve.end());
    for(auto i : sve) {
        cout << i << " ";
    }
    cout << endl;
    sort(sve.begin(), sve.end(), isShorter);
    for(auto i : sve) {
        cout << i << " ";
    }
    cout << endl;
}

struct Sales_data {
    string bookNo;
    Sales_data(string bn) {
        bookNo = bn;
    };
    string isbn() {
        return bookNo;
    };
};

bool compareIsbn(Sales_data &sd1, Sales_data &sd2) {
    return sd1.isbn().size() < sd2.isbn().size();
}

void test12() {
    Sales_data book1("zl");
    Sales_data book2("zzzl");
    Sales_data book3("zzl");
    Sales_data book4("lz");
    vector<Sales_data> vsd = {book1, book2, book3, book4};
    sort(vsd.begin(), vsd.end(), compareIsbn);
    for(auto i : vsd) {
        cout << i.bookNo << " ";
    }
    cout << endl;
}

bool sizeMore5(const string &s) {
    return s.size() >= 5;
}

void test13() {
    vector<string> sve = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto it_end = partition(sve.begin(), sve.end(), sizeMore5);
    for(auto cb = sve.cbegin(); cb < it_end; cb++) {
        cout << *cb << " ";
    }
    cout << endl;
}

void test14() {
    auto sum = [](int a, int b){return a+b;};
    cout << sum(3, 4) << endl;
}

void test15() {
    int m =10;
    auto sum = [m](int a){return a+m;};
    cout << sum(5) << endl;
}

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

void test16() {
    vector<string> sve = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(sve, 5);
}

void test17() {
    Sales_data book1("zl");
    Sales_data book2("zzzl");
    Sales_data book3("zzl");
    Sales_data book4("lz");
    vector<Sales_data> vsd = {book1, book2, book3, book4};
    sort(vsd.begin(), vsd.end(),
        [](Sales_data &sd1, Sales_data &sd2){return sd1.isbn().size() < sd2.isbn().size();});
    for(auto i : vsd) {
        cout << i.bookNo << " ";
    }
    cout << endl;
}

void test18(){
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    int sz = 5;
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    stable_sort(words.begin(), words.end(),
                [](const string &s1, const string &s2){return s1.size() < s2.size();});
    auto wc = partition(words.begin(), words.end(),
                [sz](string &s){return s.size() < sz;});
    auto count = words.end() - wc;
    cout << count << " "<< (count > 1 ? "words" : "word") << " of length "
         << sz << " or longger" << endl;
    for_each(wc, words.end(), [](string &s){ cout << s << " ";});
    cout << endl;
}

void test19(){
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    int sz = 5;
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    stable_sort(words.begin(), words.end(),
                [](const string &s1, const string &s2){return s1.size() < s2.size();});
    auto wc = stable_partition(words.begin(), words.end(),
                [sz](string &s){return s.size() < sz;});
    auto count = words.end() - wc;
    cout << count << " "<< (count > 1 ? "words" : "word") << " of length "
         << sz << " or longger" << endl;
    for_each(wc, words.end(), [](string &s){ cout << s << " ";});
    cout << endl;
}

void test20() {
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto count = count_if(words.begin(), words.end(),
                [](const string &s){return s.size() > 6;});
    cout << count << endl;
}

void test21() {
    int m = 5;
    auto b = [&m]()->bool{return --m;};
    while(b());
    cout << m << endl;
}

bool shorterThan(const string &s, int l) {
    return s.size() <= l;
}

void test22() {
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto count = count_if(words.begin(), words.end(),
                bind(shorterThan, placeholders::_1, 6));
    cout << count << endl;
}

bool shorter(const string &s, int l) {
    return s.size() < l;
}

void test24() {
    vector<int> ive = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string s;
    while(cin >> s && s != "q") {
        auto iter = find_if(ive.begin(), ive.end(), bind(shorter, s, placeholders::_1));
        if(iter != ive.end()) cout << *iter << endl;
    }
}

bool check_size(const string &s, int l) {
    return s.size() >= l;
}

void test25() {
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    stable_sort(words.begin(), words.end(),
                [](const string &s1, const string &s2){return s1.size() < s2.size();});
    auto wc = find_if(words.begin(), words.end(), bind(check_size, placeholders::_1, 5));
    auto count = words.end() - wc;
    cout << count << " "<< (count > 1 ? "words" : "word") << " of length 5 or longger" << endl;
    for_each(wc, words.end(), [](string &s){ cout << s << " ";});
    cout << endl;

}

void test27() {
    vector<int> ive = {1, 2, 2, 3, 3, 3, 4, 5};
    list<int> lst;
    unique_copy(ive.begin(), ive.end(), inserter(lst, lst.begin()));
    for(auto i : lst) cout << i << " ";
    cout << endl;
}

void test28() {
    vector<int> ori = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ive, bve;
    list<int> fve;
    copy(ori.rbegin(), ori.rend(), front_inserter(fve));
    copy(ori.begin(), ori.end(), back_inserter(bve));
    copy(ori.begin(), ori.end(), inserter(ive, ive.begin()));
    for(auto i : fve) cout << i << " ";
    cout << endl;
    for(auto i : bve) cout << i << " ";
    cout << endl;
    for(auto i : ive) cout << i << " ";
    cout << endl;

}

void test29() {
    ifstream in("test.txt");
    istream_iterator<string> str_it(in), end;
    ostream_iterator<string> out_iter(cout, " ");
    copy(str_it, end, out_iter);
    cout << endl;
}

void test30() {
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, " ");
    vector<int> ive(in, eof);
    sort(ive.begin(), ive.end());
    copy(ive.begin(), ive.end(), out);
}

void test31() {
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, " ");
    vector<int> ive(in, eof);
    sort(ive.begin(), ive.end());
    unique_copy(ive.begin(), ive.end(), out);
}


int main() {
    test42();
    return 0;
}
