#ifndef _EMPLOYEEINTERFACE_H_
#define _EMPLOYEEINTERFACE_H_
#include "userinterface.h"
#include <vector>
class EmployeeInterface : public UserInterface
{
protected:

public:
    void Menu();
    void EditBook(unsigned int edit);
};

#endif // EMPLOYEE

