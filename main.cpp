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
  if(S->NewBook("TORT", 12, "A2", 3))
  {
    cout << "Created";
  }\
  if(S->NewBook("AC", 12,"F1", 4))
  {
    cout << "Created";
  }
  User* u = new User;
  u->SetNickname("VOV");
  cout << u->GetNickname();
  u->SetPassword("DOD");
  cout << u->GetPassword();
  u->SetStatus(1);
  cout << u->GetStatus();
}
