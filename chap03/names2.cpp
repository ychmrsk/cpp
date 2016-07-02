#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME


int main()
{
  cout << "Please enter two names\n";
  string first;
  string second;
  cin >> first >> second;
  if (first == second)
    cout << "that's the same name twice\n";
  if (first < second)
    cout << first << " is alphabetically before " << second << endl;
  if (first > second)
    cout << first << " is alphabetically after " << second << endl;
}
