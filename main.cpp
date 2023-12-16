#include <iostream>
#include "book.h"
#include "book_system.h"
#include "user.h"
#include "customer.h"
int main()
{
    BookSystem *S = new BookSystem;
    S->NewBook("ABCD", 10, "F7");
    S->NewBook("EFGHRTY", 23, "A2");
    S->NewBook("TORT", 12, "A2");\
    S->NewBook("AC", 12,"F1");

  int c;
  cout << "Customer (1) or Employee (2): ";
  cin >> c;
  cout << endl;
  if(c == 1)
  {
      user *U= new customer;
      U->setsysref(S);
      U->ShowBook(S->Sort(1, 1));
      U->ShowBook(S->Sort(1, 0));
      U->ShowBook(S->Sort(2, 1));
      U->ShowBook(S->Sort(2, 0));
      U->Menu();
  }
}
