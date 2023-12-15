#include "user.h"
#include <iomanip>

void user::ShowBook(vector<Book*> Books)
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


