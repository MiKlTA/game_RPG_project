#ifndef SIMPLEHERO_H
#define SIMPLEHERO_H

#include "basichero.h"



class SimpleHero : public BasicHero
{
public:
    SimpleHero() {};
    SimpleHero(std::string name, std::string description,
               unsigned int maxHealth, unsigned int maxCapacity,
               unsigned int unarmedDamage, SpecialFraction dexterity,
               SpecialFraction levelMultipler, unsigned int inventorySize);
    virtual ~SimpleHero() {};

    
     const std::string getClassName() const
    {return typeid(BasicHero).name();};
};

#endif // SIMPLEHERO_H
