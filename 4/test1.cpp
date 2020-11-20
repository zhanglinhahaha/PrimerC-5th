#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;

void t44() {
    int i,i1;
    double d,d1;
    d = i = 3.5;
    i1 = d1 = 3.5;
    cout << d <<" "<<i<<"\n";
    cout << d1 <<" "<<i1<<"\n";
/*
    if(42 = i) {
        cout<<"42 = i"<<"\n";
  }
*/
    if(i = 42) {
        cout<<"i = 42"<<"\n";
    }
    double dval;
    int ival, *pi;
    dval = ival = 0;
    pi = 0;
    cout<<dval<<" "<<ival<<" "<<pi<<"\n";
}

void t47() {
    int v[10]={0,1,2,3,4,5,6,7,8,9};
    std::vector<int> vi(v,v+10);
    for(auto &i : vi) {
       cout<<((i%2 == 0)? i : i*2)<<" ";
    }
    cout<<"\n";

}

void t422() {
    int grade;
    while(cin>>grade) {
        if(grade >= 90) {
            cout << "high pass"<<"\n";
        }
        else if(grade >= 75) {
            cout << "pass"<<"\n";
        }
        else if(grade >= 60) {
            cout << "low pass"<<"\n";
        }
        else{
            cout << "fail"<<"\n";
        }
    }
}

void t4221() {
    int grade;
    while(cin>>grade) {
        cout<<(grade>=90?"high pass" : grade>=75?"pass" : grade>=60?"low pass" :"fail")<<"\n";
    }
}

void t423() {
    std::string s = "word";
    std::string s1 = s +( s[s.size()-1] == 's'? "" : "s");
    cout<<s1<<"\n";
}

void t425() {
    cout<<sizeof(int)<<" "<<sizeof(char)<<"\n";
    cout<< (~'q'<<6) <<"\n";
}

void t428() {
    cout<<"bool"<<sizeof(bool)<<"\n";
    cout<<"char"<<sizeof(char)<<"\n";
    cout<<"long"<<sizeof(long)<<"\n";
    cout<<"unsigned long"<<sizeof(unsigned long)<<"\n";
    cout<<"int"<<sizeof(int)<<"\n";
    cout<<"unsigned int"<<sizeof(unsigned int)<<"\n";
    cout<<"short"<<sizeof(short)<<"\n";
    cout<<"long long"<<sizeof(long long)<<"\n";
    cout<<"float"<<sizeof(float)<<"\n";
    cout<<"double"<<sizeof(double)<<"\n";
    cout<<"long double"<<sizeof(long double)<<"\n";
}

void t429() {
    int x[10];
    int *p = x;
    cout<< sizeof(x)/sizeof(*x) <<"\n";
    cout<< sizeof(*x) <<"\n";
    cout<< sizeof(x) <<"\n";
    cout<< sizeof(p)/sizeof(*p) <<"\n";
    cout<< sizeof(*p) <<"\n";
    cout<< sizeof(p) <<"\n";
}

void t432() {
    constexpr int size = 5;
    int ia [size] = {1,2,3,4,5};
    for(int *ptr = ia, ix=0;ix != size && ptr != ia+size;++ix, ++ptr) {
    cout << ix <<" "<< ptr <<" "<<ia+ix<< " "<<ia+size<<"\n";
    }
}

void t433() {
    int x = 1, y =5;
    cout << (x>y? ++x,++y : --x,--y)<<"\n";
    cout << x <<" "<<y<<"\n";
    int x1 = 1, y1 =5;
    cout << (x1<y1? ++x1,++y1 : --x1,--y1)<<"\n";
    cout << x1 <<" "<< y1 <<"\n";
}

void t436() {
    int i = 2;
    double d = 3.14;
    cout << (i*=static_cast<int>(d))<<"\n";
}

void t437() {
    int i;double d;
    const std::string *ps;
    char *pc;
    void *pv;
    pv = static_cast<void*>(const_cast<std::string*>(ps));
    i = static_cast<int>(*pc);
    pv = static_cast<void*>(&d);
    pc = static_cast<char*>(pv);
}

int main() {
    t437();
    return 0;
}
