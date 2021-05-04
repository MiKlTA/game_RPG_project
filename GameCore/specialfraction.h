#ifndef SHORTDOUBLE_H
#define SHORTDOUBLE_H

class SpecialFraction
{
    
public:
    explicit SpecialFraction(unsigned char num);
    
    operator double() const;
    operator float() const;
    unsigned char getChar() const;
    
    static float makeFloatFromUChar(unsigned char num);
    static double makeDoubleFromUChar(unsigned char num);
    
private:
    unsigned char m_data;
};


#endif // SHORTDOUBLE_H
