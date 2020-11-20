#ifndef _BINARY_H_
#define _BINARY_H_
#include "Query.h"
#include "Query_base.h"

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
        lhs(l), rhs(r), opSym(s) 
    {
        if(isDeBug) std::cout << "BinaryQuery::BinaryQuery()  where s=" + s + "\n";
    }
    std::string rep() const {
        if(isDeBug) std::cout << "BinaryQuery::rep()\n";
        return "(" + lhs.rep() + " "+ opSym + " "+ rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;
};
#endif
