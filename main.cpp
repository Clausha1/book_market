#include <iostream>
#include "book.h"
#include "book_system.h"
int main()
{
  BookSystem *S = new BookSystem;
  S->NewBook("ABCD", 10, "F7");
  S->NewBook("ABCDE", 10 ,"A2");
  vector<Book*> b;
  b = S->GetAllBooks();
  cout << &b;
  vector<Book*> bo = S->Find("AB");
  for (unsigned int i=0; i<b.size();i++ )
    {
      cout << b[i]->GetBookName();
      cout << b[i]->GetQuantity();
      cout << b[i]->GetLocation();
    }
  for (unsigned int i=0; i<b.size();i++ )
    {
  cout << bo[i]->GetBookName();
  cout << bo[i]->GetQuantity();
  cout << bo[i]->GetLocation();
      }
}
