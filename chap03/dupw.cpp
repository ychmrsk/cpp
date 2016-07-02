#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME


int main()
{
  string previous = " ";
  string current;
  while (cin >> current) {
    if (previous == current)
      cout << "repeated word: " << current << endl;
    previous = current;
  }
}
