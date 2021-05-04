#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <typeinfo>
#include <algorithm>
#include <vector>

#include "items/basicitem.h"
#include "items/itemweapon.h"
#include "items/itemfood.h"
#include "functionsWithItems.h"



class Inventory
{
    
public:
    using containerItem_t = std::vector<BasicItem *>;
    
    
    
    Inventory();
    Inventory(unsigned int size);
    ~Inventory();
    
    const containerItem_t & getItems() const;
    const ItemWeapon * getCurrentWeapon() const;

    unsigned int getMaxSize() const;
    
    // returns true if action was successfully done
    bool addItem(BasicItem *item);
    bool removeItem(ID_t itemID);
    
    // returns true if weapon successfully found and equiped
    bool equip(ID_t itemID);
    void unequip();

    
    // returns true if food successfully found and ate
    bool eatFood(ID_t itemID, unsigned int &curative);

    
private:
    unsigned int m_size;
    containerItem_t m_items;
    ItemWeapon *m_curWeapon;
    
    void clearItems();
};

#endif // INVENTORY_H
