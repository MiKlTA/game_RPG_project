#include "allFunctions.h"

void fightCycle(BasicHero *hero, BasicMonster *monster,
                Game::FightResult &fightResult)
{
    while (true)
    {
        prepare();
        
        printSeparator();
        
        if (!monster->wasViewed())
        {
            Game::g_delay = 20;
            Game::g_timePause = 600;
        }
        else
        {
            Game::g_timePause = 0;
        }
        printWithDelayWithPauses(
                    "||" + encloseInCharactersToCenterWithDelay(
                        "On the stage goes$.$.$.$ "
                        + monster->getGameObjectInfo().name
                        + ",", ' ', 2)
                    + "||$$");
        resetTimePause();
        resetDelay();
        
        printSeparator();
        
        printWithDelayWithPauses(
                    "|| - " 
                    + monster->getGameObjectInfo().description
                    + "$\n");
        
        printBasicMonster(monster);
        
        printSeparator();
        
        if (!monster->wasViewed())
        {
            Game::g_delay = 20;
            Game::g_timePause = 750;
        }
        else
        {
            Game::g_timePause = 0;
        }
        printWithDelayWithPauses(
                    "||" + encloseInCharactersToCenterWithDelay(
                        "... and you!$", ' ', 2)
                    + "||");
        resetTimePause();
        resetDelay();
        
        printSeparator();
        
        printBasicHero(hero);
        
        printSeparator();
        
        unsigned int plDamage = hero->getBasicHeroInfo().unarmedDamage;
        if (hero->getInventory().getCurrentWeapon() != nullptr)
        {
            plDamage += hero->getInventory().getCurrentWeapon()
                    ->getItemWeaponInfo().damage;
        }
        printCase(0, "Attack (" + std::to_string(plDamage) + ")");
        
        const unsigned char escapeChance
                = (hero->getBasicHeroInfo().dexterity
                * (UCHAR_MAX - monster->getBasicMonsterInfo().dexterity))
                / (UCHAR_MAX + 1);
        printCase(1,
                  "Try to escape ("
                  + std::to_string(
                      static_cast<int>(
                          std::round(SpecialFraction::makeFloatFromUChar(
                                         escapeChance)
                                     * 100.f)
                          )
                      )
                  + "%)");
        
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
        if (choosedIndex > 1)
        {
            goto beginInput;
        }
        
        if (choosedIndex == 0)
        {
            if (monster->hit(plDamage))
            {
                processPlayerWin(hero, monster);
                fightResult = Game::FightResult::PLAYER_WIN;
                return;
            }
            else
            {
                if (hero->hit(monster->getBasicMonsterInfo().damage))
                {
                    fightResult = Game::FightResult::PLAYER_LOSE;
                    printLoseMessage(monster);
                    return;
                }
            }
        }
        else if (choosedIndex == 1)
        {
            if (randomize(escapeChance * 10))
            { // success
                fightResult = Game::FightResult::PLAYER_ESCAPE;
                printFightMessage("You were saved by a miracle! You escaped!");
                return;
            }
            else
            { // unsuccess
                if (hero->hit(monster->getBasicMonsterInfo().damage))
                {
                    fightResult = Game::FightResult::PLAYER_LOSE;
                    printLoseMessage(monster);
                    return;
                }
            }
        }
        
        prepare();
    }
}

void printFightMessage(std::string message)
{
    prepare();
    
    printSeparator();
    
    printWithDelayWithPauses("|| " + message + "$\n");
    
    printSeparator();
    
    printCase(0, "Back");
    
    printSeparator();
    printInputPrecede();
    inputCase();
    
    prepare();
}

void printLoseMessage(BasicMonster *monster)
{
    printFightMessage("You have fallen in an unequal struggle with "
                      + monster->getGameObjectInfo().name);
}

void processPlayerWin(BasicHero *hero, BasicMonster *monster)
{
    hero->addLevel(monster->getBasicMonsterInfo().exp);
    printFightMessage("You've won this useless piece of hardware!");
}
