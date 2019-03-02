#include "GameEngine.h"
#include "Quads.h"
#include "Globals.h"
#include "TileInterpreter.h"
#include "bmp.h"
#include "EEPROM.h"

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
    //arduboy.setCursor(xFromQuadIndex(index), yFromQuadIndex(index));
    drawBMP(floorArray[index], index);
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
  
    if(isButton(getCharAtCharacter()) && (character.didMoved())){
      character.setMoved(false);
      if(buttonPressed)
        buttonPressed = false;
      else 
        buttonPressed = true;
      gateOperation();
    }
  
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
      setState(GameState::MENU);
  }
  if(arduboy.justPressed(B_BUTTON)) {
      setState(GameState::MAZE);
  }
  if(arduboy.justPressed(B_BUTTON) && arduboy.justPressed(A_BUTTON)){
      character.newLevel();
      resetParts();
      floorLevel = 0;
      setState(GameState::SELECT);
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
    arduboy.drawBitmap(80,40, Wheel16, 16, 16, WHITE);
  }
  if(uniParts[1]){
    //print stem}
    arduboy.drawBitmap(80,20, Stem16, 16, 16, WHITE);
  }
  if(uniParts[2]){
    //print seat}
    arduboy.drawBitmap(80, 5, Seat16, 16, 16, WHITE);
  }
  if(uniParts[3]){
    //print peddels}
    arduboy.drawBitmap(100, 30, Pedals16, 16, 16, WHITE);
  }
  if(uniParts[4]){
    //print crank}
    arduboy.drawBitmap(60, 30, Crank16, 16, 16, WHITE);
  }
}

void GameEngine::printMapInfo(){
  //arduboy.drawBitmap(0,0, pauseScreen, 121, 64, WHITE);
  drawFrame();
  //drawSquare(30, 20, 3);
  arduboy.setCursor(8,8);
  arduboy.print(F("Level: "));
  arduboy.println(level+1);
  arduboy.setCursor(8,16);
  arduboy.print(F("Floor: "));
  arduboy.print(floorLevel+1); 
  arduboy.setCursor(8,24);
  arduboy.print(F("Out of: "));
  arduboy.println(numOfFloors[level]);

}

void GameEngine::highscoreUpdate(){
  if(minSteps[level] == 0){
    minSteps[level] = character.getSteps();
    saveEEPROMSteps();
  }
  else if(minSteps[level] > character.getSteps()){
    minSteps[level] = character.getSteps();
    saveEEPROMSteps();
  }

  if(bitRead(levelsCleared[(level+1)%8], (level+1)%8)==0){
    bitSet(levelsCleared[(level+1)%8], (level+1)%8);
    saveEEPROMLevel();
  }
}


void GameEngine::nextLevel(){
  if(allParts() && level == MaxLevel-1){
    highscoreUpdate();
    STATE = GameState::SELECT;
    
  }
  else if(allParts()){
    highscoreUpdate();
    character.newLevel();
    resetParts();
    floorLevel = 0;
    //levelsCleared[level] = true;
    ++level;
    unpackFloor();
    setState(GameState::NEXTLEVEL);
  }

    
}

void GameEngine::winScreen(){
  arduboy.setCursor(20,20);
  arduboy.println(F("YOU WIN FOR NOW"));
  arduboy.setCursor(20,30);
  arduboy.print(F("Steps: "));
  arduboy.println(character.getSteps());
}

void GameEngine::unpackFloor(){
  hasButton = false;
  buttonPressed = false;
  for(uint8_t i = 0; i < 189; ++i){
    floorArray[i] = static_cast<char>(pgm_read_byte_near(&floors[level][floorLevel][i]));
    if (isButton(pgm_read_byte_near(&floors[level][floorLevel][i])))
      hasButton = true;
  }
}

void GameEngine::replaceChar(char part, char replacement){
  for(uint8_t i = 0; i < 189; ++i){
        if(floorArray[i] == part)
          floorArray[i] = replacement;
      }    
}

void GameEngine::gateOperation(){
  if(buttonPressed)
    replaceChar(static_cast<char>(pgm_read_byte_near(&CLOSEDGATE)), static_cast<char>(pgm_read_byte_near(&OPENGATE)));
   else
     replaceChar(static_cast<char>(pgm_read_byte_near(&OPENGATE)), static_cast<char>(pgm_read_byte_near(&CLOSEDGATE)));

   
    
}

