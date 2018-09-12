//#include <Arduboy2.h>
#include "Globals.h"  
#include "GameEngine.h"
#include "Character.h"
#include "TileInterpreter.h"
#include "utils.h"
#include "Quads.h"
#include "bmp.h"
// Arduboy2 arduboy; 
 

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.clear();
  
}



void loop() {

  static GameEngine game = GameEngine();

  if(!arduboy.nextFrame()){
    return;
  }
  arduboy.pollButtons();
  
  arduboy.clear();

  switch(game.getState()){
    case GameState::SPLASH:
      //print splashscreen function
    arduboy.drawBitmap(0,0, splashScreen, 121, 64, WHITE);
      if(arduboy.justPressed(A_BUTTON))
        game.setState(GameState::MAZE);
     // if(arduboy.justPressed(B_BUTTON))
       // game.setState(GameState::HELP);      
      break;

    case GameState::HELP:
      //print help documentation
      if(arduboy.justPressed(B_BUTTON))
        game.setState(GameState::SPLASH);
        break;  
      
    case GameState::MAZE:
      game.draw();
      game.Update();
      break;

    case GameState::MENU:
      game.pauseMenu();
      break;

    case GameState::WIN:
      game.winScreen();
      break;
 

  }
  arduboy.display();
}
