#ifndef _BOOK_H_
#define _BOOK_H_
using namespace std;
#include<vector>
#include<string>
class Book
{
private:
  unsigned int bookID;
  string bookname;
  unsigned int quantity;
  string location;
  unsigned int price;
  vector<unsigned int> buyerID;
public:
  Book(unsigned int ID)
  {
   bookID=ID;
  }
  void SetBookName(string Name);
  void SetBookPrice(unsigned int p);
  unsigned int GetBookPrice();
  void SetLocation(string Loc);
  bool SetBuyerID(unsigned int ID);
  unsigned int GetBookID();
  void SetQuantity(unsigned int q);
  unsigned int GetQuantity();
  string GetLocation();
  string GetBookName();
  vector<unsigned int> GetBuyerID();
};
#endif // BOOK

