#include<iostream>
using namespace std;
int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;
    a++;
    std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;
    b++;
    std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;
    c++;
    std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;
    d++;
    std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;
    return 0;
}
//编译时 g++ -o decl decltype.cpp -std=c++11
