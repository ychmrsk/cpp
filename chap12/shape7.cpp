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
    sine.set_color(Color::blue);
    win.attach(sine);
    win.set_label("canvas #4");

    Polygon poly;
    poly.add(Point(300, 200));
    poly.add(Point(350, 100));
    poly.add(Point(400, 200));

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("canvas #5");

    Rectangle r(Point(200, 200), 100, 50);
    win.attach(r);
    win.set_label("canvas #6");

    Closed_polyline poly_rect;
    poly_rect.add(Point(100,50));
    poly_rect.add(Point(200,50));
    poly_rect.add(Point(200,100));
    poly_rect.add(Point(100,100));
    poly_rect.add(Point(50,75));
    win.attach(poly_rect);

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("canvas #7");

    
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
