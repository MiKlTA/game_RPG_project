#ifndef ITEM_FOOD_H
#define ITEM_FOOD_H

#include <string>

#include "basicitem.h"



struct ItemFoodInfo
{
    unsigned int curative;
};

class ItemFood : public BasicItem
{
    
public:
    ItemFood() {};
    ItemFood(std::string name, std::string description, unsigned int weight,
              unsigned int curative);
    virtual ~ItemFood() {};
    
    const ItemFoodInfo & getItemFoodInfo() const;


/*    virtual const std::string getClassName() const override
    {return typeid(ItemFood).name();};*/
    
protected:
    ItemFoodInfo m_itemFoodInfo;
};

#endif // ITEM_FOOD_H
