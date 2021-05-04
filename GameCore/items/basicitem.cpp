#include "basicitem.h"

BasicItem::BasicItem(std::string name, std::string description,
                       unsigned int weight)
    : GameObject(name, description),
      m_basicItemInfo{weight}
{
    
}

const BasicItemInfo & BasicItem::getBasicItemInfo() const
{
    return m_basicItemInfo;
}
