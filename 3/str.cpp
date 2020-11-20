#include <iostream>
#include <string>

int main(){
    //如果没有加std::，只使用string会报错
    std::string s1 = "hello";
    std::cout<<s1<<'\n';
    return 0;
}
