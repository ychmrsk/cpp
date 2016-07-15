#include "../std_lib_facilities.h"

class my_vector {
  int sz;
  double* elem;
public:
  my_vector(int s);
  int size() const { return sz; }
};

int main()
{
  char ch = 'c';
  char* pc = &ch;

  int ii = 17;
  int* pi = &ii;

  cout << "pc == " << pc << ", contents of pc == " << *pc << "\n";
  cout << "pi == " << pi << ", contents of pi == " << *pi << "\n";

  *pc = 'x';
  *pi = 27;
  
  cout << "pc == " << pc << ", contents of pc == " << *pc << "\n";
  cout << "pi == " << pi << ", contents of pi == " << *pi << "\n";

  cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(true) << '\n';
  cout << "the size of char is " << sizeof(char) << ' ' << sizeof('a') << '\n';
  cout << "the size of int  is " << sizeof(int)  << ' ' << sizeof(2+2) << '\n';
  cout << "the size of double is " << sizeof(double) << ' ' << sizeof(2.0) << '\n';

  int* p = 0;
  bool* pb = 0;
  double* pd = 0;

  cout << "the size of bool* is " << sizeof(bool*) << ' ' << sizeof(pb) << '\n';
  cout << "the size of char* is " << sizeof(char*) << ' ' << sizeof(pc) << '\n';
  cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
  cout << "the size of double* is " << sizeof(double*) << ' ' << sizeof(pd) << '\n';

  vector<int> v(1000);
  cout << "the size of vector<int>(1000) is " << sizeof(v) << '\n';

}
