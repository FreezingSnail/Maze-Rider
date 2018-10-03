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
  unpackFloor();

}

void GameEngine::draw(){

  
  for(uint8_t index = 0; index <= 188; ++index){
    arduboy.setCursor(xFromQuadIndex(index), yFromQuadIndex(index));
    arduboy.print(floorArray[index]);
  }
  

  character.printChar(); 
}


bool GameEngine::Move(){
//array[width * row + col]

  if(arduboy.justPressed(UP_BUTTON)){
    return ((movable(floorArray[indexAbove(character.getIndex())]) || validMoveGate(floorArray[indexAbove(character.getIndex())], UPGATE)) && character.getY() >6 );
    
  }
  else if(arduboy.justPressed(DOWN_BUTTON)){
    return ((movable(floorArray[indexBelow(character.getIndex())]) || validMoveGate(floorArray[indexBelow(character.getIndex())], DOWNGATE)) && character.getY() < 51);
    
  } 
  else if(arduboy.justPressed(LEFT_BUTTON)){
    return ((movable(floorArray[character.getIndex()-1]) || validMoveGate(floorArray[(character.getIndex()-1)], LEFTGATE)) && character.getX() >= 1);
    
  }
      
  else if(arduboy.justPressed(RIGHT_BUTTON)){
    return ((movable(floorArray[character.getIndex()+1]) || validMoveGate(floorArray[(character.getIndex()+1)], RIGHTGATE)) && character.getX() <120 );
    
  }
      
  else{
    return false;
  }

}

void GameEngine::Update(){
  //unpackFloor();
  character.moveChar(Move());
  //testfloor();
  
  if(upStair(getCharAtCharacter()) && character.didMoved()){
    character.setMoved(false);
    --floorLevel;
    unpackFloor();
  }
  if(downStair(getCharAtCharacter()) && character.didMoved()){
    character.setMoved(false);
    ++floorLevel;
    unpackFloor();
  }

  getPart(isPart(getCharAtCharacter()));

  nextLevel();
  pause();

  writeOver();
  
  
}


char GameEngine::getCharAtCharacter(){
  return floorArray[character.getIndex()];
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
    arduboy.println(F("o"));
  }
  if(uniParts[1]){
    //print stem}
    arduboy.println(F("l"));
  }
  if(uniParts[2]){
    //print seat}
    arduboy.println(F("~"));
  }
  if(uniParts[3]){
    //print peddels}
    arduboy.println(F("="));
  }
  if(uniParts[4]){
    //print crank}
    arduboy.println(F("z"));
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
  if(allParts()){
    character.newLevel();
    resetParts();
    floorLevel = 0;
    ++level;
    unpackFloor();
    setState(GameState::NEXTLEVEL);
  }
  else if(allParts() && level == MAX_LEVEL)
    STATE = GameState::WIN;
    
}

void GameEngine::winScreen(){
  arduboy.setCursor(20,20);
  arduboy.println(F("YOU WIN FOR NOW"));
  arduboy.setCursor(20,30);
  arduboy.print(F("Steps: "));
  arduboy.println(character.getSteps());
}

void GameEngine::unpackFloor(){
  for(uint8_t i = 0; i < 189; ++i)
    floorArray[i] = static_cast<char>(pgm_read_byte_near(&floors[level][floorLevel][i]));
}

void GameEngine::replaceChar(char part){
  for(uint8_t i = 0; i < 189; ++i){
        if(floorArray[i] == part)
          floorArray[i] = static_cast<char>(pgm_read_byte_near(&open));
      }
}

void GameEngine::writeOver(){
// ~ index   [2]
// o index   [0]
// l index   [1]
// = index   [3]
// z index   [4]

  if(uniParts[0]){
      replaceChar(static_cast<char>(pgm_read_byte_near(&WHEEL)));
  }
  if(uniParts[1])
    replaceChar(static_cast<char>(pgm_read_byte_near(&STEM)));
  if(uniParts[2])
    replaceChar(static_cast<char>(pgm_read_byte_near(&SEAT)));    
  if(uniParts[3])
    replaceChar(static_cast<char>(pgm_read_byte_near(&PEDDELS))); 
  if(uniParts[4])
    replaceChar(static_cast<char>(pgm_read_byte_near(&CRANK)));
}    


void GameEngine::nextLevelScreen(){
  arduboy.print(F("Entering Level: "));
  arduboy.println(level + 1);
  arduboy.println(F("A to continue."));
  if(arduboy.justPressed(A_BUTTON)){
    setState(GameState::MAZE);
  }
}

void GameEngine::levelSelect(){
  for(int x = 1; x <= MAX_LEVEL; x++){
    arduboy.print(F("Level "));
    arduboy.println(x);
  }
  arduboy.println();
  
  static int levelSelected = 1;
  arduboy.print(F("Level selected: "));
  arduboy.println(levelSelected);

  if(arduboy.justPressed(UP_BUTTON)) --levelSelected;
  if(arduboy.justPressed(DOWN_BUTTON)) ++levelSelected;

  if(levelSelected < 1) levelSelected = MAX_LEVEL;
  if(levelSelected > MAX_LEVEL) levelSelected = 1;

  if(arduboy.justPressed(B_BUTTON)) {
    level = (levelSelected - 1);
    unpackFloor();
    STATE = GameState::MAZE;
  }
  
}

