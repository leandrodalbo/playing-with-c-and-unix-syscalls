#include "user/user.h"
#include <stdlib.h>
#include <stdio.h>

void freeAllocatedUsers(User **users);
void fillWithUsers(int total, User **users);
void showUsers(int total, User *users);

int main()
{
  int totalUsers = 10;
  User *users;

  fillWithUsers(totalUsers, &users);
  showUsers(totalUsers, users);
  freeAllocatedUsers(&users);
}

void freeAllocatedUsers(User **users)
{
  free(*users);
}

void fillWithUsers(int total, User **users)
{
  *users = (User *)malloc(total * sizeof(User));

  for (int i = 0; i < total; i++)
  {
    (*users)[i] = createUser("xxx");
  }
}

void showUsers(int total, User *users)
{
  for (int i = 0; i < total; i++)
  {
    printUser(users[i]);
  }
}