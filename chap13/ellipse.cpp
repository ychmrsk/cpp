// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

#include "Simple_window.h" // [Next]button
// #include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
  try {
    Point tl(100, 100);
    Simple_window win(tl, 600, 400, "polyline");

    Ellipse e1(Point(200,200),50,50);
    Ellipse e2(Point(200,200),100,50);
    Ellipse e3(Point(200,200),100,150);

    win.attach(e1);
    win.attach(e2);
    win.attach(e3);

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
