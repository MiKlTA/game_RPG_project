#ifndef ALLFUNCTIONS_H
#define ALLFUNCTIONS_H

#include <string>
#include <iostream>
// only for std::this_thread::sleep_for
#include <thread>
#include <chrono>



#include "../GameCore/rooms/roomsimple.h"
#include "../GameCore/roommanager.h"



// global constants and flags ----------------------------------------------

namespace Game 
{

const bool g_DefaultEnableDelay = false;

const std::string g_ErrorOfUnknownCharacter 
= "(!!) Unknown character encountered\n";

const std::string g_ErrorOfUnknownItem
= "(!!) Unknown item encountered\n";

const unsigned int g_DefaultDelay = 0;
const unsigned int g_DelayOfSeparator = 0;
const unsigned int g_DefaultTimePause = 50;

const char g_DelaySymbol = '$';

}

// enums -------------------------------------------------------------------

namespace Game
{

enum FightResult
{
    PLAYER_WIN      =   0,
    PLAYER_LOSE     =   1,
    PLAYER_ESCAPE   =   2
};

}

// global vars -------------------------------------------------------------

namespace Game 
{

extern bool g_enableDelay;

extern unsigned int g_delay;
extern unsigned int g_timePause;

}


// input\output functions.cpp-------------------------------------------------

void print(std::string str);

void println(std::string str);

void printSymbWithDelay(char symb);
void printWithDelay(std::string str);

void printWithDelayWithPauses(std::string str, char pauseSymb);
void printWithDelayWithPauses(std::string str);

void clearConsole();

void printSeparator();

void printCase(unsigned int num, std::string info);

void printInputPrecede();
void printInputPrecede();

void printErrorUnknownCharacter();
void printErrorUnknownItem();

void printGameObject(GameObject *object);

void printBasicItem(BasicItem *item);

void printBasicMonster(BasicMonster *monster);

void printBasicHero(BasicHero *hero);

void printBasicObject(BasicObject *object);

char inputCase();

// other functions -----------------------------------------

void resetDelay();
void resetTimePause();

void prepare();

std::string repeatSymbol(char symb, unsigned int count);

std::string encloseInCharacters(std::string str,
                                char symbL, unsigned int countL,
                                char symbR, unsigned int countR);
std::string encloseInCharacters(std::string str, char symb,
                                unsigned int countL, unsigned int countR);
std::string encloseInCharacters(std::string str,
                                char symb, unsigned int count);

std::string encloseInCharactersToCenter(std::string str,
                                        char symb, unsigned int indent);

std::string encloseInCharactersToCenterWithDelay(
        std::string str, char symb, unsigned int indent);

unsigned int countUntouchedObjects(
        const RoomSimple::ObjectContainer_t &objects);

unsigned int countUntouchedMonsters(
        const RoomSimple::MonsterContainer_t &monsters);

// ---------------------------------------------------------

void introduction();

void mainMenu();

void initRooms(RoomManager &roomManager);

void chooseRoom(RoomManager &roomManager,
                ID_t startRoomID,
                BasicHero *hero);
void processRoom(BasicRoom *room, BasicHero *hero);

void roomSimpleCycle(RoomSimple *room, BasicHero *hero);
void printObjectsInRoomSimpleCycle(RoomSimple *room);
void printMonstersInRoomSimpleCycle(RoomSimple *room);

void inventoryCycle(BasicHero *hero);
void printItemsInInventoryCycle(const Inventory &inventory);

void itemView(BasicHero *hero, BasicItem *item);
void nonSelfHarmFunction();

void objectLootCycle(BasicHero *hero, BasicObject *object);
void whatWeGotAfterObjectLoot(const BasicObject::ContainerItems_t &loot,
                              const BasicObject::ContainerItems_t &deletedLoot,
                              BasicObject *object);

void fightCycle(BasicHero *hero, BasicMonster *monster,
                Game::FightResult &fightResult);
void printFightMessage(std::string message);
void printLoseMessage(BasicMonster *monster);
void processPlayerWin(BasicHero *hero, BasicMonster *monster);

#endif // ALLFUNCTIONS_H