void GameEngine::writeOver(){
// ~ index   [2]
// o index   [0]
// l index   [1]
// = index   [3]
// z index   [4]

  if(uniParts[0]){
      replaceChar(static_cast<char>(pgm_read_byte_near(&WHEEL)), static_cast<char>(pgm_read_byte_near(&OPENSPACE)));
  }
  if(uniParts[1])
    replaceChar(static_cast<char>(pgm_read_byte_near(&STEM)), static_cast<char>(pgm_read_byte_near(&OPENSPACE)));
  if(uniParts[2])
    replaceChar(static_cast<char>(pgm_read_byte_near(&SEAT)), static_cast<char>(pgm_read_byte_near(&OPENSPACE)));    
  if(uniParts[3])
    replaceChar(static_cast<char>(pgm_read_byte_near(&PEDDELS)), static_cast<char>(pgm_read_byte_near(&OPENSPACE))); 
  if(uniParts[4])
    replaceChar(static_cast<char>(pgm_read_byte_near(&CRANK)), static_cast<char>(pgm_read_byte_near(&OPENSPACE)));
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
  drawFrame();
  static int levelSelected = 0;
  arduboy.setCursor(8,8);
  arduboy.print(F("Level "));
  if(bitRead(levelsCleared[levelSelected%8], levelSelected%8)){
    arduboy.println(levelSelected+1);
    arduboy.setCursor(8,16);
    if(minSteps[levelSelected]>0){
      arduboy.print(F("Least Steps: "));
      arduboy.println(minSteps[levelSelected]);
    }
    else
    arduboy.println(F("Unlocked"));
  }
  else {
    arduboy.print(levelSelected +1); 
    arduboy.setCursor(8,16);
    arduboy.println(F(" Locked"));
  }

  if(arduboy.justPressed(UP_BUTTON)) --levelSelected;
  if(arduboy.justPressed(DOWN_BUTTON)) ++levelSelected;

  if(levelSelected < 0) levelSelected = MaxLevel-1;
  if(levelSelected > MaxLevel-1) levelSelected = 0;

  if(arduboy.justPressed(A_BUTTON) && bitRead(levelsCleared[levelSelected%8], levelSelected%8)) {
    level = (levelSelected);
    unpackFloor();
    STATE = GameState::MAZE;
  }
  
}

void GameEngine::drawBMP(char tile, uint8_t index){
   if(tile == pgm_read_byte_near(DASH) || tile == pgm_read_byte_near(VERTICAL))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), walls, 6, 7, WHITE);
   else if(tile == pgm_read_byte_near(DOWNSTAIR))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), DStair, 6, 7, WHITE);
    else if(tile == pgm_read_byte_near(UPSTAIR))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), UStair, 6, 7, WHITE);
    else if(tile == pgm_read_byte_near(LEFTGATE))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), LGate, 6, 7, WHITE);
    else if(tile == pgm_read_byte_near(RIGHTGATE))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), RGate, 6, 7, WHITE);
    else if(tile == pgm_read_byte_near(UPGATE))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), UGate, 6, 7, WHITE);
    else if(tile == pgm_read_byte_near(DOWNGATE))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), DGate, 6, 7, WHITE);
    else if(tile == pgm_read_byte_near(WHEEL))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), UWheel, 6, 7, WHITE);
    else if(tile == pgm_read_byte_near(STEM))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), UStem, 6, 7, WHITE);
    else if(tile == pgm_read_byte_near(SEAT))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), USeat, 6, 7, WHITE);
    else if(tile == pgm_read_byte_near(PEDDELS))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), UPedals, 6, 7, WHITE);
    else if(tile == pgm_read_byte_near(CRANK))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), UCrank, 6, 7, WHITE);
     else if(tile == pgm_read_byte_near(DOWNGATE))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), DGate, 6, 7, WHITE);
     else if(tile == pgm_read_byte_near(UPGATE))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), UGate, 6, 7, WHITE);
     else if(tile == pgm_read_byte_near(CLOSEDGATE))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), CGate, 6, 7, WHITE);
     else if(tile == pgm_read_byte_near(OPENGATE))
      arduboy.drawBitmap(xFromQuadIndex(index), yFromQuadIndex(index), OGate, 6, 7, WHITE);
    else{
      arduboy.setCursor(xFromQuadIndex(index), yFromQuadIndex(index));
      arduboy.print(tile);
    }


}
