/* UPANDDOWN_INO */
#include "Config.h"

int animationArray[7];
int groundUpArray[7] = { FIRSTGROUND, SECONDGROUND, THIRDGROUND, FOURTHGROUND, THIRDGROUND, SECONDGROUND, FIRSTGROUND };
int groundDownArray[7] = { FOURTHGROUND, THIRDGROUND, SECONDGROUND, FIRSTGROUND, SECONDGROUND, THIRDGROUND, FOURTHGROUND };

void upAndDownAnimation(bitDirection animationDirection, lastCycle cycle){
  turnAllLayersOff();
  firstByte = 0B11111111;
  secondByte = 0B11111111;
  shiftData(MSB);

  // Select direction
  if(animationDirection == LSB){
    memcpy(animationArray, groundUpArray, sizeof(groundUpArray[0])*7);
  } else {
    memcpy(animationArray, groundDownArray, sizeof(groundDownArray[0])*7);
  }

  // Loop through ground layers
  for(int i = 0; i < 6 + cycle; i++){
    if(i == 0){
      turnLayerOn(animationArray[i]);
    } else {
      turnLayerOff(animationArray[i-1]);
      turnLayerOn(animationArray[i]);
    }

    shiftDelay();
  }
}
/* END UPANDDOWN_INO */
