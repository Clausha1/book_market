#ifndef _USER_H_
#define _USER_H_
#include <string.h>
#include <string>
using namespace std;
class User
{
private:
  string nickname;
  string password;
  int status;
public:
  user();
  void SetNickname(string n);
  string GetNickname();
  void SetPassword(string p);
  string GetPassword();
  void SetStatus(int s);
  int GetStatus();
};

#endif // USER_H
