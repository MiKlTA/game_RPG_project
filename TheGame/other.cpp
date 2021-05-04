#include "allFunctions.h"

bool Game::g_enableDelay = Game::g_DefaultEnableDelay;

unsigned int Game::g_delay = Game::g_DefaultDelay;
unsigned int Game::g_timePause = Game::g_DefaultTimePause;

void resetDelay()
{
    Game::g_delay = Game::g_DefaultDelay;
}

void resetTimePause()
{
    Game::g_timePause = Game::g_DefaultTimePause;
}

void prepare()
{
    clearConsole();
    resetDelay();
    resetTimePause();
}

std::string repeatSymbol(char symb, unsigned int count)
{
    std::string result;
    
    result.append(count, symb);
    
    return result;
}

std::string encloseInCharacters(std::string str,
                                char symbL, unsigned int countL,
                                char symbR, unsigned int countR)
{
    return repeatSymbol(symbL, countL) + str + repeatSymbol(symbR, countR);
}

std::string encloseInCharacters(std::string str, char symb,
                                unsigned int countL, unsigned int countR)
{
    return encloseInCharacters(str, symb, countL, symb, countR);
}

std::string encloseInCharacters(std::string str,
                                char symb, unsigned int count)
{
    return encloseInCharacters(str, symb, count, symb, count);
}

std::string encloseInCharactersToCenter(std::string str,
                                        char symb, unsigned int indent)
{
    // because the screen size is even
    if (str.size() % 2 != 0)
    {
        str += " ";
    }
    unsigned int charactersCount = (80 - 2 * indent - str.size()) / 2;

    
    if (charactersCount > 0)
    {
        return encloseInCharacters(str, symb, charactersCount);
    }
    else
    {
        return std::string();
    }
}

std::string encloseInCharactersToCenterWithDelay(
        std::string str, char symb, unsigned int indent, char delaySymb)
{
    std::string strWithoutDelaySymb;
    
    for (char i : str)
    {
        if (i != delaySymb)
        {
            strWithoutDelaySymb += i;
        }
    }
    
    // because the screen size is even
    if (strWithoutDelaySymb.size() % 2 != 0)
    {
        strWithoutDelaySymb += " ";
    }
    unsigned int charactersCount = (80 - 2 * indent
                                    - strWithoutDelaySymb.size()) / 2;

    
    if (charactersCount > 0)
    {
        return encloseInCharacters(str, symb, charactersCount);
    }
    else
    {
        return std::string();
    }
}

std::string encloseInCharactersToCenterWithDelay(
        std::string str, char symb, unsigned int indent)
{
    return encloseInCharactersToCenterWithDelay(
                str, symb, indent, Game::g_DelaySymbol);
}

unsigned int countUntouchedObjects(const RoomSimple::ObjectContainer_t &objects)
{
    unsigned int untouchedObjects = 0;
    for (auto i : objects)
    {
        if (!i->getBasicObjectInfo().wasExamined)
        {
           untouchedObjects++;
        }
    }
    return untouchedObjects;
}

unsigned int countUntouchedMonsters(
        const RoomSimple::MonsterContainer_t &monsters)
{
    unsigned int untouchedObjects = 0;
    for (auto i : monsters)
    {
        if (!i->wasViewed())
        {
           untouchedObjects++;
        }
    }
    return untouchedObjects;
}
