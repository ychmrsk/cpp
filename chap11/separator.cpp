#include "../std_lib_facilities.h"

int main()
{
  string line;
  getline(cin, line);
  for (int i=0; i<line.size(); ++i)
    switch (line[i]) {
    case ';': case '.': case ',': case '?': case '!':
      line[i] = ' ';
    }

  stringstream ss(line);
  vector<string> vs;
  string word;

  while (ss >> word)
    vs.push_back(word);

  for (int i=0; i<vs.size(); ++i)
    cout << vs[i] << endl;
}
