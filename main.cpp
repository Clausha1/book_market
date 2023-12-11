#include <iostream>
#include "book.h"
#include "book_system.h"
int main()
{
  BookSystem S = new BookSystem;
  S.NewBook("ABCD", 10, "F7");

 Book* b1 = new Book(1);

 vector<unsigned int> ref;
 b1->SetBookName(S.GetNewBookName());
 cout << b1->GetBookName();
 b1->SetQuantity(S.GetNewBookQuantity());
 cout << b1->GetQuantity();
 b1->SetLocation(S.GetNewBookLocation());
 cout << b1->GetLocation();
 if(b1->SetBuyerID(1000)){
     cout << "Pasted";
   }
 else
   {
     cout << "Cant paste";
   };
 if(b1->SetBuyerID(1001)){
     cout << "Pasted";
   }
 else
   {
     cout << "Cant paste";
   };
 ref = b1->GetBuyerID();
 for (unsigned int i; i<ref.size(); i++)
   {
     cout << ref[i] << " ";
   };
 delete b1;
 return 0;
}
