#ifndef _BOOK_SYSTEM_H_
#define _BOOK_SYSTEM_H_
#include "invoice.h"
#include "book.h"
#include "user.h"\

struct LocList
{
public:
  string BookName;
  string Location;
};
class BookSystem{
protected:
  vector<LocList> locListR;
  vector<Book*> books;
  vector<User*> users;
  Invoice* invoice;
public:
  bool NewBook(string Name, int q, string Loc, unsigned int p);
  bool NewUser(string Name, string pass, unsigned int s);
  bool DeleteBook(unsigned int ID);
  bool DeleteUser(unsigned int ID, unsigned int selfID);
  void NewInvoice();
  void InvoiceInFile();
  unsigned int EditBook(unsigned int ID, string Name, unsigned int q, string Loc, unsigned int p);
  vector<Book*> GetAllBooks();
  vector<User*> GetAllUsers();
  vector<LocList> ListOfBuyerBooksLocations(unsigned int BuyerID);
  vector<Book*> Sort(int par, bool s);
  vector<Book*> Find(string Name);
  bool Receipt(unsigned int ID, unsigned int q, unsigned int p);
};
#endif // BOOK_SYSTEM

