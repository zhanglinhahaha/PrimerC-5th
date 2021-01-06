#ifndef _OR_H_
#define _OR_H_
#include "BinaryQuery.h"
#include "Query.h"

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right): BinaryQuery(left, right, "|") {
        if(isDeBug) std::cout << "OrQuery::OrQuery\n";
    }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& text) const {
    if(isDeBug) std::cout << "OrQuery::eval()\n";
    //查询左右两边的对象的结果
    auto right = rhs.eval(text), left = lhs.eval(text);
    //or，将讲个结果合成一个
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}
#endif
