#ifndef _AND_H_
#define _AND_H_
#include "BinaryQuery.h"
#include <algorithm>

class AndQuery: public BinaryQuery {
public:
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right): BinaryQuery(left, right, "&") {
        if(isDeBug) std::cout << "AndQuery::AndQuery()\n";
    }
    QueryResult eval(const TextQuery&) const ;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery& text) const {
    if(isDeBug) std::cout << "AndQuery::eval()\n";
    auto right = rhs.eval(text), left = lhs.eval(text);
    //and，求两个结果的并集
    auto ret_lines = make_shared<set<line_no>>();
    std::set_intersection(left.begin(), left.end(),
                     right.begin(), right.end(),
                    inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

#endif
