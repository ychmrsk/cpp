// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

#include "Simple_window.h" // [Next]button
// #include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
  try {
    Point tl(100, 100);
    Simple_window win(tl, 600, 400, "rectangle");

    Rectangle rect00(Point(150,100), 200, 100);
    Rectangle rect11(Point(50,50), Point(250,150));
    Rectangle rect12(Point(50,150), Point(250,250));
    Rectangle rect21(Point(250,50), 200, 100);
    Rectangle rect22(Point(250,150), 200, 100);

    rect00.set_fill_color(Color::yellow);
    rect11.set_fill_color(Color::blue);
    rect12.set_fill_color(Color::red);
    rect21.set_fill_color(Color::green);

    win.attach(rect00);
    win.attach(rect11);
    win.attach(rect12);
    win.attach(rect21);
    win.attach(rect22);

    rect11.move(400,0);
    rect11.set_fill_color(Color::white);
    win.set_label("rectangle2");

    win.put_on_top(rect00);
    win.set_label("rectangle3");

    rect00.set_color(Color::invisible);
    rect11.set_color(Color::invisible);
    rect12.set_color(Color::invisible);
    rect21.set_color(Color::invisible);
    rect22.set_color(Color::invisible);
    
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
