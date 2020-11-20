#ifndef _NOT_H_
#define _NOT_H_
#include "Query.h"
#include "Query_base.h"

class NotQuery: public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) {
        if(isDeBug) std::cout << "NotQuery::NotQuery()\n";
    }
    std::string rep() const {
        if(isDeBug) std::cout << "NotQuery::rep()\n";
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery&) const ;
    Query query;
};
inline Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery& text) const {
    if(isDeBug) std::cout << "NotQuery::eval()\n";
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for(size_t n = 0; n != sz; ++n) {
        if(beg == end || *beg != n)
            ret_lines->insert(n);
        else if(beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

#endif
