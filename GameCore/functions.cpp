#include "functions.h"


bool randomize(unsigned char chance)
{
    // 0..254 < 0 and 0..254 < 255
    return rand() % 255 < chance;
}
