#include "roommanager.h"

RoomManager::~RoomManager()
{
    deleteAllRooms();
}

bool RoomManager::connectRoom(ID_t first, ID_t second)
{
    auto firstRoomIter = findByID(m_rooms, first);
    auto secondRoomIter = findByID(m_rooms, second);
    
    if (firstRoomIter != m_rooms.end()
            && secondRoomIter != m_rooms.end())
    {
        (*firstRoomIter)->addConnection(*secondRoomIter);
        (*secondRoomIter)->addConnection(*firstRoomIter);
        return true;
    }
    
    return false;
}

const RoomManager::RoomContainer_t & RoomManager::getRooms() const
{
    return m_rooms;
}

// private -------------------------------------------------------------

void RoomManager::deleteAllRooms()
{
    for (auto i : m_rooms)
    {
        delete i;
    }
    m_rooms.clear();
}
