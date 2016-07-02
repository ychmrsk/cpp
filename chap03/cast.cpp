#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME


int main()
{
  int a = 20000;
  char c = a;
  int b = c;
  if (a != b)
    cout << "oops!: " << a << " != " << b << endl;
  else
    cout << "Wow! We have large characters\n";
}
