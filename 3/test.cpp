#include <iostream>
#include <string>
#include <vector>

void test() {
    int ia[] = {0,1,2,3,4};
    //ia2 是指针
    //auto 定义的变量必须有初始值
    auto ia2(ia);
    //ia3是数组
    //ia3 = ia; 数组不允许拷贝
    decltype(ia) ia3 = {0,1,2,3,4};
    std::cout<<*ia2<<" "<<ia3[0]<<"\n";
}

void dou() {
    std::vector<int> n;
    for(int i=0; i<10; i++) {
        n.push_back(i);
    }
    for(auto r : n) {
        std::cout<<r<<" ";
    }
    std::cout<<"\n";
    for(auto &r : n) {
        r = 2*r;
    }

    for(auto r : n) {
        std::cout<<r<<" ";
    }
    std::cout<<"\n";
}

int main(){
    std::string s1 = "Hello";
    std::string s2 = "Hiya";
    std::cout<<(s2>s1)<<"\n";
    std::cout<<('A'>'B')<<"\n";
    std::string s = "some string";
    if(s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
    }
    std::cout<<s<<"\n";
    for(auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
        *it = toupper(*it);
    }
    std::cout<<s<<"\n";
    dou();
    test();
    return 0;
}
