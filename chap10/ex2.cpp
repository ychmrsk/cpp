#include "../std_lib_facilities.h"

struct Reading {
  int hour;
  double temperature;
  Reading(int h, double t) :hour(h), temperature(t) {}
};

int main()
{
  cout << "Please enter name of input file name: ";
  string iname;
  cin >> iname;
  ifstream ist(iname.c_str());
  if (!ist) error("can't open input file ", iname);
  
  vector<Reading> temps;
  int hour;
  double temperature;
  while (ist >> hour >> temperature) {
    if (hour < 0 || 23 < hour) error("hour out of range");
    temps.push_back(Reading(hour, temperature));
  }

  cout << "Please enter name of output file name: ";
  string oname;
  cin >> oname;
  ofstream ost(oname.c_str());
  if (!ost) error("can't open output file ", oname);

  for (int i=0; i<temps.size(); ++i)
    ost << '(' << temps[i].hour << ',' << temps[i].temperature << ")\n";
}
