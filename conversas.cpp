#include "conversas.h"
#include "user.h"

Conversas::Conversas(std::string label, std::string icon)
{
    this->label = label;
    this->icon = icon;
}

void Conversas::addUser(User *user){
    usuarios.insert(std::make_pair(user->getName(), user));
}

void Conversas::setLabel(std::string label){
    this->label = label;
}

std::string Conversas::getLabel(){
    return label;
}

std::string Conversas::getIcon(){
    return icon;
}

std::vector<std::string> Conversas::getMsg(){
    return msg;
}

void Conversas::addMsg(std::string m){
    msg.push_back(m);

}
