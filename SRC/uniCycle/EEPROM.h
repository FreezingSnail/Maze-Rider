#pragma once

#include <Arduboy2.h>

#include "GameEngine.h"
#include "Globals.h"
#include "Quads.h"

constexpr uint16_t eepromSaveId = 0x0101;
constexpr uint16_t eepromSaveOffset = 373;

constexpr uint16_t eepromStart = (EEPROM_STORAGE_SPACE_START + eepromSaveOffset);
constexpr uint16_t eepromLevelDataStart = (eepromStart + sizeof(uint16_t));
constexpr uint16_t eepromStepDataStart = (eepromLevelDataStart + sizeof(levelsCleared));

void initEEPROM();
void saveEEPROMLevel();
void saveEEPROMSteps();
void loadEEPROMLevel();
void loadEEPROMSteps();


