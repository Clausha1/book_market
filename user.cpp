#include "user.h"

user::user()
{

}

string user::GetNickname()
{
  return nickname;
}

void user::SetNickname(string n)
{
  nickname = n;
}

void user::SetPassword(string p)
{
  password = p;
}

string user::GetPassword()
{
  return password;
}

int user::GetStatus()
{
  return status;
}

void user::SetStatus(int s)
{
  status = s;
}
