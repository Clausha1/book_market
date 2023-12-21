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
    EditBook();
break;
case 5:
    ShowAllUsers();
break;
}
}

void EmployeeInterface::SetSelfStatus(unsigned int s)
{
    selfstatus = s;
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
    system("cls");
    system("pause");
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
    system("cls");
    system("pause");
    Menu();
}
