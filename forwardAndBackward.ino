/* FORWARDANDBACKWARD_INO */
#include "Config.h"

void forwardAndBackwardAnimation(bitDirection animationDirection, lastCycle cycle){
  /*
  * Function: circleAnimation
  * ----------------------------
  *   Animation of 4 bits going from the front to the back of the cube
  *
  *   animationDirection: Determines the inital direction of the animation
  *   
  *   Cycle: Makes the animation look smoother when played multiple times by eliminating the last state
  *   
  *   returns: none
  */
  turnAllLayersOn();

  if(animationDirection == MSB){
    /*
    * Move forward
    */
    firstByte = 0B00001111;
    secondByte = 0B00000000
    
    for(int i = 0; i < 4; i++){
      shiftData(animationDirection);

      if(firstByte == 0B11110000){
        firstByte = 0B00000000;
        secondByte = 0B00001111;
      
      } else {
        secondByte = secondByte << 4;
        firstByte = firstByte << 4;
        
      }
      shiftDelay();
    }

    /*
    * Move backwards
    */
    firstByte = 0B00000000;
    secondByte = 0B00001111;

    for(int i = 0; i < 2 + cycle; i++){
      shiftData(animationDirection);

      if(secondByte == 0B00001111){
        secondByte = 0B00000000;
        firstByte = 0B11110000;
      
      } else {
        secondByte = secondByte >> 4;
        firstByte = firstByte >> 4;
        
      }
      shiftDelay();
    }
  
  } else {
    /*
    * Move backwards
    */
    firstByte = 0B00000000;
    secondByte = 0B00001111;

    for(int i = 0; i < 4; i++){
      shiftData(animationDirection);

      if(secondByte == 0B11110000){
        secondByte = 0B00000000;
        firstByte = 0B00001111;
      
      } else {
        secondByte = secondByte << 4;
        firstByte = firstByte << 4;
        
      }
      shiftDelay();
    }

    /*
    * Move forward
    */
    firstByte = 0B00001111;
    secondByte = 0B00000000;

    for(int i = 0; i < 2 + cycle; i++){
      shiftData(animationDirection);

      if(firstByte == 0B00001111){
        firstByte = 0B00000000;
        secondByte = 0B11110000;
      
      } else {
        secondByte = secondByte >> 4;
        firstByte = firstByte >> 4;
        
      }
      shiftDelay();
    }
  }
}
/* END FORWARDANDBACKWARD_INO */
