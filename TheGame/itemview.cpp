#include "allFunctions.h"

void itemView(BasicHero *hero, BasicItem *item)
{
    prepare();
    
    printSeparator();
    
/*
    std::string className = item->getClassName();
    if (className == typeid(ItemFood).name())
    {
        ItemFood *food = new ItemFood(*dynamic_cast<ItemFood *>(item));
        printItemFood(food);
        
        printSeparator();
        
        processFood(hero, food);
    }
    else if (className == typeid(ItemWeapon).name())
    {
        ItemWeapon *weapon = new ItemWeapon(*dynamic_cast<ItemWeapon *>(item));
        printItemWeapon(weapon);
        
        printSeparator();
        
        processWeapon(hero, weapon);
    }
    
    prepare();*/
}

void processFood(BasicHero *hero, ItemFood *food)
{
    printCase(0, "Eat");
    printCase(1, "Throw away");
    printCase(2, "Back");
    
    printSeparator();
    
    beginSwitch:
    printInputPrecede();
    switch (inputCase())
    {
    case '0':
        hero->eatFoodFromInventory(food->getID());
        break;
    case '1':
        hero->takeItem(food->getID());
        break;
    case '2':
        return;
    default:
        printErrorUnknownCharacter();
        goto beginSwitch;
    }
}

void processWeapon(BasicHero *hero, ItemWeapon *weapon)
{
    printCase(0, "Hit yourself");
    bool isEquipped = false;
    if (ptrIsValid(hero->getInventory().getCurrentWeapon()))
    {
        isEquipped = hero->getInventory().getCurrentWeapon()->getID()
                == weapon->getID();
    }
    
    if (isEquipped)
    {
        printCase(1, "Remove from equipment");
    }
    else
    {
        printCase(1, "Equip");
    }
    printCase(2, "Throw away");
    printCase(3, "Back");
    
    printSeparator();
    
    beginSwitch:
    printInputPrecede();
    switch (inputCase())
    {
    case '0':
        nonSelfHarmFunction();
        break;
    case '1':
        if (isEquipped)
        {
            hero->unequip();
        }
        else
        {
            hero->equip(weapon->getID());
        }
        break;
    case '2':
        if (isEquipped)
        {
            hero->unequip();
        }
        hero->takeItem(weapon->getID());
        break;
    case '3':
        return;
    default:
        printErrorUnknownCharacter();
        goto beginSwitch;
    }
}

void nonSelfHarmFunction()
{
    prepare();
    
    printSeparator();
    
    printWithDelayWithPauses("|| Selfharm is not an option$!$!$!\n");
    
    printSeparator();
    
    printCase(0, "Back");
    
    printSeparator();
    printInputPrecede();
    inputCase();
    
    prepare();
}
