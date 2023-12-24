#ifndef _USERINTERFACE_H_
#define _USERINTERFACE_H_
#include <iostream>
#include "book_system.h"
using namespace std;

class UserInterface
{
protected:
    BookSystem* sysref;
    unsigned int selfstatus;
    unsigned int selfID;

public:
    void setsysref(BookSystem* ref);
    void SortBook();
    void ShowBook(vector<Book*> Books);

    void Show();
    void Find();
    void Sort();

    virtual void Menu()=0;
    void SetSelfStatus(unsigned int s);
    void SetSelfID(unsigned int ID);
    void ShowAllOrders(vector<Order*> orders, bool status);
};

#endif // USER_H
