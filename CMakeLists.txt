cmake_minimum_required(VERSION 3.5)

project(project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(project
    TheGame/main.cpp
    TheGame/allfunctions.h
    TheGame/other.cpp
    TheGame/iofunctions.cpp
    TheGame/introduction.cpp
    TheGame/mainmenu.cpp
    TheGame/initialozationrooms.cpp
    TheGame/chooseroom.cpp
    TheGame/roomsimplecycle.cpp
    TheGame/inventorycycle.cpp
    TheGame/itemview.cpp
    TheGame/objectlootcycle.cpp
    TheGame/fightcycle.cpp
    GameCore/gameobject.h
    GameCore/gameobject.cpp
    GameCore/functions.h
    GameCore/functions.cpp
    GameCore/functionsWithItems.h
    GameCore/functionsWithItems.cpp
#    GameCore/functionsWithHero.h
#    GameCore/functionsWithHero.cpp
    GameCore/specialfraction.h
    GameCore/specialfraction.cpp
    GameCore/items/basicItem.h
    GameCore/items/basicItem.cpp
    GameCore/items/itemfood.h
    GameCore/items/itemfood.cpp
    GameCore/items/itemweapon.h
    GameCore/items/itemweapon.cpp
    GameCore/rooms/basicroom.h
    GameCore/rooms/basicroom.cpp
    GameCore/rooms/roomsimple.h
    GameCore/rooms/roomsimple.cpp
    GameCore/monsters/simplemonster.h
    GameCore/monsters/simplemonster.cpp
    GameCore/monsters/basicmonster.h
    GameCore/monsters/basicmonster.cpp
    GameCore/heroes/basichero.h
    GameCore/heroes/basichero.cpp
    GameCore/heroes/simplehero.h
    GameCore/heroes/simplehero.cpp
    GameCore/objects/basicobject.h
    GameCore/objects/basicobject.cpp
    GameCore/objects/simpleobject.h
    GameCore/objects/simpleobject.cpp
    GameCore/inventory.h
    GameCore/inventory.cpp
    GameCore/roommanager.h
    GameCore/roommanager.cpp
    GameCore/classwithid.h
    GameCore/classwithid.cpp
    )
