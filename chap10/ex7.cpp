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

int get_int()
{
  int n = 0;
  while (true) {
    if (cin >> n) return n;
    cout << "Sorry, that was not a number. please try again:\n";
    skip_to_int();
  }
}

int get_int(int low, int high)
{
  cout << "please enter an integer in the range "
       << low << " to " << high << " (inclusive):\n";
  while (true) {
    int n = get_int();
    if (low <= n && n <= high) return n;
    cout << "sorry " << n << " is not in the [" << low << ":" << high
         << "] range. please try again:\n";
  }
}

int main()
{
  int n = get_int(1, 10);
}

