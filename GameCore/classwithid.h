#ifndef CLASSWITHID_H
#define CLASSWITHID_H

#include <vector>
#include <random>



using ID_t = unsigned long long;



class ClassWithID
{
    
public:
    ClassWithID();
    virtual ~ClassWithID();
    
    ID_t getID() const;
    
private:
    ID_t m_thisID;
    static std::vector<ID_t> m_IDs;
};

#endif // CLASSWITHID_H
