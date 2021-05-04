#include "functionsWithItems.h"


/*
BasicItem * loadItem(std::ifstream &ifs)
{
    BasicItem *result = nullptr;
    
    std::string name;
    ifs >> name;
    if (name == typeid(ItemFood).name())
    {
        result = new ItemFood;
        dynamic_cast<ItemFood *>(result)->load(ifs);
    }
    else if (name == typeid(ItemWeapon).name())
    {
        result = new ItemWeapon;
        dynamic_cast<ItemWeapon *>(result)->load(ifs);
    }
    
    return result;
}

void saveItem(std::ofstream &ofs, const BasicItem *bi)
{
    ofs << bi->getClassName() << "\n";
    
    bi->save(ofs);
}
*/
