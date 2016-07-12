#include "../std_lib_facilities.h"

class Date {
public:
  Date(int y, int m, int d);
  void add_day(int n);
  int month() { return m; }
  int day() { return d; }
  int year() { return y; }
private:
  int y, m, d;
};

Date::Date(int yy, int mm, int dd)
  :y(yy), m(mm), d(dd)
{
}
// Date::Date(int yy, int mm, int dd)
// {
//   y = yy; m = mm; d = dd;
// }

void Date::add_day(int n)
{
  // todo
}


void f()
{
  Date birthday(1970, 12, 30);
  birthday.m = 14;  // error : Date::m is a private member
  cout << birthday.month() << endl;  // ok
}nn


