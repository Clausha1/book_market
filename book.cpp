#include "book.h"
string Book::GetBookName()
{
  return bookname;
}

Book* Book::find(string name){
  if (name == bookname)
    {
      return *this;
    }
}

void Book::SetBookName(string Name)
{
  bookname = Name;
}


void Book::SetLocation(string Loc)
{
  location =Loc;
}

void Book::SetQuantity(unsigned int q){
  quantity=q;
}

unsigned int Book::GetQuantity(){
  return quantity;
}

string Book::GetLocation()
{
  return location;
}

bool Book::SetBuyerID(unsigned int ID)
{
  if (quantity > buyerID.size())
  {
     buyerID.push_back(ID);
  return 1;
    }
      else
  {
   return 0;
}
}

vector<unsigned int> Book::GetBuyerID()
{
  return buyerID;
}

unsigned int Book::GetBookID()
{
return bookID;
}
