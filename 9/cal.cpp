#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool lower(string l, string h) {
    if((h == "*" || h == "/") && (l == "+" || l == "-")) {
        return true;
    }
    else if(l == "*" && h == "/") {
        return true;
    }
    else if(l == "+" && h == "-") {
        return true;
    }
    else return false;
}

void calcu(stack<int> &v, stack<string> &o) {
    int tmp1 = v.top();
    v.pop();
    int tmp2 = v.top();
    v.pop();
    int tmp;
    string ope = o.top();
    o.pop();
    if(ope == "+") {
        tmp = tmp1 + tmp2;
    }else if(ope == "-") {
        tmp = tmp2 - tmp1;
    }else if(ope == "*") {
        tmp = tmp1 * tmp2;
    }else if(ope == "/") {
        tmp = tmp2 / tmp1;
    }
    v.push(tmp);
}

void cal(string s) {
    auto begin = s.begin();
    stack<string> o;
    stack<int> v;
    while(s.size() != 0) {
        string ele = s.substr(0, s.find_first_of("+-*/()="));
        s = s.substr(s.find_first_of("+-*/()="));
        string ope = s.substr(0, 1);
        s.erase(s.begin());
        //操作数入栈
        if(ele.size() != 0) {
            v.push(stoi(ele));
        }
        //操作符入栈
        if(ope.size() != 0 && ope != "=") {
            if(!o.empty() && lower(ope, o.top())) {
                calcu(v, o);
            }
            if(ope == ")") {
                string l = o.top();
                while(l != "(") {
                    calcu(v, o);
                    l = o.top();
                }
                o.pop();
            }
            else {
                o.push(ope);
            }
        }
    }
    while(!o.empty()) {
        calcu(v, o);
    }
    cout << v.top() << endl;
}

int main() {
    string s;
    while(getline(cin, s) && s != "q") {
        if(*s.end() != '=') s.append("=");
        cal(s);
    }
    return 0;
}
