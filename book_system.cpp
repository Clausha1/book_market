#include "book.h"
#include "book_system.h"
#include <string>
#include <string.h>

string str_tolower(string str)
{
  string s;
  s.resize(str.size());
  for (unsigned int i=0; i<str.size(); i++)
  {
       s[i]=tolower(str[i]);
    }
  return s;
}

void BookSystem::NewBook(string Name, int q, string Loc){
  unsigned int max = books.size();
  books.push_back(new Book(max+1));
  books[max]->SetBookName(Name);
  books[max]->SetQuantity(q);
  books[max]->SetLocation(Loc);
 }


vector<Book*> BookSystem::GetAllBooks(){
  return books;
}

vector<Book*> BookSystem::Find(string Name)
{
  vector<Book*> b;
  for (unsigned int i=0; i<books.size(); i++)
  {
      if (strcmp(str_tolower(books[i]->GetBookName()).substr(0, strlen(Name.c_str())).c_str(), str_tolower(Name).c_str())==0)
      {
        b.push_back(books[i]);
      }
    }
  return b;
}

vector<Book*> BookSystem::SortBooksByName(bool s){

}
