#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME

int area(int length, int width)
{
  if (length <= 0 || width <= 0)
    error("non-positive area() argument");
  return length * width;
}

int framed_area(int x, int y)
{
  const int frame_width = 2;
  if (x-frame_width <= 0 || y-frame_width <= 0)
    error("non-positive area() argument called by framed_area()");
  return area(x-frame_width, y-frame_width);
}

int main()
{
  int x = -1;
  int y = 2;
  int z = 4;

  //  if (x <= 0) error("non-positive x");
  //  if (y <= 0) error("non-positive y");
  int area1 = area(x, y);
  
  int area2 = framed_area(1, z);
  int area3 = framed_area(y, z);
  double ratio = double(area1)/area3;

  cout << area1 << endl << area2 << endl << area3 << endl << ratio << endl;
}
