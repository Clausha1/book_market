#ifndef _BOOK_SYSTEM_H_
#define _BOOK_SYSTEM_H_
#include<vector>
#include<string>
#include<book.h>
using namespace std;
struct LocList{
public:
  string BookName;
  string Location;
};
class BookSystem{
protected:
  vector<LocList> locListR;
  vector<int> findList;
  vector<Book*> books;
public:
  void NewBook(string Name, int q, string Loc);
  vector<Book*> GetAllBooks();
  vector<LocList> ListOfBuyerBooksLocations(unsigned int BuyerID);
  vector<LocList> ListOfBooksLocations(vector<int> MarkedBooksList);
  vector<int> FindOnRequest(vector<bool> FindMarked, vector<string> FindPrompts);
  vector<Book*> Sort(int par, bool s);
  vector<Book*> Find(string Name);
};
#endif // BOOK_SYSTEM

