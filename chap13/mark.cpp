// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

#include "Simple_window.h" // [Next]button
// #include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
  try {
    Point tl(100, 100);
    Simple_window win(tl, 600, 400, "mark");

    Marked_polyline mpl("1234");
    mpl.add(Point(100,100));
    mpl.add(Point(150,200));
    mpl.add(Point(250,250));
    mpl.add(Point(300,200));

    win.attach(mpl);

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
