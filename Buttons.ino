/* CICLE_INO */
#include "Ground.h"
#include "ShiftData.h"

int posY = 1;

void moveY(){
      if(posY == 0){
      digitalWrite(groundArray[3], LOW);
      digitalWrite(groundArray[posY], HIGH);
      delay(700);
      posY++;
    } else if(posY == 3){
      digitalWrite(groundArray[posY - 1], LOW);
      digitalWrite(groundArray[posY], HIGH);
      delay(700);
      posY = 0;
    } else {
       digitalWrite(groundArray[posY - 1], LOW);
      digitalWrite(groundArray[posY], HIGH);
      delay(700);
      posY++;
    }

}

void moveX(){
    if(firstByte == 0B00001000){
      firstByte = 0B00000001;
    } else if(firstByte == 0B10000000){
      firstByte = 0B00010000;
    } else {
      firstByte = firstByte << 1;
    }

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
     turnAllLayersOff();
     firstByte = 0B00000001;
     secondByte = 0B00000000;
     shiftData(MSB);
     turnLayerOn(FIRSTGROUND);
}
/* END CIRCLE_INO */
