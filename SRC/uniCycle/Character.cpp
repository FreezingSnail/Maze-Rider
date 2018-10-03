#include "Character.h"
#include "Globals.h"
#include "utils.h"
#include "Quads.h"
//#include "TileInterpreter.h"

const char characterTile[] PROGMEM = "C";


//bool Character::moveable(Tile &tile) {
//  const char open = " ";
//  return (tile.getChar() == open);
//}

Character::Character() {
  charTile = characterTile;
}

void Character::moveChar(bool canMove) {
  
  if(canMove){
    setMoved(true);
    if (arduboy.justPressed(UP_BUTTON)) {
      yLoc -= 6;
      index = indexAbove(index);
      ++steps;
    }
    if (arduboy.justPressed(DOWN_BUTTON)){
      yLoc += 6;
      index = indexBelow(index);
      ++steps;
    }
    if (arduboy.justPressed(LEFT_BUTTON)){
      xLoc -= 6;
      index -=1;
      ++steps;
    }
    if (arduboy.justPressed(RIGHT_BUTTON)){
      xLoc += 6; 
      index +=1;
      ++steps;
    }
  }

}

int Character::getX(){
  return xLoc;
}

int Character::getY(){
  return yLoc;
}

int Character::getIndex(){
  return index;
}

void Character::printChar() {
  arduboy.setCursor(xFromQuadIndex(index), yFromQuadIndex(index));
  arduboy.print(static_cast<char>(pgm_read_byte_near(charTile)));
}

bool Character::didMoved(){
  return moved;
}

void Character::setMoved(bool state){
  moved = state;
}


void Character::newLevel(){
  index = 73;
  xLoc = xFromQuadIndex(index);
  yLoc = yFromQuadIndex(index);
}

int Character::getSteps(){
  return steps;
}

