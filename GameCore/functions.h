#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <algorithm>
#include <typeinfo>
#include <vector>
#include <random>
#include <climits>

#include "classwithid.h"



const std::string fillSpaces(const std::string &str);
const std::string makeSpaces(const std::string &str);
// from 0 to 255 (0% - 100%)
bool randomize(unsigned char chance);


template <typename T>
bool ptrIsValid(const T *t)
{
    if (t == nullptr)
    {
        return false;
    }
    
    try
    {
        (*t);
    }
    catch (...)
    {
        return false;
    }
    return true;
}


template<typename T>
typename std::vector<T *>::iterator
findByID(std::vector<T *> & container, ID_t id)
{
    return std::find_if(container.begin(), container.end(),
                                 [&id](const T *itemPtr)
    {
        return (itemPtr->getID() == id);
    });
}

template<typename T>
typename std::vector<T *>::const_iterator
findByID(const std::vector<T *> & container, ID_t id)
{
    return std::find_if(container.cbegin(), container.cend(),
                                 [&id](const T *itemPtr)
    {
        return (itemPtr->getID() == id);
    });
}

#endif // FUNCTIONS_H
