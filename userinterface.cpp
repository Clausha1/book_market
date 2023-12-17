#include "userinterface.h"
#include "book_system.h"
#include "customerinterface.h"
#include <iomanip>

void UserInterface::ShowBook(vector<Book*> Books)
{
    cout << setfill(' ') << left << setw(20) << "Book Name"  << "|";
    cout << setfill(' ') << left << setw(20) << "Book Quantity" << "|";
    cout << setfill(' ') << left << setw(20) << "Book Location" << "\t";
    cout << endl;
    cout << "-------------------------------------------------------";
    cout << endl;

    for (unsigned int i=0; i<Books.size();i++ )
      {
        cout << setfill(' ') << left << setw(20) << Books[i]->GetBookName()  << "|";
        cout << setfill(' ') << left << setw(20) << Books[i]->GetQuantity() << "|";
        cout << setfill(' ') << left << setw(20) << Books[i]->GetLocation() << "\n";
      }
}

void UserInterface::setsysref(BookSystem* ref)
{
    sysref = ref;
}

string UserInterface::FindBook()
{
    cout << "Find: ";
    string name;
    cin >> name;
}

void UserInterface::Show()
{
    ShowBook(sysref->GetAllBooks());
    system ("pause");
    system("cls");
    Menu();
}

void UserInterface::Find()
{
    string temp;
    cout << "Find by Template: ";
    cin >> temp;
    ShowBook(sysref->Find(temp));
    system ("pause");
    system("cls");
    Menu();
}

void UserInterface::Sort()
{
    int sor1;
    int sor2;
    cout << "Alphabeticly (1) or Quantity (2): ";
    cin >> sor1;
    cout << endl;
    if(sor1 == 1)
    {
        cout << "Ascending (1) or Descending (2): ";
        cin >> sor2;
        cout << endl;
        if(sor2 == 1)
        {
            ShowBook(sysref->Sort(1, 1));
            system ("pause");
            system("cls");
            Menu();
        }
        else
        {
            ShowBook(sysref->Sort(1, 0));
            system ("pause");
            system("cls");
            Menu();
        }
    }
    else{
        if(sor2 == 1)
        {
            ShowBook(sysref->Sort(2, 1));
            system ("pause");
            system("cls");
            Menu();
        }
        else
        {
            ShowBook(sysref->Sort(2, 0));
            system ("pause");
            system("cls");
            Menu();
        }
    }
    system ("pause");
    system("cls");
    Menu();
}
