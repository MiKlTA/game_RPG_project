#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

#include "basicobject.h"



class SimpleObject : public BasicObject
{
public:
    SimpleObject() {};
    SimpleObject(std::string name, std::string description,
                 unsigned int levelAdd);
    virtual ~SimpleObject() {};

    
/*    virtual const std::string getClassName() const override
    {return typeid(SimpleObject).name();};*/
};

#endif // SIMPLEOBJECT_H
