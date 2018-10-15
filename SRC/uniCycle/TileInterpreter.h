#pragma once
#include "Quads.h"


void interpret();
bool movable(char tileChar);  //all tiles that can be transvered
bool upStair(char tile);      //tile that moves up
bool downStair(char tile);    //tile that moves down
Parts isPart(char tile);      //checks if tile is a part

bool validMoveGate(char tile, const char* gateType);  //validate if moving through directional gate
bool isButton(char tile);     //returns if tile is a button

char printtile(char tile);    //unused
