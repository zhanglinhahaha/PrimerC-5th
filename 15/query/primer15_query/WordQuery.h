#ifndef _WORDQUERY_H_
#define _WORDQUERY_H_
#include "Query_base.h"

class WordQuery: public Query_base {
    friend class Query;
    WordQuery(const std::string &s): query_word(s) {
        if(isDeBug)std::cout << "WordQuery::WordQuery(" + s + ")\n";
    }
    QueryResult eval(const TextQuery &t) const {
        if(isDeBug)std::cout << "WordQuery::eval()\n";
        return t.query(query_word);
    }
    std::string rep() const {
        if(isDeBug)std::cout << "WordQuery::rep()\n";
        return query_word;
    }
    std::string query_word;
};
#endif

