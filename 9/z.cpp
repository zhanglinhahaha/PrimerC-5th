#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

void test49() {
    fstream fin;
    fin.open("test.txt");
    string de("bdfghjklpqtyBDFGHJKLPQTY");
    int lengthmax = 0;
    string ret;
    if(fin) {
        string word;
        while(fin >> word) {
            auto pos = word.find_first_of(de);
            if(pos == string::npos && lengthmax < word.size()) {
                lengthmax = word.size();
                ret = word;
            }
        }
    }
    fin.close();
    cout << lengthmax << " " << ret << endl;
    return;
}

void test50() {
    vector<string> svec = {"1", "12", "3", "5"};
    float sum = 0;
    for(auto s : svec) sum += stof(s);
    cout << sum << endl;
}

map<string,unsigned int> M = {
{"January", 1}, {"Jan", 1}, {"1", 1},
{"February",2}, {"Feb", 2}, {"2", 2},
{"March", 3}, {"Mar", 3}, {"3", 3},
{"April", 4}, {"Apr", 4}, {"4", 4},
{"May", 5}, {"5", 5},
{"June", 6}, {"Jun", 6}, {"6", 6},
{"July", 7}, {"Jul", 7}, {"7", 7},
{"August", 8}, {"Aug", 8}, {"8", 8},
{"September", 9}, {"Sept", 9}, {"9", 9},
{"October", 10}, {"Oct", 10}, {"10", 10},
{"November", 11}, {"Nov", 11}, {"11", 11},
{"December", 12}, {"Dec", 12}, {"12", 12}
};

struct Date {
    unsigned int year, month, day;
    Date(string date) {
        string m = date.substr(0, date.find_first_of(" ,/"));
        string y = date.substr(date.find_first_of(",/ "));
        y.erase(y.begin());
        string d = y.substr(0, y.find_first_of(" ,/"));
        y = y.substr(y.find_first_of(" ,/"));
        y.erase(y.begin());
        cout << y  << " " << m << " " << d << endl;
        year = stof(y);
        day = stof(d);
        if(M.count(m)) {
            month = M[m];
        }else month = 0;
        cout << year << " " << month << " " << day << endl;
    }
};

void test52() {
    stack<char> cal;
    string s;
    int sum = 0;
    while(getline(cin, s)) {
        auto begin = s.begin();
        while(begin != s.end()) {
            if(*begin != ')') {
                cal.push(*begin);
            }
            else {
                char tmp;

            }
        }
    }
}

int main() {
    test52();
    /*
    string d;
    while(getline(cin, d) && d != "q") {
        Date D(d);
    }
    */
    return 0;
}


