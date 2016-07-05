#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME

int main()
{
  cout << "Please enter expression (we can handle + - * /):\n";
  int lval = 0;
  int rval;
  char op;
  cin >> lval;

  if (!cin) error("no first operand");
  while (cin >> op) {
    cin >> rval;
    if (!cin) error("no second operand");
    switch (op) {
    case '+':
      lval += rval;
      break;
    case '-':
      lval -= rval;
      break;
    case '*':
      lval *= rval;
      break;
    case '/':
      lval /= rval;
      break;
    default:
      cout << "Result: " << lval << '\n';
      return 0;
    }
  }
  error("bad expression");
}

