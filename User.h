#ifndef _USERS_H_
#define _USERS_H_

#include <string.h>
class User
{
public:
    User(){}
    User(char*, char*);

    //重载 "==" 运算符
    bool operator ==(const User& u) const{
        if(!strcmp(userName, u.userName)
           && !strcmp(password, u.password))
            return true;
        return false;
    }
private:
    char userName[20];
    char password[20];
};
#endif
