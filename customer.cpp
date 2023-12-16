#include "book.h"
#include "book_system.h"
#include "user.h"
#include "customer.h"

void customer::Menu()
{
cout << "1) Show All Books" << endl;
cout << "2) Search Book" << endl;
cout << endl;
cout << "Select action: ";
int x;
cin >> x;
cout << endl;

switch(x)
{
case 1:
    ShowBook(sysref->GetAllBooks());
    system ("pause");
    system("cls");
    Menu();
break;
case 2:
    cout << "Find by Template: ";
    string temp;
    cin >> temp;
    ShowBook(sysref->Find(temp));
    system ("pause");
    system("cls");
    Menu();
break;
}
}
