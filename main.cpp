#include <iostream>
#include "user.h"
#include "book.h"\
#include "userinterface.h"
#include "customerinterface.h"
#include "user.h"
#include "book_system.h"
int main()
{
    BookSystem *S = new BookSystem;

    if(S->NewBook("ABCD", 10, "F7", 1))
      {
        cout << "Created";
      }
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

    S->NewUser("Name", "pass", 1);

    unsigned int c;
    bool isexituser = 0;
    do{
    cout << "Customer (1) or Employee (2): ";
    cin >> c;
    cout << endl;
    if(c == 1)
    {
        string name;
        string pass;
        bool isexist = 0;
        do{
        cout << "Input your Nickname: ";
        cin >> name;
        cout << "Input your Password: ";
        cin >> pass;
        vector<User*> userref = S->GetAllUsers();

        for (vector<User*>::iterator it=userref.begin(); it!=userref.end(); it++)
        {
          if (((*it)->GetStatus() == c) && ((*it)->GetNickname() == name) && ((*it)->GetPassword() == pass))
            {
              cout << "Login is successful" << endl;
              isexist = 1;
              break;
            }
        }
        if (isexist)
        {
            UserInterface *U= new CustomerInterface;
            U->setsysref(S);
            U->Menu();
        }
        else
        {
            cout << "User is not exist or invalid password" << endl;
        }
        cout << "Do you want to rewrite? (1) Yes; (0) No: ";
        cin >> isexituser;
        if(!isexituser)
        {
           break;
        }
        } while(!isexist);
    }
    } while(c);
}
