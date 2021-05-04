#include "allFunctions.h"

void objectLootCycle(BasicHero *hero, BasicObject *object)
{
    prepare();
    
    printSeparator();
    
    printBasicObject(object);
    
    printSeparator();
    
    if (!object->getBasicObjectInfo().wasExamined)
    {
        printCase(0, "Loot");
        printCase(1, "Back");
        
        printSeparator();
        
        beginSwitch:
        printInputPrecede();
        switch (inputCase())
        {
        case '0':
        {
            BasicObject::ContainerItems_t items, deletedItems;
            object->examine(items);
            bool itemWasSuccessfullyPush = true;
            for (auto i : items)
            {
                if (itemWasSuccessfullyPush)
                {
                    itemWasSuccessfullyPush = hero->giveItem(i);
                }
                else
                {
                    deletedItems.push_back(i);
                }
            }
            hero->addLevel(object->getBasicObjectInfo().levelAdd);
            
            whatWeGotAfterObjectLoot(items, deletedItems, object);
            break;
        }
        case '1':
            prepare();
            return;
        default:
            printErrorUnknownCharacter();
            goto beginSwitch;
            break;
        }
    }
    else
    {
        printCase(0, "Back");
        
        printSeparator();
        
        printInputPrecede();
        inputCase();
    }
    
    prepare();
}


void whatWeGotAfterObjectLoot(const BasicObject::ContainerItems_t &loot,
                              const BasicObject::ContainerItems_t &deletedLoot,
                              BasicObject *object)
{
    prepare();
    
    printSeparator();
    
    if (!loot.empty())
    {
        printWithDelayWithPauses(
                    "|| In "
                    + object->getGameObjectInfo().name
                    + " you found:$\n");
        for (auto i : loot)
        {
            printWithDelayWithPauses(
                        "|| "
                        + i->getGameObjectInfo().name
                        + "$\n");
        }
    }
    else
    {
        printWithDelayWithPauses("|| You didn't find anything :($\n");
    }
    
    printSeparator();
    
    if (!deletedLoot.empty())
    {
        printWithDelayWithPauses(
                    "|| Due to insufficient storage capacity of the inventory,"
                    "you lost:$\n");
        for (auto i : deletedLoot)
        {
            printWithDelayWithPauses(
                        "|| "
                        + i->getGameObjectInfo().name
                        + "$\n");
        }
        
        printSeparator();
    }
    
    printCase(0, "Ok");
    
    printSeparator();
    
    printInputPrecede();
    inputCase();
    
    prepare();
}
