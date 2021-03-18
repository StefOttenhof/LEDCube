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
    if(firstLedsData == 0B00001000){
      firstLedsData = 0B00000001;
    } else if(firstLedsData == 0B10000000){
      firstLedsData = 0B00010000;
    } else {
      firstLedsData = firstLedsData << 1;
    }

    if(secondLedsData == 0B00001000){
      secondLedsData = 0B00000001;
    } else if(secondLedsData == 0B10000000){
      secondLedsData = 0B00010000;
    } else {
      secondLedsData = secondLedsData << 1;
    }
    shiftData(MSB);
}

void moveZ(){
  if(firstLedsData >= 0B00010000){
    secondLedsData = firstLedsData >> 4;
    firstLedsData = 0B00000000;
  } else if(secondLedsData >= 0B00010000){
    firstLedsData = secondLedsData >> 4;
    secondLedsData = 0B00000000;
  } else {
    firstLedsData = firstLedsData << 4;
    secondLedsData = secondLedsData << 4;
  }

  shiftData(MSB);
}

void configLayout(){
     turnAllLayersOff();
     firstLedsData = 0B00000001;
     secondLedsData = 0B00000000;
     shiftData(MSB);
     turnLayerOn(FIRSTGROUND);
}
/* END CIRCLE_INO */
