#include "../std_lib_facilities.h"

/*
  1. enumeration
     - 関連する名前がついた一連の整数定数が必要な場合に使用する
  2. overload of operator
*/

enum Month {
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum Day {
  monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

Month int_to_month(int x)
{
  if (x < jan || dec < x) error("bad month");
  return Month(x);
}

Month operator++(Month& m)
{
  m = (m == Dec) ? Jan : Month(m+1);
  return m;
}

vector<string> month_tbl;

ostream& operator<<(ostream& os, Month m)
{
  return os << month_tbl[m];
}


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

