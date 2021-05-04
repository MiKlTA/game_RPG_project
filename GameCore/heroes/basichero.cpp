#include "basichero.h"

BasicHero::BasicHero(std::string name, std::string description,
                     unsigned int maxHealth, unsigned int maxCapacity,
                     unsigned int unarmedDamage, SpecialFraction dexterity,
                     SpecialFraction levelMultipler,
                     unsigned int inventorySize)
    : GameObject(name, description),
      m_basicHeroInfo{maxHealth, maxHealth, maxCapacity, maxCapacity, unarmedDamage,
                      dexterity.getChar(), levelMultipler.getChar(), 0, 0},
      m_inventory(inventorySize)
{
    
}

BasicHero::~BasicHero()
{
    deleteDefaultItems();
}

const BasicHeroInfo & BasicHero::getBasicHeroInfo() const
{
    return m_basicHeroInfo;
}


const Inventory & BasicHero::getInventory() const
{
    return m_inventory;
}

void BasicHero::setFullHealth()
{
    m_basicHeroInfo.health = m_basicHeroInfo.maxHealth;
}

bool BasicHero::hit(unsigned int damage)
{
    if (m_basicHeroInfo.health > 0)
    {
        if (m_basicHeroInfo.health > damage)
        {
            m_basicHeroInfo.health -= damage;
            return false;
        }
        else
        {
            m_basicHeroInfo.health = 0;
            // return false; no need
        }
    }
    return true;
}

bool BasicHero::giveItem(BasicItem *itemPtr)
{
    unsigned int weight = itemPtr->getBasicItemInfo().weight;
    
    if (m_basicHeroInfo.capacity >= weight)
    {
        m_basicHeroInfo.capacity -= weight;
        m_inventory.addItem(itemPtr);
        return true;
    }
    return false;
}

bool BasicHero::takeItem(ID_t itemID)
{
    auto itemIter = findByID(m_inventory.getItems(), itemID);
    
    unsigned int weight = (*itemIter)->getBasicItemInfo().weight;
    
    if (m_basicHeroInfo.capacity + weight <= m_basicHeroInfo.maxCapacity)
    {
        m_basicHeroInfo.capacity += weight;
        unsigned long long ID = (*itemIter)->getID();
        m_inventory.removeItem(ID);
        return true;
    }
    return false;
}

double BasicHero::getLevelStep()
{
    return SpecialFraction::makeFloatFromUChar(m_basicHeroInfo.levelMultipler)
            * (500 * std::sqrt(m_basicHeroInfo.level + 1) - 400);
}

void BasicHero::addLevel(unsigned int level)
{
    const double rim = getLevelStep();
    
    if (m_basicHeroInfo.levelProgress + level >= rim)
    {
        unsigned int oldLevel = m_basicHeroInfo.levelProgress;
        m_basicHeroInfo.levelProgress = 0;
        m_basicHeroInfo.level++;
        addLevel(oldLevel + level - rim);
    }
    else
    {
        m_basicHeroInfo.levelProgress += level;
    }
}

bool BasicHero::equip(ID_t itemID)
{
    return m_inventory.equip(itemID);
}

void BasicHero::unequip()
{
    m_inventory.unequip();
}

bool BasicHero::eatFoodFromInventory(ID_t foodID)
{
    unsigned int curative;
    bool success = m_inventory.eatFood(foodID, curative);
    
    if (success)
    {
        if (m_basicHeroInfo.health + curative <= m_basicHeroInfo.maxHealth)
        {
            m_basicHeroInfo.health += curative;
        }
        else
        {
            setFullHealth();
        }
        return true;
    }
    return false;
}


// private ---------------------------------------------------------------

void BasicHero::deleteDefaultItems()
{
    for (auto i : m_defaultItems)
    {
        delete i;
    }
    m_defaultItems.clear();
}
