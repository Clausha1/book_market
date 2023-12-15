#include "book.h"
#include "book_system.h"

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

vector<Book*> BookSystem::SortBooksByName(bool s){
  vector<Book*> Sort;
  if (s)
    {
      for (int i=0; i<books.size();i++)
        {
          if (books[i]->GetBookName()>)
        }
    }
}
