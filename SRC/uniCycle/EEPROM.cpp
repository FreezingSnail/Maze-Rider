#include "EEPROM.h"

void initEEPROM() {

  uint8_t c1 = EEPROM.read(EEPROM_START_C1);
  uint8_t c2 = EEPROM.read(EEPROM_START_C2);

  if(c1 != 1 || c2 != 1) 
  {    
      EEPROM.update(EEPROM_START_C1, 1);
      EEPROM.update(EEPROM_START_C2, 1);
      {
          uint16_t eepromIndex = EEPROM_arrayOneSaveLocationClears;
          for(uint8_t index = 0; index < 8; ++index)
          {
            EEPROM.put(eepromIndex, levelsCleared[index]);
            ++eepromIndex;
          }
      }
      {
          uint16_t  eepromIndex = EEPROM_arrayTwoSaveLocationSteps;
          for(uint8_t index = 0; index < MaxLevel; ++index)
          {
            EEPROM.put(eepromIndex, minSteps[index]);
            eepromIndex += sizeof(minSteps[0]);
          }
      }
      //EEPROM.put(EEPROM_arrayOneSaveLocationClears, levelsCleared); //bool array of levels beaten
      //EEPROM.put(EEPROM_arrayTwoSaveLocationSteps, minSteps);       //uint16_t array of number of steps taken  
  }
  else
  {
    {
      const uint16_t * eepromPointer = reinterpret_cast<const uint16_t *>(EEPROM_arrayTwoSaveLocationSteps);
      for(uint8_t index = 0; index < MaxLevel; ++index)
      {
        minSteps[index] = eeprom_read_word(eepromPointer);
        ++eepromPointer;
      }
    }
      const uint8_t * eepromPointer = reinterpret_cast<const uint8_t *>(EEPROM_arrayOneSaveLocationClears);  //bit array
      for(uint8_t index = 0; index < 8; ++index)
      {
        levelsCleared[index] = eeprom_read_byte(eepromPointer);
        ++eepromPointer;
      }

  }
}

void saveEEPROMLevel()
{
   uint8_t eepromIndex = EEPROM_arrayOneSaveLocationClears;
      for(uint8_t index = 0; index < MaxLevel; ++index)
      {
        EEPROM.update(eepromIndex, levelsCleared[index]);
        ++eepromIndex;
      }
  
}

void saveEEPROMSteps()
{
  uint8_t  eepromIndex = EEPROM_arrayTwoSaveLocationSteps;
      for(uint8_t index = 0; index < MaxLevel; ++index)
      {
        EEPROM.put(eepromIndex, minSteps[index]);
        eepromIndex += sizeof(minSteps[0]);
      }
}

