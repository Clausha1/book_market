#include "book.h"
#include "book_system.h"
#include "userinterface.h"
#include "customerinterface.h"

void CustomerInterface::ShowCart(){
vector<Book*> bookc = sysref->GetAllBooks();
vector<Book*> outputOrder;
for (unsigned int i=0; i<bookc.size(); i++){
for (unsigned int j=0; j<cart.size(); j++){
if (bookc[i]->GetBookID() == cart[j]){
outputOrder.push_back(bookc[i]);
break;
}
}
}
ShowBook(outputOrder);
}

void CustomerInterface::Menu() {
cout << "1) Show All Books" << endl;
cout << "2) Search Book" << endl;
cout << "3) Sort Books" << endl;
cout << "4) Add to cart"<< endl;
cout << "5) Show cart"<< endl;
cout << "6) Clear Cart" << endl;
cout << "7) Provide Order" << endl;
cout << endl;
cout << "Select action: ";
int x;
cin >> x;
cout << endl;

switch(x) {
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
unsigned int order;
cout<< "Write ID of a book you want to order: ";
cin >> order;

if (AddToCart(order)){
cout<< "Book added";
}
else {
cout<<"Book with that ID doesn't exist";
}
system("pause");
system("cls");
Menu();
case 5:
ShowCart();
system("pause");
system("cls");
Menu();
case 6:
ClearCart();
system("pause");
system("cls");
Menu();
  case 7:
    ProvideOrder();
    ClearCart();
    system("pause");
    system("cls");
    Menu();
}
}

bool CustomerInterface::AddToCart(unsigned int order){
vector<Book*> bookc = sysref->GetAllBooks();
bool isexist=0;
for (unsigned int i=0; i<bookc.size(); i++){
if (bookc[i]->GetBookID() == order){
isexist=1;
}
}
if (isexist){
cart.push_back(order);
return 1;
}
else {
return 0;
}
}

vector<unsigned int> CustomerInterface::ProvideOrder(){
return cart;
}

void CustomerInterface::ClearCart() {
cart.clear();
cout << "Your cart has been cleared!" << endl;
}
