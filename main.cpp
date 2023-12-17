#include <iostream>
#include "book.h"
#include "book_system.h"
#include "userinterface.h"
#include "customerinterface.h"
int main()
{
    BookSystem *S = new BookSystem;
  int c;
  if(S->NewBook("ABCD", 10, "F7", 1))
    {
      cout << "Created";
    }
  if(S->NewBook("ABCD", 10, "F7", 1))
    {
      cout << "Created";
    }
  if(S->NewBook("EFGHRTY", 23, "A2", 2))
  {
    cout << "Created";
  }
  if(S->NewBook("TORT", 12, "A2", 3))
  {
    cout << "Created";
  }\
  if(S->NewBook("AC", 12,"F1", 4))
  {
    cout << "Created";
  }
  cout << "Customer (1) or Employee (2): ";
  cin >> c;
  cout << endl;
  if(c == 1)
  {
      UserInterface *U= new CustomerInterface;
      U->setsysref(S);
      U->Menu();
  }
    return 0;
}
