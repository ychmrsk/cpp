#include "../std_lib_facilities.h"

char ch;
while (cin.get(ch)) {
  if (isspace(ch)) {
    // skip
  }
  if (isdigit(ch)) {
    // digit
  }
  else if (isalpha(ch)) {
    // identifier
  }
  else {
    // operator
  }
 }

