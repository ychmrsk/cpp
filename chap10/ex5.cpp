#include "../std_lib_facilities.h"

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
    } else if (cin.fail()) {
      cin.clear();
      cout << "sorry, that was not a number. please try again.\n";
      char ch;
      while (cin >> ch && !isdigit(ch))
        ;
      if (!cin) error("no input");
      cin.unget();
    } else {  // eof or bad
      error("no input");
    }
  }
}
