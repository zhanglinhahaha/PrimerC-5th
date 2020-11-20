#include <iostream>
#include <string>

int main() {
    std::string s;
    operator>>(std::cin, s);
    std::cout << s << "\n";
    return 0;
}
