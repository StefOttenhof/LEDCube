/* CICLE_INO */
#include "Config.h"

int indexesLsb[12] = { 0B11100000, 0B01110000, 0B00110001, 0B00010001, 0B00000001, 0B00000000, 0B00000000, 0B00000000, 0B00000000, 0B00001000, 0B10001000, 0B11001000};
int indexesMsb[12] = { 0B00000000, 0B00000000, 0B00000000, 0B00010000, 0B00010001, 0B00010011, 0B00000111, 0B00001110, 0B10001100, 0B10001000, 0B10000000, 0B00000000};

void circleAnimation(bitDirection animationDirection, lastCycle cycle){
   // Set all layers to high
  turnAllLayersOn();

  if(animationDirection == MSB){
    for(int i = 0; i < 12 - cycle; i++){
       firstByte = indexesMsb[i];
       secondByte = indexesLsb[i];
        
       shiftData(MSB);

       shiftDelay();
    }
  } else {
    for(int i = 12; i >= 0 + cycle; i--){
       firstByte = indexesMsb[i];
       secondByte = indexesLsb[i];
        
       shiftData(MSB);

       shiftDelay();
    }
  }
}
/* END CIRCLE_INO */
