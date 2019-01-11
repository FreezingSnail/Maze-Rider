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
  arduboy.drawRect(xFromQuadIndex(index), yFromQuadIndex(index), 6, 7, BLACK);
  arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), snail, 6, 7, WHITE);
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
  steps = 0;
}

int Character::getSteps(){
  return steps;
}
