#ifndef MODERINTERFACE
#define MODERINTERFACE
#include "userinterface.h"
#include <vector>
class ModerInterface : public UserInterface
{
protected:

private:


public:
    void Menu();
    void EditBook();
    void ShowAllUsers();
    void DeleteBook();
    void NewBook();
    void DeleteUser();
    void SetSelfStatus(unsigned int s);
};

#endif // MODERINTERFACE

