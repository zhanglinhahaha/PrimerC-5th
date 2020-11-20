#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

using namespace std;
using line_no = vector<string>::size_type;

class QueryResult {
friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(string s, shared_ptr<set<line_no>> p,
        shared_ptr<vector<string>> f):
        sought(s), lines(p), file(p){ }
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
}

ostream& print(ostream& os, const QueryResult& qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << ((qr.lines->size) > 1)? "times" : "time" << endl;
    for(auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    }
    return os;
}
