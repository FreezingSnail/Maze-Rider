#pragma once
#include "Quads.h"


void interpret();
bool movable(char tileChar);
bool upStair(char tile);
bool downStair(char tile);
Parts isPart(char tile);

bool validMoveGate(char tile, const char* gateType);
bool isButton(char tile);

char printtile(char tile);
