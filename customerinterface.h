#ifndef _CUSTOMERINTERFACE_H_
#define _CUSTOMERINTERFACE_H_
#include "book_system.h"
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
    bool CancelOrder(unsigned int ID);
    bool AddToCart(unsigned int order);
    vector<unsigned int> ProvideOrder();
    vector<unsigned int> orderId();
};

#endif // CUSTOMER

