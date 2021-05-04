#include "basicroom.h"

BasicRoom::BasicRoom(): m_wasViewed(false)
{
    
}

BasicRoom::BasicRoom(std::string name, std::string description)
    : GameObject(name, description),
      m_wasViewed(false)
{
    
}

void BasicRoom::addConnection(BasicRoom *br)
{
    m_adjacentRooms.push_back(br);
}

bool BasicRoom::removeConnection(ID_t roomID)
{
    for (auto i = m_adjacentRooms.begin(); i != m_adjacentRooms.end(); ++i)
    {
        if ((*i)->getID() == roomID)
        {
            m_adjacentRooms.erase(i);
            return true;
        }
    }
    return false;
}

void BasicRoom::removeAllConnectionsFromAllRooms()
{
    for (auto i : m_adjacentRooms)
    {
        i->removeConnection(this->getID());
    }
    m_adjacentRooms.clear();
}

void BasicRoom::view()
{
    m_wasViewed = true;
}

bool BasicRoom::wasViewed() const
{
    return m_wasViewed;
}

const BasicRoom::Container_t & BasicRoom::getAdjacentRooms() const
{
    return m_adjacentRooms;
}
