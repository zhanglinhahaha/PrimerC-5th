#include <iostream>
#include <string>
#include <cctype>
void numpunct(std::string str) {
    decltype(str.size()) punct_num = 0;
    for(auto c : str) {
        if(ispunct(c)) punct_num++;
    }
    std::cout<<str<<" has puncts : "<<punct_num<<"\n";
}

void toUp(std::string str) {
    for(auto &c : str) {
        c = toupper(c);
    }
    std::cout<<str<<"\n";
}

int main() {
    std::string s1("hello,world!");
    numpunct(s1);
    toUp(s1);
    return 0;
}
