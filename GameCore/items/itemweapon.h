#ifndef ITEM_WEAPON_H
#define ITEM_WEAPON_H

#include "basicitem.h"



struct ItemWeaponInfo
{
    unsigned int    damage;
    unsigned int    maxDurability;
    unsigned int    durability;
};

class ItemWeapon : public BasicItem
{
public:
    ItemWeapon() {};
    ItemWeapon(std::string name, std::string description, unsigned int weight,
                unsigned int damage, unsigned int maxDurability,
               unsigned int durability);
    virtual ~ItemWeapon() {};
    
    const ItemWeaponInfo & getItemWeaponInfo() const;

    // returns true if item is broken
    bool use();
    
/*    virtual const std::string getClassName() const override
    {return typeid(ItemWeapon).name();};*/
    
protected:
    ItemWeaponInfo m_itemWeaponInfo;
};

#endif // ITEM_WEAPON_H
