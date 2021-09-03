#ifndef CONVERSAS_H
#define CONVERSAS_H

#include <map>
#include <vector>
#include <QPixmap>

class User;

class Conversas{
    std::string label;
    std::string icon;
    std::vector<std::string> msg;
    std::map<std::string, User*> usuarios;

    void addUser(User* user);

public:
    Conversas(std::string label, std::string icon);
    void setLabel(std::string label);
    std::string getLabel();
    std::string getIcon();
    std::vector<std::string> getMsg();
    void addMsg(std::string m);

    friend class User;

};

#endif // CONVERSAS_H

#include "user.h"

