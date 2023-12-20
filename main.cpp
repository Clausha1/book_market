#include <iostream>
#include "user.h"
#include "book.h"\
#include "userinterface.h"
#include "customerinterface.h"
#include "user.h"
#include "book_system.h"
int main()
{
    BookSystem *S = new BookSystem;
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
  if(S->NewBook("TORT", 12, "A2", 5))
  {
    cout << "Created";
  }\
  if(S->NewBook("AC", 12,"F1", 4))
  {
    cout << "Created";
  }
   if(S->DeleteBook(2))
    {
      cout<<"Deleted";
    }
    if(S->NewBook("EFGHRTY", 23, "A2", 5))
    {
      cout << "Created";
    }
  vector<Book*> b = S->GetAllBooks();
  for (unsigned int i=0; i<b.size(); i++)
  {
  cout << b[i]->GetBookID();
  }
  if(S->NewUser("ABCD", "ABCD", 1))
    {
      cout << "Created";
    }
  if(S->NewUser("ABCD", "F7", 1))
    {
      cout << "Created";
    }
  if(S->NewUser("ТОRT","A2", 1))
  {
    cout << "Created";
  }
  if(S->NewUser("TORT", "A2", 2))
  {
    cout << "Created";
  }\
  if(S->NewUser("AC", "F1", 4))
  {
    cout << "Created";
  }
  vector<User*> u = S->GetAllUsers();
  for (unsigned int i=0; i<u.size(); i++)
  {
  cout << u[i]->GetUserID();
  }
}
