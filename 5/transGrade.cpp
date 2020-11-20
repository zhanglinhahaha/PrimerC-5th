#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void transIf() {
    int grade;
    while(cin >> grade) {
        if(grade >= 90) {
            cout << "A"  << endl;
        }
        else if(grade >= 80) {
            cout << "B"  << endl;
        }
        else if(grade >= 60) {
            cout << "C"  << endl;
        }
        else {
            cout << "D"  << endl;
        }
    }
}

void trans() {
    int grade;
    while(cin >> grade) {
        (grade >= 90)? cout << "A" << endl :
            (grade >= 80)? cout << "B" << endl :
                (grade >= 60)? cout << "C" << endl : cout << "D" << endl;
    }
}

void count() {
    string seq;
    while(cin >> seq) {
        int Cnt = 0;
        string::iterator iter = seq.begin();
        while(iter != seq.end()) {
            if(*iter == 'a' || *iter == 'e' || *iter == 'i' || *iter == 'o' || *iter == 'u') {
                Cnt++;
            }
            iter++;
        }
        cout << Cnt << endl;
    }
}

void countSt() {
    string seq;
    while(getline(cin, seq)) {
        int aCnt =0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
        int blank = 0, t = 0, n = 0;
        int ff = 0, fl = 0, fi = 0;
        string::iterator iter = seq.begin();
        while(iter != seq.end()) {
            switch(*iter) {
                case'a':
                case'A':
                    aCnt++;break;
                case'e':
                case'E':
                    eCnt++;break;
                case'i':
                case'I':
                    iCnt++;break;
                case'o':
                case'O':
                    oCnt++;break;
                case'u':
                case'U':
                    uCnt++;break;
                case' ':
                    blank++;break;
                case'\t':
                    t++;break;
                case'\n':
                    n++;break;
                case'f':
                    {
                        string::iterator next = iter + 1;
                        if(*next == 'f' ) ff++;
                        else if(*next == 'l') fl++;
                        else if(*next == 'i') fi++;
                        break;
                    }
                default:break;
            }
            iter++;
        }
        cout << "aCnt: " << aCnt << endl;
        cout << "eCnt: " << eCnt << endl;
        cout << "iCnt: " << iCnt << endl;
        cout << "oCnt: " << oCnt << endl;
        cout << "uCnt: " << uCnt << endl;
        cout << "blank: " << blank << endl;
        cout << "t: " << t << endl;
        cout << "n: " << n << endl;
        cout << "ff: " << ff << endl;
        cout << "fl: " << fl << endl;
        cout << "fi: " << fi << endl;
    }
}

void countWord() {
    string line, word;
    while(getline(cin, line)) {
        string w;
        int count = 0, n = 0;
        istringstream record(line);
        string before;
        record >> before;
        while(record >> word) {
            if(word == before) {
                n++;
            }else {
                if(n >= count) {
                    count = n;
                    w = before;
                }
                n = 0;
                before = word;
            }
        }
        if(n >= count) {
            count = n;
            w = before;
        }
        if(count == 0) {
            cout << "没有连续单词出现过" <<endl;
        }
        else {
            cout << w << " " << count+1 <<endl;
        }
    }
}

bool com() {
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    auto max = v2.begin();
    auto min = v1.begin();
    while(min != v1.end()) {
        if(*max != *min) return false;
        max++, min++;
    }
    return true;
}

void comStr() {
    cout << "请输入两个string" << endl;
    string str1,str2;
    cin >> str1 >> str2;
    do {
        if(str1.size() > str2.size()) {
            cout << str2 << endl;
        }
        else cout << str1 <<endl;
    }while(cin>>str1>>str2);
}

void printRe() {
    string before, word;
    bool flag = true;
    cin>>before;
    while(cin>>word) {
        if(word == before) {
            cout << "Re" << endl;
            flag = false;
            break;
        }
        if(word == "0") break;
        before = word;
    }
    if(flag) cout << "success" << endl;
}

void devide() {
    int v1, v2;
    while(cin>>v1>>v2) {
        try {
            if(v2 == 0) {
                throw runtime_error("除数为0");
            }
            cout << v1/v2 << endl;
        }
        catch(runtime_error err) {
            cout << err.what() << endl;
            cout << "Try again or Give up, Enter Y to continue " << endl;
            char c;
            cin>>c;
            if(c != 'y' && c != 'Y') {break;}
            cout << "agin:" << endl;
        }
    }
}

int main() {
    devide();
    return 0;
}
