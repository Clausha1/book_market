#ifndef _CUSTOMERINTERFACE_H_
#define _CUSTOMERINTERFACE_H_
#include "book_system.h"
#include "userinterface.h"
#include <vector>
class CustomerInterface : public UserInterface
{
protected:
  vector<int> cart;

public:
    void ShowCart(vector<int> cartList);
    void Menu();
    bool AddToCart(unsigned int order);
    vector<int> ProvideOrder();
};

#endif // CUSTOMER

