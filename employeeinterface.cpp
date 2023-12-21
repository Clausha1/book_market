#include "employeeinterface.h"
#include "book_system.h"

void EmployeeInterface::Menu()
{
cout << "1) Show All Books" << endl;
cout << "2) Search Book" << endl;
cout << "3) Sort Books" << endl;
cout << "4) Edit Book"<<endl;
cout << endl;
cout << "Select action: ";
int x;
cin >> x;
cout << endl;

switch(x)
{
case 1:
    Show();
break;
case 2:
    Find();
break;
case 3:
    Sort();
break;
case 4:
    unsigned int ID;
    string Name;
    unsigned int q;
    string Loc;
    unsigned int p;
    ShowBook(sysref->GetAllBooks());
    cout << endl;
    cout << "Select book ID: ";
    cin >> ID;
    cout << "Enter book Name: ";
    cin >> Name;
    cout << "Enter book Quantity: ";
    cin >> q;
    cout << "Enter book Location: ";
    cin >> Loc;
    cout << "Enter book Price: ";
    cin >> p;
    unsigned int edit = sysref->EditBook(ID, Name, q, Loc, p);
    switch (edit)
    {
    case 0:
        cout << "Book with that ID is not exist" << endl;
    break;

    case 1:
        cout << "Book quantity can't be more than ordered book quantity" << endl;
    break;

    case 2:
        cout << "Book edited" << endl;
    break;
    }

    system("pause");
    Menu();
}
}
