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
  Menu color_menu;

  static void cb_red(Address, Address);
  static void cb_blue(Address, Address);
  static void cb_black(Address, Address);

  void red_pressed() { change(Color::red); }
  void blue_pressed() { change(Color::blue); }
  void black_pressed() { change(Color::black); }

  void change(Color c) { lines.set_color(c); }
  
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
    xy_out(Point(100, 0), 100, 20, "current (x,y):"),
    color_menu(Point(x_max()-70, 40), 70, 20, Menu::vertical, "color")
{
  attach(next_button);
  attach(quit_button);
  attach(next_x);
  attach(next_y);
  attach(xy_out);
  attach(lines);
  color_menu.attach(new Button(Point(0, 0), 0, 0, "red", cb_red));
  color_menu.attach(new Button(Point(0, 0), 0, 0, "blue", cb_blue));
  color_menu.attach(new Button(Point(0, 0), 0, 0, "black", cb_black));
  attach(color_menu);
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

void Lines_window::cb_red(Address, Address pw)
{
  reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::cb_blue(Address, Address pw)
{
  reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_black(Address, Address pw)
{
  reference_to<Lines_window>(pw).black_pressed();
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

