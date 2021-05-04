#include "simplemonster.h"

SimpleMonster::SimpleMonster(std::string name, std::string description,
                             unsigned int maxHealth,
                             unsigned int damage, unsigned int exp,
                             SpecialFraction dexterity)
    : BasicMonster(name, description, maxHealth, damage, exp, dexterity)
{
    
}

SimpleMonster::BasicMonster *SimpleMonster::clone() const
{
    return new SimpleMonster(*this);
}
