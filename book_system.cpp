#include "book_system.h"
void BookSystem::NewBook(string Name, int q, string Loc){
  int max = 0;
  for (int i=0; i<books.size(); i++)
    {
      if (books[i]>max)
        {
          max = books[i];
        }
    }
  books.push_back(new Book(max+1));
  nBookName = Name;
  nBookQuantity = q;
  nBookLocation = Loc;
}

string BookSystem::GetNewBookName(){
  return nBookName;
}

int BookSystem::GetNewBookQuantity(){
  return nBookQuantity;
}

int BookSystem::GetNewBookLocation()
{
  return nBookLocation;
}

vector<LocList> BookSystem::ListOfBuyerBooksLocations(unsigned int BuyerID)
{

}

vector<LocList> BookSystem::ListOfBooksLocations(vector<int> MarkedBooksList)
{

}
vector<int> BookSystem::FindOnRequest(vector<bool> FindMarked, vector<string> FindPrompts)
{

}
