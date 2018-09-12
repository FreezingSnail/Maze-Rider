#include "GameEngine.h"
#include "Quads.h"
#include "Globals.h"
#include "TileInterpreter.h"
#include "bmp.h"

// ~ index 95 x2  [0]
// o index 46 x3  [1]
// l index 0 x4   [2]
// = index 161 x5 [3]
// z index 17 x4  [4]

GameEngine::GameEngine(){
  floors;
  character = Character();
  level = 0;
  floorLevel = 0;

}

void GameEngine::draw(){

  
  for(uint8_t index = 0; index <= 188; ++index){
    arduboy.setCursor(xFromQuadIndex(index), yFromQuadIndex(index));
    arduboy.print(static_cast<char>(pgm_read_byte_near(&floors[level][floorLevel][index])));
  }
  
  hideParts();
  character.printChar(); 
//  arduboy.setCursor(0,0);
//  arduboy.print(character.getY());


    

  
}

bool GameEngine::Move(){
//array[width * row + col]

  if(arduboy.justPressed(UP_BUTTON)){
    return (movable((pgm_read_byte_near(&floors[level][floorLevel][indexAbove(character.getIndex())]))) && character.getY() >6 );
    
  }
  else if(arduboy.justPressed(DOWN_BUTTON)){
    return (movable(pgm_read_byte_near(&floors[level][floorLevel][indexBelow(character.getIndex())])) && character.getY() < 51);
    
  } 
  else if(arduboy.justPressed(LEFT_BUTTON)){
    return (movable(pgm_read_byte_near(&floors[level][floorLevel][character.getIndex()-1])) && character.getX() >= 1);
    
  }
      
  else if(arduboy.justPressed(RIGHT_BUTTON)){
    return (movable(pgm_read_byte_near(&floors[level][floorLevel][character.getIndex()+1])) && character.getX() <120 );
    
  }
      
  else{
    return false;
  }

}

void GameEngine::Update(){
  character.moveChar(Move());
  //testfloor();
  if(upStair(getCharAtCharacter()) && character.didMoved()){
    character.setMoved(false);
    --floorLevel;
  }
  if(downStair(getCharAtCharacter()) && character.didMoved()){
    character.setMoved(false);
    ++floorLevel;
  }

  getPart(isPart(getCharAtCharacter()));

  nextLevel();
  pause();
  
  
}


char GameEngine::getCharAtCharacter(){
  return pgm_read_byte_near(&floors[level][floorLevel][character.getIndex()]);
}

void GameEngine::getPart(Parts part){
  if(part != Parts::nothing)
    uniParts[static_cast<int>(part)] = true;
}

bool GameEngine::allParts(){
  if(uniParts[0] && uniParts[1] && uniParts[2] && uniParts[3] && uniParts[4] ) 
    return true;
  else
    return false;
}

/*void GameEngine::testfloor(){
  if(arduboy.justPressed(DOWN_BUTTON))
    ++level;
  else if(arduboy.justPressed(UP_BUTTON))
    --level;
}

void GameEngine::nextLevel(){
//  if(arduboy.justPressed(A_BUTTON)){
    character.newLevel();
    resetParts();
    floorLevel = 0;
    ++level;
//  }
}*/

void GameEngine::hideParts(){ //sins against PROGMEM

// level 1 (index 0) part indexs.  
// ~ index 84 x1  [2]
// o index 144 x2  [0]
// l index 83 x1   [1]
// = index 141 x0 [3]
// z index 64 x0  [4]
  if(level== 0){
    if(uniParts[2] && floorLevel == 1){
      arduboy.setCursor(xFromQuadIndex(84), yFromQuadIndex(84));
      arduboy.print(F(" "));
    }
    if(uniParts[0] && floorLevel == 2){
      arduboy.setCursor(xFromQuadIndex(144), yFromQuadIndex(144));
      arduboy.print(F(" "));
    }
    if(uniParts[1] && floorLevel == 1){
      arduboy.setCursor(xFromQuadIndex(83), yFromQuadIndex(83));
      arduboy.print(F(" "));
    }
    if(uniParts[3] && floorLevel == 0){
      arduboy.setCursor(xFromQuadIndex(141), yFromQuadIndex(141));
      arduboy.print(F(" "));
    }
    if(uniParts[4] && level == 0){
      arduboy.setCursor(xFromQuadIndex(64), yFromQuadIndex(64));
      arduboy.print(F(" "));
    }
  
  }
  else if(level == 1){
// level 2 (index 1) part indexs.  
// ~ index 95 x2  [2]
// o index 46 x3  [0]
// l index 0 x4   [1]
// = index 161 x5 [3]
// z index 17 x4  [4]
    if(uniParts[2] && floorLevel == 1){
      arduboy.setCursor(xFromQuadIndex(95), yFromQuadIndex(95));
      arduboy.print(F(" "));
    }
    if(uniParts[0] && floorLevel == 2){
      arduboy.setCursor(xFromQuadIndex(46), yFromQuadIndex(46));
      arduboy.print(F(" "));
    }
    if(uniParts[1] && floorLevel == 3){
      arduboy.setCursor(xFromQuadIndex(0), yFromQuadIndex(0));
      arduboy.print(F(" "));
    }
    if(uniParts[3] && floorLevel == 4){
      arduboy.setCursor(xFromQuadIndex(161), yFromQuadIndex(161));
      arduboy.print(F(" "));
    }
    if(uniParts[4] && floorLevel == 3){
      arduboy.setCursor(xFromQuadIndex(17), yFromQuadIndex(17));
      arduboy.print(F(" "));
    }
  }
}
void GameEngine::resetParts(){
  for(int x = 0;x<5; ++x){
    uniParts[x] = false;}
}

GameState GameEngine::getState(){
  return STATE;
}

void GameEngine::setState(GameState state){
  STATE = state; 
}

void GameEngine::pauseMenu(){
  pause();
  printParts();
  printMapInfo();
  
}

void GameEngine::pause(){
  if(arduboy.justPressed(A_BUTTON)){
      setState(GameState::MENU);}
  if(arduboy.justPressed(B_BUTTON)) {
      setState(GameState::MAZE);
  }
}

/*  wheel,
  stem,
  seat,
  peddels,
  crank,
  nothing,
  */
void GameEngine::printParts(){
  if(uniParts[0]){
    //printwheel}
  }
  if(uniParts[1]){
    //print stem}
  }
  if(uniParts[2]){
    //print seat}
  }
  if(uniParts[3]){
    //print peddels}
  }
  if(uniParts[4]){
    //print crank}
  }
}

void GameEngine::printMapInfo(){
  arduboy.drawBitmap(0,0, pauseScreen, 121, 64, WHITE);
 
  arduboy.print(F("Level: "));
  arduboy.println(level+1);

  arduboy.print(F("Floor: "));
  arduboy.println(floorLevel);
  
}

void GameEngine::nextLevel(){
  if(allParts() && level == 0){
    character.newLevel();
    resetParts();
    floorLevel = 0;
    ++level;
  }
  else if(allParts() && level != 0)
    STATE = GameState::WIN;
    
}

void GameEngine::winScreen(){
  arduboy.setCursor(20,20);
  arduboy.println(F("YOU WIN FOR NOW"));
  arduboy.setCursor(20,30);
  arduboy.print(F("Steps: "));
  arduboy.println(character.getSteps());
}

