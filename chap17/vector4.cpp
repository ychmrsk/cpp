#include "../std_lib_facilities.h"

class my_vector {
  int sz;
  double* elem;
public:
  my_vector(int s)
    : sz(s), elem(new double[s])
  {
    for (int i=0; i<s; ++i) elem[i] = 0;
  }

  ~my_vector()
  { delete[] elem; }
  
  int size() const { return sz; }

  double get(int n) const { return elem[n]; }
  void set(int n, double v) { elem[n] = v; }
};


int main()
{
  my_vector v(5);
  for (int i=0; i<v.size(); ++i) {
    v.set(i, 1.1*i);
    cout << "v[" << i << "] == " << v.get(i) << '\n';
  }

  vector v(4);
  int x = v.size();
  double d = v.get(3);
  
  vector* p = new vector(4);
  int x = p->size();
  double d = p->get(3);

}

Register* in = reinterpret_cast<Register*>(0xff);

void f(const Buffer* p)
{
  Buffer* b = const_cast<Buffer*>(p);
}


void f()
{
  int x = 10;
  int* p = &x;
  *p = 7;
  int x2 = *p;
  int* p2 = &x2;
  p2 = p;
  p = &x2;

  int y = 10;
  int& r = y;
  r = 7;
  int y2 = r;
  int& r2 = y2;
  r2 = r;
  r = &y2;  // error
}

