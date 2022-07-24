
typedef struct UserStruct
{
  char *name;
} User;

extern User createUser(char *name);
void printUser(User user);