#ifndef USER_H
#define USER_H
#include <vector>
#include <iostream>
using namespace std;
#include "book.h"

class user
{
public:
    void FindBook();
    void SortBook();
    void ShowBook(vector<Book*> Books);
    virtual void Menu()=0;
};

#endif // USER_H
