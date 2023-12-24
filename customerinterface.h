#ifndef _CUSTOMERINTERFACE_H_
#define _CUSTOMERINTERFACE_H_
#include "userinterface.h"
#include <vector>
class CustomerInterface : public UserInterface
{
protected:
  vector<unsigned int> cart;
public:
    void ShowCart();
    void Menu();
    void ClearCart();
    void CancelOrder(unsigned int ID);
    bool AddToCart(unsigned int order);
    void PlaceOrder();
    void ViewOrders();
    bool CancelOneItem(unsigned int ID);
};

#endif // CUSTOMER

