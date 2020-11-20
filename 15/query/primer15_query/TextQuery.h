#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_
#include "QueryResult.h"

class QueryResult;
class TextQuery {
public:
    TextQuery(ifstream&);
    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

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

QueryResult TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}
#endif // _TEXTQUERY_H_
