#include "allFunctions.h"

void print(std::string str)
{
    std::cout << str;
}

void println(std::string str)
{
    print(str);
    std::cout << std::endl;
}

void printSymbWithDelay(char symb)
{
    if (Game::g_enableDelay && symb != ' ')
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(Game::g_delay));
    }
    std::cout << symb;
}

void printWithDelay(std::string str)
{
    for (char i : str)
    {
        printSymbWithDelay(i);
    }
}

void printWithDelayWithPauses(std::string str, char pauseSymb)
{
    for (char i : str)
    {
        if (i != pauseSymb)
        {
            printSymbWithDelay(i);
        }
        else
        {
            if (Game::g_enableDelay)
            {
                std::this_thread::sleep_for(
                            std::chrono::milliseconds(Game::g_timePause)
                            );
            }
        }
    }
}

void printWithDelayWithPauses(std::string str)
{
    printWithDelayWithPauses(str, Game::g_DelaySymbol);
}

void clearConsole()
{
    system("cls");
}

void printSeparator()
{
    unsigned int oldDelay = Game::g_delay;
    Game::g_delay = Game::g_DelayOfSeparator;
    
    printWithDelay("<|=" + repeatSymbol('-', 74) + "=|>");
    
    Game::g_delay = oldDelay;
}

void printCase(unsigned int num, std::string info)
{
    printWithDelayWithPauses(
                "(( " + std::to_string(num) + "\t-\t" + info
                + Game::g_DelaySymbol + "\n"
                );
}

void printInputPrecede()
{
    printWithDelay(">> ");
}

void printErrorUnknownCharacter()
{
    printWithDelay(Game::g_ErrorOfUnknownCharacter);
}

void printErrorUnknownItem()
{
    printWithDelay(Game::g_ErrorOfUnknownItem);
}

void printGameObject(GameObject *object)
{
    printWithDelayWithPauses("|| "
                             + object->getGameObjectInfo().name
                             + Game::g_DelaySymbol + "\n"
                             );
    printWithDelayWithPauses("|| Id: "
                             + std::to_string(object->getID())
                             + Game::g_DelaySymbol + "\n"
                             );
    printWithDelayWithPauses("|| "
                             + object->getGameObjectInfo().description
                             + Game::g_DelaySymbol + "\n"
                             );
}

void printBasicItem(BasicItem *item)
{
    printGameObject(item);
    printWithDelayWithPauses("|| Weight: "
                             + std::to_string(
                                 item->getBasicItemInfo().weight
                                 )
                             + Game::g_DelaySymbol + "\n"
                             );
}

void printItemFood(ItemFood *food)
{
    printBasicItem(food);
    printWithDelayWithPauses("|| Curative: "
                             + std::to_string(
                                 food->getItemFoodInfo().curative
                                 )
                             + Game::g_DelaySymbol + "\n"
                             );
}

void printItemWeapon(ItemWeapon *weapon)
{
    printBasicItem(weapon);
    printWithDelayWithPauses("|| Damage: "
                             + std::to_string(
                                 weapon->getItemWeaponInfo().damage
                                 )
                             + Game::g_DelaySymbol + "\n"
                             );
    printWithDelayWithPauses("|| Maximum durability: "
                             + std::to_string(
                                 weapon->getItemWeaponInfo().maxDurability
                                 )
                             + Game::g_DelaySymbol + "\n"
                             );
    printWithDelayWithPauses("|| Current durability: "
                             + std::to_string(
                                 weapon->getItemWeaponInfo().durability
                                 )
                             + Game::g_DelaySymbol + "\n"
                             );
}

void printBasicMonster(BasicMonster *monster)
{
    printGameObject(monster);
    
    printWithDelayWithPauses("|| Health: "
                             + std::to_string(
                                 monster->getBasicMonsterInfo().health)
                             + "/"
                             + std::to_string(
                                 monster->getBasicMonsterInfo().maxHealth)
                             + Game::g_DelaySymbol + "\n"
                             );
    
    printWithDelayWithPauses("|| Damage: "
                             + std::to_string(
                                 monster->getBasicMonsterInfo().damage)
                             + Game::g_DelaySymbol + "\n"
                             );
    
    printWithDelayWithPauses("|| Dexterity: "
                             + std::to_string(
                                 monster->getBasicMonsterInfo().dexterity)
                             + Game::g_DelaySymbol + "\n"
                             );
    
    printWithDelayWithPauses("|| Experience: "
                             + std::to_string(
                                 monster->getBasicMonsterInfo().exp)
                             + Game::g_DelaySymbol + "\n"
                             );

}

