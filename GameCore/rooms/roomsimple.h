#ifndef ROOM_SIMPLE_H
#define ROOM_SIMPLE_H

#include "BasicRoom.h"



class RoomSimple : public BasicRoom
{
    
public:
    using MonsterContainer_t = std::vector<BasicMonster *>;
    using ObjectContainer_t = std::vector<BasicObject *>;
    
    RoomSimple() {};
    RoomSimple(std::string name, std::string description);
    
    void addMonster(BasicMonster *monster);
    void addObject(BasicObject *object);
    
    void removeMonster(ID_t monsterID);
    
    const MonsterContainer_t & getMonsters() const;
    const ObjectContainer_t & getObjects() const;

    const std::string getClassName() const
    {return typeid(RoomSimple).name();};
    
private:
    MonsterContainer_t m_monsters;
    ObjectContainer_t m_objects;
};

#endif // ROOM_SIMPLE_H
