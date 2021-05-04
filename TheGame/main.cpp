#include <iostream>
#include <fstream>

//#include "../GameCore/items/itemfood.h"
//#include "../GameCore/items/itemweapon.h"
//#include "../GameCore/heroes/basichero.h"

//#include "../GameCore/functionsWithHero.h"

#include "allFunctions.h"
#include "../GameCore/objects/simpleobject.h"
#include "../GameCore/monsters/simplemonster.h"
#include "../GameCore/heroes/simplehero.h"


int main()
{   
    srand(time(0));
    
    std::ofstream ofs;
//    std::ifstream ifs;
    
    
    /*ItemFood sweets({"Sweets", "This is a simple sweets", 3, 3});
    ofs.open("sweets.food");
    sweets.save(ofs);
    ofs.close();
    
    ItemWeapon cocktailStraw({"Straw", "A cocktail straw picked up from the road",
                               1, 1, 3, 3}),
                knife({"Knife", "Your friend", 5, 5, 150, 150});
    
    ofs.open("cocktailStraw.weapon");
    cocktailStraw.save(ofs);
    ofs.close();
    
    ofs.open("knife.weapon");
    knife.save(ofs);
    ofs.close();
    
    BasicHero bh({"Player", "Simple player", 100, 100, 50, 50, 2,
                   SpecialFraction(4), SpecialFraction(2)});
    bh.addDefaultItem(std::shared_ptr<ItemWeapon>(
                          new ItemWeapon(cocktailStraw)));
    bh.addDefaultItem(std::shared_ptr<ItemWeapon>(
                          new ItemWeapon(knife)));
    ofs.open("basicPlayer.player");
    bh.save(ofs);
    ofs.close();*/
    
    
    
    /*ItemFood sweets;
    ifs.open("sweets.food");
    sweets.load(ifs);
    ifs.close();
    
    ItemWeapon cocktailStraw, knife;
    ifs.open("cocktailStraw.weapon");
    cocktailStraw.load(ifs);
    ifs.close();
    ifs.open("knife.weapon");
    knife.load(ifs);
    ifs.close();
   
    BasicHero bh;
    ifs.open("basicPlayer.player");
    bh.load(ifs);
    ifs.close();
    
    bh.giveItem(std::shared_ptr<ItemFood>(new ItemFood(sweets)));
    
    printItemFood(std::cout, sweets);
    std::cout << std::endl;
    printItemWeapon(std::cout, cocktailStraw);
    std::cout << std::endl;
    printItemWeapon(std::cout, knife);
    std::cout << std::endl;
    printHero(std::cout, bh);
    
    
    for (auto i : bh.getDefaultItems())
    {
        std::cout << i->getGameObjectInfo().name << std::endl;
    }*/
    
    ItemWeapon pen("Pen", "Pencil's best friend", 2, 3, 3, 3);
    ItemWeapon pencil("Pencil", "Pencil's best friend", 2, 2, 5, 5);
    ItemWeapon stapler("Stapler", "His story is too scary for this game",
                       5, 3, 10, 10);
    
    ItemFood sweets("Sweets", "Everyone's favorite candy with lemon flavor",
                    2, 5);
    ItemFood bar("Chocolate bar", "someone's snack", 10, 30);
    ItemFood apple("Apple", "Who hides apples in the table?", 15, 15);
    
    BasicObject *table = new SimpleObject("Table", "Simple table", 5);
    table->addLootItem(new ItemWeapon(pen), 100);
    table->addLootItem(new ItemWeapon(pencil), 80);
    table->addLootItem(new ItemWeapon(stapler), 64);
    
    BasicObject *chair
            = new SimpleObject("Chair", "Your favorite office chair", 0);

    
//    ofs.open("start_room.room");
//    simpleRoom.save(ofs);
    
    
    SimpleMonster *printer = new SimpleMonster(
                "Printer",
                "Will print your will on you",
                30,
                3,
                30,
                SpecialFraction(3));
    SimpleMonster *monitor = new SimpleMonster(
                "Monitor",
                "Showing you all the possible ways of your death",
                10,
                3,
                10,
                SpecialFraction(5));
    SimpleMonster *computerMouse = new SimpleMonster(
                "Computer mouse",
                "Warning! Afraid of computer cats",
                10,
                2,
                15,
                SpecialFraction(20));
    
    
    BasicHero * hero(new SimpleHero(
                                        "Alex",
                                        "Simple office worker",
                                        100,
                                        50,
                                        2,
                                        SpecialFraction(5),
                                        SpecialFraction(128),
                                        10)
                                    );
    ofs.open("simple_hero.hero");
    ofs.close();
    hero->giveItem(new ItemWeapon(pen));
    hero->giveItem(new ItemWeapon(stapler));
    hero->giveItem(new ItemFood(sweets));
    hero->giveItem(new ItemFood(apple));
    
    
    
    RoomSimple *simpleRoom = new RoomSimple("Start room", "It's your office");
    simpleRoom->addObject(table);
    simpleRoom->addObject(chair);
    simpleRoom->addMonster(monitor);
    
    RoomSimple *roomWithTable = new RoomSimple("Room with table",
                                               "Guess why it's called that");
    roomWithTable->addObject(table);
    
    RoomSimple *monsterRoom
            = new RoomSimple("Monstroom",
                             "A room where there are a lot of monsters");
    monsterRoom->addMonster(printer);
    monsterRoom->addMonster(monitor);
    monsterRoom->addMonster(computerMouse);
    monsterRoom->addMonster(printer);
    monsterRoom->addMonster(monitor);
    monsterRoom->addMonster(computerMouse);
    
    RoomSimple *objectsRoom
            = new RoomSimple("Objectoroom",
                             "A room where there are a lot of objects");
    
    objectsRoom->addObject(table);
    objectsRoom->addObject(chair);
    objectsRoom->addObject(table);
    objectsRoom->addObject(chair);
    objectsRoom->addObject(table);
    objectsRoom->addObject(table);
    
    
    
    RoomManager roomManager;
    
    roomManager.addRoom(simpleRoom);
    ID_t r1ID = (*std::prev(roomManager.getRooms().end()))->getID();
    
    roomManager.addRoom(roomWithTable);
    ID_t r2ID = (*std::prev(roomManager.getRooms().end()))->getID();
    
    roomManager.addRoom(monsterRoom);
    ID_t r3ID = (*std::prev(roomManager.getRooms().end()))->getID();
    
    roomManager.addRoom(objectsRoom);
    ID_t r4ID = (*std::prev(roomManager.getRooms().end()))->getID();
    
    roomManager.connectRoom(r1ID, r3ID);
    roomManager.connectRoom(r3ID, r2ID);
    roomManager.connectRoom(r3ID, r4ID);
    
    chooseRoom(roomManager, r1ID, hero);
    
    
    
    return 0;
}
