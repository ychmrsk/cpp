#include "../std_lib_facilities.h"

// g++ -std=c++11 FNAME.cpp -o ONAME
// clean up code

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

const char number = '8';  // t.kind==number means that token has number
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";

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
  void ignore(char c);
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
  case print:
  case quit:
  case '(': case ')':
  case '+': case '-': case '*': case '/': case '%':
    return Token(ch);
  case '.':
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
    {
      cin.putback(ch);
      double val;
      cin >> val;
      return Token(number, val);
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

void Token_stream::ignore(char c)
{
  if (full && c==buffer.kind) {
    full = false;
    return;
  }
  full = false;

  char ch = 0;
  while (cin >> ch)
    if (ch == c) return;
}

vector<Token> tok;
Token get_token();  // read Token from cin
double expression();
double term();
double primary();

Token_stream ts;

void clean_up_mess()
{
  ts.ignore(print);
}

void calculate()
{
  while (cin)
    try {
      cout << prompt;
      Token t = ts.get();
      while (t.kind == print) t = ts.get();
      if (t.kind == quit) return;
      ts.putback(t);
      cout << result << expression() << endl;
    } catch (exception& e) {
      cerr << e.what() << endl;
      clean_up_mess();
    }
}

int main()
{
  try {
    calculate();
    return 0;
  } catch (exception& e) {
    cerr << e.what() << endl;
    // keep_window_open("~~");
    return 1;
  } catch (...) {
    cerr << "exception \n";
    // keep_window_open("~~");
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
    case '%':
      {
        double d = primary();
        int i1 = int(left);
        if (i1 != left) error("left-hand operand of % not int");
        // int i1 = narrow_cast<int>(left);
        int i2 = int(d);
        if (i2 != d) error("right-hand operand of % not int");
        //int i2 = narrow_cast<int>(term());
        if (i2 == 0) error("%: divide by zero");
        left = i1 % i2;
        t = ts.get();
        break;
      }
    default:
      ts.putback(t);
      return left;
    }
  }
}

/* Primary
     Number
     '(' Expression ')'
     '-' Primary
     '+' Primary
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
  case number:
    return t.value;
  case '-':
    return - primary();
  case '+':
    return primary();
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
