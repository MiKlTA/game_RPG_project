#include "itemfood.h"

ItemFood::ItemFood(std::string name, std::string description,
                     unsigned int weight, unsigned int curative)
    : BasicItem(name, description, weight),
      m_itemFoodInfo{curative}
{
    
}

const ItemFoodInfo & ItemFood::getItemFoodInfo() const
{
    return m_itemFoodInfo;
}
