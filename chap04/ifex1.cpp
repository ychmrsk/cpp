#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME


int main()
{
  int a = 0;
  int b = 0;
  cout << "Please enter two integers\n";
  cin >> a >> b;

  if (a < b)
    cout << "max(" << a << "," << b << ") is " << b << "\n";
  else
    cout << "max(" << a << "," << b << ") is " << a << "\n";
}
