#include "userinterface.h"
#include "customerinterface.h"
#include "moderinterface.h"
#include "user.h"
#include "book_system.h"
#include "employeeinterface.h"
int main()
{
    BookSystem *S = new BookSystem;
    S->NewInvoice();
    S->NewUser("mod","mod", 3);

    if(S->NewBook("ABCD", 10, "F7", 1))
      {
        cout << "Created";
      }
    vector <Book*> a = S->Find("ABCD");
    a[0]->SetOrderedQuantity(20);

    if(S->NewBook("ABCD", 10, "F7", 1))
      {
        cout << "Created";
      }
    if(S->NewBook("EFGHRTY", 23, "A2", 2))
    {
      cout << "Created";
    }
    if(S->NewBook("TORT", 12, "A2", 5))
    {
      cout << "Created";
    }\
    if(S->NewBook("AC", 12,"F1", 4))
    {
      cout << "Created";
    }
     if(S->DeleteBook(3))
      {
        cout<<"Deleted";
      }
      if(S->NewBook("EFGHRTY", 23, "A2", 5))
      {
        cout << "Created";
      }

    vector<Book*> b = S->GetAllBooks();

    S->NewUser("cus", "pass", 1);
    S->NewUser("Customer 2", "pass", 1);
    S->NewUser("Customer 3", "pass", 1);
    S->NewUser("Customer 4", "pass", 1);
    S->NewUser("emp", "pass", 2);

    unsigned int c;
    bool isexituser = 0;
    do{
    system("cls");
    cout << "Customer (1) or Employee (2) or Moder (3) or Escape(0): ";
    cin >> c;
    cout << endl;
    if(c == 1 )
    {
        string name;
        string pass;
        bool isexist = 0;
        do{
        system("cls");
        cout << "Input your Nickname: ";
        cin >> name;
        cout << "Input your Password: ";
        cin >> pass;
        vector<User*> userref = S->GetAllUsers();
        unsigned int ID;
        for (vector<User*>::iterator it=userref.begin(); it!=userref.end(); it++)
        {
          if (((*it)->GetStatus() == c) && ((*it)->GetNickname() == name) && ((*it)->GetPassword() == pass))
            {
              system("cls");
              cout << "Login is successful" << endl;
              ID=(*it)->GetUserID();
              isexist = 1;
              break;
            }
        }
        if (isexist)
        {
            UserInterface *U= new CustomerInterface;
            U->SetSelfID(ID);
            U->setsysref(S);
            U->Menu();
            delete &U;
        }
        else
        {
            cout << "User is not exist or invalid password" << endl;
            cout << "Do you want to rewrite? (1) Yes; (0) No: ";
            cin >> isexituser;
        }
        if(!isexituser)
        {
           break;
        }
        } while(!isexist);
    }

    if(c == 2)
    {
        string name;
        string pass;
        bool isexist = 0;
        do{
        system("cls");
        cout << "Input your Nickname: ";
        cin >> name;
        cout << "Input your Password: ";
        cin >> pass;
        vector<User*> userref = S->GetAllUsers();

        for (vector<User*>::iterator it=userref.begin(); it!=userref.end(); it++)
        {
          if (((*it)->GetStatus() == c) && ((*it)->GetNickname() == name) && ((*it)->GetPassword() == pass))
            {
              system("cls");
              cout << "Login is successful" << endl;
              isexist = 1;
              break;
            }
        }
        if (isexist)
        {
            UserInterface *U= new EmployeeInterface;
            U->SetSelfStatus(c);
            U->setsysref(S);
            U->Menu();
            delete &U;
        }
        else
        {
            cout << "User is not exist or invalid password" << endl;
            cout << "Do you want to rewrite? (1) Yes; (0) No: ";
            cin >> isexituser;
        }        
        if(!isexituser)
        {
           break;
        }
        } while(!isexist);
    }

    if(c == 3)
    {
        string name;
        string pass;
        bool isexist = 0;
        do{
        system("cls");
        cout << "Input your Nickname: ";
        cin >> name;
        cout << "Input your Password: ";
        cin >> pass;
        vector<User*> userref = S->GetAllUsers();

        for (vector<User*>::iterator it=userref.begin(); it!=userref.end(); it++)
        {
          if (((*it)->GetStatus() == c) && ((*it)->GetNickname() == name) && ((*it)->GetPassword() == pass))
            {
              system("cls");
              cout << "Login is successful" << endl;
              isexist = 1;
              break;
            }
        }
        if (isexist)
        {
            UserInterface *U= new ModerInterface;
            U->SetSelfStatus(c);
            U->setsysref(S);
            U->Menu();
            delete &U;
        }
        else
        {
            cout << "User is not exist or invalid password" << endl;
            cout << "Do you want to rewrite? (1) Yes; (0) No: ";
            cin >> isexituser;
        }
        if(!isexituser)
        {
           break;
        }
        } while(!isexist);
    }
    if(c == 0)
    {
        break;
    }

    } while(c);
    delete S;
    return 0;
}
