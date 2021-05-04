#include "inventory.h"


Inventory::Inventory()
    : m_size(10),
      m_curWeapon(nullptr)
{
    
}

Inventory::Inventory(unsigned int size)
    : m_size(size),
      m_curWeapon(nullptr)
{
    
}

Inventory::~Inventory()
{
    clearItems();
}

const Inventory::containerItem_t & Inventory::getItems() const
{
    return m_items;
}

const ItemWeapon *Inventory::getCurrentWeapon() const
{
    return m_curWeapon;
}

unsigned int Inventory::getMaxSize() const
{
    return m_size;
}

bool Inventory::addItem(BasicItem *item)
{
    if (m_items.size() < m_size)
    {
        m_items.push_back(item);
        return true;
    }
    return false;
}

bool Inventory::removeItem(ID_t itemID)
{
    auto itemIter = findByID(m_items, itemID);
    
    if (itemIter != m_items.end())
    {
        if (m_curWeapon != nullptr)
            if (m_curWeapon->getID() == itemID)
        {
            unequip();
        }
        
        for (auto i = m_items.begin(); i != m_items.end(); ++i)
        {
            if (i == itemIter)
            {
                delete *itemIter;
                m_items.erase(itemIter);
                return true;
            }
        }
    }
    return false;
}

bool Inventory::equip(ID_t itemID)
{
    auto itemIter = findByID(m_items, itemID);
    
    if (itemIter != m_items.end())
        if ((*itemIter)-getClassName() == typeid(ItemWeapon).name())
    {
        m_curWeapon = dynamic_cast<ItemWeapon *>(*itemIter);
        return true;
    }
    return false;
}

void Inventory::unequip()
{
    m_curWeapon = nullptr;
}

bool Inventory::eatFood(ID_t itemID, unsigned int &curative)
{
    auto itemIter = findByID<BasicItem>(m_items, itemID);
    
    if (itemIter != m_items.end()
            && (*itemIter)->getClassName() == typeid(ItemFood).name())
    {
        curative = dynamic_cast<ItemFood *>(*itemIter)
                ->getItemFoodInfo().curative;
        
        m_items.erase(itemIter);
        return true;
    }
    return false;
}

// private -------------------------------------------------

void Inventory::clearItems()
{
    for (auto i : m_items)
    {
        delete i;
    }
    m_items.clear();
}
