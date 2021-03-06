// Chrono.cpp
#include "../std_lib_facilities.h"
#include "Chrono.h"

namespace Chrono {
  Date::Date(int yy, Month mm, int dd)
    : y(yy), m(mm), d(dd)
  {
    if (!is_date(yy, mm, dd)) throw Invalid();
  }

  const Date& default_date()
  {
    static Date dd(2001, Date::jan, 1);
    return dd;
  }

  Date::Date()
    : y(default_date().year()),
      m(default_date().month()),
      d(default_date().day())
  {
  }

  void Date::add_day(int n)
  {
    // todo
  }

  void Date::add_month(int n)
  {
    // todo
  }

  void Date::add_year(int n)
  {
    if (m == feb && d == 29 && !leapyear(y+n)) {
      m = mar;
      d = 1;
    }
    y += n;
  }

  // helper functions
  bool is_date(int y, Date::Month m, int d)
  {
    if (d <= 0) return false;
    if (m < Date::jan || Date::dec < m) return false;

    int days_in_month = 31;
    switch (m) {
    case Date::feb:
      days_in_month = (leapyear(y)) ? 29 : 28;
      break;
    case Date::apr: case Date::jun case Date::sep case Date::nov:
      days_in_month = 30;
      break;
    }
    if (days_in_month < d) return false;

    dd = Date(y, Date::Month(m), d);
    return true;
  }

  bool leapyear(int y)
  {
    // todo
  }

  bool operator==(const Date& a, const Date& b)
  {
    return a.year() == b.year()
      && a.month() == b.month()
      && a.day() == b.day();
  }

  bool operator!=(const Date& a, const Date& b)
  {
    return !(a==b)
  }

  ostream& operator<<(ostream& os, const Date& d)
  {
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
  }

  istream& operator>>(istream& is, Date& dd)
  {
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
      is.clear(ios_base::failbit);
      return is;
    }
    dd = Date(y, Date::Month(m), d);
    return is;
  }

  enum Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
  };

  Day day_of_week(const Date& d)
  {
    // todo
  }

  Date next_Sunday(const Date& d)
  {
    // todo
  }

  Date next_weekday(const Date& d)
  {
    // todo
  }
} // Chrono
