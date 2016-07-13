#include "../std_lib_facilities.h"

/*
int main()
{
  int i = 0;
  cin >> i;
  if (!cin) {
    if (cin.bad()) error("cin is bad");
    if (cin.eof()) {
      // end of file
    }
    if (cin.fail()) {
      cin.clear();
      // recovery
    }
  }
}
*/

void fill_vector(istream& ist, vector<int>& v, char terminator)
{
  int i = 0;
  while (ist >> i) v.push_back(i);
  if (ist.eof()) return;
  if (ist.bad()) error("ist is bad");
  if (ist.fail()) {
    ist.clear();
    char c;
    ist >> c;
    if (c != terminator) {
      ist.unget();
      ist.clear(ios_base::failbit);
    }
  }
}


ist.exceptions(ist.exceptions()|ios_base::badbit);

void fill_vector(istream& ist, vector<int>& v, char terminator)
{
  int i = 0;
  while (ist >> i) v.push_back(i);
  if (ist.eof()) return;

  // not good, bad, eof => fail
  ist.clear();
  char c;
  ist >> c;
  if (c != terminator) {
    ist.unget();
    ist.clear(ios_base::failbit);
  }
}

