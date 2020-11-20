#include <iostream>

using namespace std;

class base {
public:
    int pub = 0;
protected:
    int prot = 1;
private:
    int priv = 2;
};

class pub_derv : public base {
public:
    void memfcn(base &b) {b = *this;}
    int pubd() {
        cout << "pub_derv pub: " << pub << endl;
    }
    void protd() {
        cout << "pub_derv prot: " << prot << endl;
    }
    void privd() {
        //cout << "pub_derv priv: " << priv << endl;
    }
};

class prot_derv : protected base {
public:
    void memfcn(base &b) {b = *this;}
    void pubd() {
        cout << "prot_derv pub: " << pub << endl;
    }
    void protd() {
        cout << "prot_derv prot: " << prot << endl;
    }
    void privd() {
        //cout << "prot_derv priv: " << priv << endl;
    }
};

class priv_derv : private base {
public:
    void memfcn(base &b) {b = *this;}
    void pubd() {
        cout << "priv_derv pub: " << pub << endl;
    }
    void protd() {
        cout << "priv_derv prot: " << prot << endl;
    }
    void privd() {
        //cout << "priv_derv priv: " << priv << endl;
    }
};

class pub_pub_derv : public pub_derv {
public:
    void memfcn(base &b) {b = *this;}
    void pub_pub() {
        cout << "pub_pub_derv pub: " << pub << endl;
    }
    void pub_prot() {
        cout << "pub_pub_derv prot: " << prot << endl;
    }
    void pub_priv() {
        //cout << "pub_pub_derv priv: " << priv << endl;
    }
};

class pub_prot_derv : public prot_derv {
public:
    void memfcn(base &b) {b = *this;}
    void pub_pub() {
        cout << "pub_prot_derv pub: " << pub << endl;
    }
    void pub_prot() {
        cout << "pub_prot_derv prot: " << prot << endl;
    }
    void pub_priv() {
        //cout << "pub_prot_derv priv: " << priv << endl;
    }
};

class pub_priv_derv : public priv_derv {
public:
    void memfcn(base &b) {b = *this;}
    void pub_pub() {
        //cout << "pub_prot_derv pub: " << pub << endl;
    }
    void pub_prot() {
        //cout << "pub_prot_derv prot: " << prot << endl;
    }
    void pub_priv() {
        //cout << "pub_prot_derv priv: " << priv << endl;
    }
};

void test20() {
    pub_derv d1;
    priv_derv d2;
    prot_derv d3;
    pub_pub_derv dd1;
    pub_priv_derv dd2;
    pub_prot_derv dd3;
    base *p = &d1;
    p = &d2;
    p = &d3;
    p = &dd1;
    p = &dd2;
    p = &dd3;
}

int main() {
    test20();
/*
    pub_derv pbd;
    pbd.pubd();
    pbd.protd();
    pbd.privd();
    prot_derv ptd;
    ptd.pubd();
    ptd.protd();
    ptd.privd();
    priv_derv pvd;
    pvd.pubd();
    pvd.protd();
    pvd.privd();
不管base(基类)的派生类是以何种权限继承基类的，在派生类中只能访问public和protected
*/
/*
    pub_priv_derv ppd;
    ppd.pub_pub();
    ppd.pub_prot();
    ppd.pub_priv();
    pub_derv pbd;
    cout << pbd.pub << endl;
    prot_derv ptd;
    //cout << ptd.pub << endl;
    priv_derv pvd;
    //cout << pvd.pub << endl;
*/
    return 0;
}
