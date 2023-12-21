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
  bool DeleteBook(unsigned int ID);
  bool DeleteUser(unsigned int ID, unsigned int selfID);
  unsigned int EditBook(unsigned int ID, string Name, unsigned int q, string Loc, unsigned int p);
  vector<Book*> GetAllBooks();
  vector<User*> GetAllUsers();
  vector<LocList> ListOfBuyerBooksLocations(unsigned int BuyerID);
  vector<Book*> Sort(int par, bool s);
  vector<Book*> Find(string Name);
};
#endif // BOOK_SYSTEM

