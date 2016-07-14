// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

#include "Simple_window.h" // [Next]button
// #include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
  try {
    Point tl(100, 100);
    Simple_window win(tl, 600, 400, "mark");

    Circle c1(Point(100, 200), 50);
    Circle c2(Point(150, 200), 100);
    Circle c3(Point(200, 200), 150);

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    
    Mark m1(Point(100, 200), 'x');
    Mark m2(Point(150, 200), 'y');
    Mark m3(Point(200, 200), 'z');
    c1.set_color(Color::blue);
    c2.set_color(Color::red);
    c3.set_color(Color::green);

    win.attach(m1);
    win.attach(m2);
    win.attach(m3);

    win.wait_for_button();
  }
  catch (exception& e) {
    // error
    return 1;
  }
  catch (...) {
    // error
    return 2;
  }
