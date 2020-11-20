#include <iostream>
#include <string>
#include <limits>
/*
4种求值顺序
逻辑与运算符：&& 先计算左侧，左侧为真继续计算右侧
逻辑或运算符：||
条件运算符：?:
逗号运算符：,

如果m%n不等于0，则它的符号与m相同；
*/

using std::cout;
void t41() {
    cout<<"*****4.1*****"<<"\n";
    cout<<"5+10*20/2 = "<<5+10*20/2<<"\n";
    cout<<"*****4.2*****"<<"\n";
    std::string s = "Hello World!";
    cout<<"*s.begin() = "<<*s.begin()<<"\n";
    cout<<"*(s.begin()) = "<<*(s.begin())<<"\n";
    cout<<"*s.begin()+1 = "<<*s.begin()+1<<"\n";
    cout<<"(*s.begin())+1 = "<<(*s.begin())+1<<"\n";
}

void t42() {
    cout<<"*****4.4*****"<<"\n";
    cout<<"12/3*4+5*15+24%4/2 = "<<12/3*4+5*15+24%4/2<<"\n";
    cout<<"*****4.5*****"<<"\n";
    cout<<"-30*3+21/5 = "<<-30*3+21/5<<"\n";
    cout<<"-30+3*21/5 = "<< -30+3*21/5<<"\n";
    cout<<"30/3*21%5 = "<<30/3*21%5<<"\n";
    cout<<"-30/3*21%4 = "<<-30/3*21%4<<"\n";
    cout<<"*****4.6*****"<<"\n";
    int i;
    while(1) {
        std::cin>>i;
        if(i%2 == 0) {
            cout<<i<<" is a even number"<<"\n";
            if(i==0)break;
        }
        else{
            cout<<i<< " is a odd number"<<"\n";
        }
    }
    cout<<"*****4.7*****"<<"\n";
    int value = std::numeric_limits<int>::max();
    cout<<"int value "<< std::numeric_limits<int>::max()<<" + 1 = "<<value+1<<"\n";
}

void t43() {
    cout<<"*****4.9*****"<<"\n";
    const char *cp = "Hello World";
    if(cp && *cp) {
        cout<<cp<<" "<<*cp<<"\n";
    }
    cout<<"*****4.10*****"<<"\n";
    int value;
    while(1) {
        std::cin>>value;
        if(value == 42) {
            break;
        }
    }
    cout<<"*****4.11*****"<<"\n";
    int a,b,c,d;
    while(1){
        std::cin>>a>>b>>c>>d;
        if(a>b&&b>c&&c>d) {
            cout<<"sucessful!"<<"\n";
            break;
        }
    }
    cout<<"*****4.12*****"<<"\n";
    int i,j,k;
    while(1) {
        std::cin>>i>>j>>k;
        cout<<(i!=j<k)<<"\n";
        if(i == 0 && j ==0) {
            break;
        }
    }
}

int main() {
    t41();
    t42();
    t43();
    return 0;
}
