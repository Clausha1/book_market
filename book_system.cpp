#include "book.h"
#include "book_system.h"
#include <string>
#include <string.h>
#include <algorithm>
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

bool compareBooksByTitleAscending(Book* a, Book* b) {
    return (a->GetBookName() < b->GetBookName());
}

bool compareBooksByTitleDescending(Book* a, Book* b) {
    return (a->GetBookName() > b->GetBookName());
}

bool compareBooksByQuantityAscending(Book* a, Book* b) {
    return (a->GetQuantity() < b->GetQuantity());
}

bool compareBooksByQuantityDescending(Book* a, Book* b) {
    return (a->GetQuantity() > b->GetQuantity());
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

vector<Book*> BookSystem::Sort(int par, bool s){ // s: 1 - по возрастанию, 0-по убыванию
  vector<Book*> sortBooks = books;
  switch (par) {
    case 1:
      if (s) {
          sort(sortBooks.begin(), sortBooks.end(), compareBooksByTitleAscending);
         } else {
             sort(sortBooks.begin(), sortBooks.end(), compareBooksByTitleDescending);
         }
      break;
    case 2:
      if (s) {
          sort(sortBooks.begin(), sortBooks.end(), compareBooksByQuantityAscending);
         } else {
          sort(sortBooks.begin(), sortBooks.end(), compareBooksByQuantityDescending);
         }
      break;
    default:
      break;
    }
  return sortBooks;
}
