#include "../std_lib_facilities.h"

class Date {
public:
  class Invalid {};
  Date(int y, int m, int d);
  void add_day(int n);
  int month() { return m; }
  int day() { return d; }
  int year() { return y; }
private:
  int y, m, d;
  bool check();  // invalid date??
};

Date::Date(int yy, int mm, int dd)
  :y(yy), m(mm), d(dd)
{
  if (!check()) throw Invalid();
}

bool Date::check()
{
  if (m<1 || 12<m) return false;
  // ...
}

void Date::add_day(int n)
{
  // todo
}


void f(int x, int y)
  try {
    Date dxy(2004, x, y);
    cout << dx << '\n';
    dxy.add_day(2);
  }
  catch (Date::Invalid) {
    error("invalid date");
  }

