#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME

// cin : character input stream

int main()
{
  cout << "Please enter your first name and age:\n";
  string first_name;
  int age;
  cin >> first_name;
  cin >> age;
  cout << "Hello, " << first_name << " (age " << age << " )\n";
}

