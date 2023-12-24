#include "book.h"
string Book::GetBookName()
{
  return bookname;
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

void Book::SetBuyerID(unsigned int ID)
{
     buyerID.push_back(ID);
}

vector<unsigned int> Book::GetBuyerID()
{
  return buyerID;
}

unsigned int Book::GetBookID()
{
return bookID;
}


void Book::SetBookPrice(unsigned int p)
{
price=p;
}
unsigned int Book::GetBookPrice()
{
  return price;
}

void Book::SetOrderedQuantity(unsigned int q)
{
   orderedquantity=q;
}

unsigned int Book::GetOrderedQuantity()
{
  return orderedquantity;
}
