#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME


int main()
{
  cout << "Please enter your first and second names\n";
  string first;
  string second;
  cin >> first >> second;
  string name = first + ' ' + second;
  cout << "Hello, " << name << endl;
}

