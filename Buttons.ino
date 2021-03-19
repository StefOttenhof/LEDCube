/* CICLE_INO */
#include "Ground.h"
#include "ShiftData.h"

int posY = 1;

void moveY(){
  /*
  * Function: moveY
  * ----------------------------
  *   Moves active LED on Y scale based on current active LED
  *
  *   returns: none
  */
  if(posY == 0){
    turnLayerOff(groundArray[3]);
    turnLayerOn(groundArray[posY]);
    shiftDelay();
    posY++;
    
  } else if(posY == 3){
    turnLayerOff(groundArray[posY - 1]);
    turnLayerOn(groundArray[posY]);
    shiftDelay();
    posY = 0;
   
  } else {
    turnLayerOff(groundArray[posY - 1]);
    turnLayerOn(groundArray[posY]);
    shiftDelay();
    posY++;
    
  }

}

void moveX(){
  /*
  * Function: moveX
  * ----------------------------
  *   Moves active LED on X scale based on current active LED
  *
  *   returns: none
  */

  /*
  * Modify first byte
  */
  if(firstByte == 0B00001000){
    firstByte = 0B00000001;
  } else if(firstByte == 0B10000000){
    firstByte = 0B00010000;
  } else {
    firstByte = firstByte << 1;
  }

  /*
  * Modify second byte
  */
  if(secondByte == 0B00001000){
    secondByte = 0B00000001;
  } else if(secondByte == 0B10000000){
    secondByte = 0B00010000;
  } else {
    secondByte = secondByte << 1;
  }
    
  shiftData(MSB);
}

void moveZ(){
  /*
  * Function: moveZ
  * ----------------------------
  *   Moves active LED on Z scale based on current active LED
  *
  *   returns: none
  */
  if(firstByte >= 0B00010000){
    secondByte = firstByte >> 4;
    firstByte = 0B00000000;
  } else if(secondByte >= 0B00010000){
    firstByte = secondByte >> 4;
    secondByte = 0B00000000;
  } else {
    firstByte = firstByte << 4;
    secondByte = secondByte << 4;
  }

  shiftData(MSB);
}

void configLayout(){
  /*
  * Function: configLayout
  * ----------------------------
  *   Initializes cube with only one active led in the bottom corner
  *
  *   returns: none
  */
  turnAllLayersOff();
  
  firstByte = 0B00000001;
  secondByte = 0B00000000;
  shiftData(MSB);
  
  turnLayerOn(FIRSTGROUND);
}
/* END CIRCLE_INO */
