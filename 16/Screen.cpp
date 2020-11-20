#include <iostream>
#include <string>

using namespace std;

template <unsigned H, unsigned W>
class Screen {
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(char c): contents(H*W, c) { }
    char get() const { return contents[cursor]; }
    Screen &move(pos r, pos c) {
        pos row = r * width;
        cursor = row + c;
        return *this;
    }
    void set(pos r, pos c, char a) {
        contents[r*width + c] = a;
    }
    friend ostream& operator<<(ostream& os, const Screen<H, W>& c) {
        unsigned int i, j;
        for(i = 0; i < c.height; ++i) {
            os << c.contents.substr(i*W, W) << endl;
        }
        return os;
    }
    friend istream& operator>>(istream& is, Screen<H, W>& c) {
        char a;
        is >> a;
        string tmp(H*W, a);
        c.contents = tmp;
        return is;
    }
private:
    pos cursor = 0;
    pos height = H, width = W;
    string contents;
};

int main() {
    Screen<10, 20> s;
    cin >> s;
    cout << s;
    s.move(3, 5);
    s.set(3, 5, 'z');
    cout << s.get() << endl;
    cout << s;
    return 0;
}
