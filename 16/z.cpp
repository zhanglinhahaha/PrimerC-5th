#include <iostream>
#include <string>
#include <functional>

template <typename T>
void print(std::ostream &os, T t) {
    os << t << " ";
}

template <typename T>
int compare(const T &v1, const T &v2) {
    if(std::less<T>()(v1, v2)) return -1;
    if(std::less<T>()(v2, v1)) return 1;
    return 0;
}

int main() {
    int m, n;
    while(std::cin >> m >> n && m != 0) {
       print(std::cout, m);
       print(std::cout, n);
       print(std::cout, compare(m, n));
       std::cout << "\n";
    }
    std::string q, r;
    while(std::cin >> q >> r && q != "q") {
       print(std::cout, q);
       print(std::cout, r);
       print(std::cout, compare(q, r));
       std::cout << "\n";
    }
    return 0;
}
