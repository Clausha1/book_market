#include "user.h"

User::User(unsigned int ID)
{
  userID = ID;
}

unsigned int User::GetUserID()
{
  return userID;
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

unsigned int User::GetStatus()
{
  return status;
}

void User::SetStatus(unsigned int s)
{
  status = s;
}
