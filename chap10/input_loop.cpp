#include "../std_lib_facilities.h"

class My_type {};

int main()
{
  My_type var;

  while (ist >> var) {
    // ...
  }
  if (ist.bad()) error("bad input stream");
  if (ist.fail()) {
    //... terminator?
  }
  // ... EOF detected
}

// ************************************************************

int main()
{
  ist.exceptions(ist.exceptions()|ios_base::badbit);

  My_type var;

  while (ist >> var) {
    // ...
  }
  if (ist.fail()) {
    ist.clear();
    char ch;
    if (!(ist >> ch && ch == '|'))
      error("bad termination of input");
  }
}

// ************************************************************

void end_of_loop(istream& ist, char term, const string& message)
{
  if (ist.fail()) {
    ist.clear();
    char ch;
    if (ist >> ch && ch == term) return;
    error(message);
  }
}

int main()
{
  ist.exceptions(ist.exceptions()|ios_base::badbit);

  My_type var;

  while (ist >> var) {
    // ...
  }
  end_of_loop(ist, '|', "bad termination of file");

  // ... EOF detected
}
