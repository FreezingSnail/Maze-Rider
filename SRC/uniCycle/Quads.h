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
  SELECT,
  MAZE,
  MENU,
  NEXTlEVEL,
  WIN,
  NEXTLEVEL,
};



const char PROGMEM OPENSPACE[] = " ";
const char PROGMEM VERTICAL[] = "|";
const char PROGMEM DASH[] = "-";
const char PROGMEM UPSTAIR[] = "U";
const char PROGMEM DOWNSTAIR[] = "D";

const char PROGMEM LEFTGATE[] = "<";
const char PROGMEM RIGHTGATE[] = ">";
const char PROGMEM UPGATE[] = "^";
const char PROGMEM DOWNGATE[] = "v";

const char PROGMEM BUTTON[] = "@";
const char PROGMEM CLOSEDGATE[] = "*";
const char PROGMEM OPENGATE[] = "#";

const char PROGMEM WHEEL[] = "o";
const char PROGMEM STEM[] = "l";
const char PROGMEM SEAT[] = "~";
const char PROGMEM PEDDELS[] = "=";
const char PROGMEM CRANK[] = "z";

const char PROGMEM TEST[] = "~ o l z =           #             @                 ^      v    <   >          *                                                                                                            ";

const char PROGMEM intro1[] = "  -   --------   ---- o- -        - -    - -- - -- - - --- --~-    - --   -     ---- ----    - - - -      - l- -- - - -   ---  - -- -- -   --- - z  - -- --   ---=- - -          -----   -   ";

const char PROGMEM intro2[] = "         < <     >>>  ----- - > > -- --v-  <l << ------   -o -  - --   -- -  - --v-  -^-- - -- - --            - -- -  - -^--  - --v-  < <    -=-   - z> --------- -^- -~- --    > >    <<< -";

const char PROGMEM intro3[] = "- >>>>>>>>  <<<<<<<  - -<@ < <@< ------=- -o-vv<@<@-  - >  -~- -l-@v ----  -^@> -#  -z-v <@<<@< -@-  ---^- - v ----  -^--  --@-*-  < <@-  >@>@> --^- - <@< <@< ----  >> -   >>>>>>  <<<<< >> ";

const char PROGMEM l1x1[] = "||   || ----|D    D|D|| D || || | -| |    ||   || |- -| | |----|z| |   |   |   ||D| | |D|-| |   |--- | | | |-|D| |   |    |   |     | |- -| |=||-- ------| ||D|| |--|           |---|      --";
const char PROGMEM l1x2[] = "|---  -------U--   |U|D  |            |-| |   | |---- | |  |D| |-|-| |  ---| D| |U|l~ |U| |-         |-|-  | |U  |---|--|       | |----   ---| ||    |       U           D----------------  D";
const char PROGMEM l1x3[] = "----------|          |U        | ---| |-- ----| |-- |   -| |U        |U  | | U|  -- | |-| |---|-- -|-  | | | |     |    |  -|-| | |------| | |  o| | | |----- | | |---|  U|                 U";

const char PROGMEM l2x1[] = "D   |-----------    D--|              |---  | |----| |---| |   |   |              |-| | | |--| |----| |  | |      | | ---| |--  |------| |          |   |     |-| |-| |-D       | |D          ";
const char PROGMEM l2x2[] = "U------------|     |U             |D|-- | --- || ||--| --|-| |     -| ||---       |  |-|-| ||D ~| | -  -  |   |D||---|||  -        | |-||---|-|D---|--| |-||     |-|    U         |U|        ";
const char PROGMEM l2x3[] = "  D|    |-|------|--| -||---|D |   U  |D |   |o  ||    |--  | ||- |-| |---- |    |D|   | | | U   | || --- -|--|U| |---- ||   |  D  |-|       ||U|D|---------------------D                   D";
const char PROGMEM l2x4[] = "l|U  |-|---|  | -z |D -|- | |U  |  | D|U|   |D |-|-| |--| |-|| - |------|        |U   |  |    --| | | |-- |---  ||     | |   | |U   ||----| |----U| |----||          |-|U| |D     D   | |   U";
const char PROGMEM l2x5[] = "|                | |U| |----|| -----|U|U| | |U   |  |    | | | | |--- | -| |- | | | |    | |  | |  | | | ---| | |--- | |  | |  ~ | |      ||---| |  l_| |------||=   -| -o |U|   |U          ";

const char PROGMEM l3x1[] = "              D|D| |D | |------^--  | |-| D|      |   |--| |-| --|---| <   >         z|D    |   |------|| > --|----v--   |=| D |   |--|   | D | | | | |      |     |   |-|D|D-----|-----|---|";
const char PROGMEM l3x2[] = " |            U| |  U |^------| ||  | |v|  |^   D--| |-| | | |^ |^--     U      |D   |^U  ---| |    |---- |-------| |----|D  U | |  D    < ~U |----U| | ----| |----|    -|U|U <           --D";
const char PROGMEM l3x3[] = "| <<<< |------------|| |l<<  >>>>>>>>>  ||  | >>U   < |v--|| || |>v----| vv| --||U|| |>v----|   <   |---|  > <|  >>>>> | |U    ||v||U >>>> -|o|--- --|     >>>  -|-|    --|--| <<<<<      --U";

const char PROGMEM l4x1[] = "------D          >  ---   ----^v^---- -- --- ---  <   >  - -- --- ---D >   <D - --=---~---  <   >  - -- --- ------v^v---- >  --- ------   - -  -- --- ------ D ---  -- ---     >     >   <  -";
const char PROGMEM l4x2[] = "------UD-- ------  <  *  U----          -  @----    --- ---- -  ^- D-U -----U- -- - v*-*--  ----- - --^-  @>  -------- - o  -   > @ <    >  -    - - @ < @   U > ------ ----------------    ";
const char PROGMEM l4x3[] = "-@-----U >U < <<<<^vv  -----  > ^>^^>>>^vv ------  v^^v>^vv^>>>   < >   v^><v^Uv><vv-  --- - v<^^v<^>><vv-- * - -  <^>vv<^vv^v-- -l- - >>>vv>>>vvvv-- --- - ^<^v^>^>vvvv--   > - <v<v>v>Uvz>U";

const char PROGMEM l5x1[] = "D     ****@***--     ------@*@@*@@*---- -  -@*@*@*@*@*@* @-  -   *@ @*@*@ @*@* @> -  -@*@*@*@*@*@* @-  - z-----@*@@*@@*--***-  -   -@***@***--*~*-  -----@--   ----***-  >        D   <   --D";
const char PROGMEM l5x2[] =">@---   *@@*@   -**---v@--@v^------- -*o---@ --^v@-   ---  **---@@*-@v^- U -l--  ----v-=-^v@-   -*@-- ---- ---@v^-- -@@@@-@ < - --- v -- -@@@ -@ > -       -   - ------ ---U---   U    <     ";
constexpr size_t MaxLevel { 8 };

const char * const testlevel[] {TEST};

constexpr uint8_t numOfFloors[] = {1,1,1,3,5,3,3,2};
const char * const introOne[] {intro1};
const char * const introTwo[] {intro2};
const char * const introThree[] {intro3};
const char * const levelOne[] {l1x1, l1x2, l1x3};
const char * const levelTwo[] {l2x1, l2x2, l2x3, l2x4, l2x5};
const char * const levelThree[] {l3x1, l3x2, l3x3};
const char * const levelFour[] {l4x1, l4x2, l4x3};
const char * const levelFive[] {l5x1, l5x2};




const char open[] PROGMEM = " ";




