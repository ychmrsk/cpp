// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

#include "Simple_window.h" // [Next]button
// #include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
  try {
    Point tl(100, 100);

    Simple_window win(tl, 600, 400, "canvas");

    Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");
    win.attach(xa);
    win.set_label("canvas #2");

    Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("canvas #3");

    Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);
    win.attach(sine);
    win.set_label("canvas #4");
    
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
