#include <iostream>

using namespace std;

int fact(int val) {
    int sum = 1;
    while(val > 1) sum *= val--;
    return sum;
}

int t66(int);
void interaction() {
    int n;
    cout << "please input a value" << endl;
    while(cin >> n) cout << "return = " << t66(n) << endl;
}

int t65(int val) {
    return (val > 0)? val : -val;
}

int t66(int val) {
    int sum = 0;
    static int count = 0;
    sum++;
    cout << "val = " << val << endl;
    cout << "sum = " << sum << endl;
    if(count == 0) {
        count++;
        cout << "count = " << count << endl;
        return 0;
    }
    else {
        count++;
        cout << "count = " << count << endl;
        return 1;
    }
}

void swap(int *v1, int *v2) {
    int tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

void s() {
    int v1, v2;
    while(cin >> v1 >>v2) {
        cout << "before swap : " << v1 << " " << v2 << endl;
        swap(&v1, &v2);
        cout << "after swap : " << v1 << " " << v2 << endl;
    }
}

int main() {
    s();
    return 0;
}
