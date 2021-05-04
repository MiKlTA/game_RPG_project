#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <vector>

#include "rooms/basicroom.h"



class RoomManager
{
public:
    ~RoomManager();
    
    using RoomContainer_t = std::vector<BasicRoom *>;
    
    //returns true if action was successfully done
    bool connectRoom(ID_t first, ID_t second);
    
    void addRoom(BasicRoom *roomp);
    const RoomContainer_t & getRooms() const;
    
private:
    RoomContainer_t m_rooms;
    
    void deleteAllRooms();
};

#endif // ROOMMANAGER_H
