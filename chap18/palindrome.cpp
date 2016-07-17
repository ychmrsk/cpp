#include "../std_lib_facilities.h"

bool is_palindrome(const string& s)
{
  int first = 0;
  int last = s.length()-1;

  while (first < last) {
    if (s[first] != s[last]) return false;
    ++first;
    --last;
  }
  return true;
}

int main1()
{
  string s;
  while (cin >> s) {
    cout << s << " is";
    if (!is_palindrome(s)) cout << " not";
    cout << " a palindrome\n";
  }
}

bool is_palindrome2(const char s[], int n)
{
  int first = 0;
  int last = n-1;

  while (first < last) {
    if (s[first] != s[last]) return false;
    ++first;
    --last;
  }
  return true;
}

istream& read_word(istream& is, char* buffer, int max)
{
  is.width(max);
  is >> buffer;

  return is;
}

int main2()
{
  const int max = 128;
  char s[max];
  while (read_word(cin, s, max)) {
    cout << s << " is";
    if (! is_palindrome2(s, strlen(s))) cout << " not";
    cout << " a palindrome\n";
  }
}

bool is_palindrome3(const char* first, const char* last)
{
  while (first < last) {
    if (*first != *last) return false;
    ++first;
    --last;
  }
  return true;
}

bool is_palindrome4(const char* first, const char* last)
{
  if (first < last) {
    if (*first != *last) return false;
    return is_palindrome4(first+1, last-1);
  }
  return true;
}


int main()
{
  const int max = 128;
  char s[max];
  while (read_word(cin, s, max)) {
    cout << s << " is";
    if (!is_palindrome3(&s[0], &s[strlen(s)-1])) cout << " not";
    cout << " a palindrome\n";
  }
}

