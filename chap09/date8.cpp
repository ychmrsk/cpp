#include "../std_lib_facilities.h"

/*
  1. enumeration
     - 関連する名前がついた一連の整数定数が必要な場合に使用する
  2. overload of operator
*/

class Date {
public:
  class Invalid {};
  enum Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };
  Date(); // default constructor
  Date(int y, Month m, int d);
  void add_day(int n);
  int month() const { return m; }
  int day() const { return d; }
  int year() const { return y; }
private:
  int y;  // year
  Month m;
  int d;  // day
  bool check();  // invalid date??
};

const Date& default_date()
{
  static Date dd(2001, Date::jan, 1);
  return dd;
}

Date::Date()
  :y(default_date().year()),
   m(default_date().month()),
   d(default_date().day())
{
}

Date::Date(int yy, Month mm, int dd)
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

