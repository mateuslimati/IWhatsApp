#include "chatsmanager.h"

ChatsManager::ChatsManager()
{

}

bool ChatsManager::addUser(User* user){
    return userConversas.insert(std::make_pair(user, nullptr)).second;
}

bool ChatsManager::addConversa(Conversas* conversas){

}
