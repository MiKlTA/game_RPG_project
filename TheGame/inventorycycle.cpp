#include "allFunctions.h"

void inventoryCycle(BasicHero *hero)
{
    while (true)
    {
        prepare();
        
        printSeparator();
        
        printWithDelay("||" + encloseInCharactersToCenter(
                           "Your inventory", ' ', 2
                           )
                       + "||");
        
        printSeparator();
        
        printWithDelayWithPauses(
                    "|| Place in the inventory:\t"
                    + std::to_string(hero->getInventory().getItems().size())
                    + "/"
                    + std::to_string(hero->getInventory().getMaxSize())
                    + "$\n");
        
        printSeparator();
        
        printBasicHero(hero);
        
        printSeparator();
        
        printWithDelayWithPauses(
                    "|| Your health:\t"
                    + std::to_string(hero->getBasicHeroInfo().health)
                    + "/"
                    + std::to_string(hero->getBasicHeroInfo().maxHealth)
                    + "$\n");
        
        printSeparator();
        
        printItemsInInventoryCycle(hero->getInventory());
        
        printCase(hero->getInventory().getItems().size(), "Back");
        
        printSeparator();
        
        unsigned int choosedIndex;
        beginInput:
        printInputPrecede();
        std::string input;
        std::cin >> input;
        try
        {
            choosedIndex = std::stoi(input);
        }
        catch (...)
        {
            goto beginInput;
        }
        if (choosedIndex > hero->getInventory().getItems().size())
        {
            goto beginInput;
        }
        
        if (choosedIndex != hero->getInventory().getItems().size())
        {
            auto choosedItemIter = hero->getInventory().getItems().begin()
                    + choosedIndex;
            itemView(hero, *choosedItemIter);
        }
        else // else - back
        {
            return;
        }
        
        prepare();
    }
}

void printItemsInInventoryCycle(const Inventory &inventory)
{

    for (unsigned int i = 0; i < inventory.getItems().size(); ++i)
    {
        auto cur = inventory.getItems()[i];

        std::string itemType;
        if (cur->getClassName() == typeid(ItemFood).name())
        {
            itemType = "F";
        }
        else if (cur->getClassName() == typeid(ItemWeapon).name())
        {
            itemType = "W";
            if (inventory.getCurrentWeapon() != nullptr)
                if (inventory.getCurrentWeapon()->getID()
                        == cur->getID())
                {
                    itemType += "*";
                }
        }
        else
        {
            itemType = "#";
        }
        
        printWithDelayWithPauses("|| "
                                 + std::to_string(i)
                                 + " --->\t"
                                 + cur->getGameObjectInfo().name
                                 + "\t\t|\t"
                                 + std::to_string(
                                     cur->getBasicItemInfo().weight
                                     )
                                 + "\t|\t"
                                 + itemType
                                 +"\t|$\n");
    }
    
    printSeparator();
    
    for (unsigned int i = 0; i < inventory.getItems().size(); ++i)
    {
        printCase(i, "View");
    }
}
