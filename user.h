#ifndef _USER_H_
#define _USER_H_
#include <string.h>
#include <string>
using namespace std;
class User
{
private:
  unsigned int userID;
  string nickname;
  string password;
  unsigned int status;
public:
  User(unsigned int ID);
  unsigned int GetUserID();
  void SetNickname(string n);
  string GetNickname();
  void SetPassword(string p);
  string GetPassword();
  void SetStatus(unsigned int s);
  unsigned int GetStatus();
};

#endif // USER_H
