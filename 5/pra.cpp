#include <iostream>

using namespace std;

void test() {
    int ival1, ival2;
    while(cin >> ival1 >> ival2) {
        if(ival1 != ival2)
            ival1 = ival2;
        else ival1 = ival2 = 0;
        cout << ival1 << " " << ival2 << endl;
    }
}

int main() {
    test();
    return 0;
}
