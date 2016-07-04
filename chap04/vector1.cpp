#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME

int main()
{
  vector<double> temps;
  double temp;
  while (cin >> temp)
    temps.push_back(temp);

  double sum = 0;
  // average
  for (int i = 0; i < temps.size(); ++i)
    sum += temps[i];
  cout << "Average temperature: " << sum / temps.size() << endl;

  // median
  sort(temps.begin(), temps.end());
  cout << "Median temperature:" << temps[temps.size()/2] << endl;
}
