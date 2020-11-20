#include "window_mgr.h"

int main() {
    Window_mgr win;
    win.getScreen(0).display(cout);
    win.clear(0);
    win.getScreen(0).display(cout);
    Screen s(10, 115, 'z');
    s.move(4, 0).set('#').display(cout);
    cout<<"\n";
    auto i = win.addScreen(s);
    win.getScreen(i).display(cout);
    win.clear(i);
    win.getScreen(i).display(cout);
    return 0;
}
