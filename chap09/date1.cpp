#include "../std_lib_facilities.h"

struct Date {
  int y;  // year
  int m;  // month
  int d;  // date
};

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
