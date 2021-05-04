#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <fstream>

#include "functions.h"
#include "classwithid.h"



struct GameObjectInfo
{
    std::string name;
    std::string description;
};

class GameObject : public ClassWithID
{
    
public:
    GameObject() {};
    GameObject(std::string name, std::string description);
    virtual ~GameObject() {};
    
    const GameObjectInfo & getGameObjectInfo() const;

    
protected:
    GameObjectInfo m_gameObjectInfo;
};

#endif // GAMEOBJECT_H
