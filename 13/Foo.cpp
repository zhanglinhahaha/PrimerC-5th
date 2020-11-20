#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
public:
    Foo(vector<int> &v) : data(v) { }
    Foo sorted() && {
        cout << "&&" << endl;
        sort(data.begin(), data.end());
        return *this;
    }
    Foo sorted() const &{
        cout << "const &" << endl;
        return Foo(*this).sorted();
        //Foo ret(*this);
        //return ret.sorted();
        //sort(ret.data.begin(), ret.data.end());
        //return *this;
    }
private:
    vector<int> data;
};

int main() {
    vector<int> tmp = {0,2,1,3};
    Foo f0(tmp);
    f0.sorted();
}
