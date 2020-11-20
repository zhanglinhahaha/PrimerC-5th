#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include "screen.h"
class Window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen&);
    Screen getScreen(ScreenIndex i) {
        return screens[i];
    }
private:
    vector<Screen> screens{Screen(5, 115, 'w')};
};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size()-1;
}

#endif
