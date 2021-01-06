#include "TextQuery.h"
#include "Query_base.h"
#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "NotQuery.h"

std::ostream& operator<<(std::ostream& os, const Query& query) {
    return os << query.rep();
}

int main() {
    ifstream fin;
    fin.open("test.txt");
    TextQuery tq(fin);
    std::string s1 = "fiery", s2 = "bird";
    Query_base::setDebug(false);

	Query q1(s1), q2(s2);
	AndQuery aq(q1, q2);

    // 19.6
	Query_base* qb = &aq;
    if(AndQuery* aqt = dynamic_cast<AndQuery*> (qb)) {
        print(cout, aqt->eval(tq));
    }else {
        cout << "dynamic_cast error\n";
    }

    // 19.7
    Query_base& p = aq;
	try{
		AndQuery& ap = dynamic_cast<AndQuery&>(p);
		print(cout, ap.eval(tq));
	}
	catch (bad_cast){
		cout << "dynamic_cast error\n";
	}

    // 19.8
    cout << (typeid(*qb) == typeid(p)) << " " << (typeid(*qb) == typeid(AndQuery)) << endl;
    return 0;
}
