#include "../std_lib_facilities.h"

class my_vector {
  int sz;
  double* elem;
public:
  my_vector(int s);
  int size() const { return sz; }
};

double* calc(int res_size, int max)
{
  double* p = new double[max];
  double* res = new double[res_size];

  return res;
}

double* r = calc(100, 1000);

double* calc(int res_size, int max)
{
  double* p = new double[max];
  double* res = new double[res_size];

  delete[] p;
  return res;
}

double* r = calc(100, 1000);
delete[] r;

int main()
{
  int n = 2;
  
  double* p = new double[4];
  double x = *p;  // 1st object pointed by p
  double y = p[2];  // 3rd object pointed by p
  *p = 8.8;
  p[3] = 4.4;

  int* pi = new int;
  int* qi = new int[4];

  double* pd = new double;
  double* qd = new double[n];

  double* p = new double;
  double* q = new double[1000];
  q[700] = 7.7;
  q = p;
  double d = q[700];

  double* p0;
  double* p1 = new double;
  double* p2 = new double(5.5);  // initailization
  double* p3 = new double[5];

  double* p4 = new double[5];
  for (int i=0; i<5; ++i) p[4] = i;

  double* p0 = 0;  // null pointer
  double* p0 = nullptr;

}
