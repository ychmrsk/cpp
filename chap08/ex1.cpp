#include "../std_lib_facilities.h"

void g(int a, int &r, const int& cr)
{
  ++a;
  ++r;
  int x = cr;
}

int main()
{
  int x = 0;
  int y = 0;
  int z = 0;

  cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
  g(x, y, z);
  cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
//  g(1, 2, 3);
//  cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
  g(1, y, 3);
  cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
}

void larger(vector<int>& v1, vector<int>& v2)
{
  if (v1.size() != v2.size()) error("larger(): different sizes");
  for (int i=0; i<v1.size(); ++i)
    if (v1[i] < v2[i])
      swap(v1[i], v2[i]);
}

void f()
{
  vector<int> vx;
  vector<int> vy;
  // read from cin into vx, vy
  larger(vx, vy);
}

void f(T, x);
f(y);
T x = y;

void f(double);

void g(int y)
{
  f(y);
  double x(y);
}
