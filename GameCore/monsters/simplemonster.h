#ifndef SIMPLEMONSTER_H
#define SIMPLEMONSTER_H

#include "basicmonster.h"



class SimpleMonster : public BasicMonster
{
    
public:
    SimpleMonster() {};
    SimpleMonster(std::string name, std::string description,
                  unsigned int maxHealth, unsigned int damage,
                  unsigned int exp, SpecialFraction dexterity);
    virtual ~SimpleMonster() {};
    
    const std::string getClassName() const
    {return typeid(BasicMonster).name();};
};

#endif // SIMPLEMONSTER_H
