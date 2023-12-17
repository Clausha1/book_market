#ifndef _CUSTOMERINTERFACE_H_
#define _CUSTOMERINTERFACE_H_
#include "book_system.h"
#include "userinterface.h"

class CustomerInterface : public UserInterface
{
public:
    void Menu();
};

#endif // CUSTOMER

