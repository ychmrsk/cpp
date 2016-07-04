#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME

int square(int);

int main()
{
  for (int i = 0; i < 10; ++i)
    cout << i << '\t' << square(i) << '\n';
}

int square(int x)
{
  return x * x;
}
