#include "customerinterface.h"
void CustomerInterface::ShowCart(){
  vector<Book*> bookc = sysref->GetAllBooks();
  vector<Book*> outputOrder;
  for (unsigned int i=0; i<bookc.size();i++){
      for (unsigned int j=0; j<cart.size();j++){
          if (bookc[i]->GetBookID()==cart[j]){
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
cout << "6) Delete one item from cart" << endl;
cout << "7) Clear Cart" << endl;
cout << "8) Provide Order" << endl;
cout << "9) ShowAllOrders" << endl;
cout << endl;
cout << "Select action: ";
int x;
cin >> x;
cout << endl;


switch(x) {
case 0:

break;
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
cout<< "Book added\n";
}
else {
cout<<"Book with that ID doesn't exist\n";
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
    unsigned int orderId;
    cout << "Enter ID of the order you want to cancel: ";
    cin >> orderId;
    cout << endl;
    if (CancelOrder(orderId)){
        cout<<"Order cancelled\n";
      }
    else {
        cout<<"No such order\n";
      }
    system("pause");
    system("cls");
    Menu();
case 7:
ClearCart();
system("pause");
system("cls");
Menu();
  case 8:
    PlaceOrder();
    ClearCart();
    system("pause");
    system("cls");
    Menu();
  case 9:
    vector<Order*>v1=sysref->GetAllOrders(selfID);
    ShowAllOrders(v1);
    system("pause");
    system("cls");
    Menu();

 /* case 10:
    ViewOrders();
    system("pause");
    system("cls");
    Menu();
*/

}
}
bool CustomerInterface::CancelOrder(unsigned int ID){
  bool isexist=0;
  vector<unsigned int>::iterator a;
  for (vector<unsigned int>::iterator it=cart.begin();it!= cart.end(); it++){
      if ((*it)==ID){
          isexist=1;
          a=it;
          break;
        }
    }
  if (!isexist){
      return 0;
    }
  cart.erase(a);
  return 1;
}
void CustomerInterface::PlaceOrder()
{
bool success =sysref->PushToOrders(selfID, cart);
if (success)
{
cout << "Order placed successfully!" << endl;
}
else
{
cout << "Failed to place order. Please check your cart." << endl;
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




void CustomerInterface::ClearCart() {
cart.clear();
cout << "Your cart has been cleared!" << endl;
}
/* void CustomerInterface::ViewOrders() {
  vector<Order> orders = sysref->GetOrdersByCustomerID(selfID);
  if (orders.empty()) {
    cout << "You have no orders yet." << endl;
  } else {
    cout << "Your orders: " << endl;
    for (const auto& order : orders) {
      cout << "Order ID: " << order.GetOrderID() << " | Order Date: " << order.GetOrderDate() << " | Total Amount: " << order.GetTotalAmount() << endl;
      // Можно добавить ещё информации о заказе, если это необходимо
    }
  }
}
*/
