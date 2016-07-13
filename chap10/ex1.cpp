#include "../std_lib_facilities.h"

int main()
{
  cout << "Please enter input file name: ";
  string name;
  cin >> name;
  ifstream ist(name.c_str());
  if (!ist) error("can't open input file ", name);
  // ...

  cout << "Please enter name of output file: ";
  string oname;
  cin >> oname;
  ofstream ost(oname.c_str());
  if (!ost) error("can't open output file ", oname);
  // ...
}

