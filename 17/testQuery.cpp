#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

using namespace std;
typedef vector<string>::size_type line_no;
typedef tuple<string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>>  result_tuple;

class TextQuery {
public:
    TextQuery(ifstream&);
    result_tuple query(const string &) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

ostream &print(ostream & os, const result_tuple &qr) {
    os << get<0>(qr) << " occurs " << get<1>(qr)->size() << " "
       << (((get<1>(qr)->size()) > 1)? " times " : " time ") << endl;
    for(auto num : *(get<1>(qr))) {
        os << "\t(line " << num + 1 << ") "
           << *(get<2>(qr)->begin() + num) << endl;
    }
    return os;
}

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
    string text;
    while(getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word) {
            auto &lines = wm[word];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

result_tuple TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return result_tuple(sought, nodata, file);
    else
        return result_tuple(sought, loc->second, file);
}

int main() {
    ifstream fin;
    fin.open("test.txt");
    TextQuery tq(fin);
    string s;
    while(cin>>s && s != "q") {
        result_tuple qr = tq.query(s);
        print(cout, qr);
    }
}
