#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME


int main()
{
  cout << "Please enter a floating-point value: ";
  double n;
  cin >> n;
  cout << "n == " << n
       << "\nn+1 == " << n+1
       << "\nthree times n == " << 3*n
       << "\ntwice n == " << n+n
       << "\nn squared == " << n*n
       << "\nhalf of n == " << n/2
       << "\nsquare root of n == " << sqrt(n)
       << endl;
}

