#ifndef _USERINTERFACE_H_
#define _USERINTERFACE_H_
#include <vector>
#include <iostream>
using namespace std;
#include "book.h"
#include "book_system.h"

class UserInterface
{
protected:
    BookSystem* sysref;

public:
    void setsysref(BookSystem* ref);
    void SortBook();
    void ShowBook(vector<Book*> Books);

    void Show();
    void Find();
    void Sort();

    virtual void Menu()=0;
};

#endif // USER_H
