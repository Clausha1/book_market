#include "userinterface.h"
#include "customerinterface.h"
#include <iomanip>

void UserInterface::ShowBook(vector<Book*> Books)
{
    cout << setfill(' ') << left << setw(20) << "Book ID"  << "|";
    cout << setfill(' ') << left << setw(20) << "Book Name"  << "|";
    cout << setfill(' ') << left << setw(28) << "Book Quantity (Ordered/All)" << "|";
    cout << setfill(' ') << left << setw(20) << "Book Location" << "|";
    cout << setfill(' ') << left << setw(20) << "Book Price" << "\t";
    cout << endl;
    cout << setfill('-') << left << setw(100) << "-";
    cout << endl;

    for (unsigned int i=0; i<Books.size();i++ )
      {
        cout << setfill(' ') << left << setw(20) << Books[i]->GetBookID()  << "|";
        cout << setfill(' ') << left << setw(20) << Books[i]->GetBookName()  << "|";

        cout << setfill(' ') << right << setw(14) << Books[i]->GetOrderedQuantity()<< left << setw(1) <<"/" << left << setw(13)<< Books[i]->GetQuantity()<< "|";
        cout << setfill(' ') << left << setw(20) << Books[i]->GetLocation() << "|";
        cout << setfill(' ') << left << setw(20) << Books[i]->GetBookPrice() << "\n";
      }
}
void UserInterface::ShowAllOrders(vector<Order*> orders){
  for (vector<Order*>::iterator it= orders.begin();it!=orders.end();it++){
      cout << "Order#" << (*it)->orderID <<endl;
      vector<Book*> b=sysref->GetAllBooks();
      vector <Book*> a;
      for (vector<Book*>::iterator it2=b.begin(); it2!=b.end(); it2++){
          for (vector<unsigned int>::iterator it3=(*it)->cart.begin();it3!=(*it)->cart.end();it3++){
              if ((*it2)->GetBookID()==*it3){
                  a.push_back(*it2);
                }
            }
        }
      ShowBook(a);
      a.clear();
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

void UserInterface::SetSelfStatus(unsigned int s)
{
    selfstatus = s;
}
void UserInterface::SetSelfID(unsigned int ID)
{
    selfstatus = ID;
}
