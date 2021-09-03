#ifndef USER_H
#define USER_H

#include <iostream>
#include <map>

#include "conversas.h"

class User{
    std::string name;
    std::string username;
    std::string pass;
    std::vector<Conversas*> conversas;

public:
    User(std::string username = "");
    void addConversa(Conversas* conversa);
    std::vector<Conversas*> getConversas();
    void setName(std::string name);
    void setUsername(std::string username);
    void setPass(std::string pass);
    std::string getName();
    std::string getUsername();
    bool cmpPass(std::string pass);

};

#endif // GRUPOS_H
