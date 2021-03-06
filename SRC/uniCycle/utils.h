#pragma once
#include "Globals.h"
#include "bmp.h"
#include "Quads.h"
#include <stdint.h>
#define QUADWIDTH 21
#define QUADHEIGHT 6

inline uint8_t flattenIndex(uint8_t x, uint8_t y)
  {
    return (((y) * (QUADWIDTH)) + (x));
  }

 inline uint8_t xFromQuadIndex(uint8_t index){
  if(index < 21)
    return  (index)*QUADHEIGHT;
  else if(index < 42)
    return (-(QUADWIDTH) + index)*QUADHEIGHT;
  else if(index < 63)
    return (-(QUADWIDTH*2) + index)*QUADHEIGHT;
  else if(index < 84)
    return (-(QUADWIDTH*3) + index)*QUADHEIGHT;
  else if(index < 105)
    return (-(QUADWIDTH*4) + index)*QUADHEIGHT;
  else if(index < 126)
    return (-(QUADWIDTH*5) + index)*QUADHEIGHT;
  else if(index < 147)
    return (-(QUADWIDTH*6) + index)*QUADHEIGHT;
  else if(index < 168)
    return (-(QUADWIDTH*7) + index)*QUADHEIGHT;
  else if(index < 189)
    return (-(QUADWIDTH*8) + index)*QUADHEIGHT;
  else if(index < 210)
    return (-(QUADWIDTH*9) + index)*QUADHEIGHT;
 }

inline uint8_t yFromQuadIndex(uint8_t index){
  return ((index - (index%QUADWIDTH)) / QUADWIDTH)*7;
}



inline uint8_t indexAbove(uint8_t indexFrom){
  return indexFrom - QUADWIDTH;
}

inline uint8_t indexBelow(uint8_t indexFrom){
  return indexFrom + QUADWIDTH;
}

//Draw Utils


inline void drawRow(int yAxis){
  for(int count = 0; count < 22; ++count)
    arduboy.drawBitmap(xFromQuadIndex(count), yAxis, walls, 6, 7, WHITE);
}

inline void drawColumn(int xAxis){
  for(int count = 0; count < 9; ++count)
    arduboy.drawBitmap(xAxis, (count * 7), walls, 6, 7, WHITE);
}

inline void drawFrame(){
  drawColumn(0);
  drawColumn(120);
  drawRow(0);
  drawRow(56);
}

inline void drawSquare(int x, int y, int dimension){
  for(int vertical = 0; vertical < dimension; ++vertical)
    for(int horizontal = 0; horizontal < dimension; ++horizontal)
    arduboy.drawBitmap((x + (horizontal * 6)), (y + (vertical*7)), walls, 6, 7, WHITE);
}



