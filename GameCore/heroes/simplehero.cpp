#include "simplehero.h"

SimpleHero::SimpleHero(std::string name, std::string description,
                       unsigned int maxHealth, unsigned int maxCapacity,
                       unsigned int unarmedDamage, SpecialFraction dexterity,
                       SpecialFraction levelMultipler,
                       unsigned int inventorySize)
    : BasicHero(name, description, maxHealth, maxCapacity,
                unarmedDamage, dexterity, levelMultipler, inventorySize)
{
    
}

