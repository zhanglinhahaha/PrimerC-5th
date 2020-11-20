#include <iostream>

std::istream & read(std::istream &in) {
    int num;
    while(in>>num) {
        std::cout<<num<<" ";
    }
    std::cout<<"\n";
    return in;
}

int main() {
    read(std::cin);
    return 0;
}
