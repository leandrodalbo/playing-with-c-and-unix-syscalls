#include "./user.h"
#include <stdio.h>

User createUser(char *userName)
{
  User newUser = {.name = userName};
  return newUser;
}

void printUser(User user)
{
  printf("User with name: %s \n", user.name);
}
