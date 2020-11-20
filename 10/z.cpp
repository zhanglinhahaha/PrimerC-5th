#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <functional>
#include <fstream>
#include <iterator>

using namespace std;

struct Sale_data {
    string bookNo;
    double price;
    int num;
};

istream &operator>>(istream &is, Sale_data &item) {
    is >> item.bookNo >> item.price >> item.num;
    return is;
}

ostream &operator<<(ostream &os,const Sale_data &item) {
    os << item.bookNo << " " << item.price << " " << item.num;
    return os;
}

bool compareIsbn(const Sale_data &sd1, const Sale_data &sd2) {
    return sd1.bookNo.size() < sd2.bookNo.size();
}

void test32() {
    istream_iterator<Sale_data> in(cin), eof;
    ostream_iterator<Sale_data> out(cout, "\n");
    vector<Sale_data> sve(in, eof);
    copy(sve.begin(), sve.end(), out);
    sort(sve.begin(), sve.end(), compareIsbn);
    copy(sve.begin(), sve.end(), out);
}

void oddEven(const string &in, const string &odd, const string &even) {
    ifstream fin(in);
    ofstream foutodd(odd);
    ofstream fouteven(even);
    istream_iterator<int> i(fin), eof;
    ostream_iterator<int> oodd(foutodd, "\n");
    ostream_iterator<int> oeven(fouteven, "\n");
    while(i != eof) {
        if(*i%2) oodd = *i;
        else oeven = *i;
        i++;
    }
}

void test33() {
    oddEven("num.txt", "odd.txt", "even.txt");
}

void test34() {
    ifstream fin("num.txt");
    istream_iterator<int> in(fin), eof;
    vector<int> ive(in, eof);
    for(auto rbe = ive.crbegin(); rbe < ive.crend(); ++rbe) {
        cout << *rbe << " ";
    }
    cout << endl;
}

void test35() {
    ifstream fin("num.txt");
    istream_iterator<int> in(fin), eof;
    vector<int> ive(in, eof);
    for(auto end = ive.cend() - 1; end >= ive.cbegin(); --end) {
        cout << *end << " ";
    }
    cout << endl;
}

void test36() {
    list<int> lst = {0, 1, 2, 3, 0, 1, 2, 0, 2, 3, 0, 4};
    auto last = find(lst.crbegin(), lst.crend(), 0);
    cout << *last << *last.base() << endl;
}

void test37() {
    vector<int> ive = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst(ive.crbegin()+2, ive.crend()-3);
    for(auto i : lst) cout << i << " ";
    cout << endl;
}

void test() {
    vector<int> ive = {0, 1, 2, 3, 4};
    replace(ive.begin(), ive.end(), 2, 8);
    for(auto i : ive) cout << i << " "; cout << endl;
}

void test42() {
    list<string> lst = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    lst.sort();
    lst.unique();
    for(auto s : lst) cout << s << " "; cout << endl;
}

int main() {
    test42();
    return 0;
}
