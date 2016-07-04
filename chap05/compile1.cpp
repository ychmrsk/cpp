#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME

int area(int, int);

int main()
{
  /*
  int s1 = area(7;
  int s2 = area(7)
  Int s3 = area(7);
  int s4 = area('7);

  int x0 = arena(7);
  int x1 = area(7);
  int x2 = area("seven", 2)
  */

  int x4 = area(10, -7);
  int x5 = area(10.7, 9.3);
  char x6 = area(100, 9999);

  cout << x4 << x5 << x6 << endl;
}

int area(int length, int width)
{
  return length * width;
}
