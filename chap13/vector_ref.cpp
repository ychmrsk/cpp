// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

#include "Simple_window.h" // [Next]button
// #include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
  try {
    Point tl(100, 100);
    Simple_window win(tl, 600, 400, "vector ref");

    Vector_ref<Rectangle> vr;

    for (int i=0; i<16; ++i)
      for (int j=0; j<16; ++j) {
        vr.push_back(new Rectangle(Point(i*20, j*20), 20, 20));
        vr[vr.size()-1].set_fill_color(Color(i*16+j));
        win.attach(vr[vr.size()-1]);
      }
    
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
