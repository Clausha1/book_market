#include "userinterface.h"
#include "book_system.h"
#include "customerinterface.h"
#include <iomanip>

void UserInterface::ShowBook(vector<Book*> Books)
{
    cout << setfill(' ') << left << setw(20) << "Book ID"  << "|";
    cout << setfill(' ') << left << setw(20) << "Book Name"  << "|";
    cout << setfill(' ') << left << setw(20) << "Book Quantity" << "|";
    cout << setfill(' ') << left << setw(20) << "Book Location" << "|";
    cout << setfill(' ') << left << setw(20) << "Book Price" << "\t";
    cout << endl;
    cout << setfill('-') << left << setw(100) << "-";
    cout << endl;

    for (unsigned int i=0; i<Books.size();i++ )
      {
        cout << setfill(' ') << left << setw(20) << Books[i]->GetBookID()  << "|";
        cout << setfill(' ') << left << setw(20) << Books[i]->GetBookName()  << "|";
        cout << setfill(' ') << left << setw(20) << Books[i]->GetQuantity() << "|";
        cout << setfill(' ') << left << setw(20) << Books[i]->GetLocation() << "|";
        cout << setfill(' ') << left << setw(20) << Books[i]->GetBookPrice() << "\n";
      }
}

void UserInterface::setsysref(BookSystem* ref)
{
    sysref = ref;
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
    cout << "Alphabeticly (1) or Quantity (2) or Price (3): ";
    cin >> sor1;
    cout << endl;
    cout << "Ascending (1) or Descending (0): ";
    cin >> sor2;
    cout << endl;
    if((sor1 > 3)||(sor1<1)||(sor2<0)||(sor2>1))
    {
        cout << "Unknow command" << endl;
    }
    else
    {
        ShowBook(sysref->Sort(sor1,  sor2));
    }
    system ("pause");
    system("cls");
    Menu();
}
