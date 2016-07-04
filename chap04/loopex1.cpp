#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME

int square(int);

int main()
{
  int i = 0;
  while (i < 10) {
    cout << i << '\t' << square(i) << '\n';
    ++i;
  }
}

int square(int x)
{
  return x * x;
}
