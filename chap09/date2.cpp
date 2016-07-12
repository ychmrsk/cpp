#include "../std_lib_facilities.h"

struct Date {
  int y;  // year
  int m;  // month
  int d;  // date
};

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
