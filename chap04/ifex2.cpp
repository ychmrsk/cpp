#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME


int main()
{
  const double cm_per_inch = 2.54;
  double length = 1;
  char unit = ' ';
  cout << "Please enter a length followed by a unit (c or i)\n";
  cin >> length >> unit;

  if (unit == 'i')
    cout << length << "in == " << cm_per_inch * length << "cm\n";
  else if (unit == 'c')
    cout << length << "cm == " << length / cm_per_inch << "in\n";
  else
    cout << "Sorry, I don't know a unit called '" << unit << "'\n";
}

