#ifndef _QUERY_H_
#define _QUERY_H_
#include <memory>
#include "TextQuery.h"
#include "WordQuery.h"

class Query_base;
class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string& s): q(new WordQuery(s)) {
        if(q->isDeBug) std::cout << "Query::Query(const std::string& s) where s="+s+"\n";
    }
    QueryResult eval(const TextQuery &t) const {
        if(q->isDeBug) std::cout << "Query::eval()\n";
        return q->eval(t);
    }
    std::string rep() const {
        if(q->isDeBug) std::cout << "Query::rep()\n";
        return q->rep();
    }
    void setDebug(bool b) {
        q->isDeBug = b;
    }
    bool getDebug() {
        return q->isDeBug;
    }
private:
    Query(std::shared_ptr<Query_base> query): q(query) {
        std::cout << "Query::Query(std::shared_ptr<Query_base> query)\n";
    }
    std::shared_ptr<Query_base> q;
};
#endif
