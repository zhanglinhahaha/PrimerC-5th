#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
 
 int main(int argc,char** argv)
 {
    //*(解引用)运算符优先级优于+(加号)运算符
        int a[3][3] = {1,3,5,7,9,11,13,15,17};
            cout<<"a[2]+1:"<<a[2]+1<<endl;//生成a[2][1]的地址，二维数组中a[2]代表一个一维数组的首地址
                cout<<"*a[2]+1:"<<*a[2]+1<<endl;//先对a[2][0]取值，再加1
                    cout<<"*(a[2]+1):"<<*(a[2]+1)<<endl;//生成a[2][1]的地址，再取值
                        cout<<"(*a[2])+1:"<<(*a[2])+1<<endl;//先对a[2][0]取值，再加1
                         
                            //*(解引用)运算符优先级与+(一元正号)运算符相同，皆为右结合律
                                cout<<"+*a[2]："<<+*a[2]<<endl;
                                 
                                  
                                    //*(解引用)运算符的优先级低于后置递增运算符(++),但是结果为1
                                        //这是一个坑点，因为后置++返回的是原对象的副本，并不会将其递增的结果返回
                                            int c[3]= {1,3,5};
                                                vector<int> b(c,c+3);
                                                    auto p = b.begin();
                                                        cout<<"*p++:"<<*p++<<endl;
                                                         
                                                            cin.get();
                                                                return 0;
                                                                }

