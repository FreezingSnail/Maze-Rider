#include "EEPROM.h"

void initEEPROM()
{
	uint16_t * eepromStartPointer = reinterpret_cast<uint16_t *>(eepromStart);

	// Read save id
	uint16_t saveId = eeprom_read_word(eepromStartPointer);

	// If save id matches
	if(saveId == eepromSaveId) 
	{
		// Load data
		loadEEPROMLevel();
		loadEEPROMSteps();
	}
	else
	{
		// Else reset eeprom
		eeprom_write_word(eepromStartPointer, eepromSaveId);
		
		saveEEPROMLevel();
		saveEEPROMSteps();
	}
}

void saveEEPROMLevel()
{
	uint8_t * eepromLevelsPointer = reinterpret_cast<uint8_t *>(eepromLevelDataStart);
	eeprom_update_block(levelsCleared, eepromLevelsPointer, sizeof(levelsCleared));
}

void loadEEPROMLevel()
{
	const uint8_t * eepromLevelsPointer = reinterpret_cast<const uint8_t *>(eepromLevelDataStart);
	eeprom_read_block(levelsCleared, eepromLevelsPointer, sizeof(levelsCleared));
}

void saveEEPROMSteps()
{
	uint16_t * eepromStepsPointer = reinterpret_cast<uint16_t *>(eepromStepDataStart);
	eeprom_update_block(minSteps, eepromStepsPointer, sizeof(minSteps));
}

void loadEEPROMSteps()
{
	const uint16_t * eepromStepsPointer = reinterpret_cast<const uint16_t *>(eepromStepDataStart);
	eeprom_read_block(minSteps, eepromStepsPointer, sizeof(minSteps));
}