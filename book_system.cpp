#include "book_system.h"
#include <algorithm>
string str_tolower(string str)
{
  string s;
  s.resize(str.size());
  for (unsigned int i=0; i<str.size(); i++)
  {
       s[i]=tolower(str[i]);
    }
  return s;
}

bool compareBooksByTitleAscending(Book* a, Book* b) {
    return (a->GetBookName() < b->GetBookName());
}

bool compareBooksByTitleDescending(Book* a, Book* b) {
    return (a->GetBookName() > b->GetBookName());
}

bool compareBooksByQuantityAscending(Book* a, Book* b) {
    return (a->GetQuantity() < b->GetQuantity());
}

bool compareBooksByQuantityDescending(Book* a, Book* b) {
    return (a->GetQuantity() > b->GetQuantity());
}

bool compareBooksByPriceAscending(Book* a, Book* b) {
    return (a->GetBookPrice() < b->GetBookPrice());
}

bool compareBooksByPriceDescending(Book* a, Book* b) {
    return (a->GetBookPrice() > b->GetBookPrice());
}

bool BookSystem::NewBook(string Name, int q, string Loc, unsigned int p){
  unsigned int max = books.size();
  for (unsigned int i=0; i<books.size();i++)
    {
      if (books[i]->GetBookName() == Name)
        {
          return 0;
        }
    }
  unsigned int max_id = 0;
  for (unsigned int i=0; i<books.size();i++)
    {
      if (books[i]->GetBookID() > max_id)
        {
          max_id = books[i]->GetBookID();
        }
    }
  bool isnotinitializedid =0;
  for (unsigned int i =1; i<max_id;i++)
    {
      for (unsigned int j=0; j<books.size(); j++)
        {
          if(books[j]->GetBookID() == i)
            {
              isnotinitializedid =0;
              break;
            }
          else
          {
              isnotinitializedid =1;
            }
        }
      if (isnotinitializedid)
        {
          max = i-1;
          break;
        }
    }
  books.push_back(new Book(max+1));
  books[books.size()-1]->SetBookName(Name);
  books[books.size()-1]->SetQuantity(q);
  books[books.size()-1]->SetLocation(Loc);
  books[books.size()-1]->SetBookPrice(p);
  return 1;
 }

bool BookSystem::NewUser(string Name, string pass, unsigned int s)
{
  unsigned int max = users.size();
  for (unsigned int i=0; i<users.size();i++)
    {
      if ((users[i]->GetNickname() == Name) && (users[i]->GetStatus()==s))
        {
          return 0;
        }
    }
  unsigned int max_id = 0;
  for (unsigned int i=0; i<users.size();i++)
    {
      if (users[i]->GetUserID() > max_id)
        {
          max_id = users[i]->GetUserID();
        }
    }
  bool isnotinitializedid =0;
  for (unsigned int i =1; i<max_id;i++)
    {
      for (unsigned int j=0; j<users.size(); j++)
        {
          if(users[j]->GetUserID() == i)
            {
              isnotinitializedid =0;
              break;
            }
          else
          {
              isnotinitializedid =1;
            }
        }
      if (isnotinitializedid)
        {
          max = i-1;
          break;
        }
    }
  users.push_back(new User(max+1));
  users[users.size()-1]->SetNickname(Name);
  users[users.size()-1]->SetPassword(pass);
  users[users.size()-1]->SetStatus(s);
  return 1;
}

bool BookSystem::DeleteBook(unsigned int ID)
{
  for (vector<Book*>::iterator it=books.begin(); it!=books.end(); it++)
    if (((*it)->GetBookID()==ID) && ((*it)->GetOrderedQuantity()==0))
      {
        books.erase(it);
        return 1;
      }
  return 0;
}

bool BookSystem::DeleteUser(unsigned int ID, unsigned int selfstatus)
{
      for (vector<User*>::iterator it=users.begin(); it!=users.end(); it++)
        if (((*it)->GetUserID()==ID) && ((*it)->GetStatus()<selfstatus))
          {
            users.erase(it);
            return 1;
          }
  return 0;
}

vector<Book*> BookSystem::GetAllBooks(){
  return books;
}

vector<User*> BookSystem::GetAllUsers()
{
  return users;
}

vector<Book*> BookSystem::Find(string Name)
{
  vector<Book*> b;
  for (unsigned int i=0; i<books.size(); i++)
  {
      if (strcmp(str_tolower(books[i]->GetBookName()).substr(0, strlen(Name.c_str())).c_str(), str_tolower(Name).c_str())==0)
      {
        b.push_back(books[i]);
      }
    }
  return b;
}

