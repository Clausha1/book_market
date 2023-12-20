#include "user.h"

User::User()
{

}

string User::GetNickname()
{
  return nickname;
}

void User::SetNickname(string n)
{
  nickname = n;
}

void User::SetPassword(string p)
{
  password = p;
}

string User::GetPassword()
{
  return password;
}

int User::GetStatus()
{
  return status;
}

void User::SetStatus(int s)
{
  status = s;
}
