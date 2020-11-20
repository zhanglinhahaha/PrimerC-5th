#ifndef _QUERY_BASE_H_
#define _QUERY_BASE_H_
#include "TextQuery.h"

class Query_base {
    friend class Query;
protected:
    virtual ~Query_base() = default;
    static bool isDeBug;
private:
    //查询结果函数
    virtual QueryResult eval(const TextQuery&) const = 0;
    //返回基础查询的string表示形式
    virtual std::string rep() const = 0;
public:
    void setDebug(bool b) { isDeBug = b;}
    bool getDebug() { return isDeBug;}
};

bool Query_base::isDeBug = true;

#endif // _QUERY_BASE_H_
