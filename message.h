#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message
{
    std::string label;
    std::string icon;

public:
    Message(std::string label, std::string icon);
    std::string getLabel();
    std::string getIcon();
};

#endif // MESSAGE_H
