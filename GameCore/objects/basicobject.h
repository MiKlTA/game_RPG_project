#ifndef BASIC_OBJECT_H
#define BASIC_OBJECT_H

#include <typeinfo>
#include <vector>
#include <random>

#include "../specialfraction.h"
#include "../gameobject.h"
#include "../items/basicitem.h"
#include "../functionsWithItems.h"



struct BasicObjectInfo
{
    unsigned int    levelAdd;
    bool            wasExamined;
};

class BasicObject : public GameObject
{
    
public:
    // BasicItem item, unsigned char chance;
    using LootContainer_t = std::vector<std::pair<BasicItem *, unsigned char>>;
    // BasicItem item
    using ContainerItems_t = std::vector<BasicItem *>;
    
    
    
    BasicObject() {};
    BasicObject(std::string name, std::string description,
                unsigned int levelAdd);
    virtual ~BasicObject();
    
    void addLootItem(BasicItem *item, unsigned char chance);
    const LootContainer_t & getLootItems() const;
    
    const BasicObjectInfo & getBasicObjectInfo() const;

    void examine(ContainerItems_t &items);
    
protected:
    BasicObjectInfo m_basicObjectInfo;
    
    LootContainer_t m_loot;
    
private:
    void deleteLoot();
};

#endif // BASIC_OBJECT_H
