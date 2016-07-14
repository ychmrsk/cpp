// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

#include "Simple_window.h" // [Next]button
// #include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double) { return 1; }

double slope(double x) { return x/2; }

double square(double x) { return x*x; }

double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
  try {
    const int xmax = 600;
    const int ymax = 400;

    const int x_orig = xmax/2;
    const int y_orig = ymax/2;
    const Point orig(x_orig, y_orig);

    const int r_min = -10;
    const int r_max = 11;

    const int n_points = 400;

    const int x_scale = 30;
    const int y_scale = 30;

    Simple_window win(Point(100, 100), xmax, ymax, "graph");

    Function s(one, r_min, r_max, orig, n_points, x_scale, y_scale);
    Function s2(slope, r_min, r_max, orig, n_points, x_scale, y_scale);
    Function s3(square, r_min, r_max, orig, n_points, x_scale, y_scale);

    win.attach(s);
    win.attach(s2);
    win.attach(s3);

    Text ts(Point(100, y_orig-40), "one");
    Text ts2(Point(100, y_orig+y_orig/2-20), "x/2");
    Text ts3(Point(x_orig-100, 20), "x*x");

    ts.set_font_size(14);
    ts2.set_font_size(14);
    ts3.set_font_size(14);

    win.attach(ts);
    win.attach(ts2);
    win.attach(ts3);

    const int xlength = xmax-40;
    const int ylength = ymax-40;

    Axis x(Axis::x, Point(20, y_orig), xlength, xlength/x_scale, "one notch == 1");
    Axis y(Axis::y, Point(x_orig, ylength+20), ylength, ylength/y_scale, "one notch == 1");

    x.label.set_font_size(14);
    y.label.set_font_size(14);
    
    win.attach(x);
    win.attach(y);

    Function s4(cos, r_min, r_max, orig, 400, 30, 30);
    s4.set_color(Color::blue);
    Function s5(sloping_cos, r_min, r_max, orig, 400, 30, 30);
    x.label.move(-160, 0);
    x.label.set_font_size(14);
    x.notches.set_color(Color::dark_red);

    win.attach(s4);
    win.attach(s5);

    Function f1(log, 0.000001, r_max, orig, 200, 30, 30);
    Function f2(sin, r_min, r_max, orig, 200, 30, 30);
    f2.set_color(Color::blue);
    Function f3(cos, r_min, r_max, orig, 200, 30, 30);
    Function f4(exp, r_min, r_max/2, orig, 200, 30, 30);
    f4.set_color(Color::green);

    win.attach(f1);
    win.attach(f2);
    win.attach(f3);
    win.attach(f4);
    
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
