/*
const int *p;
指向int类型常量的指针，指针"自以为是"的结果，他们觉得自己指向了常量。
指针指向的值不可以通过此指针更改，但是可以更改指针的指向，也可以改变p1指针指向的值
int *const p;
常量指针，一旦初始化之后，存放在指针中的那个地址就不能再改变，不变的是指针本身而非指向的值
指针指向的值可以通过此指针更改，但是不可以更改指针的指向
*/
#include<iostream>

int main(){
    int a = 3;
    int b = 4;
    //常量指针
    const int *p1 = &a;
    std::cout<<a<<"\t"<<*p1<<std::endl;
    //如果要改变p1的值
    //方法1，改变p1指针指向a的值
    a = 1000;
    std::cout<<a<<"\t"<<*p1<<std::endl;
    //方法2，改变p1指针的指向
    p1 = &b;
    std::cout<<a<<"\t"<<*p1<<std::endl;
    int *const p2 = &b;
    std::cout<<b<<"\t"<<*p2<<std::endl;
    //如果要改变p2的值，直接更改
    *p2 = 100;
    std::cout<<b<<"\t"<<*p2<<std::endl;
}
