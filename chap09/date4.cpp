#include "../std_lib_facilities.h"

class Date {
  int y, m, d;
public:
  Date(int y, int m, int d);
  void add_day(int n);
  int month() { return m; };
  int day() { return d; };
  int year() { return y; }
};

void f()
{
  Date birthday(1970, 12, 30);
  birthday.m = 14;  // error : Date::m is a private member
  cout << birthday.month() << endl;  // ok
}




struct Date {
  int y, m, d;  // year, month, day
  Date(int y, int m, int d);  // constructor
  void add_day(int n);
};

void f()
{
  Date my_birthday;  // error : not initialized
  Date today(12, 24, 2007);  // runtime error
  Date last(2000, 12, 31);  // ok
  Date christmas = Date(1976, 12, 24);  // ok
}

void g()
{
  Date birthday(1960, 12, 31);
  ++birthday.d;  // invalid date

  Date today(1970, 2, 3);
  today.m = 14;  // invalid date
}


// helper functions
void init_day(Date& dd, int y, int m, int d)
{
  // confirm effectivity of date, and initialize it
}

void add_day(Date& dd, int n)
{
  // add n-days to dd
}

void f()
{
  Date today;
  init_day(today, 12, 24, 2005);
  add_day(today, 1);
}

void g()
{
  Date today;
  // ...
  cout << today << '\n';
  // ...
  init_day(today, 2008, 3, 30);
  // ...
  Date tomorrow;
  tomorrow.y = today.y;
  tomorrow.m = today.m;
  tomorrow.d = today.d+1;
  cout << tomorrow << '\n';
}

int main()
{
  Date today;
  today.y = 2005;
  today.m = 24;
  today.d = 12;

  Date x;
  x.y = -3;
  x.m = 13;
  x.d = 32;

  Date y;
  y.y = 2000;
  y.m = 2;
  y.d = 29;
}
