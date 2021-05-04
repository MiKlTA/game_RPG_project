#include "classwithid.h"

std::vector<ID_t> ClassWithID::m_IDs = std::vector<ID_t>();

ClassWithID::ClassWithID()
{
    ID_t newID;
    
    beginCycle:
    
    
    newID = ((rand() * RAND_MAX * RAND_MAX + rand() * RAND_MAX + rand())
            % (1ll + UINT32_MAX )) * (1ll + UINT32_MAX )
            + 
            ((rand() * RAND_MAX * RAND_MAX + rand() * RAND_MAX + rand())
            % (1ll + UINT32_MAX))
            - 1ll;
    
    for (ID_t i : m_IDs)
    {
        if (i == newID)
        {
            goto beginCycle;
        }
    }
    m_thisID = newID;
}

ClassWithID::~ClassWithID()
{
    for (auto i = m_IDs.begin(); i != m_IDs.end(); ++i)
    {
         if ((*i) == m_thisID)
         {
             m_IDs.erase(i);
             return;
         }
    }
}

ID_t ClassWithID::getID() const
{
    return m_thisID;
}
