#include "allFunctions.h"

void introduction()
{
    prepare();
    
    printSeparator();
    
    printWithDelayWithPauses(
                "|| Hello.$\n"
                "|| For a normal game, choose a buffer size of 80.$$\n"
                "|| The game was made by Name.$$\n"
                );
    
    printSeparator();
    
    printCase(0, "Understand");
    printCase(1, "Exit");
    
    printSeparator();
    
    beginSwitch:
    printInputPrecede();
    switch (inputCase())
    {
    case '0':
        mainMenu();
        break;
    case '1':
        prepare();
        return;
    default:
        printErrorUnknownCharacter();
        goto beginSwitch;
    }
    
    prepare();
}
