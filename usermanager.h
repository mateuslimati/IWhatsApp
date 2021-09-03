#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <map>
#include <string>
#include "user.h"

class UserManager{
    std::map<std::string, User*> users;

public:
    UserManager();
    bool addUser(User *user);
    bool login(std::string username, std::string pass);
    User* getUser(std::string username);
    bool searchUser(std::string username);
    std::map<std::string,User*> getUsers();
};

#endif // USERMANAGER_H
