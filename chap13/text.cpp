// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

#include "Simple_window.h" // [Next]button
// #include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
  try {
    Point tl(100, 100);
    Simple_window win(tl, 600, 400, "polyline");

    Open_polyline opl;
    opl.add(Point(100,100));
    opl.add(Point(150,200));
    opl.add(Point(250,250));
    opl.add(Point(300,200));

    win.attach(opl);

    Closed_polyline cpl;
    cpl.add(Point(200,100));
    cpl.add(Point(250,200));
    cpl.add(Point(350,250));
    cpl.add(Point(400,200));
    cpl.add(Point(200,250));

    win.attach(cpl);

    Text t(Point(200,200), "A closed polyline that isn't a polygon");
    t.set_color(Color::blue);
    //    t.set_font(Graph_lib::Font::times_bold);
    t.set_font_size(14);
    win.attach(t);

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
