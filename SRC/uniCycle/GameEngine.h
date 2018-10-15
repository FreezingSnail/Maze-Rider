#pragma once

#include "utils.h"
#include "Quads.h"
#include "Character.h"


class GameEngine{
  private:
    
    const char * const *  floors[MAX_LEVEL] {testlevel, levelOne, levelTwo, levelThree};
    Character character{};
    uint8_t level{ 0 };
    uint8_t floorLevel { 0 };
    bool uniParts[5] = { false, false, false, false, false };
    char floorArray[190] {};
    GameState STATE { GameState::SPLASH };
    bool levelsCleared[MAX_LEVEL] { true,true,true};
    bool hasButton {false};
    bool buttonPressed {false};

    bool Move();                  //determine if moveable tile at selected destination
    char getCharAtCharacter();    //return tile at character location
    void getPart(Parts part);     //update part array to true at part index
    bool allParts();              //check if all parts have been collected

    void pause();                 //switch between pause and maze state
    
    void resetParts();            //set part bool array to false
    void printParts();            //display collect parts on pause screen
    void printMapInfo();          //print level and floor currently on
    void nextLevel();             //advances to next level and resets level initialisers
    
    void unpackFloor();           //load floor data into ram
    void replaceChar(char part, char replacement);  //replace part tile with blank tile
    void writeOver();             //check to see if part tiles need to be written over
    void gateOperation();         //Swaps gate tile on button press    ￼
    void drawBMP(char tile, uint8_t index); //Draws correct tileBMP from char

  public:
    GameEngine();                 //constructor
    void draw();                  //draw game and character
    void Update();                //step game logic

    void pauseMenu();             //display pause screen
    void winScreen();             //display win screen
    
    GameState getState();         //return current GameState
    void setState(GameState state);//Set GameState

    void nextLevelScreen();        //next level screen
    void levelSelect();            //select screen;

    
};

