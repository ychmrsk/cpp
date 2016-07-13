// g++ -std=c++11 test.cpp -lfltk -o test

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

int main()
{
  Fl_Window window(200, 200, "Window title");
  Fl_Box box(0, 0, 200, 200, "Hey, I mean, Hello, world!");
  window.show();
  return Fl::run();
}
