#ifndef BASIC_ROOM_H
#define BASIC_ROOM_H

#include <string>
#include <fstream>
#include <typeinfo>
#include <set>
#include <vector>

#include "../heroes/basichero.h"
#include "../monsters/basicmonster.h"
#include "../objects/basicobject.h"
#include "../classwithid.h"



class BasicRoom : public GameObject
{
    
public:
    using Container_t = std::vector<BasicRoom *>;
    
    BasicRoom();
    BasicRoom(std::string name, std::string description);
    
    void addConnection(BasicRoom *br);
    bool removeConnection(ID_t roomID);
    void removeAllConnectionsFromAllRooms();
    
    void view();
    bool wasViewed() const;
    
    const Container_t & getAdjacentRooms() const;
    
private:
    Container_t m_adjacentRooms;
    
    bool m_wasViewed;
};

#endif // BASIC_ROOM_H
