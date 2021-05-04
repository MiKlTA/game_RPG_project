#ifndef FUNCTIONSWITHITEMS_H
#define FUNCTIONSWITHITEMS_H

#include <fstream>

#include "functions.h"

#include "items/basicitem.h"
#include "items/itemfood.h"
#include "items/itemweapon.h"
#include "monsters/basicmonster.h"
#include "objects/basicobject.h"



BasicItem * loadItem(std::ifstream &ifs);
void saveItem(std::ofstream &ofs, const BasicItem *bi);



#endif // FUNCTIONSWITHITEMS_H
