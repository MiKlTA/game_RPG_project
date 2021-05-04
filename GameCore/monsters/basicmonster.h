//
// Created by Asus on 15.04.2021.
//

#ifndef TEST_PROJEKT_BASICMONSTER_H
#define TEST_PROJEKT_BASICMONSTER_H

#include "../gameobject.h"
#include "../functions.h"
#include "../specialfraction.h"



struct BasicMonsterInfo
{
    unsigned int    maxHealth;
    unsigned int    health;
    
    unsigned int    damage;
    unsigned int    exp;
    unsigned char   dexterity;
};

class BasicMonster : public GameObject
{

public:
    BasicMonster() {};
    BasicMonster(std::string name, std::string description,
                 unsigned int maxHealth, unsigned int damage,
                 unsigned int exp, SpecialFraction dexterity);
    virtual ~BasicMonster() {};
    
    const BasicMonsterInfo & getBasicMonsterInfo() const;
    
//    void increaseDamage(unsigned int damage);

    bool hit(unsigned int damage);
    
    void view();
    bool wasViewed() const;
    
protected:
    BasicMonsterInfo m_basicMonsterInfo;
    
    bool m_wasViewed;
};

#endif //TEST_PROJEKT_BASICMONSTER_H
