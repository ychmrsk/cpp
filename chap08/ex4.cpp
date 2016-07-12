#include "../std_lib_facilities.h"
#include <string>
#include <iostream>

namespace Graph_lib {
  struct Color {};
  struct Shape {};
  struct Line : Shape {};
  struct Function : Shape {};
  struct Text : Shape {};
  // ...
  int gui_main() {}
}

namespace TextLib {
  class Text {};
  class Glyph {};
  class Line {};
  // ...
}

/* ************************************************************ */

int main()
{
  std::string name;
  std::cout << "Please enter your first name\n";
  std::cin >> name;
  std::cout << "Hello, " << name << '\n';
}

/* ************************************************************ */
using std::string;
using std::cout;

int main()
{
  string name;
  cout << "Please enter your first name\n";
  std::cin >> name;
  cout << "Hello, " << name << '\n';
}

/* ************************************************************ */
using namespace std;

int main()
{
  string name;
  cout << "Please enter your first name\n";
  cin >> name;
  cout << "Hello, " << name << '\n';
}
