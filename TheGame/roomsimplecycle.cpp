#include "allFunctions.h"

void roomSimpleCycle(RoomSimple *room, BasicHero *hero)
{
    while (true)
    {
        prepare();
        
        printSeparator();
        
        printWithDelay("||" + encloseInCharactersToCenter(
                           "You in room: " + room->getGameObjectInfo().name,
                           ' ', 2)
                       + "||");
        printWithDelay("||" + encloseInCharactersToCenter(
                           std::to_string(room->getID()), ' ', 2)
                       + "||");
        printWithDelayWithPauses(
                    "|| - " 
                    + room->getGameObjectInfo().description
                    + "$\n");
        
        printSeparator();
        
        printWithDelayWithPauses(
                    "|| Objects count: "
                    + std::to_string(room->getObjects().size())
                    + ",$\n");
        printWithDelayWithPauses(
                    "|| including untouched ones: "
                    + std::to_string(countUntouchedObjects(room->getObjects()))
                    + "$\n");
        printWithDelayWithPauses(
                    "|| Monsters count: "
                    + std::to_string(room->getMonsters().size())
                    + "$\n");
        printWithDelayWithPauses(
                    "|| including untouched ones: "
                    + std::to_string(countUntouchedMonsters(room->getMonsters()))
                    + "$\n");
        
        printSeparator();
        
        printBasicHero(hero);
        
        printSeparator();
        
        printWithDelay("|| Objects in this room:\n");
        printObjectsInRoomSimpleCycle(room);
        
        printSeparator();
        
        printWithDelay("|| Monsters in this room:\n");
        printMonstersInRoomSimpleCycle(room);
        
        printSeparator();
        
        for (unsigned int i = 0; i < room->getObjects().size(); ++i)
        {
            printCase(i, "View");
        }
        
        for (unsigned int i = 0; i < room->getMonsters().size(); ++i)
        {
            printCase(i + room->getObjects().size(), "Attack");
        }
        
        unsigned int gotoinventoryIndex
                = room->getObjects().size() + room->getMonsters().size();
        printCase(gotoinventoryIndex, "Go to inventory");
        printCase(room->getObjects().size() + room->getMonsters().size() + 1,
                  room->getMonsters().empty() ?
                      "Back" : "Back (not all monsters are killed yet)");
        
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
        if (choosedIndex > gotoinventoryIndex + 1)
        {
            goto beginInput;
        }
        
        if (choosedIndex < gotoinventoryIndex)
        {
            if (choosedIndex < room->getObjects().size()) // means - choosed object
            {
                auto choosedObjectIter = room->getObjects().begin()
                        + choosedIndex;
                objectLootCycle(hero, *choosedObjectIter);
            }
            else // means - choosed object
            {
                auto choosedMonsterIter = room->getMonsters().begin()
                        + choosedIndex - room->getObjects().size();
                Game::FightResult fightResult;
                fightCycle(hero, *choosedMonsterIter, fightResult);
                (*choosedMonsterIter)->view();
                if (fightResult == Game::FightResult::PLAYER_WIN)
                {
                    room->removeMonster((*choosedMonsterIter)->getID());
                }
                else if (fightResult == Game::FightResult::PLAYER_LOSE)
                {
                    exit(0);
                }
            }

        }
        else if (choosedIndex == gotoinventoryIndex)
        {
            inventoryCycle(hero);
        }
        else if (room->getMonsters().empty())
        // you can only go back when all the monsters are killed!
        {
           return;
        }
        
        prepare();
    }
}

void printObjectsInRoomSimpleCycle(RoomSimple *room)
{
    for (unsigned int i = 0; i < room->getObjects().size(); ++i)
    {
        auto cur = room->getObjects()[i];
        
        printWithDelayWithPauses(
                    "|| "
                    + std::to_string(i)
                    + " -=- "
                    + cur->getGameObjectInfo().name
                    + "\t\t| "
                    + (cur->getBasicObjectInfo().wasExamined ? "( )" : "(?)")
                    + " |$\n");
    }
}

void printMonstersInRoomSimpleCycle(RoomSimple *room)
{
    for (unsigned int i = 0; i < room->getMonsters().size(); ++i)
    {
        auto cur = room->getMonsters()[i];
        
        if (cur->wasViewed())
        {
            printWithDelayWithPauses(
                        "|| "
                        + std::to_string(i)
                        + " -=- "
                        + cur->getGameObjectInfo().name
                        + "\t\t| "
                        + std::to_string(cur->getBasicMonsterInfo().health)
                        + "/"
                        + std::to_string(cur->getBasicMonsterInfo().maxHealth)
                        + " |$\n");
        }
        else
        {
            printWithDelayWithPauses(
                        "|| "
                        + std::to_string(i)
                        + " -=- Unknown\t\t| ?/? |$\n");
        }
    }
}
