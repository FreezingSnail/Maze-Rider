#pragma once
#include "Quads.h"
#include <stdint.h>


class Character{
  private:
      const char * charTile;
      uint8_t index;

      uint8_t xLoc; //multiple of 6
      uint8_t yLoc; //multiple of 6
      int steps{0};
      bool moved;
    

  public: 
    Character();
    void getPart(int num);
    void moveChar(bool dir);
    void printChar();
   // bool moveable(Tile &tile);
    int getX();
    int getY();
    int getIndex();
    bool didMoved();
    void setMoved(bool state);
    void newLevel();
    int getSteps();
};


