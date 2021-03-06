// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

// #include "Simple_window.h" // [Next]button
#include "std_lib_facilities.h"
#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include <iostream>

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
  Lines_window(Point xy, int w, int h, const string& title);
  Open_polyline lines;
private:
  Button next_button;
  Button quit_button;
  In_box next_x;
  In_box next_y;
  Out_box xy_out;

  static void cb_next(Address, Address);
  void next();
  static void cb_quit(Address, Address);
  void quit();
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
  : Window(xy, w, h, title),
    next_button(Point(x_max()-150, 0), 70, 20, "Next point", cb_next),
    quit_button(Point(x_max()-70, 0), 70, 20, "Quit", cb_quit),
    next_x(Point(x_max()-310, 0), 50, 20, "next x:"),
    next_y(Point(x_max()-210, 0), 50, 20, "next y:"),
    xy_out(Point(100, 0), 100, 20, "current (x,y):")
{
  attach(next_button);
  attach(quit_button);
  attach(next_x);
  attach(next_y);
  attach(xy_out);
  attach(lines);
}

void Lines_window::cb_quit(Address, Address pw)
{
  reference_to<Lines_window>(pw).quit();
}

void Lines_window::quit()
{
  hide();
}

void Lines_window::cb_next(Address, Address pw)
{
  reference_to<Lines_window>(pw).next();
}

void Lines_window::next()
{
  int x = next_x.get_int();
  int y = next_y.get_int();

  lines.add(Point(x, y));

  ostringstream ss;
  ss << '(' << x << ',' << y << ')';
  xy_out.put(ss.str());

  redraw();
}


int main()
  try {
    Lines_window win(Point(100, 100), 600, 400, "lines");
    return gui_main();
  }
  catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch (...) {
    cerr << "some exception\n";
    return 2;
  }

