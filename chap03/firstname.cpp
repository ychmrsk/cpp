#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME

// cin : character input stream

int main()
{
  cout << "Please enter your first name:\n";
  string first_name;
  cin >> first_name;
  cout << "Hello, " << first_name << "!\n";
}
