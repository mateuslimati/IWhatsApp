#include "usermanager.h"

UserManager::UserManager(){

}

bool UserManager::addUser(User *user){
    return users.insert(std::make_pair(user->getUsername(), user)).second;
}

bool UserManager::login(std::string username, std::string pass){
    if(users.find(username) != users.end()){
        User *user = users.find(username)->second;
        if(user->cmpPass(pass))
            return true;
    }
    return false;
}

User* UserManager::getUser(std::string username){
    return users.find(username)->second;
}

bool UserManager::searchUser(std::string username){
    if(users.find(username) != users.end())
        return true;
    return false;
}

std::map<std::string,User*> UserManager::getUsers(){
    std::map<std::string,User*> usuarios = users;
    return usuarios;
}
