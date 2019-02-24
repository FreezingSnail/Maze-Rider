#pragma once
#include "GameEngine.h"
#include "Globals.h"
#include "Quads.h"
 constexpr uint16_t EEPROM_START_C1 = EEPROM_STORAGE_SPACE_START +373; 
 constexpr uint16_t EEPROM_START_C2 = EEPROM_START_C1 + 1;
 constexpr uint16_t EEPROM_arrayOneSaveLocationClears = EEPROM_START_C2 + 1;
 constexpr uint16_t EEPROM_arrayTwoSaveLocationSteps = EEPROM_arrayOneSaveLocationClears + 10;

void initEEPROM();
void saveEEPROMLevel();
void saveEEPROMSteps();


