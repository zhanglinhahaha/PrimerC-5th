#ifndef _QUERYRESULT_H_
#define _QUERYRESULT_H_
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

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(string s, shared_ptr<set<line_no>> p,
        shared_ptr<vector<string>> f):
        sought(s), lines(p), file(f){ }
    const shared_ptr<vector<string>> get_file() const{return file;}
    std::set<line_no>::iterator
    begin(){ return lines->begin();}
    std::set<line_no>::iterator
    end(){ return lines->end();}
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream &print(ostream & os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << (((qr.lines->size()) > 1)? " times " : " time ") << endl;
    for(auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    }
    return os;
}
#endif // _QUERYRESULT_H_