vector<Book*> BookSystem::Sort(int par, bool s){ // s: 1 - по возрастанию, 0-по убыванию
  vector<Book*> sortBooks = books;
  switch (par) {
    case 1:
      if (s) {
          sort(sortBooks.begin(), sortBooks.end(), compareBooksByTitleAscending);
         } else {
             sort(sortBooks.begin(), sortBooks.end(), compareBooksByTitleDescending);
         }
      break;
    case 2:
      if (s) {
          sort(sortBooks.begin(), sortBooks.end(), compareBooksByQuantityAscending);
         } else {
          sort(sortBooks.begin(), sortBooks.end(), compareBooksByQuantityDescending);
         }
      break;
    case 3:
      if (s) {
          sort(sortBooks.begin(), sortBooks.end(), compareBooksByPriceAscending);
         } else {
          sort(sortBooks.begin(), sortBooks.end(), compareBooksByPriceDescending);
         }
      break;
    default:
      break;
    }
  return sortBooks;
}


unsigned int BookSystem::EditBook(unsigned int ID, string Name, unsigned int q, string Loc, unsigned int p)
{
  Book* bookref;
  bool isexist=0;
  for (vector<Book*>::iterator it=books.begin(); it<books.end(); it++)
    {
      if ((*it)->GetBookID()==ID)
        {
          bookref = *it;
          isexist =1;
        }
    }
  if (!isexist)
    {
      return 0;
    }
  if (q<bookref->GetOrderedQuantity())
    {
     return 1;
    }
  bookref->SetBookName(Name);
  bookref->SetQuantity(q);
  bookref->SetLocation(Loc);
  bookref->SetBookPrice(p);
  return 2;
}


bool BookSystem::Receipt(unsigned int ID, unsigned int q, unsigned int p)
{
  Book* bookref;
  bool isexist=0;
  for (vector<Book*>::iterator it=books.begin(); it<books.end(); it++)
    {
      if ((*it)->GetBookID()==ID)
        {
          bookref = (*it);
          isexist =1;
        }
    }
  if (!isexist)
    {
      return 0;
    }
  bookref->SetQuantity(bookref->GetQuantity()+q);
  Book b = *bookref;
  b.SetBookPrice(p);
  b.SetQuantity(q);
  b.ClearBuyerID();
  invoice->SetIncome(b);
  return 1;
}

void BookSystem::NewInvoice()
{
  invoice = new Invoice;
}

bool BookSystem::PushToOrders(unsigned int ID, vector<unsigned int> cart)
{
  unsigned int max = orders.size();
  unsigned int maxID =0;
  if (!cart.size())
    {
      return 0;
    }
  for (vector<Order*>::iterator it=orders.begin(); it!=orders.end(); it++)
    {
      if (maxID<(*it)->orderID)
        {
            maxID = (*it)->orderID;
        }
    }
  for (unsigned int i=0; i<maxID; i++)
    {
      bool isexist=0;
      for (vector<Order*>::iterator it=orders.begin(); it!=orders.end(); it++)
        {
          if (i==(*it)->orderID)
            {
              isexist =1;
              break;
            }
        }
      if (!isexist)
        {
          max = i-1;
          break;
        }
    }
  orders.push_back(new Order(max+1));
  orders[orders.size()-1]->status = 0;
  orders[orders.size()-1]->userID = ID;
  orders[orders.size()-1]->cart = cart;
  for (vector<Book*>::iterator it = books.begin(); it!=books.end(); it++)
  {
    for (vector<unsigned int>::iterator it2 = cart.begin(); it2!=cart.end(); it2++)
    if ((*it)->GetBookID()==(*it2))
      {
        (*it)->SetOrderedQuantity((*it)->GetOrderedQuantity()+1);
        (*it)->SetBuyerID(ID);

      }
  }
  return 1;
}


bool BookSystem::ProvideOrder(unsigned int ID)
{
  bool isexist =0;
  Order* order;
  for (vector<Order*>::iterator it=orders.begin(); it!=orders.end();it++)
    {
      if (((*it)->orderID == ID) && ((*it)->status))
        {
          isexist = 1;
          order = *it;
          break;
        }
    }
  if (!isexist)
    {
      return 0;
    }
  vector<Order*> ord = GetAllOrders(order->userID);
  isexist=0;
  Book* b;

      for (vector<unsigned int>::iterator it=order->cart.begin();it!=order->cart.end();it++)
        {
          for (vector<Book*>::iterator it2=books.begin(); it2!=books.end(); it2++)
            {
              if ((*it2)->GetBookID()==(*it))
                {
                  b=*it2;
                  break;
                }
            }
          for (vector<Order*>::iterator it2=ord.begin(); it2!=ord.end();it2++)
            {
      for (vector<unsigned int>::iterator it3=(*it2)->cart.begin();it3!=(*it2)->cart.end(); it3++)
        {
          if ((*it)==(*it3))
            {
              isexist=1;
              break;
            }

        }
      if(isexist)
        {
          break;
        }
        }
          if(!isexist)
            {
              b->DeleteBuyerID(order->userID);
            }
        }
      Book bc(0);
  for (vector<unsigned int>::iterator it=order->cart.begin();it!=order->cart.end();it++)
    {
      for (vector<Book*>::iterator it2=books.begin(); it2!=books.end(); it2++)
        {
          if((*it2)->GetBookID()==(*it))
            {
          bc =*(*it2);
          bc.ClearBuyerID();
          bc.SetOrderedQuantity(0);
          bc.SetQuantity(1);
          invoice->SetOutcome(bc);
            }
        }
    }
  return 1;
}


