#include <iostream>
#include "book.h"
#include "book_system.h"
int main()
{
  BookSystem *S = new BookSystem;
  S->NewBook("ABCD", 10, "F7");
  vector<Book*> b;
  b = S->GetAllBooks();
  cout << &b;
  for (unsigned int i=0; i<b.size();i++ )
    {
      cout << b[i]->GetBookName();
      cout << b[i]->GetQuantity();
      cout << b[i]->GetLocation();
    }
}
