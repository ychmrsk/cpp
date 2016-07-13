#include "../std_lib_facilities.h"

class Punct_stream {
public:
  Punct_stream(istream& is)
    : source(is), sensitive(true) { }
  void whitespace(const string& s) { white = s; }
  void add_white(char c) { white += c; }
  bool is_whitespace(char c);

  void case_sensitive(bool b) { sensitive = b; }
  bool is_case_sensitive() { return sensitive; }

  Punct_stream& operator>>(string& s);
  operator bool();

private:
  istream& source;
  istringstream buffer;
  string white;    // whitespace characters
  bool sensitive;  // upper <> lower case
};

Punct_stream& Punct_stream::operator>>(string& s)
{
  while (!(buffer >> s)) {
    if (buffer.bad() || !source.good()) return *this;
    buffer.clear();

    string line;
    getline(source, line);

    for (int i=0; i<line.size(); ++i)
      if (is_whitespace(line[i]))
        line[i] = ' ';
      else if (!sensitive)
        line[i] = tolower(line[i]);
    buffer.str(line);
  }
  return *this;
}

bool Punct_stream::is_whitespace(char c)
{
  for (int i=0; i<white.size(); ++i)
    if (c == white[i]) return true;
  return false;
}

Punct_stream::operator bool()
{
  return !(source.fail() || source.bad()) && source.good();
}


int main()
{
  Punct_stream ps(cin);
  ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
  ps.case_sensitive(false);

  cout << "please enter words\n";
  vector<string> vs;
  string word;
  while (ps >> word) vs.push_back(word);

  sort(vs.begin(), vs.end());
  for (int i=0; i<vs.size(); ++i)
    if (i == 0 || vs[i] != vs[i-1])
      cout << vs[i] << endl;
}
