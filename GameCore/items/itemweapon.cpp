#include "itemweapon.h"

ItemWeapon::ItemWeapon(std::string name, std::string description,
                         unsigned int weight, unsigned int damage,
                         unsigned int maxDurability, unsigned int durability)
    : BasicItem(name, description, weight),
      m_itemWeaponInfo{damage, maxDurability, durability}
{
    
}

const ItemWeaponInfo & ItemWeapon::getItemWeaponInfo() const
{
    return m_itemWeaponInfo;
}



bool ItemWeapon::use()
{
    if (m_itemWeaponInfo.durability > 0)
    {
        m_itemWeaponInfo.durability--;
    }
    
    return !(m_itemWeaponInfo.durability > 0);
}

