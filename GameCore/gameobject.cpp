#include "gameobject.h"

GameObject::GameObject(std::string name, std::string description)
    : m_gameObjectInfo{name, description}
{
    
}

const GameObjectInfo & GameObject::getGameObjectInfo() const
{
    return m_gameObjectInfo;
}

