#include "allFunctions.h"

void chooseRoom(RoomManager &roomManager, ID_t startRoomID, BasicHero *hero)
{
    auto currentRoomIter = findByID(roomManager.getRooms(), startRoomID);
    
    if (currentRoomIter == roomManager.getRooms().end())
    {
        return;
    }
    
    BasicRoom *curRoom = *currentRoomIter;
    curRoom->view();
    
    while (true)
    {
        prepare();
        
        printSeparator();
        
        printWithDelay("||" + encloseInCharactersToCenter(
                           "You in room: " + curRoom->getGameObjectInfo().name,
                           ' ', 2)
                       + "||");
        printWithDelay("||" + encloseInCharactersToCenter(
                           std::to_string(curRoom->getID()), ' ', 2)
                       + "||");
        
        printSeparator();
        
        printWithDelay("||" + encloseInCharactersToCenter(
                           "Rooms near you", ' ', 2
                           )
                       + "||");
        
        printSeparator();
        
        for (unsigned int i = 0; i < curRoom->getAdjacentRooms().size(); ++i)
        {
            auto cur = curRoom->getAdjacentRooms()[i];
            
            printWithDelayWithPauses(
                        "|| "
                        + std::to_string(i)
                        + " -=- "
                        + cur->getGameObjectInfo().name
                        + "\t\t\t| "
                        + (cur->wasViewed() ? "( )" : "(?)")
                        + " |$\n"
                        );
        }
        
        printSeparator();
        
        for (unsigned int i = 0; i < curRoom->getAdjacentRooms().size(); ++i)
        {
            auto cur = curRoom->getAdjacentRooms()[i];
            
            printCase(i, (!cur->wasViewed() ? "Visit" : "Go (not visit)"));
        }
        printCase(curRoom->getAdjacentRooms().size(),
                  "Return to the current room");
        
        printSeparator();
        
        unsigned int choosedIRoomIndex;
        beginInput:
        printInputPrecede();
        std::string input;
        std::cin >> input;
        try
        {
            choosedIRoomIndex = std::stoi(input);
        }
        catch (...)
        {
            goto beginInput;
        }
        if (choosedIRoomIndex > curRoom->getAdjacentRooms().size())
        {
            goto beginInput;
        }
        
        if (choosedIRoomIndex != curRoom->getAdjacentRooms().size())
        {
            auto choosedIRoomIter = curRoom->getAdjacentRooms().begin()
                    + choosedIRoomIndex;
            curRoom = *choosedIRoomIter;
            
            if (!curRoom->wasViewed())
            {
                processRoom(curRoom, hero);
            }
        }
        else // else - go to current room
        {
            processRoom(curRoom, hero);
        }
        
        
        prepare();
    }
}
/*
void processRoom(BasicRoom *room, BasicHero *hero)
{
    if (room->getClassName() == typeid(RoomSimple).name())
    {
        room->view();
        roomSimpleCycle(dynamic_cast<RoomSimple *>(room), hero);
    }
}*/
