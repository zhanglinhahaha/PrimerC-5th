#include <iostream>
#include <string>

using namespace std;

class Animals {
public:
    Animals(string n): name(n) { }
    virtual void speak() = 0;
    virtual ~Animals() {
        cout << "~Animals" << endl;
    }
protected:
    string name;
};

class Dog : public Animals {
public:
    Dog(string s): Animals(s) { }
    void speak() override {
        cout << "I'm " << name << ", and wang wang wang..." << endl;
    }
    ~Dog() {
        cout << "~Dog" << endl;
    }
};

class Cat : public Animals {
public:
    Cat(string s): Animals(s) { }
    void speak() override {
        cout << "I'm " << name << ", and miao miao miao..." << endl;
    }
    ~Cat() {
        cout << "~Cat" << endl;
    }
};

int main() {
    Dog d("xiaohei");
    Cat c("tom");
    Animals* a = &d;
    a->speak();
    a = &c;
    a->speak();
    cout << "a over" << endl;
    Animals *b = new Cat("sec");
    delete b;
    cout << "b over" << endl;
    return 0;
};
