/* FORWARDANDBACKWARD_INO */
#include "Config.h"

void forwardAndBackwardAnimation(bitDirection animationDirection, lastCycle cycle){
  // Set all layers to high
  turnAllLayersOn();

  if(animationDirection == MSB){
    // Set bit pattern
    firstByte = 0B00001111;
    secondByte = 0B00000000;

    // Loop 
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

    // Set bit pattern
    firstByte = 0B00000000;
    secondByte = 0B00001111;

    // Loop 
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
    // Set bit pattern
    firstByte = 0B00000000;
    secondByte = 0B00001111;

    // Loop 
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

    // Set bit pattern
    firstByte = 0B00001111;
    secondByte = 0B00000000;

    // Loop 
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
