#include "TileInterpreter.h"
#include "Quads.h"
// char open = " ";

bool movable(char tileChar){
  if(tileChar == (pgm_read_byte_near(SEAT)) || tileChar == (pgm_read_byte_near(STEM)) || tileChar == (pgm_read_byte_near(WHEEL)) || tileChar == (pgm_read_byte_near(PEDDELS)) || tileChar == (pgm_read_byte_near(CRANK)) || tileChar == (pgm_read_byte_near(OPENSPACE))  || tileChar == (pgm_read_byte_near(UPSTAIR)) || tileChar == (pgm_read_byte_near(DOWNSTAIR)) )
    return true;

  return false;
}

bool upStair(char tileChar){
  if (tileChar == (pgm_read_byte_near(UPSTAIR)))
    return true;

  return false;
}

bool downStair(char tileChar){
  if (tileChar == (pgm_read_byte_near(DOWNSTAIR)))
    return true;

  return false;
}

Parts isPart(char tileChar){
  if (tileChar == (pgm_read_byte_near(STEM)))
    return Parts::stem;
  else if (tileChar == (pgm_read_byte_near(SEAT)))
    return Parts::seat;
  else if (tileChar == (pgm_read_byte_near(WHEEL)))
    return Parts::wheel;
  else if (tileChar == (pgm_read_byte_near(PEDDELS)))
    return Parts::peddels;
  else if (tileChar == (pgm_read_byte_near(CRANK)))
    return Parts::crank;
  else
    return Parts::nothing;
}


