#include <iostream>
int main(){
    std::cout<<"Sum cal,Ctrl+D get sum.\nprint value:"<<std::endl;
    int sum=0,value=0;
    while(std::cin>>value){
        sum+=value;
    }
    std::cout<<"Sum is: "<<sum<<std::endl; 
    return 0;
}
