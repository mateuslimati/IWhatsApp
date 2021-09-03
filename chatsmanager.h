#ifndef CHATSMANAGER_H
#define CHATSMANAGER_H

#include "user.h"
#include "conversas.h"

#include <vector>
#include <map>

class ChatsManager{
    std::map<User*, std::vector<Conversas*>> userConversas;
    std::map<Conversas*, std::vector<User*>> conversasUser;

public:
    ChatsManager();
    bool addUser(User* user);
    bool addConversa(Conversas* conversas);
};

#endif // CHATSMANAGER_H
