#include "message.h"

Message::Message(std::string label, std::string icon)
{
    this->label = label;
    this->icon = icon;
}

std::string Message::getLabel(){
    return label;
}

std::string Message::getIcon(){
    return icon;
}

