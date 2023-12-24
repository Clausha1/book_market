#ifndef _BOOK_SYSTEM_H_
#define _BOOK_SYSTEM_H_
#include "invoice.h"
#include "book.h"
#include "user.h"\

struct Order
{
public:
  unsigned int orderID;
  bool status;
  unsigned int userID;
  vector<unsigned int> cart;
  Order(unsigned int ID)
  {
    orderID = ID;
  }
};
class BookSystem{
private:
  vector<Order*> orders;
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
  bool PushToOrders(unsigned int ID, vector<unsigned int> cart);
  bool CancelOrder(unsigned int userID, unsigned int ID);
  bool AcceptOrder(unsigned int ID);
  bool ProvideOrder(unsigned int ID);
  vector<Order*> GetAllOrders();
  vector<Order*> GetAllOrders(unsigned int ID);
  vector<Book*> Sort(int par, bool s);
  vector<Book*> Find(string Name);
  bool Receipt(unsigned int ID, unsigned int q, unsigned int p);
};
#endif // BOOK_SYSTEM

