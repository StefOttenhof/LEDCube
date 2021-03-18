/* UPANDDOWN_INO */
#include "Config.h"

void leftAndRightAnimation(bitDirection animationDirection, lastCycle cycle){
  /*
  * Function: leftAndRightAnimation
  * ----------------------------
  *   Animation of 4 bits going from the left to the right of the cube
  *
  *   animationDirection: Determines the inital direction of the animation
  *   
  *   Cycle: Makes the animation look smoother when played multiple times by eliminating the last state
  *   
  *   returns: none
  */
  turnAllLayersOn();
  firstByte = 0B00010001;
  secondByte = 0B00010001;
  
  for(int i = 0; i < 4; i++){
    shiftData(animationDirection);
    firstByte = firstByte << 1;
    secondByte = secondByte << 1;
    shiftDelay();
  }

  firstByte = 0B01000100;
  secondByte = 0B01000100;

  for(int i = 0; i < 2 + cycle; i++){
    shiftData(animationDirection);
    firstByte = firstByte >> 1;
    secondByte = secondByte >> 1;
    shiftDelay();
  }
}

/* END UPANDDOWN_INO */
