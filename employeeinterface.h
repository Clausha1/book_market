#ifndef _EMPLOYEEINTERFACE_H_
#define _EMPLOYEEINTERFACE_H_
#include "userinterface.h"
#include <vector>
class EmployeeInterface : public UserInterface
{
protected:

private:


public:
    void Menu();
    void EditBook();
    void ShowAllUsers();
    void DeleteBook();
    void NewBook();
    void Receipt();
};

#endif // EMPLOYEE

