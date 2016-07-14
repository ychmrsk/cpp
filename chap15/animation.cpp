// g++ -std=c++11 NAME.cpp GUI.cpp Graph.cpp Simple_window.cpp Window.cpp -lfltk -lfltk_images -o NAME

#include "Simple_window.h" // [Next]button
// #include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

double fac(double n)
{
  double r = 1;
  while (n > 1) {
    r *= n;
    --n;
  }
  return r;
}

double term(double x, int n)
{
  return pow(x, n) / fac(n);
}

double expe(double x, int n)
{
  double sum = 0;
  for (int i=0; i<n; ++i)
    sum += term(x, i);
  return sum;
}

int expN_number_of_terms = 10;

double expN(double x)
{
  return expe(x, expN_number_of_terms);
}

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

    Simple_window win(Point(100, 1000), xmax, ymax, "graph");

    Function real_exp(exp, r_min, r_max, orig, 200, x_scale, y_scale);
    real_exp.set_color(Color::blue);
    win.attach(real_exp);

    for (int n=0; n<50; ++n) {
      ostringstream ss;
      ss << "exp approximation: n==" << n;
      win.set_label(ss.str());
      expN_number_of_terms = n;
      Function e(expN, r_min, r_max, orig, 200, x_scale, y_scale);
      win.attach(e);
      win.wait_for_button();
      win.detach(e);
    }
    //    win.wait_for_button();
  }
  catch (exception& e) {
    // error
    return 1;
  }
  catch (...) {
    // error
    return 2;
  }
