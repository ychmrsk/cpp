#include "../std_lib_facilities.h"

int strlen(const char* p)
{
  int count = 0;
  while (*p) { ++count; ++p; }
  return count;
}

int strlen(const char a[])
{
  int count = 0;
  while (a[count]) { ++count; }
  return count;
}

for (int i=0; i<100; ++i) x[i] = y[i];
memcpy(x, y, 100*sizeof(int));
copy(y, y+100, x);

vector<int> x(100);
vector<int> y(100);
// ...
x = y;  // copy of 100 int


// initialization
char ac[] = "Beorn";
// 'B' 'e' 'o' 'r' 'n' 0

char* pc = "Howdy";

int strlen(const char* p)
{
  int n = 0;
  while (p[n]) ++n;
  return n;
}

