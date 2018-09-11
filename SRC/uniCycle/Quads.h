#pragma once
#include <avr/pgmspace.h>

enum class Parts{
  wheel,
  stem,
  seat,
  peddels,
  crank,
  nothing,
};

enum class GameState{
  SPLASH,
  HELP,
  MAZE,
  MENU,
  NEXTlEVEL,
  WIN,
};



const char PROGMEM OPENSPACE[] = " ";
const char PROGMEM VERTICAL[] = "|";
const char PROGMEM DASH[] = "-";
const char PROGMEM UPSTAIR[] = "U";
const char PROGMEM DOWNSTAIR[] = "D";

const char PROGMEM WHEEL[] = "o";
const char PROGMEM STEM[] = "l";
const char PROGMEM SEAT[] = "~";
const char PROGMEM PEDDELS[] = "=";
const char PROGMEM CRANK[] = "z";

const char PROGMEM l1x1[] = "||   || ----|D    D|D|| D || || | -| |    ||   || |- -| | |----|z| |   |   |   ||D| | |D|-| |   |--- | | | |-|D| |   |    |   |     | |- -| |=||-- ------| ||D|| |--|           |---|      --";
const char PROGMEM l1x2[] = "|---  -------U--   |U|D  |            |-| |   | |---- | |  |D| |-|-| |  ---| D| |U|l~ |U| |-         |-|-  | |U  |---|--|       | |----   ---| ||    |       U           D----------------  D";
const char PROGMEM l1x3[] = "----------|          |U        | ---| |-- ----| |-- |   -| |U        |U  | | U|  -- | |-| |---|-- -|-  | | | |     |    |  -|-| | |------| | |  o| | | |----- | | |---|  U|                 U";

const char PROGMEM l2x1[] = "D   |-----------    D--|              |---  | |----| |---| |   |   |              |-| | | |--| |----| |  | |      | | ---| |--  |------| |          |   |     |-| |-| |-D       | |D          ";
const char PROGMEM l2x2[] = "U------------|     |U             |D|-- | --- || ||--| --|-| |     -| ||---       |  |-|-| ||D ~| | -  -  |   |D||---|||  -        | |-||---|-|D---|--| |-||     |-|    U         |U|        ";
const char PROGMEM l2x3[] = "  D|    |-|------|--| -||---|D |   U  |D |   |o  ||    |--  | ||- |-| |---- |    |D|   | | | U   | || --- -|--|U| |---- ||   |  D  |-|       ||U|D|---------------------D                   D";
const char PROGMEM l2x4[] = "l|U  |-|---|  | -z |D -|- | |U  |  | D|U|   |D |-|-| |--| |-|| - |------|        |U   |  |    --| | | |-- |---  ||     | |   | |U   ||----| |----U| |----||          |-|U| |D     D   | |   U";
const char PROGMEM l2x5[] = "|                | |U| |----|| -----|U|U| | |U   |  |    | | | | |--- | -| |- | | | |    | |  | |  | | | ---| | |--- | |  | |  ~ | |      ||---| |  l_| |------||=   -| -o |U|   |U          ";

const char * const levelOne[] {l1x1, l1x2, l1x3};
const char *  const levelTwo[] {l2x1, l2x2, l2x3, l2x4, l2x5};



const char open[] PROGMEM = " ";




