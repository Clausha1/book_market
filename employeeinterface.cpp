
#include "employeeinterface.h"

void EmployeeInterface::Menu()
{
cout << "1) Show All Books" << endl;
cout << "2) Search Book" << endl;
cout << "3) Sort Books" << endl;
cout << "4) Edit book"<<endl;
cout << endl;
cout << "Select action: ";
int x;
cin >> x;
cout << endl;

switch(x)
{
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

    system("pause");
    Menu();
}
}
