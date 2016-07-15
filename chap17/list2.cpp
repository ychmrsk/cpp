#include "../std_lib_facilities.h"

class Link {
public:
  string value;

  Link(const string& v, Link* p = 0, Link* s = 0)
    : value(v), prev(p), succ(s) { }

  Link* insert(Link* n);
  Link* add(Link* n);
  Link* erase();
  Link* find(const string& s);
  const Link* find(const string& s) const;
  Link* advance(int n) const;
  Link* next() const { return succ; }
  Link* previous() const { return prev; }

private:
  Link* prev;
  Link* succ;
};

Link* Link::insert(Link* n)
{
  if (n==0) return this;
  if (this==0) return n;
  n->succ = this;
  if (prev) prev->succ = n;
  n->prev = prev;
  prev = n;
  return n;
}





struct Link {
  string value;
  Link* prev;
  Link* succ;
  Link(const string& v, Link* p = 0, Link* s = 0)
    : value(v), prev(p), succ(s) { }
};

Link* add(Link* p, Link* n)
{
  // todo
}

Link* erase(Link* p)
{
  if (p==0) return 0;
  if (p->succ) p->succ->prev = p->prev;
  if (p->prev) p->prev->succ = p->succ;
  return p->succ;
}

Link* find(Link* p, const string& s)
{
  while (p) {
    if (p->value == s) return p;
    p = p->succ;
  }
  return 0;
}

Link* advance(Link* p, int n)
{
  if (p==0) return 0;
  if (n > 0) {
    while (n--) {
      if (p->succ == 0) return 0;
      p = p->succ;
    }
  } else if (n < 0) {
    while (n++) {
      if (p->prev == 0) return 0;
      p = p->prev;
    }
  }
  return p;
}

Link* insert(Link* p, Link* n)
{
  if (n==0) return p;
  if (p==0) return n;
  n->succ = p;
  if (p->prev)
    p->prev->succ = n;
  n->prev = p->prev;
  p->prev = n;
  return n;
}

void print_all(Link* p)
{
  cout << "{ ";
  while (p) {
    cout << p->value;
    if (p=p->succ) cout << ", ";
  }
  cout << " }";
}

void print_all(Link* p)
{
  cout << "{ ";
  while (p) {
    cout << p->value;
    if (p=p->next()) cout << ", ";
  }
  cout << " }";
}

int main()
{
  /*
  Link* norse_gods = new Link("Thor", 0, 0);
  norse_gods = new Link("Odin", 0, norse_gods);
  norse_gods->succ->prev = norse_gods;
  norse_gods = new Link("Freia", 0, norse_gods);
  norse_gods->succ->prev = norse_gods;

  Link* norse_gods = new Link("Thor");
  norse_gods = insert(norse_gods, new Link("Odin"));
  norse_gods = insert(norse_gods, new Link("Freia"));
  */

  Link* norse_gods = new Link("Thor");
  norse_gods = insert(norse_gods, new Link("Odin"));
  norse_gods = insert(norse_gods, new Link("Zeus"));
  norse_gods = insert(norse_gods, new Link("Freia"));

  Link* greek_gods = new Link("Hera");
  greek_gods = insert(greek_gods, new Link("Athena"));
  greek_gods = insert(greek_gods, new Link("Mars"));
  greek_gods = insert(greek_gods, new Link("Poseidon"));

  Link* p = find(greek_gods, "Mars");
  if (p) p->value = "Ares";

  p = find(norse_gods, "Zeus");
  if (p) {
    if (p==norse_gods) norse_gods = p->succ;
    erase(p);
    greek_gods = insert(greek_gods, p);
  }

  print_all(norse_gods);
  cout << "\n";

  print_all(greek_gods);
  cout << "\n";



  Link* norse_gods = new Link("Thor");
  norse_gods = norse_gods->insert(new Link("Odin"));
  norse_gods = norse_gods->insert(new Link("Zeus"));
  norse_gods = norse_gods->insert(new Link("Freia"));

  Link* greek_gods = new Link("Hera");
  greek_gods = greek_gods->insert(new Link("Athena"));
  greek_gods = greek_gods->insert(new Link("Mars"));
  greek_gods = greek_gods->insert(new Link("Poseidon"));

  Link* p = greek_gods->find("Mars");
  if (p) p->value = "Ares";

  Link* p2 = norse_gods->find("Zeus");
  if (p2) {
    if (p2 == norse_gods) norse_gods = p2->next();
    p2->erase();
    greek_gods = greek_gods->insert(p2);
  }

  print_all(norse_gods);
  cout << "\n";

  print_all(greek_gods);
  cout << "\n";
  
}
