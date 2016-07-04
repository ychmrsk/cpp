#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME

int main()
{
  try {
    vector<int> v;
    int x;
    while (cin >> x)
      v.push_back(x);
    for (int i = 0; i <= v.size(); ++i)
      cout << "v[" << i << "] == " << v[i] << endl;
  } catch (out_of_range) {
    cerr << "Oops! Range error\n";
    return 1;
  } catch (...) {
    cerr << "Exception: something went wrong\n";
    return 2;
  }
}
