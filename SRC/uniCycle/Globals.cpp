#include "Globals.h"

Arduboy2 arduboy;
uint16_t minSteps[MaxLevel] {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t levelsCleared[8] { /*true,true,true,true,true,true,true,*/0B00000001, 0B00000000, 0B00000000, 0B00000000, 0B00000000, 0B00000000, 0B00000000, 0B00000000};

