/* UPANDDOWN_INO */
#include "Config.h"

void leftAndRightAnimation(bitDirection animationDirection, lastCycle cycle){
  turnAllLayersOn();
  firstByte = 0B00010001;
  secondByte = 0B00010001;

  // Loop to the left or right depending on direction
  for(int i = 0; i < 4; i++){
    // Shift bits into register
    shiftData(animationDirection);

    // Bitshift data values
    firstByte = firstByte << 1;
    secondByte = secondByte << 1;

    shiftDelay();
  }

  // Set bit pattern
  firstByte = 0B01000100;
  secondByte = 0B01000100;

  // Loop to the left or right depending on direction
  for(int i = 0; i < 2 + cycle; i++){
    // Shift bits into register
    shiftData(animationDirection);

    // Bitshift data values
    firstByte = firstByte >> 1;
    secondByte = secondByte >> 1;

    shiftDelay();
  }
}
/* END UPANDDOWN_INO */
