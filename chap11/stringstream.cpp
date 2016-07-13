#include "../std_lib_facilities.h"

double str_to_double(string s)
{
  istringstream is(s);
  double d;
  is >> d;
  if (!is) error("double format error: ", s);
  return d;
}

double d1 = str_to_double("12.4");
double d2 = str_to_double("1.34e?3");
double d3 = str_to_double("twelve point three");  // error

void my_code(string label, Temperature temp)
{
  // ...
  ostringstream os;
  os << setw(8) << label << ":"
     << fixed << setprecision(5) << temp.temp << temp.unit;
  someobject.display(Point(100, 100), os.str().c_str());
  // ...
}

int seq_no = get_next_number();
ostringstream name;
name << "myfile" << seq_no;
ofstream logfile(name.str().c_str());
