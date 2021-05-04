#include "specialfraction.h"

SpecialFraction::SpecialFraction(unsigned char num)
    : m_data(num)
{
    
}

SpecialFraction::operator double() const
{
    return m_data / 255.0;
}

SpecialFraction::operator float() const
{
    return m_data / 255.f;
}

unsigned char SpecialFraction::getChar() const
{
    return m_data;
}

float SpecialFraction::makeFloatFromUChar(unsigned char num)
{
    return num / 255.f;
}

double SpecialFraction::makeDoubleFromUChar(unsigned char num)
{
    return num / 255.0;
}
