/* UPANDDOWN_INO */
#include "Config.h"

int animationArray[7];
int groundUpArray[7] = { FIRSTGROUND, SECONDGROUND, THIRDGROUND, FOURTHGROUND, THIRDGROUND, SECONDGROUND, FIRSTGROUND };
int groundDownArray[7] = { FOURTHGROUND, THIRDGROUND, SECONDGROUND, FIRSTGROUND, SECONDGROUND, THIRDGROUND, FOURTHGROUND };

void upAndDownAnimation(bitDirection animationDirection, lastCycle cycle){
    /*
  * Function: upAndDownAnimation
  * ----------------------------
  *   Animation of 16 bits going from the bottom to the top of the cube
  *
  *   animationDirection: Determines the inital direction of the animation
  *   
  *   Cycle: Makes the animation look smoother when played multiple times by eliminating the last state
  *   
  *   returns: none
  */
  turnAllLayersOff();
  firstByte = 0B11111111;
  secondByte = 0B11111111;
  shiftData(MSB);

  /*
  * Copy one of two arrays to animationArray
  */
  if(animationDirection == LSB){
    memcpy(animationArray, groundUpArray, sizeof(groundUpArray[0])*7);
  } else {
    memcpy(animationArray, groundDownArray, sizeof(groundDownArray[0])*7);
  }

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
