/* FORWARDANDBACKWARD_INO */
#include "Config.h"

void forwardAndBackwardAnimation(bitDirection animationDirection, lastCycle cycle){
  // Set all layers to high
  turnAllLayersOn();

  if(animationDirection == MSB){
    // Set bit pattern
    firstLedsData = 0B00001111;
    secondLedsData = 0B00000000;

    // Loop 
    for(int i = 0; i < 4; i++){
      shiftData(animationDirection);

      if(firstLedsData == 0B11110000){
        firstLedsData = 0B00000000;
        secondLedsData = 0B00001111;
      } else {
        secondLedsData = secondLedsData << 4;
        firstLedsData = firstLedsData << 4;
      }

      shiftDelay();
    }

    // Set bit pattern
    firstLedsData = 0B00000000;
    secondLedsData = 0B00001111;

    // Loop 
    for(int i = 0; i < 2 + cycle; i++){
      shiftData(animationDirection);

      if(secondLedsData == 0B00001111){
        secondLedsData = 0B00000000;
        firstLedsData = 0B11110000;
      } else {
        secondLedsData = secondLedsData >> 4;
        firstLedsData = firstLedsData >> 4;
      }

      shiftDelay();
    }
  } else {
    // Set bit pattern
    firstLedsData = 0B00000000;
    secondLedsData = 0B00001111;

    // Loop 
    for(int i = 0; i < 4; i++){
      shiftData(animationDirection);

      if(secondLedsData == 0B11110000){
        secondLedsData = 0B00000000;
        firstLedsData = 0B00001111;
      } else {
        secondLedsData = secondLedsData << 4;
        firstLedsData = firstLedsData << 4;
      }

      shiftDelay();
    }

    // Set bit pattern
    firstLedsData = 0B00001111;
    secondLedsData = 0B00000000;

    // Loop 
    for(int i = 0; i < 2 + cycle; i++){
      shiftData(animationDirection);

      if(firstLedsData == 0B00001111){
        firstLedsData = 0B00000000;
        secondLedsData = 0B11110000;
      } else {
        secondLedsData = secondLedsData >> 4;
        firstLedsData = firstLedsData >> 4;
      }

      shiftDelay();
    }
  }
}
/* END FORWARDANDBACKWARD_INO */
