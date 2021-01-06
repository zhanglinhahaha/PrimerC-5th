#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_
//#include "QueryResult.h"
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

class TextQuery {
public:
	class QueryResult;
    TextQuery(ifstream&);
    QueryResult query(const std::string &) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class TextQuery::QueryResult {
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

std::ostream &print(ostream & os, const TextQuery::QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << (((qr.lines->size()) > 1)? " times " : " time ") << endl;
    for(auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
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

TextQuery::QueryResult TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return TextQuery::QueryResult(sought, nodata, file);
    else
        return TextQuery::QueryResult(sought, loc->second, file);
}
#endif // _TEXTQUERY_H_
