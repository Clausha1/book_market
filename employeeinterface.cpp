#include "employeeinterface.h"
#include "book_system.h"
#include <iomanip>

void EmployeeInterface::Menu()
{
cout << "1) Show All Books" << endl;
cout << "2) Search Book" << endl;
cout << "3) Sort Books" << endl;
cout << "4) Edit Book"<<endl;
cout << "5) Show all Users"<<endl;
cout << "6) Delete Book"<<endl;
cout << "7) Add Book"<<endl;
cout << "8) Receipt of product"<<endl;
cout << "9) Invoice"<<endl;
cout << "10) Accept the order"<<endl;
cout << "0) Exit" << endl;
cout << endl;
cout << "Select action: ";
int x;
cin >> x;
cout << endl;

switch(x)
{
case 0:

break;
case 1:
    system("cls");
    Show();
break;
case 2:
    system("cls");
    Find();
break;
case 3:
    system("cls");
    Sort();
break;
case 4:
    system("cls");
    EditBook();
break;
case 5:
    system("cls");
    ShowAllUsers();
break;
case 6:
    system("cls");
    DeleteBook();
break;
case 7:
    system("cls");
    NewBook();
break;
case 8:
    system("cls");
    Receipt();
break;
case 9:
    system("cls");
    Invoice();
break;
case 10:
    system("cls");
    Accept();
break;
}
}



void EmployeeInterface::ShowAllUsers()
{
    cout << setfill(' ') << left << setw(20) << "User ID"  << "|";
    cout << setfill(' ') << left << setw(20) << "User Name" << "|";
    cout << setfill(' ') << left << setw(20) << "Status" << "\t";
    cout << endl;
    cout << setfill('-') << left << setw(60) << "-";
    cout << endl;

    vector<User*> U = sysref->GetAllUsers();
    for(vector<User*>::iterator it = U.begin(); it != U.end(); it++)
    {
        if((*it)->GetStatus()<selfstatus)
        {
            cout << setfill(' ') << left << setw(20) << (*it)->GetUserID()  << "|";
            cout << setfill(' ') << left << setw(20) << (*it)->GetNickname() << "|";
            cout << setfill(' ') << left << setw(20) << (*it)->GetStatus() << "\n";
        }
    }
    system("pause");
    system("cls");
    Menu();
}

void EmployeeInterface::Accept()
{

}

void EmployeeInterface::Invoice()
{

}

void EmployeeInterface::Receipt()
{
    unsigned int ID;
    unsigned int q;
    unsigned int p;
    ShowBook(sysref->GetAllBooks());
    cout << endl;
    cout << "Enter book ID: ";
    cin >> ID;
    cout << "Enter book Quantity: ";
    cin >> q;
    cout << "Enter book Price: ";
    cin >> p;
    if(sysref->Receipt(ID, q, p))
    {
        cout << "Successfully Conducted" << endl;
    }
    system("pause");
    system("cls");
    Menu();
}

void EmployeeInterface::NewBook()
{
    string Name;
    int q;
    string Loc;
    unsigned int p;
    ShowBook(sysref->GetAllBooks());
    cout << endl;
    cout << "Enter book Name: ";
    cin >> Name;
    cout << "Enter book Quantity: ";
    cin >> q;
    cout << "Enter book Location: ";
    cin >> Loc;
    cout << "Enter book Price: ";
    cin >> p;
    bool add = sysref->NewBook(Name, q, Loc, p);
    switch (add)
    {
    case 0:
        cout << "This book is Exist" << endl;
    break;

    case 1:
        cout << "Book created" << endl;
    break;
    }
    system("pause");
    system("cls");
    Menu();
}

void EmployeeInterface::DeleteBook()
{
    unsigned int ID;
    ShowBook(sysref->GetAllBooks());
    cout << endl;
    cout << "Select User ID: ";
    cin >> ID;
    bool del = sysref-> DeleteBook(ID);
    switch (del)
    {
    case 0:
        cout << "Book is not Exist" << endl;
    break;

    case 1:
        cout << "Book Deleted" << endl;
    break;
    }

    system("pause");
    system("cls");
    Menu();
}

void EmployeeInterface::EditBook()
{
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
    system("cls");
    Menu();
}
