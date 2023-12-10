#include <iostream>
#include "book.h"
int main()
{
 Book* b1 = new Book(1);
 string in;
 string L;
 int q;
 vector<unsigned int> ref;
 cin >> in;
 b1->SetBookName(in);
 cout << b1->GetBookName();
 cin >> q;
 b1->SetQuantity(q);
 cout << b1->GetQuantity();
 cin >> L;
 b1->SetLocation(L);
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
