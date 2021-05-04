#include "simpleobject.h"

SimpleObject::SimpleObject(std::string name, std::string description,
                           unsigned int levelAdd)
    : BasicObject(name, description, levelAdd)
{
    
}

BasicObject *SimpleObject::clone() const
{
    return new SimpleObject(*this);
}
