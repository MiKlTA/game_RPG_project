#ifndef BASIC_ITEM_H
#define BASIC_ITEM_H

#include "../gameobject.h"



struct BasicItemInfo
{
    unsigned int weight;
};

class BasicItem : public GameObject
{
    
public:
    BasicItem() {};
    BasicItem(std::string name, std::string description, unsigned int weight);
    virtual ~BasicItem() {};
    
    const BasicItemInfo & getBasicItemInfo() const;

    
protected:
    BasicItemInfo m_basicItemInfo;
};

#endif // BASIC_ITEM_H
