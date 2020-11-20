#include <iostream>
#include <vector>

void t610(int *p, int *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

//typedef int arrT[10];
using arrT = int[5];
//arrT *func0(int i);

int a[] = {1,2,3,4,5};
arrT* func0(int i) {
    for(int i = 0; i < 5; i++) {
        std::cout << a[i] << " ";
    }
    std::cout<<"\n"<< i << "\n";
    return &a;
}

int (*func1(int i))[5] {
    for(int i = 0; i < 5; i++) {
        std::cout << a[i] << " ";
    }
    std::cout<<"\n"<< i << "\n";
    return &a;
}

auto func2(int i) -> int (*)[5] {
    for(int i = 0; i < 5; i++) {
        std::cout << a[i] << " ";
    }
    std::cout<<"\n"<< i << "\n";
    return &a;
}

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

decltype(odd) *func3(int i) {
    return (i % 2) ? &odd : &even;
}

void func() {
    int n=0;
    int (*p0)[5] = func0(n);
    for(int i = 0; i < 5; i++) {
        std::cout << (*p0)[i] << " ";
    }
    std::cout<<"func0 over\n";
    int (*p1)[5] = func1(n);
    for(int i = 0; i < 5; i++) {
        std::cout << (*p1)[i] << " ";
    }
    std::cout<<"func1 over\n";
    int (*p2)[5] = func2(n);
    for(int i = 0; i < 5; i++) {
        std::cout << (*p2)[i] << " ";
    }
    std::cout<<"func2 over\n";
    int (*p)[5] = func3(n);
    for(int i = 0; i < 5; i++) {
        std::cout << (*p)[i] << " ";
    }
    std::cout<<"func3 over\n";
    int test[5] = {0,1,0,1,2};
    int (*q)[5] = &test;
    for(int i = 0; i < 5; i++) {
        std::cout << (*q)[i]<< " ";
    }
    std::cout<<"test over\n";
}

void cer() {
    std::cerr << " Error " <<__FILE__<<"\n";
}

int main() {
    std::vector<int> t = {0,1,2};
    int n = 0, i = 1;
    int *a = &n, *b = &i;
    std::cout<< *a <<" "<<*b<<"\n";
    t610(a, b);
    std::cout<< *a <<" "<<*b<<"\n";
    cer();
    return 0;
}
