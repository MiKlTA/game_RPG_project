#include "basicobject.h"

BasicObject::BasicObject(std::string name, std::string description,
                           unsigned int levelAdd)
    : GameObject(name, description),
      m_basicObjectInfo{levelAdd, false}
{
    
}

BasicObject::~BasicObject()
{
    deleteLoot();
}

void BasicObject::addLootItem(BasicItem *item, unsigned char chance)
{
    m_loot.push_back(std::make_pair(item, chance));
}

bool BasicObject::removeLootItem(ID_t itemID)
{
    for (auto i = m_loot.begin(); i != m_loot.end(); ++i)
    {
        if ((*i).first->getID() == itemID)
        {
            delete (*i).first;
            m_loot.erase(i);
            return true;
        }
    }
    return false;
}

const BasicObject::LootContainer_t & BasicObject::getLootItems() const
{
    return m_loot;
}

const BasicObjectInfo & BasicObject::getBasicObjectInfo() const
{
    return m_basicObjectInfo;
}

// private ---------------------------------------------

void BasicObject::deleteLoot()
{
    for (auto i : m_loot)
    {
        delete i.first;
    }
    m_loot.clear();
}
