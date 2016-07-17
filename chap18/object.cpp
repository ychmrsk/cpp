#include "../std_lib_facilities.h"

struct X {
  int val;

  void out(const string& s, int nv)
  { cerr << this << "->" << s << ": " << val << " (" << nv << ")\n"; }

  X() { out("X()", 0); val=0; }
  X(int v) { out("X(int)", v); val=v; }
  X(const X& x) { out("X(X&) ", x.val); val=x.val; }
  X& operator=(const X& a) { out("X::operator=()", a.val); val=a.val; return *this; }
  ~X() { out("~X()", 0); }
};

X glob(2);

X copy(X a) { return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

int main()
{
  X loc(4);
  X loc2 = loc;
  loc = X(5);
  loc2 = copy(loc);
  loc2 = copy2(loc);
  X loc3(6);
  X& r = ref_to(loc);
  delete make(7);
  delete make(8);
  vector<X> v(4);
  XX loc4;
  X* p = new X(9);
  delete p;
  X* pp = new X[5];
  delete[] pp;
}
