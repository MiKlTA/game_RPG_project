#ifndef BASIC_HERO_H
#define BASIC_HERO_H

#include <typeinfo>
#include <vector>
#include <cmath>


#include "../specialfraction.h"
#include "../functionsWithItems.h"
#include "../inventory.h"



struct BasicHeroInfo
{
    unsigned int    maxHealth;
    unsigned int    health;
    
    unsigned int    maxCapacity;
    unsigned int    capacity;
    
    unsigned int    unarmedDamage;
    unsigned char   dexterity;
    
    unsigned char   levelMultipler;
    unsigned int    level;
    unsigned int    levelProgress;
};

class BasicHero : public GameObject
{
    
public:
    using ContainerItems_t = std::vector<BasicItem *>;
    
    
    
    BasicHero() {};
    BasicHero(std::string name, std::string description,
              unsigned int maxHealth, unsigned int maxCapacity,
              unsigned int unarmedDamage, SpecialFraction dexterity,
              SpecialFraction levelMultipler, unsigned int inventorySize);
    virtual ~BasicHero();
    
    
    const BasicHeroInfo & getBasicHeroInfo() const;
    void setBasicHeroInfo(BasicHeroInfo info);
    
    const ContainerItems_t & getDefaultItems() const;
    void addDefaultItem(BasicItem *item);
    bool removeDefaultItem(ID_t itemID);
    
    const Inventory & getInventory() const;
    
    void setFullHealth();
    bool hit(unsigned int damage);
    
    void setFullCapacity();
    bool giveItem(BasicItem *itemPtr);
    bool takeItem(ID_t itemID);
    
    // Returns the desired levelDegree to go to the next level
    double getLevelStep();
    void resetLevel();
    void addLevel(unsigned int level);
    
    // returns true if weapon successfully found and equiped
    bool equip(ID_t itemID);
    void unequip();
    
    bool eatFoodFromInventory(ID_t foodID);
    bool useEquippedWeapon(unsigned int &damage);

    
protected:
    BasicHeroInfo m_basicHeroInfo;
    
    ContainerItems_t m_defaultItems;
    Inventory m_inventory;
    
private:
    void deleteDefaultItems();
};

#endif // BASIC_HERO_H
