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
    std::string s1 = "fiery", s2 = "bird", s3 = "wind";
    std::string s4 = "Daddy", s5 = "Alice", s6 = "hair";
    cout << "=============================\n";
    // Query q0 = Query(s4);
    // Query q1 = ~Query(s5);
    // Query q2 = Query(s5) | Query(s6);
    // Query q3 = Query(s5) & Query(s6);
    Query q4 = Query(s1) & Query(s2) | Query(s3);
    //q0.setDebug(0);
    cout << "=============================\n";
    // cout << q0 << endl;
    // cout << q1 << endl;
    // cout << q2 << endl;
    // cout << q3 << endl;
    cout << q4 << endl;
    cout << "=============================\n";
    // print(cout, q0.eval(tq));
    // print(cout, q1.eval(tq));
    // print(cout, q2.eval(tq));
    // print(cout, q3.eval(tq));
    print(cout, q4.eval(tq));
    return 0;
}
