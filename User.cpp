#include "User.h"

User::User(char* name, char* pwd)
{
    strcpy(userName, name);
    strcpy(password, pwd);
}
