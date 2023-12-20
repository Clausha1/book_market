#ifndef _BOOK_SYSTEM_H_
#define _BOOK_SYSTEM_H_
#include "book.h"
#include "user.h"
using namespace std;
struct LocList{
public:
  string BookName;
  string Location;
};
class BookSystem{
protected:
  vector<LocList> locListR;
  vector<Book*> books;
  vector<User*> users;
public:
  bool NewBook(string Name, int q, string Loc, unsigned int p);
  bool NewUser(string Name, string pass, unsigned int s);
  vector<Book*> GetAllBooks();
  vector<User*> GetAllUsers();
  vector<LocList> ListOfBuyerBooksLocations(unsigned int BuyerID);
  vector<LocList> ListOfBooksLocations(vector<unsigned int> MarkedBooksList);
  vector<Book*> Sort(int par, bool s);
  vector<Book*> Find(string Name);
};
#endif // BOOK_SYSTEM

