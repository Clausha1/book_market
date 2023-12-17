#ifndef _BOOK_SYSTEM_H_
#define _BOOK_SYSTEM_H_
#include<vector>
#include<string>
#include"book.h"
#include"user.h"
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
  bool NewBook(string Name, int q, string Loc, unsigned int p);
  bool NewUser(string nick, string pass, int status);
  vector<Book*> GetAllBooks();
  vector<LocList> ListOfBuyerBooksLocations(unsigned int BuyerID);
  vector<LocList> ListOfBooksLocations(vector<int> MarkedBooksList);
  vector<Book*> Sort(int par, bool s);
  vector<Book*> Find(string Name);
};
#endif // BOOK_SYSTEM

