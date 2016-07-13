#include "../std_lib_facilities.h"

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
