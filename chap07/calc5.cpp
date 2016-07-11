#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME

/*
  Expression:
    Term
    Expression "+" Term
    EXpression "-" Term
  Term:
    Primary
    Term "*" Primary
    Term "/" Primary
    Term "%" Primary
  Primary:
    Number
    "(" Expression ")"
  Number:
    floating-point-literal
*/

/*
  one function per rule of grammer

  get_token()
  expression() : operate + and -
  term()       : operate * , / , and %
  Primary()    : Number and parenthesis
*/

class Token {
public:
  char kind;
  double value;
  Token(char ch)  // constructor
    :kind(ch), value(0) {}  // member initializer list
  Token(char ch, double val)
    :kind(ch), value(val) {}
};


class Token_stream {
public:
  Token_stream();  // read from cin and construct Token_stream
  Token get();
  void putback(Token t);
private:
  bool full;
  Token buffer;
};

Token_stream::Token_stream()
  :full(false), buffer(0)
{
}

Token Token_stream::get()
{
  if (full) {
    full = false;
    return buffer;
  }
  char ch;
  cin >> ch;
  switch (ch) {
  case ';':
  case 'q':
  case '(': case ')': case '+': case '-': case '*': case '/':
    return Token(ch);
  case '.':
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
    {
      cin.putback(ch);
      double val;
      cin >> val;
      return Token('8', val);
    }
  default:
    error("Bad token");
  }
}

void Token_stream::putback(Token t)
{
  if (full) error("putback() into a full buffer");
  buffer = t;
  full = true;
}


vector<Token> tok;
Token get_token();  // read Token from cin
double expression();
double term();
double primary();

Token_stream ts;

int main()
{
  try {
    double val = 0;
    while (cin) {
      cout << "> ";
      Token t = ts.get();
      while (t.kind == ';') t = ts.get();
      if (t.kind == 'q') {
        keep_window_open();
        return 0;
      }
      ts.putback(t);
      cout << "= " << expression() << endl;
    }
    keep_window_open();
    return 0;
  } catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
  } catch (...) {
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
  }
}

/* Expression
     Term
     Expression '+' Term
     Expression '-' Term
*/
double expression()
{
  double left = term();
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
    case '+':
      left += term();
      t = ts.get();
      break;
    case '-':
      left -= term();
      t = ts.get();
      break;
    default:
      ts.putback(t);
      return left;
    }
  }
}

/* Term
     Primary
     Term '*' Primary
     Term '/' Primary
     Term '%' Primary
*/
double term()
{
  double left = primary();
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = ts.get();
      break;
    case '/':
      {  // to define a variable in case, need { }
        double d = primary();
        if (d == 0) error("divide by zero");
        left /= d;
        t = ts.get();
        break;
      }
//    case '%':
//      left %= primary();
//      t = ts.get();
//      break;
    default:
      ts.putback(t);
      return left;
    }
  }
}

/* Primary
     Number
     '(' Expression ')'
*/
double primary()
{
  Token t = ts.get();
  switch (t.kind) {
  case '(':
    {
      double d = expression();
      t = ts.get();
      if (t.kind != ')') error("')' expected");
      return d;
    }
  case '8':
    return t.value;
  default:
    error("primary expected");
  }
}







/* expression

// expression ver.1
double expression()
{
  double left = expression();
  Token t = get_token();
  switch (t.kind) {
  case '+':
    return left + term();
  case '-':
    return left - term();
  default:
    return left;
  }
}
// expression ver.2
double expression()
{
  double left = term();
  Token t = get_token();
  switch (t.kind) {
  case '+':
    return left + expression();
  case '-':
    return left + expression();
  default:
    return left;
  }
}
// expression ver.3
double expression()
{
  double left = term();
  Token t = get_token();
  while (t.kind == '+' || t.kind == '-') {
    if (t.kind == '+')
      left += term();
    else
      left -= term();
    t = get_token();
  }
  return left;
}

*/
