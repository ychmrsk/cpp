#include "../std_lib_facilities.h"

double expression(Token_stream& ts)
{
  double left = term(ts);
  Token t = ts.get();
  // ...
}

double term(Token_stream& ts)
{
  double left = primary(ts);
  Token t = ts.get();
  // ...
  switch (t.kind) {
  case '/':
    {
      double d = primary(ts);
      // ...
    }
  }
}

double primary(Token_stream& ts)
{
  Token t = ts.get();
  switch (t.kind) {
  case '(':
    {
      double d = expression(ts);
      // ...
    }
    // ...
  }
}


/*
  activation record stack

  = call stack : LIFO (Last In, First Out)

1.expression()
2.term()
3.primary()
4.expression()

<stack>
<1.expression> ts
<1.expression> left
<1.expression> t
<1.expression> implementation
<2.term>       ts
<2.term>       left
<2.term>       t
<2.term>       d
<2.term>       implementation
<3.primary>    ts
<3.primary>    t
<3.primary>    d
<3.primary>    implementation
<4.expression> ts
<4.expression> left
<4.expression> t
<4.expression> implementation
*/
