#include "../std_lib_facilities.h"

/*
  { year 1990}
  { year 1991 { month jun }}
  { year 1992 { month jan (1 0 61.5) }
              { month feb (1 1 64) (2 2 65.2) } }
  { year 2000 { month feb (1 1 68) (2 3 66.66) (1 0 67.2) }
              { month dec (15 15 -9.2) (15 14 -8.8) (14 0 -2)} }
*/


void end_of_loop(istream&, char, const string&);
  
const int not_a_reading = -7777;
const int not_a_month = -1;

vector<string> month_input_tbl;

void init_input_tbl(vector<string>& tbl)
{
  tbl.push_back("jan"); 
  tbl.push_back("feb"); 
  tbl.push_back("mar"); 
  tbl.push_back("apr"); 
  tbl.push_back("may"); 
  tbl.push_back("jun"); 
  tbl.push_back("jul"); 
  tbl.push_back("aug"); 
  tbl.push_back("sep"); 
  tbl.push_back("oct"); 
  tbl.push_back("nov"); 
  tbl.push_back("dec"); 
}

int month_to_int(string s)
{
  for (int i=0; i<12; ++i)
    if (month_input_tbl[i] == s)
      return i;
  return -1;
}

vector<string> month_print_tbl;

void init_print_tbl(vector<string>& tbl)
{
  tbl.push_back("January"); 
  tbl.push_back("February"); 
  tbl.push_back("March"); 
  tbl.push_back("April"); 
  tbl.push_back("May"); 
  tbl.push_back("June"); 
  tbl.push_back("July"); 
  tbl.push_back("August"); 
  tbl.push_back("September"); 
  tbl.push_back("October"); 
  tbl.push_back("November"); 
  tbl.push_back("December"); 
}

string int_to_month(int i)
{
  if (i < 0 || 12 <= i) error("bad month index");
  return month_print_tbl[i];
}

struct Day {
  vector<double> hour;
  Day();
};

Day::Day()
  : hour(24)
{
  for (int i = 0; i < hour.size(); ++i)
    hour[i] = not_a_reading;
}

struct Month {
  int month;
  vector<Day> day;
  Month()
    : month(not_a_month), day(32) {}
};

struct Year {
  int year;
  vector<Month> month;
  Year()
    : month(12) {}
};

struct Reading {
  int day;
  int hour;
  double temperature;
};

istream& operator>>(istream& is, Reading& r)
{
  char ch1;
  if (is >> ch1 && ch1 != '(') {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }

  char ch2;
  int d;
  int h;
  double t;
  is >> d >> h >> t >> ch2;
  if (!is || ch2 != ')') error("bad reading");
  r.day = d;
  r.hour = h;
  r.temperature = t;
  return is;
}

const int implausible_min = -200;
const int implausible_max = 200;

bool is_valid(const Reading& r)
{
  if (r.day < 1 || 31 < r.day) return false;
  if (r.hour < 0 || 23 < r.hour) return false;
  if (r.temperature < implausible_min || implausible_max < r.temperature)
    return false;
  return true;
}

istream& operator>>(istream& is, Month& m)
{
  char ch = 0;
  if (is >> ch && ch != '{') {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }

  string month_marker;
  string mm;
  is >> month_marker >> mm;
  if (!is || month_marker != "month") error("bad start of month");
  m.month = month_to_int(mm);

  Reading r;
  int duplicates = 0;
  int invalids = 0;
  while (is >> r) {
    if (is_valid(r)) {
      if (m.day[r.day].hour[r.hour] != not_a_reading)
        ++duplicates;
      m.day[r.day].hour[r.hour] = r.temperature;
    } else
      ++invalids;
  }
  if (invalids) error("invalid readings in month", invalids);
  if (duplicates) error("duplicate readings in month", duplicates);
  end_of_loop(is, '}', "bad end of month");
  return is;
}

istream& operator>>(istream& is, Year& y)
{
  char ch;
  is >> ch;
  if (ch != '{') {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }
  string year_marker;
  int yy;
  is >> year_marker >> yy;
  if (!is || year_marker != "year") error("bad start of year");
  y.year = yy;

  while (true) {
    Month m;  // m in while-scope
    if (!(is >> m)) break;
    y.month[m.month] = m;
  }

  end_of_loop(is, '}', "bad end of year");
  return is;
}

void end_of_loop(istream& ist, char term, const string& message)
{
  if (ist.fail()) {
    ist.clear();
    char ch;
    if (ist >> ch && ch == term) return;
    error(message);
  }
}

int main()
{
  init_print_tbl(month_print_tbl);
  init_input_tbl(month_input_tbl);
  
  cout << "please enter input file name\n";
  string name;
  cin >> name;
  ifstream ifs(name.c_str());
  if (!ifs) error("can't open input file", name);

  ifs.exceptions(ifs.exceptions()|ios_base::badbit);

  cout << "please enter output file name\n";
  cin >> name;
  ofstream ofs(name.c_str());
  if (!ofs) error("can't open output file", name);

  vector<Year> ys;
  while (true) {
    Year y;
    if (!(ifs >> y)) break;
    ys.push_back(y);
  }
  cout << "read " << ys.size() << " years of readings\n";

  for (int i=0; i<ys.size(); ++i) print_year(ofs, ys[i]);
}
