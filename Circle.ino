/* CICLE_INO */
#include "Config.h"

/*
* Byte values for both halves of the cube
*/
int indexesSecondByte[12] = { 0B11100000, 0B01110000, 0B00110001, 0B00010001, 0B00000001, 0B00000000, 0B00000000, 0B00000000, 0B00000000, 0B00001000, 0B10001000, 0B11001000};
int indexesFirstByte[12] = { 0B00000000, 0B00000000, 0B00000000, 0B00010000, 0B00010001, 0B00010011, 0B00000111, 0B00001110, 0B10001100, 0B10001000, 0B10000000, 0B00000000};

void circleAnimation(bitDirection animationDirection, lastCycle cycle){
  /*
  * Function: circleAnimation
  * ----------------------------
  *   Animation of 3 bits going around the outter ring
  *
  *   animationDirection: Determines the inital direction of the animation
  *   
  *   Cycle: Makes the animation look smoother when played multiple times by eliminating the last state
  *   
  *   returns: none
  */
  turnAllLayersOn();

  if(animationDirection == MSB){
    for(int i = 0; i < 12 - cycle; i++){
      firstByte = indexesFirstByte[i];
      secondByte = indexesSecondByte[i]; 
      shiftData(MSB);
      shiftDelay();
    }
  
  } else {
    for(int i = 12; i >= 0 + cycle; i--){
      firstByte = indexesFirstByte[i];
      secondByte = indexesSecondByte[i];
      shiftData(MSB);
      shiftDelay();
    }
    
  }
}

/* END CIRCLE_INO */
