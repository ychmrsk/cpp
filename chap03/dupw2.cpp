#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME


int main()
{
  int number_of_words = 0;
  string previous = " ";
  string current;
  while (cin >> current) {
    ++number_of_words;
    if (previous == current)
      cout << "word number " << number_of_words
           << " repeated word: " << current << endl;
    previous = current;
  }
}
