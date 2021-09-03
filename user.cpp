#include "user.h"
#include <iostream>

using namespace std;

User::User(std::string username) :
    username(username)
{

}
void User::addConversa(Conversas* conversa){
    conversas.push_back(conversa);
    conversa->addUser(this);
}

std::vector<Conversas*> User::getConversas(){
    return conversas;
}

void User::setName(std::string name){
    this->name = name;
}

void User::setUsername(std::string username){
    this->username = username;
}

void User::setPass(std::string pass){
    this->pass = pass;
}

std::string User::getName(){
    return name;
}

std::string User::getUsername(){
    return username;
}

bool User::cmpPass(std::string pass){
    return (this->pass == pass);

}
