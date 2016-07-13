#include "../std_lib_facilities.h"

void skip_to_int()
{
  if (cin.fail()) {
    cin.clear();
    char ch;
    while (cin >> ch) {
      if (isdigit(ch) || ch=='-') {
        cin.unget();
        return;
      }
    }
  }
  error("no input");  // eof or bad
}

int main()
{
  cout << "Please enter an integer in the range 1 to 10:\n";
  int n = 0;

  while (true) {
    cin >> n;
    if (cin) {
      if (1 <= n && n <= 10) break;
      cout << "sorry" << n << "is not in the [1:10] range.\n"
           << "please try again:\n";
    } else {
      cout << "sorry, that was not a number. please try again:\n";
      skip_to_int();
    }
  }
}
