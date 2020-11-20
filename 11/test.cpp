#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <list>
#include <utility>

using namespace std;

void test3() {
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                            "the", "but", "and", "or", "an", "a"};
    string word;
    while(cin >> word && word != "q") {
        //find 返回一个迭代器,如果存在返回关键字,否则返回尾后迭代器
        if(exclude.find(word) == exclude.end())
            //map类型以关键字为下标,获得其对应的值
            ++word_count[word];
    }
    for(const auto &w : word_count) {
        cout << w.first << " occurs " << w.second
            << ((w.second > 1)? " times " : " time ") << endl;
    }
}

void test4() {
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                            "the", "but", "and", "or", "an", "a"};
    string word;
    while(cin >> word && word != "q") {
        int len = word.size() - 1;
        if(word[len] == ',' || word[len] == '.' || word[len] == '!' || word[len] == '?') {
            word = word.substr(0, len);
        }
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if(exclude.find(word) == exclude.end())
            ++word_count[word];
    }
    for(const auto &w : word_count) {
        cout << w.first << " occurs " << w.second
            << ((w.second > 1)? " times " : " time ") << endl;
    }
}

void test7() {
    map<string, vector<string>> home;
    set<string> firstname;
    string s,e;
    while(cin >> s >> e && s != "q") {
        if(firstname.find(s) == firstname.end()) {
            firstname.insert(s);
            cout << "creat a new home" << endl;
            home[s].push_back(e);
        }else {
            cout << "home have exited" << endl;
            home[s].push_back(e);
        }
    }
    for(auto iter = home.begin(); iter != home.end(); ++iter) {
        cout << iter->first << " ";
        for(auto scan = iter->second.begin(); scan < iter->second.end(); ++scan) {
            cout << *scan << " ";
        }
        cout << endl;
    }
}

void test8() {
    vector<string> exclude = {"The", "But", "And", "Or", "An", "A",
                            "the", "but", "and", "or", "an", "a"};
    string s;
    while(cin >> s && s != "q") {
        auto iter = find(exclude.begin(), exclude.end(), s);
        if(iter == exclude.end()) cout << "not exits" << endl;
        else cout << "exits" << endl;
    }
}

void test9() {
    map<string, list<int>> strlst;
    ifstream fin("test.txt");
    int l = 1;
    while(!fin.eof()) {
        string line;
        getline(fin, line);
        stringstream input(line);
        string word;
        while(input >> word) {
            cout << word << " ";
            if(strlst.find(word) == strlst.end()) {
                list<int> def;
                def.push_back(l);
                strlst[word] = def;
            }else {
                auto lst = strlst[word];
                auto findif = find(lst.begin(), lst.end(), l);
                if(findif == lst.end()) {
                    strlst[word].push_back(l);
                }
            }
        }
        cout << endl;
        l++;
    }
    for(auto scan = strlst.begin(); scan != strlst.end(); ++scan) {
        cout << scan->first << "\t";
        for(auto lst = scan->second.begin(); lst != scan->second.end(); ++lst) {
            cout << *lst << "\t";
        }
        cout << "\n";
    }
}

void test12() {
    vector<pair<string, int>> res;
    string s;
    int n = 0;
    while(cin >>s && s != "q") {
        pair<string, int> p = {s, n};
        res.push_back(p);
        n++;
    }
    for(auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
}

void test13() {
    vector<pair<string, int>> res;
    vector<pair<string, int>> res1;
    vector<pair<string, int>> res2;
    string s;
    int n = 0;
    while(cin >>s && s != "q") {
        pair<string, int> p = {s, n};
        pair<string, int> p1(s, n);
        res.push_back(p);
        res1.push_back(make_pair(s, n));
        res2.push_back(p1);
        n++;
    }
    for(auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
    for(auto p : res1) {
        cout << p.first << " " << p.second << endl;
    }
    for(auto p : res2) {
        cout << p.first << " " << p.second << endl;
    }
}

void test14() {
    map<string, pair<string, string>> people;
    string fn, la, bir;
    while(cin >> fn >> la >> bir && fn != "q") {
        people[fn] = make_pair(la, bir);
    }
    for(auto p : people) {
        cout << p.first << p.second.first << p.second.second << endl;
    }
}

void test16() {
    map<string, int> m;
    int n = 0;
    string s = "a";
    for(int i = 0; i < 5; ++i) {
        m[s] = i;
        s = s.append(s);
    }
    for(auto sc = m.begin(); sc != m.end(); ++sc) {
        cout << sc->first << " " << sc->second << endl;
    }
}

void test20() {
    map<string, size_t> word_count;
    string word;
    while(cin >> word && word != "q") {
//        auto ret = word_count.insert({word, 1});
        //insert插入成功res.second为true，ret.first指向word_count[word]的迭代器
//        if(!ret.second) ret.first->second++;
        ++word_count.insert({word, 0}).first->second;
    }
    for(const auto &w : word_count) {
        cout << w.first << " occurs " << w.second
            << ((w.second > 1)? " times " : " time ") << endl;
    }
}

void test22() {
    map<string, vector<int>> msv;
    string s = "a";
    for(int i = 0; i < 5; ++i) {
        msv.insert({s, {i}});
        s = s.append(s);
    }
    for(auto sc = msv.begin(); sc != msv.end(); ++sc) {
        cout << sc->first << " " << *(sc->second.begin()) << endl;
    }
}

void test23() {
    multimap<string, string> home;
    string fn, la;
    while(cin >> fn >> la && fn != "q") {
        home.insert({fn, la});
    }
    for(auto iter = home.begin(); iter != home.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
}

void test26() {
    map<string, int> msi;
    string s = "a";
    for(int i = 0; i < 5; ++i) {
        msi[s] = i;
        s = s.append(s);
    }
    for(auto sc = msi.begin(); sc != msi.end(); ++sc) {
        cout << sc->first << " " << sc->second << endl;
    }
}

void test28() {
    map<string, vector<int>> msv;
    string s = "a";
    vector<int> vi;
    for(int i = 0; i < 5; ++i) {
        vi.push_back(i);
        msv.insert({s, vi});
        s = s.append(s);
    }
    for(auto i : msv.find("aaaa")->second) {
        cout << i << " ";
    }
    cout << endl;
}

void test31() {
    multimap<string, string> books;
    books.insert({"JY", "TLBB"});
    books.insert({"YG", "BLSMY"});
    books.insert({"YG", "BCSJ"});
    books.insert({"LLXXS", "JPM"});
    cout << "origin:" << endl;
    for(auto b : books) {
        cout << b.first << " " << b.second << endl;
    }
    cout << "delete:" << endl;
    for(auto pos = books.equal_range("JY"); pos.first != pos.second; ++pos.first) {
        cout << pos.first->first << " " << pos.first->second << endl;
        books.erase(pos.first->first);
    }
    cout << "end:" << endl;
    for(auto begin = books.begin(); begin != books.end(); ++begin) {
        cout << begin->first << " " << begin->second << endl;
    }
}

int main() {
    test31();
    return 0;
}
