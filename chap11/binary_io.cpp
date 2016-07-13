#include "../std_lib_facilities.h"

// chap 17 ~ 19
template<class T>
char* as_bytes(T& i)
{
  void* addr = &i;

  return static_cast<char*>(addr);
}


int main()
{
  cout << "please enter input file name\n";
  string name;
  cin >> name;
  ifstream ifs(name.c_str(), ios_base::binary);
  if (!ifs) error("can't open input file ", name);

  cout << "please enter output file name\n";
  cin >> name;
  ofstream ofs(name.c_str(), ios_base::binary);
  if (!ofs) error("can't open output file ", name);

  vector<int> v;

  int i;
  while (ifs.read(as_bytes(i), sizeof(int)))
    v.push_back(i);

  // ... some operation using v

  for (int i=0; i<v.size(); ++i)
    ofs.write(as_bytes(v[i]), sizeof(int));
  
  return 0;
}
