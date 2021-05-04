#include "allFunctions.h"

void mainMenu()
{
    prepare();
    
    printSeparator();
    
    printWithDelay("||" + repeatSymbol(' ', 10) + "||");
    printWithDelay("||");
    Game::g_delay = 250;
    printWithDelay(encloseInCharacters("RISE OF THE MACHINES", ' ', 8));
    resetDelay();
    printWithDelay("||");
    printWithDelay("||" + repeatSymbol(' ', 10) + "||");
    
    printSeparator();
    
    printCase(0, "Start the game");
    printCase(1, "About the game");
    if (Game::g_enableDelay)
    {
        printCase(2, "Disable delay when writing text");
    }
    else
    {
        printCase(2, "Enable delay when writing text");
    }
    printCase(3, "Exit");
    
    printSeparator();
    
    beginSwitch:
    printInputPrecede();
    switch (inputCase())
    {
    case '0':
        
        break;
    case '1':
        
        break;
    case '2':
        Game::g_enableDelay = !Game::g_enableDelay;
        break;
    case '3':
        prepare();
        return;
    default:
        printErrorUnknownCharacter();
        goto beginSwitch;
        break;
    }
    
    prepare();
}
