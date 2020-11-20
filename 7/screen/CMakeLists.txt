project(SCREEN)
add_definitions(-std=c++11)
set(SRC_LIST window_mgr.h screen.cpp screen.h main.cpp)
add_executable(screen ${SRC_LIST})