void printBasicHero(BasicHero *hero)
{
    printWithDelayWithPauses("|| "
                             + hero->getGameObjectInfo().name
                             + Game::g_DelaySymbol + "\n"
                             );
    printWithDelayWithPauses("|| Health: "
                             + std::to_string(hero->getBasicHeroInfo().health)
                             + "/"
                             + std::to_string(
                                 hero->getBasicHeroInfo().maxHealth)
                             + Game::g_DelaySymbol + "\n"
                             );
    printWithDelayWithPauses("|| Capacity: "
                             + std::to_string(
                                 hero->getBasicHeroInfo().maxCapacity
                                 - hero->getBasicHeroInfo().capacity)
                             + "/"
                             + std::to_string(
                                 hero->getBasicHeroInfo().maxCapacity)
                             + Game::g_DelaySymbol + "\n"
                             );
    unsigned int damage = hero->getBasicHeroInfo().unarmedDamage;
    printWithDelayWithPauses("|| Unarmed damage: "
                             + std::to_string(damage)
                             + Game::g_DelaySymbol + "\n"
                             );
    if (hero->getInventory().getCurrentWeapon() != nullptr)
    {
        damage += hero->getInventory().getCurrentWeapon()->getItemWeaponInfo()
                .damage;
    }
    printWithDelayWithPauses("|| Current damage: "
                             + std::to_string(damage)
                             + Game::g_DelaySymbol + "\n"
                             );
    double dexterityAsPercentage = SpecialFraction::makeDoubleFromUChar(
                hero->getBasicHeroInfo().dexterity) * 100.0;
    printWithDelayWithPauses("|| Dexterity: "
                             + std::to_string(dexterityAsPercentage) + "%"
                             + Game::g_DelaySymbol + "\n"
                             );
    printWithDelayWithPauses("|| Level: "
                             + std::to_string(hero->getBasicHeroInfo().level)
                             + Game::g_DelaySymbol + "\n"
                             );
    
    printSeparator();
    
    // always less than 1.0 because
    // hero->addLevel does not allow this
    double linearInterp = hero->getBasicHeroInfo().levelProgress
            / hero->getLevelStep();
    // again, 76 because the console width is 80 characters
    unsigned int firstSymbolCount = 76.0 * linearInterp; // from 0 to less 76
    print("||"
          + repeatSymbol('#', firstSymbolCount)
          + repeatSymbol('_', 76 - firstSymbolCount)
          + "||");
}

void printBasicObject(BasicObject *object)
{
    printGameObject(object);
    
    printWithDelayWithPauses("|| Received level: "
                             + std::to_string(
                                 object->getBasicObjectInfo().levelAdd)
                             + Game::g_DelaySymbol + "\n"
                             );
    printWithDelayWithPauses("|| Was examined: "
                             + std::string(
                                 object->getBasicObjectInfo().wasExamined ?
                                     "yes" : "no")
                             + Game::g_DelaySymbol + "\n"
                             );
    
    printSeparator();
    
    if (!object->getLootItems().empty())
    {
        printWithDelayWithPauses(std::string() + "|| Possible loot: "
                                 + Game::g_DelaySymbol + "\n");
        for (auto i : object->getLootItems())
        {
            printWithDelayWithPauses(
                        "|| " 
                         + i.first->getGameObjectInfo().name
                         + "\t\t| Chanse: "
                         + std::to_string(
                             SpecialFraction::makeFloatFromUChar(i.second) * 100
                             ) + "%"
                        + Game::g_DelaySymbol + "\n"
                        );
        }
    }
    else
    {
        printWithDelayWithPauses(std::string()
                                 + "|| You can't find anything here"
                                 + Game::g_DelaySymbol + "\n");
    }
}



char inputCase()
{
    std::string inValue;
    std::cin >> inValue;
    if (!inValue.empty())
    {
        return inValue.at(0);
    }
    else
    {
        return 0;
    }
}
