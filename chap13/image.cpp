// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

#include "Simple_window.h" // [Next]button
// #include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
  try {
    Point tl(100, 100);
    Simple_window win(tl, 600, 400, "image");

    Image rita(Point(0, 0), "rita.jpg");
    Image path(Point(0, 0), "rita_path.gif");
    path.set_mask(Point(50, 250), 600, 400);

    win.attach(path);
    win.attach(rita);


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
