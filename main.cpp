#include <iostream>
#include "book.h"
#include "book_system.h"
#include "user.h"
#include "customer.h"
int main()
{
    BookSystem *S = new BookSystem;
    S->NewBook("ABCD", 10, "F7", 1);
    S->NewBook("EFGHRTY", 23, "A2", 2);
    S->NewBook("TORT", 12, "A2", 3);
    S->NewBook("AC", 12,"F1", 4);

  int c;
  cout << "Customer (1) or Employee (2): ";
  cin >> c;
  cout << endl;
  if(c == 1)
  {
      user *U= new customer;
      U->setsysref(S);
      U->Menu();
  }
}
