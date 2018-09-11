#pragma once
#include <stdint.h>
#define QUADWIDTH 21

inline uint8_t flattenIndex(uint8_t x, uint8_t y)
  {
    return (((y) * (QUADWIDTH)) + (x));
  }

 inline uint8_t xFromQuadIndex(uint8_t index){
  if(index < 21)
    return  (index)*6;
  else if( index >= 21 && index < 42)
    return (-(QUADWIDTH) + index)*6;
  else if(index >= 42 && index < 63)
    return (-(QUADWIDTH*2) + index)*6;
  else if(index >= 63 && index < 84)
    return (-(QUADWIDTH*3) + index)*6;
  else if(index >= 84 && index < 105)
    return (-(QUADWIDTH*4) + index)*6;
  else if(index >= 105 && index < 126)
    return (-(QUADWIDTH*5) + index)*6;
  else if(index >= 126 && index < 147)
    return (-(QUADWIDTH*6) + index)*6;
  else if(index >= 147 && index < 168)
    return (-(QUADWIDTH*7) + index)*6;
  else if(index >= 168 && index < 189)
    return (-(QUADWIDTH*8) + index)*6;
  else if(index >= 189 && index < 210)
    return (-(QUADWIDTH*9) + index)*6;
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

