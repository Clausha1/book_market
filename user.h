#ifndef USER_H
#define USER_H
#include <vector>
#include <iostream>
using namespace std;
#include "book.h"
#include "book_system.h"

class user
{
protected:
    BookSystem* sysref;

public:
    string FindBook();
    void setsysref(BookSystem* ref);
    void SortBook();
    void ShowBook(vector<Book*> Books);
    virtual void Menu()=0;
};

#endif // USER_H
