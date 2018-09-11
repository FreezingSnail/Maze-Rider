#pragma once

#include "utils.h"
#include "Quads.h"
#include "Character.h"


class GameEngine{
  private:
    const char * const *  floors[2] { levelOne, levelTwo};
    Character character;
    uint8_t level;
    uint8_t floorLevel;
    bool uniParts[5] = { false, false, false, false, false };
    GameState STATE = GameState::SPLASH;


  public:
    GameEngine();
    void draw();
    bool Move();
    void Update();
    char getCharAtCharacter();          
    void getPart(Parts part);
    bool allParts();
    void testfloor();
    void hideParts();
    //void nextLevel();
    
    
    GameState getState();
    void setState(GameState state);

    void pauseMenu();
    void pause();
    void resetParts();
    void printParts();
    void printMapInfo();
    void nextLevel();

    void winScreen();

};

