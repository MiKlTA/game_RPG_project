#include "roomsimple.h"

RoomSimple::RoomSimple(std::string name, std::string description)
    : BasicRoom(name, description)
{
    
}

void RoomSimple::addMonster(BasicMonster *monster)
{
    m_monsters.push_back(monster);
}

void RoomSimple::addObject(BasicObject *object)
{
    m_objects.push_back(object);
}

void RoomSimple::removeMonster(ID_t monsterID)
{
    auto monsterIter = findByID(m_monsters, monsterID);
    
    if (monsterIter != m_monsters.end())
    {
        delete *monsterIter;
        m_monsters.erase(monsterIter);
    }
}


const RoomSimple::MonsterContainer_t & RoomSimple::getMonsters() const
{
    return m_monsters;
}

const RoomSimple::ObjectContainer_t & RoomSimple::getObjects() const
{
    return m_objects;
}
