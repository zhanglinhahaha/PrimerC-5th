#include <iostream>
#include <numeric>
#include <iterator>

using namespace std;

void io() {
    istream_iterator<int> in(cin), eof;
    cout << accumulate(in, eof, 0) << endl;
}

int main() {
    io();
    return 0;
}
