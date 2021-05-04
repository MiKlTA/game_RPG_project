//
// Created by Asus on 15.04.2021.
//

#include <iostream>
#include "basicmonster.h"

BasicMonster::BasicMonster(std::string name, std::string description,
                           unsigned int maxHealth,
                           unsigned int damage, unsigned int exp,
                           SpecialFraction dexterity)
    : GameObject(name, description),
      m_basicMonsterInfo{maxHealth, maxHealth, damage,
                         exp, dexterity.getChar()},
      m_wasViewed(false)
{
    
}

const BasicMonsterInfo & BasicMonster::getBasicMonsterInfo() const
{
    return m_basicMonsterInfo;
}

void BasicMonster::view()
{
    m_wasViewed = true;
}

bool BasicMonster::wasViewed() const
{
    return m_wasViewed;
}