vector<Order*> BookSystem::GetAllOrders()
{
  return orders;
}

vector<Order*> BookSystem::GetAllOrders(unsigned int ID)
{
  vector<Order*> order;
  for (vector<Order*>::iterator it=orders.begin(); it!=orders.end(); it++)
    {
        if ((*it)->userID==ID)
          {
            order.push_back(*it);
          }
    }
  return order;
}


bool BookSystem::CancelOrder(unsigned int userID, unsigned int ID)
{
   for (vector<Order*>::iterator it=orders.begin(); it!=orders.end(); it++)
     {
        if (((*it)->userID==userID) && ((*it)->orderID==ID) && (!(*it)->status))
          {
            for (vector<unsigned int>::iterator it2=(*it)->cart.begin(); it2!=(*it)->cart.end(); it2++)
              {
                for (vector<Book*>::iterator it3=books.begin(); it3<books.end(); it3++)
                    {
                    if ((*it2)==(*it3)->GetBookID())
                      {
                        (*it3)->SetOrderedQuantity((*it3)->GetOrderedQuantity()-1);
                      }
                  }
              }
            orders.erase(it);
            return 1;
          }
     }
   for (vector<Order*>::iterator it=orders.begin(); it!=orders.end(); it++)
     {
        if (((*it)->userID==userID) && ((*it)->orderID==ID) && ((*it)->status))
          {
            for (vector<unsigned int>::iterator it2=(*it)->cart.begin(); it2!=(*it)->cart.end(); it2++)
              {
                for (vector<Book*>::iterator it3=books.begin(); it3<books.end(); it3++)
                    {
                    if ((*it2)==(*it3)->GetBookID())
                      {
                        (*it3)->SetOrderedQuantity((*it3)->GetOrderedQuantity()-1);
                        (*it3)->SetQuantity((*it3)->GetQuantity()+1);
                      }
                  }
              }
            orders.erase(it);
            return 1;
          }
     }
   return 0;
}


bool BookSystem::AcceptOrder(unsigned int ID)
{
  bool isexist =0;
  Order* order;
  for (vector<Order*>::iterator it=orders.begin(); it!=orders.end();it++)
    {
      if (((*it)->orderID == ID) && (!(*it)->status))
        {
          isexist = 1;
          order = *it;
          break;
        }
    }
  if (!isexist)
    {
      return 0;
    }
  order->status=1;
  for (vector<Book*>::iterator it=books.begin(); it!=books.end(); it++)
    {
      for(vector<unsigned int>::iterator it2=order->cart.begin(); it2!=order->cart.begin(); it2++)
    {
        if ((*it2)==(*it)->GetBookID())
          {
              (*it)->SetOrderedQuantity((*it)->GetOrderedQuantity()-1);
             (*it)->SetQuantity((*it)->GetQuantity()-1);
          }
    }
    }
  return 1;
}


bool BookSystem::InvoiceToFile()
{
  if (!(invoice->IsIncomeEmpty() || invoice->IsOutcomeEmpty()))
    {
      return 0;
    }


  ofstream file("D:\\CommandProject\\New2\\Invoice\\1.txt" , ios::app);
  vector<Book> income = invoice->GetIncome();
  vector<Book> outcome = invoice->GetOutcome();
  int16_t sum=0;
  for (vector<Book>::iterator it=income.begin(); it!=income.end(); it++)
    {
      file << "Book ID Book Name Quantity Price\n";
      file << (*it).GetBookID() << " " << (*it).GetBookName() << " " << (*it).GetQuantity() << " " << (*it).GetBookPrice() << "\n";
      sum -= (*it).GetQuantity() * (*it).GetBookPrice();
      delete &(*it);
    }
  for (vector<Book>::iterator it=outcome.begin(); it!=outcome.end(); it++)
    {
      file << "Book ID Book Name Quantity Price\n";
      file << (*it).GetBookID() << " " << (*it).GetBookName() << " " << (*it).GetQuantity() << " " << (*it).GetBookPrice() << "\n";
      sum += (*it).GetQuantity() * (*it).GetBookPrice();
      delete &(*it);
    }
  income.clear();
  outcome.clear();
  file << "Document summary: " << sum << "\n";
  file.close();
  delete invoice;
  NewInvoice();
  return 1;
}
