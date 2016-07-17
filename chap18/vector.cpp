#include "../std_lib_facilities.h"

class my_vector {
  int sz;
  double* elem;
  void copy(const my_vector& arg);
public:
  my_vector(int s)
    : sz(s), elem(new double[s])
  {
    for (int i=0; i<s; ++i) elem[i] = 0;
  }
  
  my_vector(const my_vector&);

  my_vector& operator=(const my_vector& a);
  
  ~my_vector()
  { delete[] elem; }

  int size() const { return sz; }

  double get(int n) const { return elem[n]; }
  void set(int n, double v) { elem[n] = v; }

};

my_vector::my_vector(const my_vector& arg)
  : sz(arg.sz), elem(new double[arg.sz])
{
  copy(arg);
}

void my_vector::copy(const my_vector& arg)
{
  for (int i=0; i<arg.sz; ++i) elem[i] = arg.elem[i];
}

my_vector& my_vector::operator=(const my_vector& a)
{
  double* p = new double[a.sz];
  for (int i=0; i<a.sz; ++i) p[i] = a.elem[i];
  delete[] elem;
  elem = p;
  sz = a.sz;
  return *this;
}

void f(int n)
{
  my_vector v(3);
  v.set(2, 2.2);
  my_vector v2 = v;  // what happen here!?

  v.set(1, 99);
  v2.set(0, 88);
  cout << v.get(0) << ' ' << v2.get(1) << '\n';
}

int main()
{
  f(1);
}
