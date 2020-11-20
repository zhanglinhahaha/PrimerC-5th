#include "TextQuery.h"

int main() {
    ifstream fin;
    fin.open("test.txt");
    TextQuery tq(fin);
    string s;
    while(cin>>s && s != "q") {
        QueryResult qr = tq.query(s);
        print(cout, qr);
    }
}
