#ifndef _BOOK_SYSTEM_H_
#define _BOOK_SYSTEM_H_
#include<vector>
#include<string>
using namespace std;
struct LocList{
public:
  string BookName;
  string Location;
};
class BookSystem{
protected:
  string nBookName;
  int nBookQuantity;
  string nBookLocation;
  vector<LocList> locListR;
  vector<int> findList;
  vector<int> booksID;
public:
  BookSystem();
  string GetNewBookName();
  int GetNewBookQuantity();
  string GetNewBookLocation();
  void NewBook(string Name, int q, string Loc);
  vector<LocList> ListOfBuyerBooksLocations(unsigned int BuyerID);
  vector<LocList> ListOfBooksLocations(vector<int> MarkedBooksList);
  vector<int> FindOnRequest(vector<bool> FindMarked, vector<string> FindPrompts);
};
#endif // BOOK_SYSTEM

